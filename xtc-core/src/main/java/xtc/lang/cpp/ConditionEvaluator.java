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

import java.util.List;
import java.util.Iterator;

import xtc.tree.GNode;
import xtc.tree.Node;
import xtc.tree.Token;
import xtc.tree.Visitor;

import xtc.type.C;
import xtc.type.Type;

import xtc.lang.cpp.PresenceConditionManager.PresenceCondition;
import xtc.lang.cpp.MacroTable.Macro;
import xtc.lang.cpp.MacroTable.Entry;
import xtc.lang.cpp.Syntax.Kind;

import net.sf.javabdd.BDD;
import net.sf.javabdd.BDDFactory;

/**
 * Generate a BDD from a preprocessor conditional expression.
 *
 * @author Paul Gazzillo
 */
public class ConditionEvaluator {
  /** Manages presence conditions. */
  protected PresenceConditionManager presenceConditionManager;

  /** An optional macro table used for the defined operator.  */
  private MacroTable macroTable;

  /** The expression parser. */
  private ExpressionParser parser;
  
  /** The BDD factory. */
  private BDDFactory B;
  
  /** The common type operations for C. */
  private final C cops;

  /**
   * True when the evaluator is constructing a string version of a
   * subexpression.  This is necessary to represent non-boolean
   * subexpression as variables in a boolean function.
   */
  private boolean dostring = false;

  /** Flag for non-boolean subexpressions. */
  private boolean nonboolean = false;

  /** Setting that pulls all undefined macros to false and empty. */
  private boolean pullUndefinedFalse = false;

  /**
   * Set the pullUndefinedFalse flag.
   *
   * @param b The new setting.
   */
  public void setPullUndefinedFalse(boolean b) {
    this.pullUndefinedFalse = b;
  }

  /**
   * Create a new condition evaluator.
   *
   * @param presenceConditionManager Manages presence conditions.
   * @param macroTable The macro table.
   */  
  public ConditionEvaluator(ExpressionParser parser,
                            PresenceConditionManager presenceConditionManager,
                            MacroTable macroTable) {
    this.presenceConditionManager = presenceConditionManager;
    this.macroTable = macroTable;
    this.parser = parser;

    this.B = presenceConditionManager.getBDDFactory();
    this.cops = new C();
  }

  /**
   * Create a new condition evaluator without macro resolution.
   *
   * @param presenceConditionManager Manages presence conditions.
   */
  public ConditionEvaluator(ExpressionParser parser,
                            PresenceConditionManager presenceConditionManager) {
    this(parser, presenceConditionManager, null);
  }

  /**
   * Evaluate a conditional expression.
   *
   * @param expression An expression.
   * @return A BDD.
   */
  public BDD evaluate(Iterator<Syntax> expression) {
    return evaluate(parser.parse(expression));
  }

  /**
   * Evaluate a conditional expression's AST.  This method can be used
   * without passing a parser.
   *
   * @param ast An AST of an expression.
   * @return A BDD.
   */
  public BDD evaluate(Node ast) {
    nonboolean = false;
    dostring = false;
    return ensureBDD(visitor.dispatch(ast));
  }

  /**
   * Return true if the expression had a non-boolean subexpression.
   *
   * @return true if there was a non-boolean subexpression.
   */
  public boolean sawNonboolean() {
    return nonboolean;
  }

  private Visitor visitor = new Visitor() {
      /** Process an integer constant. */
      public Object visitIntegerConstant(GNode n) {
        xtc.type.Type result;
    
        result = cops.typeInteger(n.getString(0));

        return result.getConstant().bigIntValue().longValue();
      }

      /** Process a character constant. */
      public Object visitCharacterConstant(GNode n) {
        xtc.type.Type result;
    
        result = cops.typeCharacter(n.getString(0));
    
        return result.getConstant().bigIntValue().longValue();
      }

      /** Process primary identifier. */
      public Object visitPrimaryIdentifier(GNode n) {
        // if (pullUndefinedFalse) {
        //   return "";
        // }
        
        return n.getString(0);
      }

      /** Process a unary minus. */
      public Object visitUnaryMinusExpression(GNode n) {
        Object a;

        nonboolean = true;
    
        dostring = true;
    
        a = dispatch(n.getGeneric(0));
    
        dostring = false;
    
        if (a instanceof Long) {
          return - (Long) a;
        }
        else {
          return "- " + parens(a);
        }
      }

      /** Process a unary plus. */
      public Object visitUnaryPlusExpression(GNode n) {
        nonboolean = true;

        return dispatch(n.getGeneric(0));
      }

      /** Process a logical negation. */
      public Object visitLogicalNegationExpression(GNode n) {
        if (dostring) {
          Object a = dispatch(n.getGeneric(0));
      
          if (a instanceof Long) {
            return "" + ((((Long) a).equals(new Long(0))) ? 1 : 0);
          }
          else {
            return "! " + parens(a);
          }
        }
        else {
          BDD a = ensureBDD(dispatch(n.getGeneric(0)));
          BDD bdd;
      
          bdd = a.not();
      
          a.free();
      
          return bdd;
        }
      }

      /** Process a bitwise negation. */
      public Object visitBitwiseNegationExpression(GNode n) {
        Object a, result;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
            
        dostring = false;
    
        if (a instanceof Long) {
          result = ~ (Long) a;
        }
        else {
          return "~ " + parens(a);
        }
    
        return result;
      }

      /** Process a multiplicative operation. */
      public Object visitMultiplicativeExpression(GNode n) {
        Object a, b, result;
        String op;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(2));
        op = n.getString(1);
    
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          if ((op.equals("/")
               || op.equals("%")) && ((Long) b).equals(new Long(0))) {
            System.err.println("division by zero in #if");
            result = new Long(0);
          }
          if (op.equals("*")) {
            result = (Long) a * (Long) b;
          }
          else if (op.equals("/")) {
            result = (Long) a / (Long) b;
          }
          else if (op.equals("%")) {
            result = (Long) a % (Long) b;
          }
          else {
            result = "";
          }
        }
        else {
          result = parens(a) + " " + op + " " + parens(b);
        }
    
        return result;
      }

      /** Process an additive operation. */
      public Object visitAdditiveExpression(GNode n) {
        Object a, b, result;
        String op;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(2));
        op = n.getString(1);
    
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          if (op.equals("+")) {
            result = (Long) a + (Long) b;
          }
          else if (op.equals("-")) {
            result = (Long) a - (Long) b;
          }
          else {
            result = "";
          }
        }
        else {
          result = parens(a) + " " + op + " " + parens(b);
        }
    
        return result;
      }

      /** Process a shift expression. */
      public Object visitShiftExpression(GNode n) {
        Object a, b, result;
        String op;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(2));
        op = n.getString(1);
    
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          if (op.equals("<<")) {
            result = (Long) a << (Long) b;
          }
          else if (op.equals(">>")) {
            result = (Long) a >> (Long) b;
          }
          else {
            result = "";
          }
        }
        else {
          result = parens(a) + " " + op + " " + parens(b);
        }
    
        return result;
      }

      /** Process a relational expression. */
      public Object visitRelationalExpression(GNode n) {
        Object a, b, result;
        String op;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(2));
        op = n.getString(1);
    
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          Long x = (Long) a;
          Long y = (Long) b;
          long zero = 0;
          long one = 1;
      
          if (op.equals("<")) {
            result = x < y ? one : zero;
          }
          else if (op.equals("<=")) {
            result = x <= y ? one : zero;
          }
          else if (op.equals(">")) {
            result = x > y ? one : zero;
          }
          else if (op.equals(">=")) {
            result = x >= y ? one : zero;
          }
          else {
            result = "";
          }
        }
        else {
          result = parens(a) + " " + op + " " + parens(b);
        }
    
        return result;
      }

      /** Process a equality expression. */
      public Object visitEqualityExpression(GNode n) {
        Object a, b, result;
        String op;
        boolean mydostring = dostring;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(2));
        op = n.getString(1);
    
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          if (op.equals("==")) {
            result = ((Long) a).equals((Long) b);
          }
          else if (op.equals("!=")) {
            result = ! ((Long) a).equals((Long) b);
          }
          else {
            result = "";
          }
        }
        else {
          String sa, sb;
      
          if (a instanceof String) {
            sa = (String) a;
          }
          else if (a instanceof Long) {
            sa = ((Long) a).toString();
          }
          else {
            return null;
          }
      
          if (b instanceof String) {
            sb = (String) b;
          }
          else if (b instanceof Long) {
            sb = ((Long) b).toString();
          }
          else {
            return null;
          }
      
          if (op.equals("==") && sa.equals(sb)) {
            result = mydostring ? "1" : B.one();
          }
          else {
            result = parens(sa) + " " + op + " " + parens(sb);
          }
        }
    
        return result;
      }

      /** Process a bitwise and. */
      public Object visitBitwiseAndExpression(GNode n) {
        Object a, b, result;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(1));
            
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          result = (Long) a & (Long) b;
        }
        else {
          result = parens(a) + " & " + parens(b);
        }
    
        return result;
      }

      /** Process a bitwise xor. */
      public Object visitBitwiseXorExpression(GNode n) {
        Object a, b, result;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(1));
            
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          result = (Long) a ^ (Long) b;
        }
        else {
          result = parens(a) + " ^ " + parens(b);
        }
    
        return result;
      }

      /** Process a bitwise or. */
      public Object visitBitwiseOrExpression(GNode n) {
        Object a, b, result;
    
        nonboolean = true;

        dostring = true;
    
        a = dispatch(n.getGeneric(0));
        b = dispatch(n.getGeneric(1));
            
        dostring = false;
    
        if (a instanceof Long && b instanceof Long) {
          result = (Long) a | (Long) b;
        }
        else {
          result = parens(a) + " | " + parens(b);
        }
    
        return result;
      }

      /** Process a logical and. */
      public Object visitLogicalAndExpression(GNode n) {
        if (dostring) {
          Object a = dispatch(n.getGeneric(0));
          Object b = dispatch(n.getGeneric(1));
      
          if (a instanceof Long && b instanceof Long) {
            return (Long) a & (Long) b;
          }
          else {
            return parens(a) + " && " + parens(b);
          }
        }
        else {
          BDD a, b, bdd;
      
          a = ensureBDD(dispatch(n.getGeneric(0)));
          b = ensureBDD(dispatch(n.getGeneric(1)));
      
          bdd = a.andWith(b);
      
          return bdd;
        }
      }

      /** Process a logical or. */
      public Object visitLogicalOrExpression(GNode n) {
        if (dostring) {
          Object a = dispatch(n.getGeneric(0));
          Object b = dispatch(n.getGeneric(1));
      
          if (a instanceof Long && b instanceof Long) {
            return (Long) a | (Long) b;
          }
          else {
            return parens(a) + " || " + parens(b);
          }
        }
        else {
          BDD a, b, bdd;
      
          a = ensureBDD(dispatch(n.getGeneric(0)));
          b = ensureBDD(dispatch(n.getGeneric(1)));
      
          bdd = a.orWith(b);
      
          return bdd;
        }
      }
  

      /** Make a new BDD argument, "defined M".  If a macro table was supplied
       * to the evaluator, look for M there and evaluate the operation.
       */
      public Object visitDefinedExpression(GNode n) {
        String parameter = n.getGeneric(0).getString(0);

        //evaluate the defined operation, preserving configurations
        if (macroTable != null) {
          List<Entry> definitions = macroTable.get(parameter, presenceConditionManager);

          if (definitions != null && definitions.size() > 0) {
            boolean hasDefined, hasUndefined, hasFree;
        
            //three conditions
            //1) defined under all configurations, so output 1 (true)
            //2) undefined under all configurations, so output 0 (false)
            //3) partially defined, so output union of configurations
        
            hasDefined = false;
            hasUndefined = false;
            hasFree = false;
            for (Entry def : definitions) {
              if (def.macro.state == Macro.State.FREE) {
                hasFree = true;
              }
              else if (def.macro.state == Macro.State.DEFINED) {
                hasDefined = true;
              }
              else if (def.macro.state == Macro.State.UNDEFINED) {
                hasUndefined = true;
              }
            }
        
            if (hasDefined && ! hasUndefined && ! hasFree) {
              //fully defined in this presenceCondition
              return B.one(); //the constant true BDD

            } else if (hasUndefined && ! hasDefined && ! hasFree) {
              //not defined in this presenceCondition
              return B.zero(); //the constant false BDD

            } else {
              //partially defined in this presenceCondition
              BDD defined = B.zero();
              List<Token> tokenlist;
              int c;
          
              for (Entry def : definitions) {
                if (def.macro.state == Macro.State.FREE) {
                  BDD newDefined;
                  BDD varBDD;
                  BDD term;

                  // pull FREE to false also if pullUndefinedFalse is
                  // set
                  if (!pullUndefinedFalse) {
                    varBDD = presenceConditionManager.getVariableManager()
                      .getDefinedVariable(parameter);

                    term = def.presenceCondition.getBDD().and(varBDD);
                    newDefined = defined.or(term);
                    term.free();
                    defined.free();
                    varBDD.free();
                    defined = newDefined;
                  } else {
                    System.err.println("pullUndefinedFalse");
                  }

                } else if (def.macro.state == Macro.State.DEFINED) {
                  BDD newDefined;
              
                  newDefined = defined.or(def.presenceCondition.getBDD());
                  defined.free();
                  defined = newDefined;
                } else if (def.macro.state == Macro.State.UNDEFINED) {
                  //do nothing
                }
              }

              return defined;
            } //end partially defined

          } else {
            // The macro was used in a conditional expression before or
            // without being defined, therefore it is a configuration
            // variable.
            if (macroTable.getConfigurationVariables()) {
              macroTable.configurationVariables.add(parameter);
            }

            if (pullUndefinedFalse) {
              return B.zero();
            }
          }
        } //end has macro table

        //if there are no macro table entries, just return the operation as is
        return "defined " + parameter;  //return a string
      }
  
      /** Process a conditional expression. */
      public Object visitConditionalExpression(GNode n) {
        if (dostring) {
          Object a = dispatch(n.getGeneric(0));
          Object b = dispatch(n.getGeneric(1));
          Object c = dispatch(n.getGeneric(2));
      
          if (a instanceof Long) {
            return (! ((Long) a).equals(new Long(0))) ? b : c;
          }
          else {
            return parens(a) + " ? " + parens(b) + " : " + parens(c);
          }
        }
        else {
          BDD a = ensureBDD(dispatch(n.getGeneric(0)));
          BDD b = ensureBDD(dispatch(n.getGeneric(1)));
          BDD c = ensureBDD(dispatch(n.getGeneric(2)));
          BDD ab, na, nac, bdd;
      
          //implement with a & b | !a & c
          ab = a.and(b);
          b.free();
          na = a.not();
          a.free();
          nac = na.and(c);
          c.free();
          na.free();
          bdd = ab.or(nac);
          nac.free();
          ab.free();
      
          return bdd;
        }
      }
    };

  /** Ensures that parentheses surround terms to preserve order of operations
    */
  public String parens(Object a) {
    String s;
    
    if (a instanceof String) {
      s = (String) a;
    }
    else if (a instanceof Long) {
      s = ((Long) a).toString();
    }
    else {
      return null;
    }
    
    if (s.indexOf(" ") >= 0) {
      return "(" + s + ")";
    }
    else {
      return s;
    }
  }

  /** Takes whatever the evaluation returns, string, boolean, or integer, and
    * creates a BDD out of it if isn't already.
    */
  public BDD ensureBDD(Object o) {
    if (o instanceof BDD) {
      return (BDD) o;
    }
    else if (o instanceof Long) {
      if (((Long) o).equals(new Long(0))) {
        return B.zero();
      }
      else {
        return B.one();
      }
    }
    else if (o instanceof String) {
      String s = parens(o);

      return presenceConditionManager.getVariableManager().getVariable(s);
    }
    else if (o instanceof Boolean) {
      Boolean b = (Boolean) o;
      
      if (b) {
        return B.one();
      }
      else {
        return B.zero();
      }
    }
    else {
      System.err.println("FATAL: ensureBDD, unforeseen type from evaluator");
      System.err.println(o);
      System.err.println(o.getClass());
      System.exit(-1);
      
      return null;
    }
  }
}
