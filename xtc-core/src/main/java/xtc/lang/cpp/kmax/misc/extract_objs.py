#!/usr/bin/env python

# Find the mapping of compilation units to controlling configuration
# variables.  Several configuration variables that turn on a
# compilation unit are a disjunction.

import sys
from os import path
from pymake import parser, parserdata, data, functions
import operator
from itertools import repeat
from collections import defaultdict


def go(stmts):
    for s in stmts:
        if isinstance(s, parserdata.SetVariable):
            objs = s.value.split()
            for o in objs:
                if o[-2:] == ".o":
                    print o
        elif isinstance(s, parserdata.ConditionBlock):
            for c in s._groups:
                _, l = c
                go(l)


kbuild=sys.argv[1]

fd = open(kbuild, 'rU')
s = fd.read()
fd.close()
stmts = parser.parsestring(s, kbuild)
go(stmts)

