#!/usr/bin/env python

# Reports configuration variables used in Makefile conditionals.
# Reports in a few ways.  find_kcu is interested in off, undef, and
# ref.  on and def of there for testing this program.

# off CONFIG_VAR

# undef CONFIG_VAR

# on CONFIG_VAR - means a single-branch conditional testing whether
# the variable is y or m, testing whether the variable is not n, or
# testing whether the variable is defined.

# def CONFIG_VAR

# ref CONFIG_VAR means a conditional references the variable in any
# other way, and the find_kcu.sh script needs to run twice with the
# variable on and off to get all kcus.

import sys
from os import path
from pymake import parser, parserdata, data, functions
import operator
from itertools import repeat
from collections import defaultdict
import re


# Print any configuration variables referenced in this conditional
# expression.
def printrefs(c):
    for m in re.findall("'CONFIG_[^']+'", str(c)):
        print "ref", m[1:-1]

# Print any configuration variables that either need to be turned off
# or are referenced in conditionals expressions.
def go(stmts):
    for s in stmts:
        if isinstance(s, parserdata.ConditionBlock):
            emit = True
            # If there is just one branch and it tests that a
            # configuration variable is turned off or undefined, then
            # we need to run make with the variable both on and off.
            if len(s._groups) == 1:
                c, _ = s._groups[0]
                if isinstance(c, parserdata.EqCondition):
                    varref, _ = c.exp1[0]
                    rhs, _ = c.exp2[0]
                    if isinstance(varref, functions.VariableRef) \
                            and varref.vname.s.startswith('CONFIG_'):
                        var = varref.vname.s
                        if rhs == 'y' and not c.expected \
                                or rhs == 'm' and not c.expected \
                                or rhs == 'n' and c.expected:
                            print "off", var
                            emit = False
                        elif rhs == 'y' and c.expected \
                                or rhs == 'm' and c.expected \
                                or rhs == 'n' and not c.expected:
                            print "on", var
                            emit = False
                elif isinstance(c, parserdata.IfdefCondition):
                    if isinstance(c.exp, data.StringExpansion) \
                            and c.exp.s.startswith('CONFIG_'):
                        var = c.exp.s
                        if not c.expected:
                            print "undef", var
                        else:
                            print "def", var
                        emit = False
            for b in s._groups:
                c, s = b
                if emit:
                    printrefs(c)
                go(s)


for kbuild in sys.argv[1:]:
    fd = open(kbuild, 'rU')
    s = fd.read()
    fd.close()
    stmts = parser.parsestring(s, kbuild)
    go(stmts)

