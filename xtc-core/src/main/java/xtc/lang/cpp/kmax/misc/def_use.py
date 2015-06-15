#!/usr/bin/env python

import sys
import os
import operator
import re
import argparse

from pymake import parser, parserdata, data, functions
from collections import defaultdict

force_off = defaultdict(bool)
inconditional = 0
inconditionaloff = 0
reassignments = 0

var_pattern = re.compile("'CONFIG_[^']+'")
tristate = re.compile("^y$|^m$|^n$|^CONFIG_")

argparser = argparse.ArgumentParser(
    formatter_class=argparse.RawDescriptionHelpFormatter,
    description="""\
Find variables defined and used in Kbuild Makefiles
""",
    )
argparser.add_argument('--tristate', '-t', type=argparse.FileType('r'))
argparser.add_argument('--bools', '-b', type=argparse.FileType('r'))
argparser.add_argument('--nonbools', '-n', type=argparse.FileType('r'))
argparser.add_argument('makefiles', metavar="Makefile", nargs='*',
                       type=str, default=sys.stdin, help="""\
The name of a Linux Makefile or subdir.  Otherwise read from stdin.""")

args = argparser.parse_args()

definitions = {} # None means its part of the arch, but its def is unknown

default_tristate = [ 'y', 'm', 'n' ]
default_bools = [ 'y', 'n' ]

if args.tristate:
  for line in args.tristate.readlines():
    vname = "CONFIG_" + line.rstrip()
    definitions[vname] = default_tristate

if args.bools:
  for line in args.bools.readlines():
    vname = "CONFIG_" + line.rstrip()
    definitions[vname] = default_bools

if args.nonbools:
  for line in args.nonbools.readlines():
    vname = "CONFIG_" + line.rstrip()
    definitions[vname] = None

print definitions

makefiles = []
for f in args.makefiles:
    if os.path.isdir(f):
        subdir = f
        f = os.path.join(subdir, "Kbuild")
        if not os.path.isfile(f):
            f = os.path.join(subdir, "Makefile") 
    if not os.path.isfile(f):
        print f, "not found"
    else:
        makefiles.append(open(f, "rU"))

def process_statements(stmts):
    for s in stmts:
        if isinstance(s, parserdata.ConditionBlock):
            for c, cstmts in s:
              print "cond:", c
              process_statements(s)
        elif isinstance(s, parserdata.SetVariable):
            if s.token in [ '=', ':=', '?=' ]:
              print s.to_source()

for f in makefiles:
    s = f.read()
    f.close()
    stmts = parser.parsestring(s, f.name)
    process_statements(stmts)
