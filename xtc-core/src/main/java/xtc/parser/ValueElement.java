/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2004 Robert Grimm
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
 * The superclass of all value elements.  Value elements are internal
 * elements that specify an explicit semantic value.
 *
 * @author Robert Grimm
 * @version $Revision: 1.3 $
 */
public abstract class ValueElement extends Element implements InternalElement {

  /** Create a new value element. */
  public ValueElement() { /* Nothing to do. */ }

}
