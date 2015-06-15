/*
 * This file is part of the sbt-rats plugin.
 * Copyright (c) 2012-2015 Anthony M Sloane, Macquarie University.
 * All rights reserved.
 * Distributed under the New BSD license.
 * See file LICENSE at top of distribution.
 */

package ast

object SList {
  type L[T] = scala.collection.immutable.List[T]
  def empty[T]: L[T] = Nil
  def create[T](hd: T): L[T] = hd :: Nil
  def create[T](hd: T, nxt: T): L[T] = hd :: nxt :: Nil
  def create[T](hd: T, tl: L[T]): L[T] = hd :: tl
}
