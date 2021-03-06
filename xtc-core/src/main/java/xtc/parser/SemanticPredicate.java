/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2004-2007 Robert Grimm
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
package xtc.parser;

/**
 * A semantic predicate.
 *
 * @author Robert Grimm
 * @version $Revision: 1.4 $
 */
public class SemanticPredicate extends Predicate {

  /**
   * Create a new semantic predicate.
   *
   * @param action The test as an action.
   */
  public SemanticPredicate(Action action) {
    super(action);
  }

  public Tag tag() {
    return Tag.SEMANTIC_PREDICATE;
  }

  public int hashCode() {
    return element.hashCode();
  }

  public boolean equals(Object o) {
    if (this == o) return true;
    if (! (o instanceof SemanticPredicate)) return false;
    return element.equals(((SemanticPredicate)o).element);
  }

}
