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

public class ExpressionActions extends ExpressionActionsInterface {
  /** Create a new actions class. */
  private ExpressionActions() {
  }

  /** The instance of this class. */
  private static ExpressionActions ref;

  /** Get the instance of this class. */
  public static ExpressionActions getInstance() {
    if (null == ref) {
      ref = new ExpressionActions();
    }
    return ref;
  }

  public void CheckDefined(Subparser subparser) {
    if (! "defined".equals(subparser.stack.get(2).value.toString())) {
      subparser.lookahead.setError();
    }
  }
}
