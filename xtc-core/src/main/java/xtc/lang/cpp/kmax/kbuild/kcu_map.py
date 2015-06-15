#!/usr/bin/env python

# Find the mapping of compilation units to controlling configuration
# variables.  Several configuration variables that turn on a
# compilation unit are a disjunction.

import sys
import os
from pymake import parser, parserdata, data, functions
import operator
from itertools import repeat
from collections import defaultdict

# Omitting firmware/, because pymake does not support order-only
# prerequisistes (which firmware/Makefile apparently uses) and
# firmware doesn't have any C compilation units anyway (except
# firmware/ihex2fw.c, which isn't part of the kernel anyway).
subdirs = [ "arch/x86/", "kernel/", "mm/", "fs/", "ipc/", "security/",
            "crypto/", "block/", "drivers/", "sound/", "net/", "lib/", "usr/" ]
subdirs = sys.argv[1:]

# The list of target prefixes that aren't for compilation units
non_kcu = [ "ccflags", "asflags", "ldflags", "subdir-ccflags", "subdir-asflags",
            "lib", "cppflags", "hostprogs" ]

# This list is used to temporarily skip anomalous kbuild files
skip = [ "drivers/video/omap/",           # objs-yy
         "drivers/staging/wlags49_h2/" ,  # conditionally-defined WLNAME
         "drivers/staging/wlags49_h25/",  # conditionally-defined WLNAME
         ]


# Save variable mappings
vars = {}

# Save multi-source object lists, including "obj-y".  This maps the
# name, e.g. "obj" to a set of compilation objects (both single and
# multi-source ones) without the .o extension.
multisource = defaultdict(set)

# Save the subdirectory in which an object lives
object_subdir = defaultdict(set)

# Save config var deps for source files
source_deps = defaultdict(set)

# Save the config vars that multi-source files propagate
multisource_deps = defaultdict(set)

# Save config var deps for subdirectories
subdir_deps = defaultdict(set)

# Get the Kbuild file from a directory.  Makefile is the preferred
# name BUT if a Kbuild file exists, then it is used instead of
# 'Makefile' according to
# http://lxr.linux.no/#linux+v3.5/Documentation/kbuild/makefiles.txt.
def get_kbuild(subdir):
    kbuild = os.path.join(subdir, "Kbuild")
    if os.path.exists(kbuild):
        return kbuild
    return os.path.join(subdir, "Makefile")

# Process the kbuild/makefile from a specific subdirectory
def enter(subdir):
    if reduce(operator.or_, map(os.path.samefile, skip, repeat(subdir, len(skip)))):
        # print "SKIPPING ", subdir
        return
    kbuild = get_kbuild(subdir)
    print "kbuild ", kbuild
    fd = open(kbuild, 'rU')
    s = fd.read()
    fd.close()
    stmts = parser.parsestring(s, kbuild)
    for s in stmts:
        if isinstance(s, parserdata.SetVariable):
            analyze(subdir, s)
        elif isinstance(s, parserdata.ConditionBlock):
            # print "NEED TO SUPPORT CONDITION"
            pass
        else:
            # print "UNSUPPORTED STATEMENT TYPE"
            pass

def add_deps(o, deps, subdir):
    filename = os.path.join(subdir, o) + ".c"
    if os.path.exists(filename):
        # A single-source compilation unit
        source_deps[o] = source_deps[o].union(deps)
        source_deps[o] = source_deps[o].union(subdir_deps[subdir])
        # print o, "depends on", source_deps[o], "and is in", subdir
    else:
        multisource_deps[o] = multisource_deps[o].union(deps)
        multisource_deps[o] = multisource_deps[o].union(subdir_deps[subdir])
        # print o, "depends on", multisource_deps[o], "and is in", subdir

# Analyze SetVariable statements for their 
def analyze(subdir, s):
    # First process the variable name.  It is either an "obj-"
    # variable or names a module built from several source files.  It
    # also may have a configuration variable controlling which list it
    # belongs to, obj-y, obj-m, etc.

    # Kbuild syntax
    # Case 1: variable is a constant string
    # Case 2: variable has a constant "obj-" and a config var suffix
    # Case 3: variable has a constant object name and a config var
    
    # Kbuild semantics
    # Prefix is either "obj-" or the name of a module.
    # Suffix is either a constant (y, m, or n) or a config var

    prefix = "" #the prefix, 'obj' or the multi-source variable
    suffix = "" #the suffix, a config var or y, m, or n
    deps = set()
    if isinstance(s.vnameexp, data.StringExpansion):
        prefix, sep, suffix = s.vnameexp.s.rpartition('-')
        if (sep != '-'):
            # Keep track of other variables just in case
            vars[s.vnameexp.s] = s.value
            return
        if len(suffix) == 0:
            # A trick used for cleaning, e.g., "subdir-".  See
            # drivers/scsi/aic7xxx/.
            return
    elif isinstance(s.vnameexp, data.Expansion):
        first, _ = s.vnameexp[0]
        if len(s.vnameexp) == 3:
            sep, _ = s.vnameexp[1]
            if sep != "-":
                return
        if isinstance(first, functions.VariableRef):
            first = first.vname
            assert isinstance(first, data.StringExpansion)
            first = first.s
            assert isinstance(first, str)
            assert first in vars
            prefix = vars[first]
            assert isinstance(first, str)
        else:
            assert isinstance(first, str)
            prefix, sep, empty = first.rpartition('-')
            if (sep != '-'):
                return
            assert len(empty) == 0
            
        second, _ = s.vnameexp[1]
        if (second == "-"):
            second, _ = s.vnameexp[2]

        if isinstance(second, functions.SubstFunction):
            # Look for a pattern where y is sub'ed for m in the
            # CONFIG.  See drivers/ethernet/Makefile for an example.
            assert isinstance(second[0], data.StringExpansion)
            assert second[0].s == "m" or second[0].s == "y"
            if isinstance(second[1], data.Expansion):
                # Look for a pattern where one configuration
                # variable's value is substituted by another's.  See
                # net/l2tp/Makefile for an example.
                assert len(second[1]) == 1
                other, _ = second[1][0]
                assert isinstance(other, functions.VariableRef)
                deps.add(other.vname.s)
            else:
                assert isinstance(second[1], data.StringExpansion)
                assert second[1].s == "y" or second[1].s == "m"
            assert isinstance(second[2], data.Expansion)
            assert len(second[2]) == 1
            suffix, _ = second[2][0]
        elif isinstance(second, functions.VariableRef):
            suffix = second
        else:
            print second
            assert isinstance(second, str)
            empty, sep, suffix = second.rpartition('-')
            if (sep != '-'):
              return
            assert len(empty) == 0

    # compunit-objs is equivalent to compunit-y according to
    # scripts/Makefile.build:406
    if suffix == "objs":
        suffix = "y"

    # Filter out targets that aren't source files, like ccflags
    if prefix in non_kcu:
        return

    # Filter out targets that don't have config var or constant
    if not isinstance(suffix, functions.VariableRef):
        if (suffix != 'y' and suffix != 'n' and suffix != 'm'):
            return

    # Add config var dependency
    if isinstance(suffix, functions.VariableRef):
        deps.add(suffix.vname.s)

    # Look for both := and +=.  Don't bother trying to figure out
    # where the list begins.  Doesn't allow ?=, which would introduce
    # strange semantics and doesn't seemed to be used for kcus anyway.
    assert s.token == '=' or s.token == ':=' or s.token == '+='

    # Kbuild syntax: the value should be a string containing a list of
    # objects and/or directory names.

    # Kbuild semantics
    # Case 1: an element is a directory name, recursively analyze the
    # kbuild file in that directory
    # Case 2: an element corresponds to a comp unit (file.o => file.c)
    # Case 3: an element corresponds to a multi-file module object
    # (name.o corresponds to another make variable, e.g. name-y :=
    # ...)  Need to add any config var to the comp units' config vars.
    # Also can sanity check to make sure that a Makefile var exists
    # for the object.
    assert isinstance(s.value, str)

    objs = s.value.split()

    # print "targ: ", prefix
    # print "deps: ", deps
    # print "objs: ", objs

    assert isinstance(prefix, str)
    for o in objs:
        if o[-2:] == ".o":
            # Compilation object.  It either corresponds to one source
            # file or names a multi-source file.
            stem = o[:-2]
            multisource[prefix].add(stem)
            add_deps(stem, deps, subdir)
            # print stem
            # If single file, add deps to its deps
            # If muli-source file, get its list of files
        elif o[-1] == "/" or prefix == "subdir":
            if o[-1] != "/":
                o += "/"
            # Descend into subdirectories
            new_subdir = os.path.join(subdir, o)
            # print new_subdir
            subdir_deps[new_subdir] = subdir_deps[new_subdir].union(deps)
            subdir_deps[new_subdir] \
                = subdir_deps[new_subdir].union(subdir_deps[subdir])
            # print new_subdir, "depends on", subdir_deps[new_subdir]
            enter(new_subdir)
        elif o[0] == "$":
            # print "NEED TO CHECK FOR VAR REF IN KCU LIST"
            pass
        else:
            # print "UNKNOWN OBJECT TYPE IN KCU LIST"
            pass


# main
if len(sys.argv) > 1:
    subdirs = sys.argv[1:]

for subdir in subdirs:
    enter(subdir)


for s in multisource:
    for o in multisource[s]:
        if o in source_deps:
            source_deps[o] = source_deps[o].union(multisource_deps[s])

for o in source_deps:
    print "kcu", o, " ", source_deps[o]
