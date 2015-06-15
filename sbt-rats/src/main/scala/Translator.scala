/*
 * This file is part of the sbt-rats plugin.
 * Copyright (c) 2012-2015 Anthony M Sloane, Macquarie University.
 * All rights reserved.
 * Distributed under the New BSD license.
 * See file LICENSE at top of distribution.
 */

import org.kiama.output.PrettyPrinter

/**
 * Translator to Rats! specifications, parameteriesed by the sementic
 * analyser to use.
 */
class Translator(analyser: Analyser) extends PrettyPrinter {

  import ast._
  import sbt.File
  import sbt.IO.write

  def translate(flags: Flags, genFile: File, grammar: Grammar) = {

    import analyser.{
      constr,
      elemtype,
      hasSpacing,
      ntname,
      nttype,
      partitionLiterals,
      requiresNoAction,
      syntaxElements,
      transformer,
      typeName
    }
    import org.kiama.attribution.Attribution.{ initTree, resetMemo }

    // Count of non-terminals on the RHS of an alternative
    // FIXME: remove or hide better
    var ntcount = 0

    def toRats: Doc = {
      val (keywords, symbols) = partitionLiterals(grammar)
      "module" <+> grammar.module.mkString(".") <> semi <@>
        toHeader(grammar.header) <@>
        toBody(grammar.body, keywords) <@>
        toOptions(grammar.options) <@>
        toSymbols(symbols) <@>
        toRules(grammar.rules) <@>
        toDefaults
    }

    def toHeader(header: String): Doc =
      line <>
        toBraceSection("header",
          "import sbtrats.Action;" <@>
            "import xtc.tree.Location;",
          if (header == null) empty else string(header))

    def toBody(userBody: String, keywords: Set[String]): Doc = {

      lazy val fixedBody =
        """
                |/**
                | * Format a Rats! parser error message according to Scala compiler
                | * conventions for better compatibility with error processors.
                | */
                |public String formatParseError (ParseError error, Boolean showCoord) throws IOException {
                |    StringBuilder buf = new StringBuilder ();
                |
                |    if (error.index == -1) {
                |        buf.append (error.msg);
                |    } else {
                |        Location loc = location (error.index);
                |        if (showCoord) {
                |            buf.append (loc.file);
                |            buf.append (':');
                |            buf.append (loc.line);
                |            buf.append (": ");
                |        }
                |
                |        buf.append (error.msg);
                |        buf.append ("\n\n");
                |
                |        String line = lineAt (error.index);
                |        buf.append (line);
                |        buf.append ('\n');
                |        for (int i = 1; i < loc.column; i++) buf.append (' ');
                |        buf.append ("^");
                |    }
                |
                |    return buf.toString ();
                |}
                """.stripMargin

      lazy val binarySupport =
        """
                |int strToInt (String number) {
                |    try {
                |        byte[] bytes = number.getBytes ("ISO-8859-1");
                |        return new java.math.BigInteger (1, bytes).intValue ();
                |    } catch (java.io.UnsupportedEncodingException e) {
                |        System.err.println ("strToInt: unsupported encoding exception");
                |        return 0;
                |    }
                |}
                |
                |Result parseBytes (String number, int start, int base) throws IOException {
                |    int n = strToInt (number);
                |    StringBuilder buf = new StringBuilder (n);
                |    for (int i = 0; i < n; i++) {
                |        int c = character (base + i);
                |        if (c != -1) {
                |            buf.append ((char)c);
                |        } else {
                |            return new ParseError (String.format ("expected %d bytes but EOF found", n), base + i);
                |        }
                |    }
                |    return new SemanticValue (buf.toString (), base + n);
                |}
                |""".stripMargin

      lazy val keywordTable =
        toBraceSection("static",
          group(toKeywords(keywords)))

      val possibleBodyParts =
        List(true -> text(fixedBody),
          (userBody != null) -> text(userBody),
          flags.includeBinarySupport -> text(binarySupport),
          flags.includeKeywordTable -> keywordTable)

      val bodyParts =
        possibleBodyParts.filter(_._1).map(_._2)

      bodyParts match {
        case Nil =>
          empty
        case _ =>
          line <>
            toBraceSection("body", vsep(bodyParts))
      }

    }

    def toBraceSection(keyword: String, contents: Doc, prefix: Doc = empty): Doc =
      keyword <+> braces(prefix <> nest(line <> contents) <> line)

    def toKeywords(keywords: Set[String]): Doc =
      "add" <+> parens(
        toBraceSection("KEYWORDS, new String[]",
          fillsep(keywords.toVector.sorted map (s => dquotes(text(s))), comma))) <> semi

    def toOptions(options: List[SyntaxOption]): Doc = {
      val userOptionStrings =
        if (options == null)
          Nil
        else
          options.distinct.flatMap {
            case Verbose()      => List("verbose")
            case SetOfString(s) => List(s"setOfString ($s)")
            case _              => Nil
          }
      val possibleOptions =
        List(flags.includeKeywordTable -> "setOfString (KEYWORDS)",
          flags.useScalaPositions -> "withLocation")
      val optionStrings =
        userOptionStrings ++
          possibleOptions.filter(_._1).map(_._2)
      line <>
        "option" <+> hsep(optionStrings map text, comma) <> semi
    }

    def escapedDquotes(s: String): Doc =
      dquotes(s.replaceAllLiterally("\"", "\\\""))

    def toSymbols(symbols: Set[String]): Doc =
      if (symbols.isEmpty)
        empty
      else {
        // Sort in reverse order of length so that earlier ones take priority
        val sortedSymbols = symbols.toVector.sortBy(-_.length)

        line <>
          "String Symbol =" <>
          nest(
            line <>
              "SymbolCharacters Spacing;") <@>
            line <>
            "transient String SymbolCharacters =" <>
            nest(
              line <>
                fillsep(sortedSymbols map (escapedDquotes(_)), " /")) <> semi
      }

    def toRules(rules: List[Rule]): Doc =
      vsep(rules map toRule)

    def toRule(rule: Rule) =
      rule match {
        case r: ASTRule    => toASTRule(r)
        case r: StringRule => toStringRule(r)
        case r: RatsRule   => toRatsRule(r)
        case RatsBlock(c)  => string(c.mkString)
      }

    def toRHS(elem: Element, isASTRule: Boolean, useSpacing: Boolean): Doc = {

      def isWord(s: String): Boolean =
        (s == "") ||
          (Character.isJavaIdentifierStart(s.head) &&
            s.tail.forall(Character.isJavaIdentifierPart))

      def toLiteral(s: String): Doc = {
        val prefix: Doc = if (isASTRule) "void" <> colon else ""
        val form = if (isWord(s)) "Word" else "Symbol"
        val suffix = if (useSpacing) colon <> form else empty
        prefix <> escapedDquotes(s) <> suffix
      }

      def toElem(elem: Element, doBindings: Boolean = false): Doc = {

        def bind(doc: Doc): Doc =
          if (doBindings) {
            ntcount = ntcount + 1
            "v" <> value(ntcount) <> colon <> doc
          } else
            doc

        def action(d: Doc): Doc =
          "^" <> braces(nest(line <> d) <> line)

        def toBlock(n: Int): Doc = {
          ntcount = ntcount + 1
          action(
            "String v" <> value(ntcount) <> semi <>
              line <>
              "yyResult = parseBytes(v" <> value(n) <> ", yyStart, yyBase);" <>
              line <>
              "if (yyResult.hasValue()) {" <>
              nest(
                line <>
                  "v" <> value(ntcount) <+> "= yyResult.semanticValue();" <>
                  line <>
                  "yyResult = new SemanticValue(null, yyResult.index);") <>
                line <>
                "} else {" <>
                nest(
                  line <>
                    "v" <> value(ntcount) <+> "= null;") <>
                  line <>
                  "}")
        }

        elem match {
          case nt: NonTerminal =>
            if (nt -> nttype == "Void")
              text(nt -> ntname)
            else
              bind(text(nt -> ntname))

          case Not(elem) =>
            "!" <> parens(toElem(elem))

          case Opt(elem) =>
            val inner = parens(toElem(elem)) <> "?"
            if (elem -> elemtype == "Void")
              inner
            else
              bind(inner)

          case Rep(zero, elem, Epsilon()) =>
            val inner = parens(toElem(elem)) <> (if (zero) "*" else "+")
            if (elem -> elemtype == "Void")
              inner
            else
              bind(inner)
          case _: Rep =>
            sys.error("toElem: separated list left in for translation")

          case Alt(left, right) =>
            parens(toElem(left) <> "/" <> toElem(right))

          case Seqn(left, right) =>
            val inner = toElem(left) <+> toElem(right)
            if (elem -> elemtype == "Void")
              inner
            else
              bind(inner)

          case CharLit(str) =>
            toLiteral(str)
          case StringLit(str) =>
            toLiteral(str)

          case CharClass(str) =>
            brackets(str)

          case Epsilon() =>
            "/* empty */"
          case Wildcard() =>
            "_"

          case Nest(elem, _) =>
            toElem(elem, doBindings)

          case Block(_, n) =>
            toBlock(n)

          case _ =>
            empty
        }

      }

      toElem(elem, isASTRule)

    }

    def toASTRule(astRule: ASTRule): Doc = {

      val ASTRule(lhs, declType, alts, isConst, _) = astRule

      def toAlternative(a: Alternative): Doc = {
        ntcount = 0

        // We want to use spacing between symbols by default but not if
        // there is a "nospacing" annotation on the rule
        val useSpacing = astRule -> hasSpacing

        hsep(a.rhs map (elem => toRHS(elem, true, useSpacing))) <+> toAction(a)
      }

      def toAction(alt: Alternative): Doc = {

        // Get the syntax elements of this alternative
        val elements = alt -> syntaxElements

        // The arguments are v1 .. vn. Normally these are passed straight through
        // to the constructor. However, if there is an annotation of the form
        // n:m then the value passed through for argument n is the result of
        // passing the original value to the method m. If an argument is an option
        // and we are using Scala options, then we translate from the nullable
        // representation to the Scala option value as we pass the argument.
        val argList =
          (1 to ntcount).map {
            case n =>
              val argName = "v" <> value(n)
              val argExp =
                if ((flags.useScalaOptions) &&
                  ((elements(n - 1) -> elemtype).startsWith("Option")))
                  "Option.apply" <+> parens(argName)
                else
                  argName
              (alt -> transformer(n) match {
                case Some(method) =>
                  method <+> parens(argExp)
                case None =>
                  argExp
              })
          }

        // Pretty-printed argument list for constructor
        val args = hsep(argList, comma)

        if (alt -> requiresNoAction)
          empty
        else
          braces(nest(line <>
            "yyValue" <+> equal <+>
            (alt.action match {
              case ApplyAction() =>
                "ParserSupport.apply(v2, v1)"
              case ConsAction(tipe) =>
                s"new Pair<$tipe>(v1, v2)"
              case DefaultAction() =>
                "new" <+> text(alt -> constr) <+> parens(args)
              case NoAction() =>
                // Not reachable
                empty
              case NilAction() =>
                "Pair.empty()"
              case SingletonAction(tipe) =>
                s"new Pair<$tipe>(v1)"
              case TailAction(tipe, constr) =>
                val num = elements.length
                val args = (1 to num).map("v" + _).mkString(", ", ", ", "")
                toBraceSection(s"new Action<$tipe>()",
                  toBraceSection(s"public $tipe run ($tipe left)",
                    "return new" <+> constr <+> parens("left" <> args) <> semi) <> semi)
            }) <> semi) <> line)

      }

      line <>
        (if (isConst) "constant" else "public") <+>
        text(astRule -> typeName) <+> lhs.name <+> equal <>
        nest(
          line <>
            lsep2(alts map toAlternative, "/") <> semi)

    }

    def toStringRule(stringRule: StringRule): Doc = {

      val StringRule(lhs, IdnUse(tipeStr), alts) = stringRule

      val tipe = if (tipeStr == "Void") "void" else "String"

      def toAlternative(e: Element): Doc =
        toRHS(e, false, false)

      def auxname(name: String): String =
        name + "Form"

      def auxdef(name: String) =
        line <>
          "public" <+> "String" <+> name <+> equal <>
          nest(
            line <>
              auxname(name) <+> "Spacing" <@>
              semi)

      def maindef(name: String): Doc =
        line <>
          "public" <+> tipe <+> name <+> equal <>
          nest(
            line <>
              lsep2(alts map toAlternative, "/") <> semi)

      if (tipeStr == "Token")
        auxdef(lhs.name) <@> maindef(auxname(lhs.name))
      else
        maindef(lhs.name)

    }

    def toRatsRule(ratsRule: RatsRule): Doc = {

      val RatsRule(lhs, tipe, code) = ratsRule

      line <>
        "public" <+> tipe.name <+> lhs.name <+> equal <>
        code <> semi

    }

    /**
     * Generate default implementations of various aspects, depending on the
     * flag settings.
     */
    def toDefaults: Doc = {

      val layoutSpec =
        if (flags.useDefaultLayout)
          """
                    |// Default layout specification
                    |public transient void Spacing   = (Space / Comment)*;
                    |public transient void Space     = ' ' / '\t' / '\f' / EOL;
                    |public transient void EOL       = '\r' '\n' / '\r' / '\n';
                    |public transient void EOF       = !_;
                    |""".stripMargin
        else
          ""

      val commentSpec =
        if (flags.useDefaultComments)
          """
                    |// Default comment specification
                    |public transient void Comment   = SLComment / MLComment;
                    |public transient void SLComment = "//" (!EOL _)* (EOL / EOF);
                    |public transient void MLComment = "/*" (MLComment / !"*/" _)* "*/";
                    |""".stripMargin
        else
          ""

      val wordsSpec =
        if (flags.useDefaultWords)
          """
                    |// Default word specification
                    |public String Identifier =
                    |    Word &{
                    |        ! contains (KEYWORDS, yyValue)
                    |    };
                    |
                    |public String Word =
                    |    WordCharacters Spacing;
                    |
                    |public transient String WordCharacters =
                    |    h:_ &{
                    |        Character.isJavaIdentifierStart (h)
                    |    } (t:_ &{
                    |        Character.isJavaIdentifierPart (t)
                    |    })*;
                    |""".stripMargin
        else
          ""

      string(layoutSpec) <@>
        string(commentSpec) <@>
        string(wordsSpec)

    }

    // Initialise the tree so we can perform attribution on it
    resetMemo()
    initTree(grammar)

    // Convert grammar to a pretty printer document representing the translated
    // Rats! specification
    val code = pretty(toRats)

    // Put the code in the specified file
    write(genFile, code)

  }

}
