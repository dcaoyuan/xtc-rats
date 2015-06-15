# sbt-rats usage documentation

The `sbt-rats` plugin enables you to use the [Rats!](http://cs.nyu.edu/rgrimm/xtc/rats-intro.html) parser generator from within a project that is built by the Scala [simple build tool sbt](http://code.google.com/p/simple-build-tool).

The plugin can be used in one of two main modes:

 * You can specify a `.rats` file which will be translated using Rats!  into a parser implementation written in Java.

 * You can specify a `.syntax` file which will be translated into a Rats! specification to produce a parser, and optionally also into a Scala implementation of abstract syntax trees and a pretty printer for those trees.

The pretty-printers produced by the plugin and a few other convenience features are designed to work with the [Kiama language processing library](http://kiama.googlecode.com).

The rest of this page describes how to install, configure and use the `sbt-rats` plugin.

We do not describe full details of using sbt, Rats! or Kiama. Please consult their respective documentation. In particular, a description of the Rats! specification notation can be found in the [Rats! introduction](http://cs.nyu.edu/rgrimm/xtc/rats-intro.html).

The plugin has most recently been tested with Scala 2.10.5, sbt 0.13.8, Rats! from xtc 2.4.0 and Kiama 1.8.0/2.0.0-SNAPSHOT, but may work with other versions.

## Instantiating the plugin

To use the plugin in a project, add a line like the following to your `project/plugins.sbt` file, selecting the version of the plugin you want to use.

    addSbtPlugin ("com.googlecode.sbt-rats" % "sbt-rats" % "2.2.0-SNAPSHOT")

In versions of sbt before 0.12.0, you will also have to add the resolver for the sbt community ivy repository. Add these lines or equivalent to the start of your `project/plugins.sbt` file.

    resolvers += Resolver.url ("scalasbt",
        new URL ("http://scalasbt.artifactoryonline.com/scalasbt/sbt-plugin-releases")
    ) (Resolver.ivyStylePatterns)

If you want to generate pretty-printers or integrate in other ways with Kiama, you will need the Kiama library, so add a dependency on it to your build. E.g., add the following to your `build.sbt`:

    libraryDependencies ++=
        Seq (
            "com.googlecode.kiama" %% "kiama" % "1.8.0"
        )

Finally, add the plugin settings to your `build.sbt`:

    sbtRatsSettings

We will describe the actual settings where relevant below.

## Plugin output

If you want to inspect the files that the plugin generates which will be included in your build, you will find them in the following directory in your project.

    target/scala-<version>/src_managed/main/sbt-rats/

The plugin also generates some intermediate files that are not included in
your build. They can be found here:

    target/sbt-rats/

## Defining the plugin input

The plugin uses a single starting point in each of its two modes. In the Rats! mode, the starting point is a single `.rats` file. In the syntax mode it is a `.syntax` file. In Rats! modes, the `ratsMainModule` setting should be set to the relevant file for your project. For example,

    ratsMainModule ::= Some (scalaSource.value / "some" / "dir" / "Parser.rats")

If the main module is a `.rats` file it should contain a normal Rats! main module. It can use other Rats! modules in the usual way. They do not have to be named in the build configuration.

If the main module is a `.syntax` file the `ratsMainModule` setting should not be set. The plugin will then pick up all syntax files automatically. These files should contain a syntax description as documented below.

The steps that translate the main module or other files into implementations are setup to run before the project is compiled. They will be automatically re-run the next time you compile, if any of the `.rats` or `.syntax` files in your project have changed since the last compile step.

## The generated parser

In both modes the end result will include a Rats!-generated parser. For example, suppose that your Rats! module is `foo.bar.Parser`. The plugin will produce the parser implementation in `Parser.java`.

The parser can be used in the usual way for Rats!-generated parsers. For example, if `reader` is a `java.io.Reader` that provides the input characters and `filename` is the name of the corresponding file, you can create a parser as follows.

    val p = new Parser (reader, filename)

If we assume the grammar contains a non-terminal symbol called `Program` then we can run the parser from input position zero as follows.

    val pr = p.pProgram (0)

The result value `pr` can be examined to see what happened. Assuming that the specification constructs an abstract syntax tree of type `Program`. If `pr.hasValue`is true then we can get the tree using

    p.value (pr).asInstanceOf[Program])

If `pr.hasValue` is false, then the following expression gives a nicely formatted error message about what went wrong.

    p.format (pr.parseError)

A typical error message is:

    /foo/bar/test/input.java:5:11: error: ';' expected
        v = 1 2 * 3;
              ^

## Debugging a generated parser

The plugin provides the `ratsVerboseOutput` build option which turns on debugging output in the generated parser. The output will contain information about parses that are being attempted, where in the input the attempt is being made, and the result of the attempt.

## Modifying the parser for use with Scala

By default, Rats! will use its own data structures to represent constructs such as optional elements, lists of elements and input positions. Using these data structures is fine from Scala, but often it is better to use more idiomatic Scala versions.

The plugin can post-process the generated parser to make it more usable from Scala. Three plugin settings control this behaviour.

 * `ratsUsesScalaLists`: use normal Scala lists instead of Rats!' pair-based lists to represent values that arise from repeated constructs (EBNF star and plus operators).

 * `ratsUseScalaOptions`: use Scala `Option` values instead of normal values and `null` to represent optional constructs (EBNF question mark operator).

 * `ratsUseScalaPositions`: use Scala library positions to represent input positions of semantic values instead of Rats!' locations. Specifically, if this option is set and the Rats! specification contains the `withLocation` option, any semantic value that is an instance of the Scala library type `scala.util.parsing.input.Positional` will have its position set. If the `ratsUseKiama` option is also set, Kiama's `org.kiama.util.Positions` module is used instead. The main difference is that `Positions` supports both start and finish positions.

All of these settings are false by default. To override the default, add to your `build.sbt`.  For example, to turn on Scala lists:

    ratsUseScalaLists := true

## Syntax mode

Writing a Rats! specification is certainly possible and it can be used with Scala code very easily. However, the Rats! notations are somewhat verbose so more has to be written than we might like. Also, Rats! has some limitations which we might like to improve on. For these reasons, the plugin also supports a custom syntax specification language from which Rats! specifications can be automatically generated.

The syntax specification you want to use should be placed in a `.syntax` file and the `ratsMainModule` setting set as described above. The current version of the plugin does not support splitting syntax specifications over multiple files.

A syntax specification starts with a module declaration which is used to determine the module for the Rats! specification and, ultimately, the Java parser. For example,

    module foo.bar.Parser;

After the module declaration an optional header section can appear. This section has the same syntax and meaning as the header construct in a Rats! specification. Its contents will be inserted into the generated parser at the top-level. For example, it is typically used to import classes that are needed to construct semantic  values.

    header {
        import foo.bar.Syntax.*;
    }

After the header section is an optional body section. This section has the same syntax and meaning as the body construct in a Rats! specification. Its contents will be insserted into the generated parser inside the parser class.

    body {
        // Code goes here...
    }

After the body section some Rats! options can be optionally specified. At the moment the only supported Rats! options are `setofString` and `verbose`.

    option setOfString (MyStrings), verbose;

The rest of a syntax specification consists of rules whose form is described in the following.

## String rules

A _string rule_ defines the form of a structure whose semantic value is a string. Typically, these rules are used to define the lexical structure  of a language, such as operators, keywords, identifiers, numbers and layout (whitespace and comments). A string rule has the form:

    <name> : String = alternative1 | ... | alternativeN.

Instead of `String`, the type can be given as `Void`, in which case the structure is parsed as usual but the value is discarded.

The structure of the construct referred to by _name_ must be defined completely by a single rule.

The alternatives are specified using the following expression forms. Note that these operators should be interpreted as those from parsing expression grammars, not context-free grammars. The main difference is that the vertical bar above and the slash below are _ordered_ in that the choices are tried in the order written. See the Rats! documentation for more detail.

    name    identifier        match whatever <name> is defined to be

    _       wildcard          match any single character

    'foo'   literal           match exactly "foo"
    "foo"   literal           match exactly "foo"

    [cs]    character class   match any single character defined by cs

    e*      repetition        match e zero or more times
    e+      repetition        match e one or more times
    e?      optionality       match e at most once

    e ** f  separation        e zero or more times separated by f
    e ++ f  separation        e one or more times separated by f

    e1 / e2  choice           match e1 or if e1 doesn't match, match e2

    e1 e2   sequence          match e1 followed by match e2

    !e      negation          match iff e doesn't match

    (e)     bracketing        match e

Literals can contain escape characters as defined by Rats!.

The two versions of alternation (vertical bar and slash) are equivalent in string rules.

As a concrete example,

    IntegerLiteral : String =
        IntegerLiteralForm Spacing.

    IntegerLiteralForm : String =
        DecimalNumeral.

    DecimalNumeral : String =
        '0'
      | NonZeroDigit Digits.

    Digits : String =
        Digit*.

    NonZeroDigit : String =
        [1-9].

    Digit : String =
        [0-9].

The first two rules above can be simplified somewhat because a special `Token` type is supported to deal with this common case of a string-value structure followed by spacing. The following rule is equivalent to the first two rules above.

    IntegerLiteral : Token =
        DecimalNumeral.

Here is a definition of layout (whitespace and comments) using this notation. Even though they are conceptually String-valued, all of these non-terminals are void since normally we don't plan to use the strings that they match.

    Spacing   : Void = (Space / Comment)*.
    Space     : Void = ' ' / '\t' / '\f' / EOL.
    EOL       : Void = '\r' '\n' / '\r' / '\n'.
    EOF       : Void = !_.
    Comment   : Void = SLComment / MLComment.
    SLComment : Void = "//" (!EOL _)* (EOL / EOF).
    MLComment : Void = "/*" (MLComment / !"*/" _)* "*/".

Note that the multi-line comment (`MLComment`) is recursive. Thus, this definition defines properly nested comments.

## Abstract syntax tree rules

The other main kind of rule in a syntax specification is an _abstract syntax tree rule_. In contrast to string rules which focus on lexical structure, abstract syntax tree rules are intended to express syntactic structure. The values of abstract syntax tree rules will in general be nodes of an abstract syntax tree structure that is being built by the parser.

Since abstract syntax tree rules correspond to tree constructs, their form is restricted. Specifically, the right-hand side of an abstract syntax tree rule can only contain identifiers, repetition, optionality, sequencing and negation. Repetition and optionality constructs can only contain single identifiers. These restrictions are in place to ensure that the plugin can determine the corresponding tree structure automatically.

For example, here is the definition of simple imperative language statements.

    Stm =
        Tipe Loc ';'                        {Decl}
      | ';'                                 {EmptyStm}
      | Assign ';'                          {AsgnStm}
      | Lab ':' Stm                         {LabStm}
      | "break" Lab ';'                     {Break}
      | "continue" Lab ';'                  {Continue}
      | "if" '(' Exp ')' Stm 'else' Stm     {If}
      | "while" '(' Exp ')' Stm             {While}
      | '{' Stm*  '}'                       {Block}.

By default, the name of the type of an abstract syntax tree rule is the same as its left-hand side non-terminal symbol, `Stm` in the example above. Since there are many alternatives, `Stm` will be an abstract class with one concrete sub-class for each form that it can take.

The annotations at the right-hand side name the classes that you want to use to represent input that matches each of the alternatives. E.g., `Decl` will be assumed to be a concrete sub-class of `Stm` that you want to use to  represent declarations.

The types of the constructors are inferred from the forms of the alternatives. For example, in the `Decl` case there will be two constructor arguments, the first of type `Tipe` and the second of type `Loc`.

In some cases, you will want to implement the tree classes yourself, but it is usually easier for them to be generated from the specification (see below).

In some cases, a rule only has one alternative.

    Program = Stm.

When this happens, the plugin will assume that the concrete class to be used for this construct is the left-hand side non-terminal name and no annotation needs to be given. Also, no abstract class would be used in this case, since there is only one choice.

By the way, defining your top-level non-terminal in this way is not ideal, since it doesn't take into account spacing that occurs at the beginning of the input, nor does it require that there is no extra input after a program has been parsed. A better way to define it is as follows:

    Program = Spacing Stm EOF.

It is also possible to give the type of a rule explicitly.

    Exp =
        ...
      | Assign
      | ...

    Assign : Exp =
        Loc "=" Exp.

Here, we have the `Exp` rule defined separately from one of its alternatives. A separate definition is necessary since the `Assign` alternative is also used in the definition of `Stm` above.

However, we still want an assignment statement to be an expression so we give an explicit type by saying `: Exp` after the `Assign` non-terminal on the left-hand side of the rule. The concrete class will be inferred to be `Assign` which will be made to extend `Exp`.

## Turning off spacing in abstract syntax tree rules

By default, abstract syntax tree rules allow whitespace or comments after literal symbols. Sometimes you don't want this because the whitespace is significant in the structure.

You can turn off the automatic spacing behaviour for a single rule by adding the `nospacing` annotation. For example,

    Foo {nospacing} =
        "F" "o" "o".

will recognise exactly the characters 'F', 'o' and 'o' in that order with no intervening spacing allowed.

## Block non-terminals

Usually the structure of a non-terminal is defined completely by the alternatives for that non-terminal. Sometimes it is necessary to parse input whose form is defined by another part of the structure.

A common case is where the length of a block of input is defined by a value of some other part of the input. This situation arises when parsing many binary formats, so sbt-rats has special support for it.

Specifically, a non-terminal of the form `Name[n]` is not defined by productions for `Name`, but by the non-terminal `n` in the same alternative. Non-terminals are numbered in an alternative starting at one. The value of bytes that make up non-terminal `n` is interpreted as an integer and the `Name` component is parsed by reading exactly that many bytes. The `Name` component will be a string containing those bytes.

To illustrate this feature, consider parsing PNG files. (The full specification is given at the end of this page.) In this format, chunks of image data have a structure that specifies a four-byte length field, a four-byte header, a block whose length is given by the length field and a four-byte CRC field. The main structure of a chunk can be specified in a syntax definition as follows.

    Chunk = Length Type Data[1] CRC.

    Length : String =
        _ _ _ _.

Notice that the `Data` field references the `Length` field by number. Each chunk will parse a data field whose length is given by the bytes parsed for the length.

sbt-rats provides two utility routines which are used to implement block parsers. `parseBytes` actually does the parsing of the block. `strToInt` converts a string of bytes into an integer value. These routines will not be included by default; turn the
`ratsIncludeBinarySupport` setting on to get their implementations.

## Rats! sections

Sometimes it is necessary to escape from the syntax specification notation into Rats! notation. A Rats! section can be included anywhere after the header of a syntax specification and its contents will be copied into the generated Rats! specification at that point.

    rats {
        // your Rats! spec here...
    }

You can also use a Rats! section to define the right-hand side of a production. This usage should be used if you define a non-terminal that has to be visible to the rest of the syntax definition. For example, in the following production we use a Rats! predicate to restrict the case of a letter to be upper case.

    UpperCaseLetter : String =
        rats {
            c:_ &{
                Character.isUpperCase (c)
            }
        }.

## Left Recursion

The form of parsing used by Rats! does not work if left recursion is present in any rule.  Rats! has some support for transforming the grammar to remove direct left recursion, but it only works for cases where generic abstract syntax trees are being built. In many cases it is better to use typed trees, so the plugin provides some support for elimination of left recursion.

Suppose that you have a rule where the left-hand side non-terminal occurs as the first element of the right-hand side, like these typical ones for expressions.

    Exp =
      | Exp "+" Exp                         {Add, left, 2}
      | Exp "*" Exp                         {Mul, left, 1}
      | Number                              {Num}
      | '(' Exp ')'.

The plugin transforms these rules into equivalent iterative forms, somewhat simplified as:

    Exp  = Exp2.
    Exp2 = Exp1 ("+" Exp1)*.
    Exp1 = Exp0 ("*" Exp0)*.
    Exp0 = Number
         | "(" Exp ")".

The annotations on the original rules give the plugin information about how to do the translation. You can give the associativity (left, right or none; left is the default) and the precedence level (a number, lower number means higher precedence; 0 is the default). In the example the precedence level annotations tell the plugin that the multiplication binds tighter than the addition which leads to the different versions of `Exp`. Moreover, the plugin uses the annotations to make sure that the correct tree is constructed by the iterative rules.

The precedence annotations should define a sequence of levels from the highest precedence (level zero) to the lowest precedence level (two in the example above). It is an error to omit a level.

## Value conversion

Value conversion is often needed when crossing from string rules to abstract syntax tree rules. For example, suppose that we have used a string rule to define `IntegerLiteral` to be a non-empty sequence of digits. The value in this case will be a string of the digits.

However, we may want to store the numeric value of the literal in the tree. Thus, the concrete sub-class of expression we will use, say `IntLit` will take an integer argument. We need some way to convert the string of digits into an integer.

To achieve conversions like this, you can add an annotation to the relevant rule to specify which conversion method to use for which arguments. The general form of the annotation is

    n: m : t

where `n` is a number, `m` is a qualified method name and `t` is a type name.

For example, we might have the following rule in our example.

    Exp =
        ...
        IntegerLiteral                      {IntLit, 1: Integer.parseInt : Int}
        ...

The annotation means that the string from the first non-terminal on the right-hand side (`IntegerLiteral`) will be passed to `Integer.parseInt` to produce an `Int` value. The `Int` will then be passed to the constructor of the `IntLit` concrete class.

This notation is somewhat cumbersome but it is rarely used and has the advantage that any method whatsoever can be called.

## Default lexical definitions

The lexical structure of a language, including layout (spacing and comments), can be specified as seen above using string rules. However, in many projects we  don't really care about the exact definition since the interesting questions are elsewhere.

For this reason, by default the plugin uses default definitions for some lexical aspects. The use of the defaults is controlled by the following settings, which are all true by default.

 * `ratsUseDefaultLayout`: use the definition of `Spacing` shown earlier to define the space between lexical symbols. Note that you will still need to use `Spacing` in various places to get the desired effect.  For example, if you define a new lexical symbol form, you should follow it with `Spacing` so that layout is allowed after an instance of that form. Turn this setting off if you want to define your own `Spacing`.

 * `ratsUseDefaultComments`: use the definition of `Comment` shown earlier to define the form of comments which are part of the `Spacing`. In essence, these are the C language family comments in both single line and multiple line versions, with arbitrary nesting of multiple line comments. Note that if you turn this setting off, you will need to define `Comment` yourself if you use the default layout.

 * `ratsUseDefaultWords`: use a default definition for the form of word-like lexical symbols (i.e., identifiers and keywords).

More explanation is needed for the last case because we have not seen an example earlier. We follow a standard Rats! technique for defining lexical symbols that consist of letters.  The default word definition consists of two main non-terminals: `Identifier` and `Word`. The idea is that `Word` captures a sequence of letters followed by layout. An identifier is then a word that is not a keyword. The current definition of a keyword is any literal that includes only letters and underscores.

The default definition that the plugin uses is as follows (in Rats! notation):

    String Identifier =
        Word &{
            ! contains (KEYWORDS, yyValue)
        };

    String Word =
        WordCharacters Spacing;

    transient String WordCharacters =
        h:_ &{
            Character.isJavaIdentifierStart (h)
        } (t:_ &{
            Character.isJavaIdentifierPart (t)
        })*;

In essence, this definition defines a word to be a sequence of one or more word characters followed by `Spacing`. The first letter in the sequence must be allowed to start a Java identifier and the rest must be allowed to be part of one. Thus, the default word structure is that of Java identifiers.

The default definition also uses a Rats! semantic predicate in the `Identifier` rule to ensure that a word cannot have the same form as a keyword. This check is implemented by looking for the character sequence in a keyword table. The table is automatically generated by the plugin to contain every string literal from the specification that is formed from only letters.

Thus, if you are happy with your identifiers being Java identifiers and don't want to allow them to be keywords, you can just use the default `Identifier` non-terminal. Otherwise, turn the `ratsUseDefaultWords` setting off and you can do what you like. The `KEYWORDS` table will be generated regardless, so you can use it in your own definition.

The setting `ratsIncludeKeywordTable` is on by default, but can be turned off to omit the definition of the keyword table.

## Generation of abstract syntax tree classes

As discussed earlier, it is common for the aim of parsing to be to construct an abstract syntax tree that represents the structure of the input text. It is fine to define the classes that form the abstract syntax tree by hand, but, in syntax mode, the plugin can also assist by defining them automatically.

The setting to control this behaviour is `ratsDefineASTClasses` which is off by default. When it is turned on, the plugin will generate a file called `Syntax.scala` in the same package as the parser. The file will contain a single object (module) called `Syntax` containing definitions of the syntax tree classes.

As discussed earlier, the syntax tree types will be a combination of abstract and concrete classes depending on the structure of the abstract syntax tree rules. The concrete classes will be defined as case classes to make their use convenient for pattern matching in later processing phases.

For example, consider the statement grammar that we saw earlier. The following classes will be defined for that grammar.

    abstract class ASTNode

    sealed abstract class Stm extends ASTNode
    case class Decl (tipe : Tipe, loc : Loc) extends Stm
    case class EmptyStm () extends Stm
    case class AsgnStm (assign : Exp) extends Stm
    case class LabStm (lab : String, stm : Stm) extends Stm
    case class Break (lab : String) extends Stm
    case class Continue (lab : String) extends Stm
    case class If (exp : Exp, stm1 : Stm, stm2 : Stm) extends Stm
    case class While (exp : Exp, stm : Stm) extends Stm
    case class Block (optStms : List[Stm]) extends Stm

A single super-class `ASTNode` is defined for all tree node classes, since it is sometimes convenient to refer the type of all nodes.

The names of the case class fields are derived from the types of the fields as follows. The base field name is the type name in lowercase. If the field is optional, its name has an 'opt' prefix (not shown in the example). If the field is a repetition, its name has an 's' on the end, and 'opt' on the beginning if the repetition can be empty (e.g., `optStms` in the `Block` class). Once the field names are determined to this level, integers are appended to make them unique within a class (e.g., `stm1` and `stm2` in the `If` class).

Note that this approach to naming has a flaw in that it is possible to generate a field name that clashes with a Scala keyword. E.g., if the  `Tipe` field were `Type` instead, we would get a field called `type` and the definition would not compile. The plugin will detect these cases and append an extra "Field" to the field name to avoid the problem. It is usually best to avoid the problem by using a different name, as we have done in the example.

If the `ratsUseScalaPositions` setting is on, the `ASTNode` class will be made to extend the `scala.util.parsing.input.Positional` type. Therefore, all nodes will get positions automatically.

Here is a typical program fragment and the corresponding tree fragment.

    if (v)
       v = 0;
    else
        v = 1;
    while (v) {
        boolean b;
        b = true;
    }

    If (
        Use (Loc ("v")),
        AsgnStm (Assign (Loc ("v"), IntLit (0))),
        AsgnStm (Assign (Loc ("v"), IntLit (1)))),
    While (
        Use (Loc ("v")),
        Block (
            List (
                Decl (BooleanType (), Loc ("b")),
                AsgnStm (Assign (Loc ("b"), True ())))))

The tree fragment was printed using Kiama's default pretty-printer.

## Kiama support

The plugin supports has some extra features to support use of the generated code with the [Kiama library](https://code.google.com/p/kiama/). These features are enabled by the `ratsUseKiama` setting, which by default is zero which means that the Kiama support is disabled. Setting `ratsUseKiama` to a non-zero number means that that major version of Kiama is to be targeted. The only supported values are one and two.

If `ratsDefineASTClasses` is true and `ratsUseKiama` is one, the generated `ASTNode` class is made to extend the class `org.kiama.attribution.Attributable` which provides useful assistance for writing attribute grammar rules that operate on the tree. if version two of Kiama is being used the `Attributable` class is no longer required.

`ratsUseKiama` can also be used to set Kiama positions of tree nodes. See the documentation of the `ratsUseScalaPositions` setting for details.

## Generation of a pretty printer

It is common to want to print abstract syntax trees, for debugging or code generation. The `ratsDefinePrettyPrinter` setting, usually false, can be set to true to ask the plugin to generate a pretty printer. Since the pretty printer is closely related to the tree structure, you also need to have `ratsDefineASTClasses` set to true.

The generated pretty printer uses Kiama's pretty-printing facility which we will not describe in detail here.

The pretty printer is generated as both a trait and an object called `PrettyPrinter` in the same package as the parser. The plugin generates both so that the default implementation can be used via the object, but the behaviour could also be over-ridden by mixing in the trait to another class.

The interface to the pretty printer is the `format` method which takes an arbitrary tree node and returns its pretty-printed representation.

    def format (astNode : ASTNode, w : Width = defaultWidth) : String

The width parameter is used to specify the desired width of the output. `defaultWidth` is seventy-five.

The pretty printer has basic behaviour where literals are printed as themselves and fields of tree nodes that represent non-terminals are printed as themselves. Sequences print their elements in order. Optional constructs print as nothing if they are not present or as their contents if they are present.

A few conventions make common variations easy to achieve and formatting directives can be added to get more complex effects.

A literal that is specified using single quotes is printed as-is, whereas one that is  specified using double quotes is followed by a space. Therefore, it is usual to use double quotes for keywords and single quotes for punctuation such as parentheses and semicolons.

The following formatting directives can be added to control the printing in more detail:

 * `\n`: indicates a place where it is advantageous to place a newline break,

 * `sp`: indicates a place where an extra space should be added,

 * `nest (e)`: indicates a place where the grammar element `e` should be printed indented one level from its surroundings, and

 * `nestnl (e)`: as for `nest` and also indicate a newline break at the  beginning of the nested output.

The indentation for `nest` and `nestnl` is four spaces by default but it can be changed using the `defaultIndent` option. For example, to change the default indentation to two spaces, specify the following option:

    option defaultIndent (2);

Similarly, the default width for pretty-printing is seventy-five but it can be changed using the `defaultWidth` option.

    option defaultWidth (50);

A common situation arises when you want to place all instances of a construct on separate lines (unless they fit together). To specify this behaviour you can add a `line` annotation to the relevant rule. It is equivalent to placing a `\n` at the beginning of each alternative in the rule.

For example, directives can be used with our statement grammar to get an effect where each statement begins on a newline and blocks are nested.

    Stm {line} =
        Type Loc ';'                                             {Decl}
      | ';'                                                      {EmptyStm}
      | Assign ';'                                               {AsgnStm}
      | Lab ':' Stm                                              {LabStm}
      | "break" Lab ';'                                          {Break}
      | "continue" Lab ';'                                       {Continue}
      | "if" '(' Exp ')' nest (Stm) \n 'else' nest (Stm)         {If}
      | "while" '(' Exp ')' Stm                                  {While}
      | '{' nest (Stm*) \n '}'                                   {Block}.

A typical pretty-print using this specification is as follows.

    {
        int v;
        v = true;
        v = 1 | 2;
        v = (1 + 2) * 3;
        v = 1 + 2 * 3;
        if (v)
            v = 0;
        else
            v = 1;
        while (v)
        {
            boolean b;
            b = true;
        }
        v = 42;
    }

Since Kiama's pretty-printers are flexible with regard to line length, you can override the default output width to get a different effect. For example, with a width of 1000, we get this output:

     { int v; v = true; v = 1 | 2; v = (1 + 2) * 3; v = 1 + 2 * 3; if (v) ...

Thus, you can see that the `\n` directives are only suggestions of where to break lines, not requirements. In this wide setting each potential line break has turned into a space.

The specification of pretty-printing for expressions does not require much more than the syntax definition to get the effect shown above. In particular, note that in the third and fourth statements, the precedence and associativity of the operators has been taken into account when deciding whether to put in parentheses or not. The rule annotations described earlier to define precedence and associativity are also used here to invoke Kiama's capability for minimal parenthesised pretty printing.

To request parenthesised printing for a particular rule we need to add a `paren` annotation in the header of the rule. This is the only change necessary to the expression rule to get pretty-printing to work as shown above.

    Exp {paren} =
        ...

## Complete example syntax specification

To bring everything together, here is the complete example syntax specification.

    module javak.java.javai.JavaI;

    header {
        import javak.java.javai.JavaISyntax.*;
    }

    Program =
      Spacing Stm* EOF.

    Stm {line} =
        Type Loc ';'                                             {Decl}
      | ';'                                                      {EmptyStm}
      | Assign ';'                                               {AsgnStm}
      | Lab ':' Stm                                              {LabStm}
      | "break" Lab ';'                                          {Break}
      | "continue" Lab ';'                                       {Continue}
      | "if" '(' Exp ')' nest (Stm) \n 'else' nest (Stm)         {If}
      | "while" '(' Exp ')' Stm                                  {While}
      | '{' nest (Stm*) \n '}'                                   {Block}.

    Type =
        "boolean"                                                {BooleanType}
      | "byte"                                                   {ByteType}
      | "char"                                                   {CharType}
      | "double"                                                 {DoubleType}
      | "float"                                                  {FloatType}
      | "int"                                                    {IntType}
      | "long"                                                   {LongType}
      | "short"                                                  {ShortType}.

    Exp {paren} =
        Lit
      | Loc                                                      {Use}
      | Exp "?" Exp ":" Exp                                      {Cond, right, 9}
      | Assign
      | Exp "|" Exp                                              {Or, none, 8}
      | Exp "^" Exp                                              {Xor, left, 7}
      | Exp "&" Exp                                              {And, left, 6}
      | Exp "==" Exp                                             {EQ, left, 5}
      | Exp "!=" Exp                                             {NE, left, 5}
      | Exp "<"  Exp                                             {LT, left, 4}
      | Exp "<=" Exp                                             {LE, left, 4}
      | Exp ">"  Exp                                             {GT, left, 4}
      | Exp ">=" Exp                                             {GE, left, 4}
      | Exp "<<" Exp                                             {Lsh, left, 3}
      | Exp ">>" Exp                                             {ARsh, left, 3}
      | Exp ">>>" Exp                                            {URsh, left, 3}
      | Exp "+" Exp                                              {Add, left, 2}
      | Exp "-" Exp                                              {Sub, left, 2}
      | Exp "*" Exp                                              {Mul, left, 1}
      | Exp "/" Exp                                              {Div, left, 1}
      | Exp "%" Exp                                              {Rem, left, 1}
      | '+' Exp                                                  {UnAdd}
      | '-' Exp                                                  {Neg}
      | '~' Exp                                                  {BitNot}
      | '!' Exp                                                  {Not}
      | '(' Type ')' Exp                                         {Cast}
      | '(' Exp ')'.

    Assign : Exp =
        Loc sp "=" Exp.

    Lit : Exp =
        IntegerLiteral               {IntLit, 1: Integer.parseInt : Int}
      | BooleanLiteral.

    IntegerLiteral : Token =
        DecimalNumeral.

    DecimalNumeral : String =
        '0'
      | NonZeroDigit Digits.

    Digits : String =
        Digit*.

    NonZeroDigit : String =
        [1-9].

    Digit : String =
        [0-9].

    BooleanLiteral : Exp =
        'false'                                                  {False}
      | 'true'                                                   {True}.

    Loc =
        Identifier.

    Lab : String =
        Identifier.

## PNG syntax specification

As another complete example, the following syntax definition can be used to generate a parser for PNG files. The most interesting parts of the definition are the use of a block non-terminal to handle variable length chunks and the use of Rats! sections to provide access to Rats! predicate syntax.

    module png.PNGParser;

    header {
        import png.PNGParserSyntax.*;
    }

    PNGFile =
        Header Body.

    Header : String =
        '\u0089' 'P' 'N' 'G' '\r' '\n' '\u001a' '\n'.

    Body =
        Chunk+.

    Chunk = Length Type Data[1] CRC {1: strToInt : Int,
                                     4: strToInt : Int}.

    Length : String =
        _ _ _ _.

    Type =
        Criticality Visibility Reserved Copyability.

    Criticality =
          UpperCaseLetter {Critical}
        | LowerCaseLetter {Ancillary}.

    Visibility =
          UpperCaseLetter {Public}
        | LowerCaseLetter {Private}.

    Reserved =
          UpperCaseLetter {InSpec}
        | LowerCaseLetter {NotInSpec}.

    Copyability =
          UpperCaseLetter {CopyableIfCriticalChunksUnchanged}
        | LowerCaseLetter {Copyable}.

    CRC : String =
        _ _ _ _.

    UpperCaseLetter : String =
        rats {
            c:_ &{
                Character.isUpperCase (c)
            }
        }.

    LowerCaseLetter : String =
        rats {
            c:_ &{
                Character.isLowerCase (c)
            }
        }.
