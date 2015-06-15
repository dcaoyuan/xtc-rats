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
public abstract class CActionsInterface implements SemanticActions {

  public void dispatch(int id, Subparser subparser) {
    switch(id) {
    case 311:
      BindIdentifierInList(subparser);
      break;

    case 310:
      BindIdentifier(subparser);
      break;

    case 313:
      BindEnum(subparser);
      break;

    case 312:
      BindVar(subparser);
      break;

    case 315:
      ExitScope(subparser);
      break;

    case 314:
      EnterScope(subparser);
      break;

    case 317:
      ReenterScope(subparser);
      break;

    case 316:
      ExitReentrantScope(subparser);
      break;

    case 318:
      KillReentrantScope(subparser);
      break;

    default:
      // Do nothing
      break;
    }
  }

  public abstract void BindIdentifierInList(Subparser subparser);

  public abstract void BindIdentifier(Subparser subparser);

  public abstract void BindEnum(Subparser subparser);

  public abstract void BindVar(Subparser subparser);

  public abstract void ExitScope(Subparser subparser);

  public abstract void EnterScope(Subparser subparser);

  public abstract void ReenterScope(Subparser subparser);

  public abstract void ExitReentrantScope(Subparser subparser);

  public abstract void KillReentrantScope(Subparser subparser);

}
