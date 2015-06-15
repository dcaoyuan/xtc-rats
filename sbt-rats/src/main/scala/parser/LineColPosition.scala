/*
 * This file is part of the sbt-rats plugin.
 * Copyright (c) 2012-2015 Anthony M Sloane, Macquarie University.
 * All rights reserved.
 * Distributed under the New BSD license.
 * See file LICENSE at top of distribution.
 */

package parser

import scala.util.parsing.input.{ Position, Positional }
import xtc.parser.ParserBase

class LineColPosition(val p: ParserBase, val index: Int, val line: Int, val column: Int) extends Position {

  override def <(that: Position): Boolean =
    line < that.line ||
      line == that.line && column < that.column

  override def lineContents: String =
    p.lineAt(index)

  override def toString(): String =
    s"$line.$column"

}
