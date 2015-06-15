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

/**
 * This class is generated from grammar annotations and provides semantic
 * action support.
 */
public abstract class ExpressionActionsInterface implements SemanticActions {

  public void dispatch(int id, Subparser subparser) {
    switch(id) {
    case 145:
      CheckDefined(subparser);
      break;

    default:
      // Do nothing
      break;
    }
  }

  public abstract void CheckDefined(Subparser subparser);

}
