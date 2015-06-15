/*
 * This file is part of the sbt-rats plugin.
 * Copyright (c) 2012-2015 Anthony M Sloane, Macquarie University.
 * All rights reserved.
 * Distributed under the New BSD license.
 * See file LICENSE at top of distribution.
 */

import org.kiama.util.Environments

/**
 * Semantic analyser for syntax definitions, parameterised by the flags
 * that apply to this build.
 */
class Analyser(flags: Flags) extends Environments {

  import ast._
  import org.kiama.==>
  import org.kiama.attribution.Attribution.{ attr, paramAttr }
  import org.kiama.attribution.Decorators.{ atRoot, chain, Chain }
  import org.kiama.output.{
    Fixity,
    Infix,
    LeftAssoc,
    NonAssoc,
    Postfix,
    Prefix,
    RightAssoc,
    Side
  }
  import org.kiama.rewriting.Rewriter.collectall
  import org.kiama.util.{ Entity, MultipleEntity, UnknownEntity }
  import org.kiama.util.Messaging.{ check, message, Messages }
  import org.kiama.util.Patterns.HasParent
  import scala.collection.mutable.ListBuffer

  val errors =
    attr(collectall {
      case d @ IdnDef(i) if d -> entity == MultipleEntity() =>
        message(d, s"'$i' is declared more than once")

      case u @ IdnUse(i) if u -> entity == UnknownEntity() =>
        message(u, s"'$i' is not declared")

      case u @ IdnUse(i) if !(u -> idntypeok) =>
        message(u, s"a ${u -> idntypedesc} can't be used here")

      case r: ASTRule if !missingPrecedences(r).isEmpty =>
        val levelStr = missingPrecedences(r).mkString(" ")
        message(r, s"missing precedence levels: $levelStr")

      case r: ASTRule if !mixedAssociativities(r).isEmpty =>
        val levelStr = mixedAssociativities(r).mkString(" ")
        message(r, s"mixed associativities at levels: $levelStr")

      case b @ Block(_, n) if (b.index + 1 == n) =>
        check(b.parent) {
          case alt: Alternative =>
            message(b, "block non-terminal can't refer to itself")
        }

      case b @ Block(_, n) =>
        check(b.parent) {
          case alt: Alternative if ((n < 1) || (n > alt.rhs.length)) =>
            message(b, s"block non-terminal reference $n out of range 1..${alt.rhs.length}")
        }

      case Rep(_, _, sep) if (sep -> elemtype != "Void") && (sep -> elemtype != "String") =>
        message(sep, "list separator must be Void or String")
    })

  /**
   * Return a pair consisting of the set of keywords used in the grammar
   * and the set of non-keywords used. Keywords are defined to be literals
   * that containing only letters andu nderscores.
   */
  def partitionLiterals(g: Grammar): (Set[String], Set[String]) =
    (g -> literals).partition(_.forall(isKeywordChar))

  /**
   * Can the given character be part of a keyword?
   */
  def isKeywordChar(c: Char): Boolean =
    c.isLetter || c == '_'

  // Entities

  /**
   * Non-terminals with a particular type
   */
  abstract class NonTerm extends Entity {
    def tipe: String
  }

  /**
   * A user-defined non-terminal with the given type and defined by the given
   * AST rule.
   */
  case class UserNonTerm(tipe: String, astRule: ASTRule) extends NonTerm

  /**
   * A user-defined non-terminal with the given type and defined by the given
   * Rats rule.
   */
  case class RatsNonTerm(tipe: String, ratsRule: RatsRule) extends NonTerm

  /**
   * A pre-defined non-terminal with the given type.
   */
  case class PreNonTerm(tipe: String) extends NonTerm

  /**
   * A user-defined constructor.
   */
  case class Cons() extends Entity

  /**
   * A type.
   */
  case class Type() extends Entity

  /**
   * The default environment, containing the grammar symbols that are
   * either provided by the plugin or are expected to be defined by
   * the user.
   */
  def defenv: Environment = {
    val possibleBindings =
      List(flags.useDefaultComments -> ("Comment" -> PreNonTerm("Void")),
        flags.useDefaultLayout -> ("EOF" -> PreNonTerm("Void")),
        flags.useDefaultLayout -> ("EOL" -> PreNonTerm("Void")),
        flags.useDefaultWords -> ("Identifier" -> PreNonTerm("String")),
        flags.useDefaultComments -> ("SLComment" -> PreNonTerm("void")),
        flags.useDefaultComments -> ("MLComment" -> PreNonTerm("void")),
        flags.useDefaultLayout -> ("Space" -> PreNonTerm("Void")),
        flags.useDefaultLayout -> ("Spacing" -> PreNonTerm("Void")),
        true -> ("String" -> Type()),
        true -> ("Token" -> Type()),
        true -> ("Void" -> Type()),
        flags.useDefaultWords -> ("Word" -> PreNonTerm("String")),
        flags.useDefaultWords -> ("WordCharacters" -> PreNonTerm("String")))
    val bindings =
      possibleBindings.filter(_._1).map(_._2)
    rootenv(bindings: _*)
  }

  lazy val literals: Chain[ASTNode, Set[String]] =
    chain(literalsin, literalsout)

  def literalsin(in: ASTNode => Set[String]): ASTNode ==> Set[String] = {
    case _: Grammar => Set()
  }

  /**
   * Split a literal string into its constituent character components.
   * Only legal literals need to be dealt with since the input has
   * already been parsed.
   */
  def parseLiteral(s: String): List[Char] =
    if (s == "")
      Nil
    else {
      val (first, len) =
        s(0) match {
          case '\\' =>
            s(1) match {
              case 'b'  => ('\b', 2)
              case 't'  => ('\t', 2)
              case 'n'  => ('\n', 2)
              case 'f'  => ('\f', 2)
              case 'r'  => ('\r', 2)
              case '['  => ('[', 2)
              case ']'  => (']', 2)
              case '\\' => ('\\', 2)
              case '\'' => ('\'', 2)
              case '\"' => ('\"', 2)
              case '-'  => ('-', 2)
              case 'u' =>
                val codePoint = Integer.parseInt(s.drop(2).take(4), 16)
                (Character.toChars(codePoint)(0), 6)
              case c if (c >= '0') && (c <= '9') =>
                val len =
                  if ((c >= '0') && (c <= '3'))
                    4
                  else if ((s(2) >= '0') && (s(2) <= '7'))
                    3
                  else
                    2
                val codePoint = Integer.parseInt(s.drop(2).take(4), 8)
                (Character.toChars(codePoint)(0), len)
            }
          case c =>
            (c, 1)
        }
      first :: parseLiteral(s.drop(len))
    }

  def isNotWhitespace(s: String): Boolean =
    !(parseLiteral(s).forall(_.isWhitespace))

  def literalsout(out: ASTNode => Set[String]): ASTNode ==> Set[String] = {
    case n @ CharLit(s) if isNotWhitespace(s) =>
      (n -> out) + s
    case n @ StringLit(s) if isNotWhitespace(s) =>
      (n -> out) + s
  }

  // Name analysis

  lazy val preenv: Chain[ASTNode, Environment] =
    chain(envin, envout)

  def envin(in: ASTNode => Environment): ASTNode ==> Environment = {
    case _: Grammar => defenv
  }

  def envout(out: ASTNode => Environment): ASTNode ==> Environment = {
    case n @ IdnDef(i) =>
      define(n -> out, i,
        if (isDefinedInScope(n -> (preenv.in), i))
          MultipleEntity()
        else
          entityFromDecl(n, i))
  }

  def entityFromDecl(n: IdnDef, i: String): Entity =
    n.parent match {
      case astRule @ ASTRule(_, tipe, _, _, _) =>
        UserNonTerm(if (tipe == null) i else tipe.name, astRule)
      case Constructor(_) =>
        Cons()
      case ratsRule @ RatsRule(_, tipe, _) =>
        RatsNonTerm(if (tipe == null) i else tipe.name, ratsRule)
      case StringRule(_, IdnUse(tipeStr), _) =>
        PreNonTerm(tipeStr)
    }

  lazy val env =
    atRoot[ASTNode, Environment](preenv)

  lazy val entity: Identifier => Entity =
    attr {
      case n =>
        lookup(n -> env, n.name, UnknownEntity())
    }

  lazy val ntname: NonTerminal => String =
    attr {
      case NonTerminal(NTName(IdnUse(name))) =>
        name
      case NonTerminal(NTGen(name, _)) =>
        name
    }

  // Type analysis

  lazy val idntype: Identifier => String =
    attr {
      case idn =>
        (idn -> entity) match {
          case _: Cons =>
            "Constructor"
          case nt: NonTerm =>
            if (nt.tipe == "Token")
              "String"
            else
              nt.tipe
          case _: Type =>
            "Type"
        }

    }

  lazy val idntypedesc: Identifier => String =
    attr {
      case idn =>
        (idn -> entity) match {
          case _: NonTerm =>
            "NonTerminal"
          case _ =>
            idn -> idntype
        }

    }

  lazy val idntypeok: Identifier => Boolean =
    attr {
      case idn =>
        (idn -> entity) match {
          case _: Cons =>
            false
          case _: Type =>
            idn.parent.isInstanceOf[ASTRule] ||
              idn.parent.isInstanceOf[RatsRule] ||
              idn.parent.isInstanceOf[StringRule]
          case _ =>
            true
        }
    }

  lazy val nttype: NonTerminal => String =
    attr {
      case NonTerminal(NTName(idnuse)) =>
        idnuse -> idntype
      case NonTerminal(NTGen(_, tipe)) =>
        tipe
    }

  lazy val elemtype: Element => String =
    attr {
      case _: Block =>
        "String"
      case nt: NonTerminal =>
        nt -> nttype
      case Opt(elem) =>
        if (elem -> elemtype == "Void")
          "Void"
        else
          "Option[%s]".format(elem -> elemtype)
      case Rep(_, elem, _) =>
        if (elem -> elemtype == "Void")
          "Void"
        else
          "List[%s]".format(elem -> elemtype)
      case Seqn(l, r) =>
        (l -> elemtype) match {
          case "Void" => r -> elemtype
          case ltype  => ltype
        }
      case Nest(elem, _) =>
        elem -> elemtype
      case _ =>
        "Void"
    }

  // Patterns

  /**
   * Pattern to match a literal element.
   */
  object Literal {
    def unapply(e: Element): Option[String] =
      e match {
        case CharLit(s)   => Some(s)
        case StringLit(s) => Some(s)
        case _            => None
      }
  }

  /**
   * Pattern to match a non-terminal name.
   */
  object NonTermIdn {
    def unapply(e: Element): Option[String] =
      e match {
        case nt: NonTerminal =>
          Some(nt -> ntname)
        case _ =>
          None
      }
  }

  // Properties

  /**
   * The name of the type that represents values of a particular rule.
   * Either given explicitly, or if implicit, the same as the LHS of
   * the rule.
   */
  lazy val typeName: ASTRule => String =
    attr {
      case astRule if astRule.tipe == null =>
        astRule.idndef.name
      case astRule =>
        astRule.tipe.name
    }

  /**
   * The action type of a recursive rule.
   */
  lazy val actionTypeName: ASTRule => String =
    attr {
      case astRule =>
        s"Action<${astRule -> typeName}>"
    }

  /**
   * The pair type of a list element.
   */
  lazy val pairTypeName: Element => String =
    attr {
      case elem =>
        s"Pair<${elem -> elemtype}>"
    }

  /**
   * Look for a particular annotation on a rule and, if it's a typed rule,
   * on the rule that defines its type.
   */
  def hasRuleAnnotation(astRule: ASTRule, ann: RuleAnnotation): Boolean = {
    val res = (astRule.anns != null) && (astRule.anns contains (ann))
    if (astRule.tipe == null)
      res
    else
      res || ((astRule.tipe) -> entity match {
        case UserNonTerm(_, otherRule) if astRule != otherRule =>
          hasRuleAnnotation(otherRule, ann)
        case _ =>
          false
      })
  }

  /**
   * Is this rule to be prefixed by line breaks when pretty-printing?
   */
  lazy val isLinePP: ASTRule => Boolean =
    attr {
      case astRule =>
        hasRuleAnnotation(astRule, Line())
    }

  /**
   * Is this rule to have its RHSes nested when pretty-printing?
   */
  lazy val isNestedPP: ASTRule => Boolean =
    attr {
      case astRule =>
        hasRuleAnnotation(astRule, Nested())
    }

  /**
   * Is this rule to be parenthesized when pretty-printing?
   */
  lazy val isParenPP: ASTRule => Boolean =
    attr {
      case astRule =>
        hasRuleAnnotation(astRule, Parenthesized())
    }

  /**
   * Is spacing turned on for this rule? I.e., does it not have a
   * `nospacing` annotation?
   */
  lazy val hasSpacing: ASTRule => Boolean =
    attr {
      case astRule =>
        !hasRuleAnnotation(astRule, NoSpacing())
    }

  /**
   * The precedences of the alternatives of a rule.
   */
  lazy val precedences: ASTRule => Set[Int] =
    attr {
      case astRule =>
        astRule.alts.map(precedence).toSet
    }

  /**
   * The expected precedences for a rule's alternatives. In other words,
   * zero up to and including the largest precedence that the user has
   * given.
   */
  lazy val expectedPrecedences: ASTRule => Set[Int] =
    attr {
      case astRule =>
        (0 to (astRule -> precedences).max).toSet
    }

  /**
   * The expected precedences for a rule's alternatives that are missing.
   * If this is not empty an error will be reported.
   */
  lazy val missingPrecedences: ASTRule => Set[Int] =
    attr {
      case astRule =>
        (astRule -> expectedPrecedences) -- (astRule -> precedences)
    }

  /**
   * A collection of the precedences of a rule that use mixed associativities.
   * At present we only support a single associativity at each precedence level.
   */
  lazy val mixedAssociativities: ASTRule => Iterable[Int] =
    attr {
      case astRule =>
        astRule.alts.groupBy(precedence).collect {
          case (prec, alts) if alts.map(associativity).distinct.length > 1 =>
            prec
        }
    }

  /**
   * The precedence level of an alternative. If no explicit precedence level
   * is given in the annotations of the alternative, return zero. If there is
   * more than one precedence annotation, the first one is used.
   */
  lazy val precedence: Alternative => Int =
    attr {
      case alt =>
        if (alt.anns == null)
          0
        else
          alt.anns.collect {
            case Precedence(level) => level
          } match {
            case level :: _ => level
            case _          => 0
          }
    }

  /**
   * Does this alternative have a precedence level annotation.
   */
  lazy val hasPrecedenceLevel: Alternative => Boolean =
    attr {
      case alt =>
        if (alt.anns == null)
          false
        else
          alt.anns.exists(_.isInstanceOf[Precedence])
    }

  /**
   * The LHS side name of a rule.
   */
  lazy val lhs: ASTRule => String =
    attr {
      case astRule =>
        astRule.idndef.name
    }

  /**
   * The LHS side symbol of the rule of an alternative.
   */
  lazy val altlhssymb: Alternative => NonTerminal =
    attr {
      case alt =>
        NonTerminal(NTName(IdnUse(alt -> astrule -> lhs)))
    }

  /**
   * Whether an alternative is left-recursive: a sequence of more
   * than one element on the RHS and the first one is the LHS.
   */
  lazy val isLeftRecursive: Alternative => Boolean =
    attr {
      case alt =>
        alt.rhs match {
          case head :: _ =>
            head == alt -> altlhssymb
          case _ =>
            false
        }
    }

  /**
   * Whether an alternative is right-recursive: a sequence of more
   * than one element on the RHS and the last one is the LHS.
   */
  lazy val isRightRecursive: Alternative => Boolean =
    attr {
      case alt =>
        alt.rhs.lastOption match {
          case Some(last) =>
            last == alt -> altlhssymb
          case None =>
            false
        }
    }

  /**
   * Whether an alternative is recursive: the LHS appears in the RHS
   * sequence.
   */
  lazy val isRecursive: Alternative => Boolean =
    attr {
      case alt =>
        alt.rhs contains NonTerminal(NTName(IdnUse(alt -> astrule -> lhs)))
    }

  /**
   * The associativity of an alternative. If there are no associativity
   * annotations, it's not associative. Otherwise, it's the first such
   * annotation that applies.
   */
  lazy val associativity: Alternative => Side =
    attr {
      case alt =>
        if (alt.anns == null)
          NonAssoc
        else
          alt.anns.collect {
            case Associativity(side) =>
              side
          } match {
            case assoc :: _ => assoc
            case _          => NonAssoc
          }
    }

  /**
   * The ASTRule of an alternative.
   */
  lazy val astrule: Alternative => ASTRule =
    attr {
      case alt =>
        alt.parent.asInstanceOf[ASTRule]
    }

  /**
   * The optional constructor for an alternative. If there are constructor
   * annotations, take the first one. Otherwise, return None.
   */
  lazy val optConstr: Alternative => Option[String] =
    attr {
      case alt =>
        if (alt.anns == null)
          None
        else
          alt.anns.collectFirst {
            case Constructor(IdnDef(name)) =>
              name
          }
    }

  /**
   * The consructor for an alternative. If there are constructor
   * annotations, take the first one. Otherwise, use the left-hand
   * side of the enclosing rule.
   */
  lazy val constr: Alternative => String =
    attr {
      case alt =>
        (alt -> optConstr) match {
          case None =>
            alt -> astrule -> lhs
          case Some(name) =>
            name
        }
    }

  /**
   * Does the annotation list for this alternative contain an annotation
   * of the form n:m:_? If so, return Some (m), otherwise return None.
   * If there are multiple such annotations, the first one is used.
   */
  lazy val transformer: Int => Alternative => Option[String] =
    paramAttr {
      case n => {
        case alt =>
          if (alt.anns == null)
            None
          else
            alt.anns.collect {
              case Transformation(m, method, _) if n == m =>
                method
            } match {
              case method :: _ => Some(method.mkString("."))
              case _           => None
            }
      }

    }

  /**
   * Whether or not an alternative requires an action. We don't need one
   * if the alternative has an explicit decoration that it requires no
   * action.
   */
  lazy val requiresNoAction: Alternative => Boolean =
    attr {
      case alt =>
        alt.action == NoAction()
    }

  /**
   * Is this alternative a transfer alternative or not? A transfer
   * alternative is one that has a single non-terminal on the right-hand
   * side, the type of that non-terminal is the same as the type of the
   * rule and there are no annotations.
   */
  lazy val isTransferAlt: Alternative => Boolean =
    attr {
      case alt if alt.anns == null =>
        alt -> syntaxElements match {
          case List(nt: NonTerminal) =>
            nt -> nttype == alt -> astrule -> typeName
          case _ =>
            false
        }
      case _ =>
        false
    }

  /**
   * The elements of an alternative, ignoring the elements that don't
   * contribute to the abstract syntax.
   */
  lazy val syntaxElements: Alternative => List[Element] =
    attr {
      case alt =>
        alt.rhs.filterNot {
          case elem =>
            elem -> elemtype == "Void"
        }
    }

  /**
   * Does the alternative require no pretty-printing clause? Cases are:
   * a) if it has no action, b) for Kiama 1.x, if it's part of a
   * parenthesized rule, features the recursive symbols and has a
   * precedence level, or c) or if it's a transfer alternative. In the
   * second case it will be handled by the paren pretty printer.
   */
  lazy val requiresNoPPCase: Alternative => Boolean =
    attr {
      case alt =>
        (alt -> requiresNoAction) ||
          ((flags.useKiama == 1) && (alt -> astrule -> isParenPP) &&
            (alt -> isRecursive) && (alt -> hasPrecedenceLevel)) ||
            (alt -> isTransferAlt)
    }

  /**
   * Alternatives of a rule that have something to say about the tree.
   */
  lazy val treeAlternatives: ASTRule => List[Alternative] =
    attr {
      case astRule =>
        astRule.alts.filter(alt => (alt.anns != null) && (alt.anns.length > 0))
    }

  /**
   * Map of field number to type as given by the alternative's
   * annotations.
   */
  lazy val fieldTypes: Alternative => Map[Int, String] =
    attr {
      case alt =>
        if (alt.anns == null)
          Map.empty
        else
          alt.anns.collect {
            case Transformation(n, _, t) =>
              (n, t.mkString("."))
          }.reverse.toMap
    }

  /**
   * Get the base field name for a particular element.
   */
  lazy val baseFieldName: Element => String =
    attr {
      case Block(name, _) =>
        name
      case nt: NonTerminal =>
        nt -> ntname
      case Opt(elem) =>
        s"opt${elem -> baseFieldName}"
      case Rep(false, elem, _) =>
        s"${elem -> baseFieldName}s"
      case Rep(true, elem, _) =>
        s"opt${elem -> baseFieldName}s"
      case Seqn(l, r) =>
        if (l -> elemtype == "Void")
          r -> baseFieldName
        else
          l -> baseFieldName
      case elem =>
        sys.error(s"baseFieldName: unexpected element kind $elem")
    }

  /**
   * List of Scala keywords used to avoid declaring a field whose name
   * is a keyword.
   */
  val scalaKeywords = List(
    "abstract", "case", "catch", "class", "def", "do", "else",
    "extends", "false", "final", "finally", "for", "forSome", "if",
    "implicit", "import", "lazy", "match", "new", "null", "object",
    "override", "package", "private", "protected", "return", "sealed",
    "super", "this", "throw", "trait", "true", "try", "type", "val",
    "var", "while", "with", "yield")

  /**
   * Make a name for a field to represent a particular element.
   */
  lazy val fieldName: Element => String =
    attr {
      case elem =>
        val basename = elem -> baseFieldName
        val isAllUpper = basename.forall(_.isUpper)
        val name =
          if (isAllUpper)
            basename.toLowerCase
          else
            (basename(0).toLower) + basename.tail
        if (scalaKeywords contains name)
          "%sField".format(name)
        else
          name
    }

  /**
   * Representation of a field by its name and its type.
   */
  case class Field(name: String, tipe: String)

  /**
   * Traverse the elements on the RHS of a rule to collect fields.
   * The names of the fields are uniqued in the process.
   */
  def fieldsOfAlternative(alt: Alternative): List[Field] = {

    /**
     * List of fields in the process of being built.
     */
    val fields = ListBuffer[Field]()

    /**
     * Add a field for the given element if it's not Void.
     */
    def addField(elem: Element) {
      if (elem -> elemtype != "Void") {
        val fieldNum = fields.length + 1
        val fieldType = (alt -> fieldTypes).getOrElse(fieldNum, elem -> elemtype)
        fields.append(Field(elem -> fieldName, fieldType))
      }
    }

    def traverseElem(elem: Element) {
      elem match {
        case Block(name, _) =>
          fields.append(Field(elem -> fieldName, "String"))
        case _: NonTerminal =>
          addField(elem)
        case Opt(innerElem) =>
          val optElem =
            if (flags.useScalaOptions)
              elem
            else
              innerElem
          addField(optElem)
        case Nest(nestedElem, _) =>
          addField(nestedElem)
        case _: Rep =>
          addField(elem)
        case Seqn(l, r) =>
          traverseElem(l)
          traverseElem(r)
        case _ =>
        // No argument for the rest of the element kinds
      }
    }

    // Traverse RHS gathering fields
    alt.rhs.map(traverseElem)

    // Set of non-unique field names
    val nonUniqueFieldNames =
      fields.map(_.name).groupBy(s => s).collect {
        case (n, l) if l.length > 1 =>
          n
      }.toSet

    /**
     * Is the field name not unique in this field list?
     */
    def isNotUnique(fieldName: String): Boolean =
      nonUniqueFieldNames contains fieldName

    /**
     * Make the field names unique by numbering fields whose names are
     * not unique.
     */
    val uniqueFields =
      fields.result.foldLeft(Map[String, Int](), List[Field]()) {
        case ((m, l), f @ Field(n, t)) =>
          if (isNotUnique(n)) {
            val i = m.getOrElse(n, 0) + 1
            (m.updated(n, i), Field(n + i.toString, t) :: l)
          } else
            (m, f :: l)
      }

    uniqueFields._2.reverse

  }

  /**
   * List of fields for a RHS of an alternative in the order of their
   * appearance in the RHS. The field names have been made unique.
   */
  lazy val fields: Alternative => List[Field] =
    attr {
      case alt =>
        fieldsOfAlternative(alt)
    }

  /**
   * Collected information about an alternative: its order (unary=1,
   * binary=2), operator, precedence, fixity and non-terminals. If we can't
   * tell or it's a case we don't support, return None.
   */
  lazy val orderOpPrecFixityNonterm: Alternative => Option[(Int, String, Int, Fixity, String, String)] =
    attr {
      case alt =>
        val lhsnt = alt -> astrule -> lhs
        alt.rhs match {

          case List(elem @ NonTermIdn(nt), Literal(op)) if nt == lhsnt =>
            Some((1, op, alt -> precedence, Postfix, elem -> fieldName, ""))

          case List(Literal(op), elem @ NonTermIdn(nt)) if nt == lhsnt =>
            Some((1, op, alt -> precedence, Prefix, elem -> fieldName, ""))

          case List(elem1 @ NonTermIdn(nt1), Literal(op), elem2 @ NonTermIdn(nt2)) if (nt1 == lhsnt) && (nt2 == lhsnt) =>
            val fixity = Infix(alt -> associativity)
            Some((2, op, alt -> precedence, fixity, elem1 -> fieldName, elem2 -> fieldName))

          case elems =>
            None

        }
    }

  /**
   * Collected information about an alternative: currently its precedence
   * and fixity.
   */
  lazy val precFixity: Alternative => (Int, Fixity) =
    attr {
      case alt =>
        val lhsnt = alt -> astrule -> lhs
        alt.rhs match {

          // Postfix
          case List(elem @ NonTermIdn(nt), Literal(op)) if nt == lhsnt =>
            (alt -> precedence, Postfix)

          // Prefix
          case List(Literal(op), elem @ NonTermIdn(nt)) if nt == lhsnt =>
            (alt -> precedence, Prefix)

          // Infix
          case elems =>
            (alt -> precedence, Infix(alt -> associativity))

        }
    }

}
