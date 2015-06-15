/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2009-2012 New York University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */
package xtc.lang.cpp;

import xtc.lang.cpp.ForkMergeParser.Subparser;
import xtc.tree.GNode;
import xtc.util.Pair;
/**
 * This class is generated from grammar annotations and provides semantic
 * value and action support.
 */
public class CSemanticValues implements SemanticValues {
  private static CSemanticValues ref;

  public static CSemanticValues getInstance() {
    if (ref == null)
        ref = new CSemanticValues();
    return ref;
  }

  public Object getValue(int id, String name, Pair<Object> values) {
    Object value;

    if (values == Pair.<Object>empty()) {
      value = null;

    } else {
      value = GNode.createFromPair(name, values.head(), values.tail());
    }

    return value;
  }
  public ValueType getValueType(int id) {
    if (0 <= id && id < 7) {
      return ValueType.NODE;
    }
    switch (id - 7) {
      case 123: // ExternalDeclarationList (130)
        // Fall through
      case 140: // DeclarationQualifierList (147)
        // Fall through
      case 141: // TypeQualifierList (148)
        // Fall through
      case 168: // StructDeclarationList (175)
        // Fall through
      case 170: // StructDefaultDeclaringList (177)
        // Fall through
      case 171: // StructDeclaringList (178)
        // Fall through
      case 177: // EnumeratorList (184)
        // Fall through
      case 181: // ParameterList (188)
        // Fall through
      case 183: // IdentifierList (190)
        // Fall through
      case 191: // MatchedInitializerList (198)
        // Fall through
      case 193: // DesignatorList (200)
        // Fall through
      case 228: // LocalLabelDeclarationList (235)
        // Fall through
      case 230: // LocalLabelList (237)
        // Fall through
      case 231: // DeclarationOrStatementList (238)
        // Fall through
      case 233: // DeclarationList (240)
        // Fall through
      case 243: // StringLiteralList (250)
        // Fall through
      case 256: // ExpressionList (263)
        // Fall through
      case 283: // AttributeSpecifierList (290)
        // Fall through
      case 287: // AttributeList (294)
        // Fall through
      case 296: // Assemblyoperands (303)
        return ValueType.LIST;

      case 0: // BREAK (7)
        // Fall through
      case 10: // RETURN (17)
        // Fall through
      case 16: // CONTINUE (23)
        // Fall through
      case 21: // GOTO (28)
        // Fall through
      case 58: // LPAREN (65)
        // Fall through
      case 59: // RPAREN (66)
        // Fall through
      case 60: // COMMA (67)
        // Fall through
      case 63: // LBRACE (70)
        // Fall through
      case 64: // RBRACE (71)
        // Fall through
      case 65: // LBRACK (72)
        // Fall through
      case 66: // RBRACK (73)
        // Fall through
      case 67: // DOT (74)
        // Fall through
      case 80: // QUESTION (87)
        // Fall through
      case 81: // COLON (88)
        // Fall through
      case 82: // SEMICOLON (89)
        // Fall through
      case 83: // ASSIGN (90)
        return ValueType.LAYOUT;

      case 303: // BindIdentifier (310)
        // Fall through
      case 304: // BindIdentifierInList (311)
        // Fall through
      case 305: // BindVar (312)
        // Fall through
      case 306: // BindEnum (313)
        // Fall through
      case 307: // EnterScope (314)
        // Fall through
      case 308: // ExitScope (315)
        // Fall through
      case 309: // ExitReentrantScope (316)
        // Fall through
      case 310: // ReenterScope (317)
        // Fall through
      case 311: // KillReentrantScope (318)
        return ValueType.ACTION;

      case 122: // TranslationUnit (129)
        // Fall through
      case 124: // ExternalDeclaration (131)
        // Fall through
      case 126: // FunctionDefinitionExtension (133)
        // Fall through
      case 134: // DeclarationExtension (141)
        // Fall through
      case 138: // DeclarationSpecifier (145)
        // Fall through
      case 139: // TypeSpecifier (146)
        // Fall through
      case 149: // BasicTypeSpecifier (156)
        // Fall through
      case 161: // StorageClass (168)
        // Fall through
      case 162: // BasicTypeName (169)
        // Fall through
      case 165: // ElaboratedTypeName (172)
        // Fall through
      case 188: // DesignatedInitializer (195)
        // Fall through
      case 197: // Declarator (204)
        // Fall through
      case 198: // TypedefDeclarator (205)
        // Fall through
      case 199: // TypedefDeclaratorMain (206)
        // Fall through
      case 203: // ParenTypedefDeclarator (210)
        // Fall through
      case 206: // IdentifierDeclarator (213)
        // Fall through
      case 207: // IdentifierDeclaratorMain (214)
        // Fall through
      case 208: // UnaryIdentifierDeclarator (215)
        // Fall through
      case 209: // PostfixIdentifierDeclarator (216)
        // Fall through
      case 212: // PostfixingFunctionDeclarator (219)
        // Fall through
      case 214: // ParenIdentifierDeclarator (221)
        // Fall through
      case 219: // PostfixingAbstractDeclarator (226)
        // Fall through
      case 224: // Statement (231)
        // Fall through
      case 232: // DeclarationOrStatement (239)
        // Fall through
      case 237: // JumpStatement (244)
        // Fall through
      case 242: // Constant (249)
        // Fall through
      case 244: // PrimaryExpression (251)
        // Fall through
      case 248: // PostfixExpression (255)
        // Fall through
      case 257: // UnaryExpression (264)
        // Fall through
      case 265: // CastExpression (272)
        // Fall through
      case 266: // MultiplicativeExpression (273)
        // Fall through
      case 267: // AdditiveExpression (274)
        // Fall through
      case 268: // ShiftExpression (275)
        // Fall through
      case 269: // RelationalExpression (276)
        // Fall through
      case 270: // EqualityExpression (277)
        // Fall through
      case 271: // AndExpression (278)
        // Fall through
      case 272: // ExclusiveOrExpression (279)
        // Fall through
      case 273: // InclusiveOrExpression (280)
        // Fall through
      case 274: // LogicalAndExpression (281)
        // Fall through
      case 275: // LogicalORExpression (282)
        // Fall through
      case 276: // ConditionalExpression (283)
        // Fall through
      case 277: // AssignmentExpression (284)
        // Fall through
      case 279: // ExpressionOpt (286)
        // Fall through
      case 280: // Expression (287)
        // Fall through
      case 281: // ConstantExpression (288)
        return ValueType.PASS_THROUGH;

      default:
        return ValueType.NODE;
    }
  }
  public boolean isComplete(int id) {
    switch(id) {
    case 275: // ShiftExpression
      // Fall through
    case 274: // AdditiveExpression
      // Fall through
    case 273: // MultiplicativeExpression
      // Fall through
    case 272: // CastExpression
      // Fall through
    case 279: // ExclusiveOrExpression
      // Fall through
    case 278: // AndExpression
      // Fall through
    case 277: // EqualityExpression
      // Fall through
    case 276: // RelationalExpression
      // Fall through
    case 283: // ConditionalExpression
      // Fall through
    case 282: // LogicalORExpression
      // Fall through
    case 281: // LogicalAndExpression
      // Fall through
    case 280: // InclusiveOrExpression
      // Fall through
    case 287: // Expression
      // Fall through
    case 286: // ExpressionOpt
      // Fall through
    case 285: // AssignmentOperator
      // Fall through
    case 284: // AssignmentExpression
      // Fall through
    case 258: // DirectSelection
      // Fall through
    case 259: // IndirectSelection
      // Fall through
    case 256: // Subscript
      // Fall through
    case 257: // FunctionCall
      // Fall through
    case 262: // CompoundLiteral
      // Fall through
    case 263: // ExpressionList
      // Fall through
    case 260: // Increment
      // Fall through
    case 261: // Decrement
      // Fall through
    case 266: // OffsetofExpression
      // Fall through
    case 267: // ExtensionExpression
      // Fall through
    case 264: // UnaryExpression
      // Fall through
    case 265: // TypeCompatibilityExpression
      // Fall through
    case 270: // LabelAddressExpression
      // Fall through
    case 268: // AlignofExpression
      // Fall through
    case 305: // AssemblyclobbersOpt
      // Fall through
    case 304: // Assemblyoperand
      // Fall through
    case 307: // AssemblyGotoargument
      // Fall through
    case 306: // Assemblyclobbers
      // Fall through
    case 308: // AssemblyJumpLabels
      // Fall through
    case 311: // BindIdentifierInList
      // Fall through
    case 310: // BindIdentifier
      // Fall through
    case 313: // BindEnum
      // Fall through
    case 312: // BindVar
      // Fall through
    case 315: // ExitScope
      // Fall through
    case 314: // EnterScope
      // Fall through
    case 317: // ReenterScope
      // Fall through
    case 316: // ExitReentrantScope
      // Fall through
    case 318: // KillReentrantScope
      // Fall through
    case 288: // ConstantExpression
      // Fall through
    case 289: // AttributeSpecifierListOpt
      // Fall through
    case 290: // AttributeSpecifierList
      // Fall through
    case 291: // AttributeSpecifier
      // Fall through
    case 294: // AttributeList
      // Fall through
    case 297: // AssemblyDefinition
      // Fall through
    case 298: // AssemblyExpression
      // Fall through
    case 299: // AssemblyExpressionOpt
      // Fall through
    case 300: // AssemblyStatement
      // Fall through
    case 301: // Assemblyargument
      // Fall through
    case 302: // AssemblyoperandsOpt
      // Fall through
    case 303: // Assemblyoperands
      // Fall through
    case 137: // FunctionOldPrototype
      // Fall through
    case 136: // FunctionPrototype
      // Fall through
    case 139: // NestedFunctionPrototype
      // Fall through
    case 138: // NestedFunctionDefinition
      // Fall through
    case 141: // DeclarationExtension
      // Fall through
    case 140: // NestedFunctionOldPrototype
      // Fall through
    case 143: // DefaultDeclaringList
      // Fall through
    case 142: // Declaration
      // Fall through
    case 129: // TranslationUnit
      // Fall through
    case 131: // ExternalDeclaration
      // Fall through
    case 130: // ExternalDeclarationList
      // Fall through
    case 133: // FunctionDefinitionExtension
      // Fall through
    case 132: // EmptyDefinition
      // Fall through
    case 135: // FunctionCompoundStatement
      // Fall through
    case 134: // FunctionDefinition
      // Fall through
    case 155: // BasicDeclarationSpecifier
      // Fall through
    case 156: // BasicTypeSpecifier
      // Fall through
    case 157: // SUEDeclarationSpecifier
      // Fall through
    case 158: // SUETypeSpecifier
      // Fall through
    case 159: // TypedefDeclarationSpecifier
      // Fall through
    case 144: // DeclaringList
      // Fall through
    case 145: // DeclarationSpecifier
      // Fall through
    case 146: // TypeSpecifier
      // Fall through
    case 147: // DeclarationQualifierList
      // Fall through
    case 148: // TypeQualifierList
      // Fall through
    case 175: // StructDeclarationList
      // Fall through
    case 173: // StructOrUnionSpecifier
      // Fall through
    case 172: // ElaboratedTypeName
      // Fall through
    case 163: // Typeofspecifier
      // Fall through
    case 162: // TypeofTypeSpecifier
      // Fall through
    case 161: // TypeofDeclarationSpecifier
      // Fall through
    case 160: // TypedefTypeSpecifier
      // Fall through
    case 164: // Typeofkeyword
      // Fall through
    case 186: // EnumeratorValueOpt
      // Fall through
    case 187: // ParameterTypeList
      // Fall through
    case 184: // EnumeratorList
      // Fall through
    case 185: // Enumerator
      // Fall through
    case 190: // IdentifierList
      // Fall through
    case 191: // Identifier
      // Fall through
    case 188: // ParameterList
      // Fall through
    case 189: // ParameterDeclaration
      // Fall through
    case 178: // StructDeclaringList
      // Fall through
    case 179: // StructDeclarator
      // Fall through
    case 176: // StructDeclaration
      // Fall through
    case 177: // StructDefaultDeclaringList
      // Fall through
    case 182: // BitFieldSize
      // Fall through
    case 183: // EnumSpecifier
      // Fall through
    case 180: // StructIdentifierDeclarator
      // Fall through
    case 181: // BitFieldSizeOpt
      // Fall through
    case 205: // TypedefDeclarator
      // Fall through
    case 204: // Declarator
      // Fall through
    case 207: // ParameterTypedefDeclarator
      // Fall through
    case 206: // TypedefDeclaratorMain
      // Fall through
    case 200: // DesignatorList
      // Fall through
    case 203: // ObsoleteFieldDesignation
      // Fall through
    case 202: // ObsoleteArrayDesignation
      // Fall through
    case 197: // InitializerList
      // Fall through
    case 196: // Initializer
      // Fall through
    case 198: // MatchedInitializerList
      // Fall through
    case 193: // TypeName
      // Fall through
    case 192: // IdentifierOrTypedefName
      // Fall through
    case 195: // DesignatedInitializer
      // Fall through
    case 194: // InitializerOpt
      // Fall through
    case 220: // ArrayDeclarator
      // Fall through
    case 221: // ParenIdentifierDeclarator
      // Fall through
    case 222: // SimpleDeclarator
      // Fall through
    case 223: // OldFunctionDeclarator
      // Fall through
    case 216: // PostfixIdentifierDeclarator
      // Fall through
    case 217: // AttributedDeclarator
      // Fall through
    case 218: // FunctionDeclarator
      // Fall through
    case 219: // PostfixingFunctionDeclarator
      // Fall through
    case 212: // SimpleParenTypedefDeclarator
      // Fall through
    case 213: // IdentifierDeclarator
      // Fall through
    case 214: // IdentifierDeclaratorMain
      // Fall through
    case 215: // UnaryIdentifierDeclarator
      // Fall through
    case 208: // CleanTypedefDeclarator
      // Fall through
    case 209: // CleanPostfixTypedefDeclarator
      // Fall through
    case 210: // ParenTypedefDeclarator
      // Fall through
    case 211: // ParenPostfixTypedefDeclarator
      // Fall through
    case 239: // DeclarationOrStatement
      // Fall through
    case 238: // DeclarationOrStatementList
      // Fall through
    case 237: // LocalLabelList
      // Fall through
    case 236: // LocalLabelDeclaration
      // Fall through
    case 235: // LocalLabelDeclarationList
      // Fall through
    case 234: // LocalLabelDeclarationListOpt
      // Fall through
    case 233: // CompoundStatement
      // Fall through
    case 232: // LabeledStatement
      // Fall through
    case 231: // Statement
      // Fall through
    case 230: // PostfixAbstractDeclarator
      // Fall through
    case 229: // UnaryAbstractDeclarator
      // Fall through
    case 228: // ArrayAbstractDeclarator
      // Fall through
    case 227: // ParameterTypeListOpt
      // Fall through
    case 226: // PostfixingAbstractDeclarator
      // Fall through
    case 225: // AbstractDeclarator
      // Fall through
    case 224: // PostfixOldFunctionDeclarator
      // Fall through
    case 254: // StatementAsExpression
      // Fall through
    case 255: // PostfixExpression
      // Fall through
    case 252: // PrimaryIdentifier
      // Fall through
    case 253: // VariableArgumentAccess
      // Fall through
    case 250: // StringLiteralList
      // Fall through
    case 251: // PrimaryExpression
      // Fall through
    case 248: // ReturnStatement
      // Fall through
    case 249: // Constant
      // Fall through
    case 246: // ContinueStatement
      // Fall through
    case 247: // BreakStatement
      // Fall through
    case 244: // JumpStatement
      // Fall through
    case 245: // GotoStatement
      // Fall through
    case 242: // SelectionStatement
      // Fall through
    case 243: // IterationStatement
      // Fall through
    case 240: // DeclarationList
      // Fall through
    case 241: // ExpressionStatement
      return true;

    default:
      return false;
    }
  }

  public boolean changeName(int id) {
    switch(id) {
    case 135: // FunctionCompoundStatement
      return true;

    default:
      return false;
    }
  }

  public String newName(int id) {
    switch(id) {
    case 135: // FunctionCompoundStatement
      return "CompoundStatement";

    default:
      return null;
    }
  }


}
