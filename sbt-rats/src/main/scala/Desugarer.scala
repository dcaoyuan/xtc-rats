/*
 * This file is part of the sbt-rats plugin.
 * Copyright (c) 2012-2015 Anthony M Sloane, Macquarie University.
 * All rights reserved.
 * Distributed under the New BSD license.
 * See file LICENSE at top of distribution.
 */

/**
 * Desugarer from syntax definition to simplified form, parameterised by
 * the analyser to use.
 */
class Desugarer(analyser: Analyser) {

  import analyser.{
    actionTypeName,
    associativity,
    constr,
    elemtype,
    idntype,
    isLeftRecursive,
    isRightRecursive,
    isTransferAlt,
    lhs,
    pairTypeName,
    precedence,
    typeName
  }
  import ast._
  import org.kiama.attribution.Attribution.{ initTree, resetMemo }
  import org.kiama.attribution.AttributableSupport.deepclone
  import org.kiama.output.{ LeftAssoc, NonAssoc, RightAssoc }
  import org.kiama.rewriting.Rewriter.{
    alltd,
    everywheretd,
    rewrite,
    rule
  }
  import org.kiama.util.Positions
  import scala.collection.mutable.ListBuffer

  /**
   * Desugar the directly left recursive rules.
   */
  def desugar(grammar: Grammar): Grammar = {

    resetMemo()
    initTree(grammar)
    val grammar1 = removeSeparatorConstructs(grammar)

    resetMemo()
    initTree(grammar1)
    val grammar2 = fixTransferAlts(grammar1)

    resetMemo()
    initTree(grammar2)
    removeLeftRecursion(grammar2)

  }

  /**
   * Look for seperator constructs `x ** y` and `x ++ y` (represented by
   * `RepSep` nodes) and replace with auxiliary rules which build the
   * list value. The following translations are made:
   *   `x ++ y` turns into `nt = x y nt | x.`
   *   `x ** y` turns into `nt = nt1 / .` and nt1 defined as in `++` case
   * where `nt` and `nt1` are fresh non-terminals.
   */
  def removeSeparatorConstructs(grammar: Grammar): Grammar = {

    val newRules = new ListBuffer[ASTRule]

    def makeSeparatorRule(rep: Rep): NonTerminal = {

      val Rep(zero, elem, sep) = rep

      // The entry point non-terminal
      val ntpos = Positions.getStart(elem)
      val nt = s"sep${ntpos.line}x${ntpos.column}"

      // The auxiliary non-terminal (if needed)
      val nt1 = s"${nt}Aux"

      // The element type of the list
      val eltype = elem -> elemtype

      // The type of the list
      val listtype = elem -> pairTypeName

      // If we are doing a zero repetition one, generate the optional rule
      if (zero) {

        // alt: nt1
        val alt1 = Alternative(List(NonTerminal(NTGen(nt1, listtype))),
          Nil,
          NoAction())

        // alt: empty
        val alt2 = Alternative(List(), Nil, NilAction())

        // Add the rule
        val alts = List(alt1, alt2)
        val newRule = ASTRule(IdnDef(nt), IdnUse(listtype), alts)
        newRules.append(newRule)

      }

      // Get the appropriate RHS non-terminal for this rule
      val nt2 = if (zero) nt1 else nt

      // alt: elem sep nt
      val alt1 = Alternative(List(elem, sep, NonTerminal(NTGen(nt2, listtype))),
        Nil,
        ConsAction(eltype))

      // alt: elem
      val alt2 = Alternative(List(deepclone(elem)),
        Nil,
        SingletonAction(eltype))

      // Add the rule
      val alts = List(alt1, alt2)
      val newRule = ASTRule(IdnDef(nt2), IdnUse(listtype), alts)
      newRules.append(newRule)

      // Return a reference to the new entry point nonterminal
      NonTerminal(NTGen(nt, listtype))

    }

    val removeSeparatorConstructsStrategy =
      everywheretd(
        rule[Element] {
          case elem @ Rep(_, _, Epsilon()) =>
            elem
          case rep: Rep =>
            makeSeparatorRule(rep)
        })

    // Rewrite to get a transformed grammar and some new rules to add to it
    val newg = rewrite(removeSeparatorConstructsStrategy)(grammar)

    grammar.copy(rules = newg.rules ++ newRules.result)

  }

  /**
   * Detect transfer rules. Find rules that just transfer a semantic
   * value from RHS to LHS and mark them as requiring no action.
   */
  def fixTransferAlts(grammar: Grammar): Grammar = {

    val fixTransferAltsStrategy =
      alltd(
        rule[Alternative] {
          case alt @ Alternative(rhs, anns, _) if alt -> isTransferAlt =>
            Alternative(rhs, anns, NoAction())
        })

    rewrite(fixTransferAltsStrategy)(grammar)

  }

  /**
   * Remove direct left recursive rules and replace with equivalent iterative
   * rules with supplementary action-based rules to construct the correct
   * semantic value.
   *
   * Example to illustrate the transformation that is performed:
   *
   * Exp Exp =
   *         Exp Op2 Id Exp   {C2, left, 2}
   *      /  Exp Op1 Exp      {C1, left, 1}
   *      /  Op3 Exp          {C4, 0}
   *      /  Foo              {C3}.
   *
   * becomes
   *
   * Exp Exp0 =
   *       Op3 Exp0 {C4}
   *     / Foo {C3}.
   *
   * Exp Exp1 ::= seed:Exp0 actions:Exp1Tail* {
   *     yyValue = apply (actions, seed)
   * };
   *
   * constant Action<Exp> Exp1Tail =
   *     Op1 v1:Exp {
   *         yyValue = new Action<Exp> () {
   *             public Exp run (Exp left) {
   *                 return new C1 (left, v1);
   *             }
   *         };
   *     };
   *
   * Exp Exp2 ::= seed:Exp1 actions:Exp2Tail* {
   *     yyValue = apply (actions, seed)
   * };
   *
   * constant Action<Exp> Exp2Tail =
   *     Op2 v1:Id v2:Exp1 {
   *         yyValue = new Action<Exp> () {
   *             public Exp run (Exp left) {
   *                 return new C2 (left, v1, v2);
   *             }
   *         };
   *     };
   *
   */
  def removeLeftRecursion(grammar: Grammar): Grammar = {

    val newRules = new ListBuffer[ASTRule]

    val removeLeftRecursionStrategy =
      alltd(
        rule[ASTRule] {
          case r: ASTRule =>
            // Rewrite r and save the new rules for adding in later
            val (newr, rules) = removeLeftRecursiveAlternatives(r)
            newRules.appendAll(rules)
            newr
        })

    // Rewrite to get a transformed grammar and some new rules to add to it
    val newg = rewrite(removeLeftRecursionStrategy)(grammar)

    grammar.copy(rules = newg.rules ++ newRules.result)

  }

  /**
   * Rewrite a single grammar rule to remove left recursion from it. Returns
   * the new version of the rule `r`, plus a list of new rules that are to
   * be added to the grammar.
   */
  def removeLeftRecursiveAlternatives(astRule: ASTRule): (ASTRule, Iterable[ASTRule]) = {

    // The type of the LHS non-terminal, is shared with new non-terminals
    val lhsnttype = (astRule.idndef) -> idntype

    /**
     * Return a strategy that replaces identifier uses of one name by
     * which is generated and of the given type.
     */
    def replaceIdns(name1: String, name2: String, tipe: String) =
      alltd(
        rule[NTUse] {
          case NTName(IdnUse(`name1`)) =>
            NTGen(name2, tipe)
        })
    /**
     * Make a name for a non-terminal to represent a particular precedence
     * level for this rule.
     * FIXME: still possibility of clashes with user names
     */
    def makePrecName(level: Int): String =
      "%sLevel%d".format(astRule -> lhs, level)

    /**
     * Make iterative rules from a set of alternatives at the same precedence
     * level.
     */
    def makeIterativeRules(prec: Int, alts: List[Alternative]): List[ASTRule] = {

      // Name of a non-terminal at this level
      val ntname = makePrecName(prec)

      // A non-terminal for this level
      def nt = NonTerminal(NTGen(ntname, lhsnttype))

      // Name for the non-terminal for the "previous" level. If we are at the
      // highest precedence level just recurse here.
      val prevntname = makePrecName(if (prec == 0) 0 else prec - 1)

      // A non-terminal for the previous level
      def prevnt = NonTerminal(NTGen(prevntname, lhsnttype))

      // Name for the non-terminal for the tail
      val tailntname = s"${ntname}Tail"

      // A non-terminal for the tail
      def tailnt = NonTerminal(NTGen(tailntname, lhsnttype))

      // Collect the alternatives together by associativity
      val assocAlts = alts.groupBy(associativity)

      // Convenience short-hands to alternatives for each associativity
      val leftAssocAlts = assocAlts.getOrElse(LeftAssoc, Nil)
      val noneAssocAlts = assocAlts.getOrElse(NonAssoc, Nil)
      val rightAssocAlts = assocAlts.getOrElse(RightAssoc, Nil)

      // Buffer of rules that we will return
      val rules = new ListBuffer[ASTRule]

      // The base rule for the non-terminal at this precedence level needs to:
      //  - seed the iteration if there are any left associative alternatives
      //  - define the recursion for any right associative alternatives
      // This buffer accumulates the alternatives.
      val baseAlts = new ListBuffer[Alternative]

      // The iteration seed rule has the the form: nt = prevnt tailnt*
      // We only need it if there are left associative alternatives
      if (leftAssocAlts.nonEmpty)
        baseAlts.append(Alternative(List(prevnt, Rep(true, tailnt, Epsilon())),
          Nil,
          ApplyAction()))

      // Strategy to replace old occurrences of the previous non-terminal
      // with the new generated one
      val renamer = replaceIdns(astRule.idndef.name, prevntname, lhsnttype)

      // Each right associative alternative turns into a single rule that defines
      // the recursive case to the next level
      val rightAlts =
        rightAssocAlts.map {
          case Alternative(rhs, anns, _) =>
            val newInitRHS = rewrite(renamer)(rhs.init)
            Alternative(newInitRHS :+ nt, anns, DefaultAction())
        }
      baseAlts.appendAll(rightAlts)

      // Each non-associative alternative turns into a single rule that defines
      // all recursive references to the next level
      val noneAlts =
        noneAssocAlts.map {
          case Alternative(rhs, anns, _) =>
            val newRHS = rewrite(renamer)(rhs)
            Alternative(newRHS, anns, DefaultAction())
        }
      baseAlts.appendAll(noneAlts)

      // If there are none/right recursive alternatives and no left recursive alternatives
      // we also need a fall-through alternative to get us to the next precedence level.
      // If there are left associative alternatives the seed rule takes care of this.
      if (leftAssocAlts.isEmpty && (noneAssocAlts.nonEmpty || rightAssocAlts.nonEmpty))
        baseAlts.append(Alternative(List(prevnt), Nil, NoAction()))

      // Define the base rule using the base alternatives
      rules.append(ASTRule(IdnDef(ntname), IdnUse(astRule -> typeName), baseAlts.result()))

      // Generate the tail rule if there are any left associative alternatives
      if (leftAssocAlts.nonEmpty) {

        // Each left associative alternative turns into an alternative of a rule
        // that defines the tail of the iteration. We ignore any old action.
        val tailAlts =
          leftAssocAlts.map {
            case alt @ Alternative(rhs, _, _) =>
              val newRHS = rewrite(renamer)(rhs.tail)
              Alternative(newRHS, Nil, TailAction(astRule -> typeName, alt -> constr))
          }

        // Define the tail rule
        rules.append(ASTRule(IdnDef(tailntname), IdnUse(astRule -> actionTypeName),
          tailAlts, true))

      }

      rules.result()

    }

    /**
     * Fix a right recursive zero-level alternative to recurse at the next level
     * or the same level, depending on whether it's right recursive or not.
     */
    def flattenRightRecursion(alt: Alternative): Alternative =
      if (alt -> isRightRecursive) {
        val rhslen = alt.rhs.length
        val recursiveLevel =
          if ((alt -> associativity == RightAssoc) || (alt -> precedence == 0))
            alt -> precedence
          else
            alt -> precedence - 1
        val recursivent = NonTerminal(NTGen(makePrecName(recursiveLevel), lhsnttype))
        val newrhs = alt.rhs.init :+ recursivent
        Alternative(newrhs, alt.anns, alt.action)
      } else
        alt

    /**
     * Handle non-left recursive alternatives.
     */
    def makeNonIterativeRule(prec: Int, alts: List[Alternative]): ASTRule = {
      val ntidn = IdnDef(makePrecName(prec))
      val recursivent = NonTerminal(NTGen(makePrecName(prec - 1), lhsnttype))
      val theseAlts = alts.map(flattenRightRecursion)
      val newAlts =
        if (prec == 0)
          theseAlts
        else {
          val fallThroughAlt = Alternative(List(recursivent), Nil, NoAction())
          theseAlts :+ fallThroughAlt
        }
      ASTRule(ntidn, IdnUse(astRule -> typeName), newAlts)
    }

    /**
     * Handle all of the alternatives at a particular precedence level. Return a
     * list of new rules for that level.
     */
    def handlePrecLevel(prec: Int, alts: List[Alternative]): List[ASTRule] = {
      val (leftRecursiveAlts, nonLeftRecursiveAlts) = alts.partition(isLeftRecursive)
      if (nonLeftRecursiveAlts.isEmpty)
        makeIterativeRules(prec, alts)
      else if (leftRecursiveAlts.isEmpty)
        List(makeNonIterativeRule(prec, alts))
      else
        sys.error(s"handlePrecLevel: mixed left recursive and non-recursive at precedence level $prec")
    }

    // Partition the alternatives into recursive ones and non-recursive ones
    val (leftRecursiveAlts, nonLeftRecursiveAlts) = astRule.alts.partition(isLeftRecursive)

    // If there are no recursive alternatives, don't change the rule
    if (leftRecursiveAlts.isEmpty) {

      (astRule, Nil)

    } else {

      // Calculate top precedence level
      // FIXME: avoid this extra pass over recursive alternatives
      val top = astRule.alts.foldLeft(0) {
        case (p, alt) => p.max(precedence(alt))
      }

      // The "topmost" (i.e. lowest precedence) non-terminal for this iteration
      val topnt = NonTerminal(NTGen(makePrecName(top), lhsnttype))

      // The head rule connects the original non-terminal to the precedence chain
      val headRule =
        ASTRule(astRule.idndef, IdnUse(astRule -> typeName),
          List(Alternative(List(topnt), null, NoAction())))

      // Group the alternatives by precedence
      val precMap = astRule.alts.groupBy(precedence)

      // Process each of the precedence levels separately
      val precRules = precMap.flatMap((handlePrecLevel _).tupled)

      (headRule, precRules)

    }

  }

}
