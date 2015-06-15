#!/usr/bin/env python

# Find all compilation units given a list of directories.

import sys
import os
import glob
import re
import fnmatch
import argparse
import subprocess
import cPickle as pickle

def chgext(filename, f, t):
  if filename.endswith(f):
    return filename[:-2] + t

def otoc(filename):
  return chgext(filename, ".o", ".c")

def hostprog_otoc(filename):
  """host programs don't have a .o extension, but their components
  might if it's a composite"""
  if not filename.endswith(".o"):
    filename = filename + ".o"
  return chgext(filename, ".o", ".c")

def otoS(filename):
  return chgext(filename, ".o", ".S")

def ctoo(filename):
  return chgext(filename, ".c", ".o")

def print_set(s, name):
  for elem in s:
    print name,elem
  print "size",name,len(s)

argparser = argparse.ArgumentParser(
    formatter_class=argparse.RawDescriptionHelpFormatter,
    description="""\
Find a set of configurations that covers all configuration variables in the
given Kbuild Makefile.
    """,
    epilog="""\
    """
    )
argparser.add_argument('makefile',
                       nargs="*",
                       type=str,
                       help="""the name of a Linux Makefile or subdir""")
argparser.add_argument('-D',
                       '--define',
                       action='append',
                       help="""\
define a make variable""")
argparser.add_argument('-x',
                       '--excludes-file',
                       help="""\
provides the excludes filename for reading and writing subdirectories that run \
without error""")
argparser.add_argument('-c',
                       '--correlate-c-files',
                       action="store_true",
                       help="""\
find corresponding .c files for the compilation units""")

args = argparser.parse_args()

if len(args.makefile) == 0:
  argparser.print_help()
  sys.exit(1)

excludes = set()
if args.excludes_file != None:
  if os.path.exists(args.excludes_file):
    with open(args.excludes_file, "r") as f:
      excludes = pickle.load(f)

def covering_set(kbuild_dir,        # src directory to process
                 compilation_units, # updated with units
                 library_units,     # updated with lib units
                 hostprog_units,    # updated with hostprog units
                 unconfigurable_units,    # updated with
                                          # unconfigurable units
                 extra_targets,     # updated with extra targets
                 clean_files,       # updated with clean-files units
                 c_file_targets,    # updated with c-files from targets var
                 broken):           # updated with kbuild files that
                                    # break kmax
  """Call the covering set program to find the list of compilation
  units and subdirectories added by the makefile in kbuild_dir"""
  global excludes

  if kbuild_dir in excludes:
    print "skipping", kbuild_dir
    return set()

  covering_set_args = [ "covering_set.py",
                        "-p",
                        # TODO default to empty variable
                        # "-Dobj=" + kbuild_dir,    # drivers/scsi/aic7xxx/
                        # "-DKERNELDIR=",           # drivers/staging/wlags49_h25/
                        # "-Dsrc=",                 # drivers/staging/wlags49_h25/
                        # "-Dlibservices=",         # drivers/staging/tidspbridge/
                        # "-DPWD=",                 # drivers/staging/rts5139/
                        # "-DGCOV=",                # drivers/scsi/lpfc/
                        # "-DDBGDEF=",              # drivers/net/wan/lmc/
                        # "-DACPI_FUTURE_USAGE=",   # drivers/acpi/acpica/
                        ]

  if args.define != None:
    for define in args.define:
      covering_set_args.append("-D" + define)

  covering_set_args.append(kbuild_dir)

  p = subprocess.Popen(covering_set_args,
                       stdout=subprocess.PIPE,
                       # stderr=subprocess.PIPE
                       )
  out, err = p.communicate()

  if p.returncode != 0:
    broken.add(kbuild_dir)
    return set()

  excludes.add(kbuild_dir)
    
  (new_compilation_units,
   new_library_units,
   new_hostprog_units,
   new_unconfigurable_units,
   new_extra_targets,
   new_clean_files,
   new_c_file_targets,
   new_pending_subdirectories) = pickle.loads(out)

  compilation_units.update(new_compilation_units)
  library_units.update(new_library_units)
  hostprog_units.update(new_hostprog_units)
  unconfigurable_units.update(new_unconfigurable_units)
  extra_targets.update(new_extra_targets)
  clean_files.update(new_clean_files)
  c_file_targets.update(new_c_file_targets)

  return new_pending_subdirectories

compilation_units = set()
subdirectories = set()
library_units = set()
hostprog_units = set()
unconfigurable_units = set()
extra_targets = set()
clean_files = set()
c_file_targets = set()
pending_subdirectories = set()
broken = set()

# find all compilation_units.  run covering_set.py until no more
# Kbuild subdirectories are left.
pending_subdirectories.update(args.makefile)
while len(pending_subdirectories) > 0:
  subdirectories.update(pending_subdirectories)
  pending_subdirectories.update(covering_set(pending_subdirectories.pop(),
                                             compilation_units,
                                             library_units,
                                             hostprog_units,
                                             unconfigurable_units,
                                             extra_targets,
                                             clean_files,
                                             c_file_targets,
                                             broken))

# find all .c files
all_c_files = set()
for subdir in subdirectories:
  all_c_files.update(glob.glob(os.path.join(subdir, "*.c")))

# find all compilation units without a corresponding .c file
unmatched_units = set()
for unit in compilation_units:
  c_file = otoc(unit)
  S_file = otoS(unit)
  if not os.path.isfile(c_file) and not os.path.isfile(S_file):
    unmatched_units.add(c_file)

# find all .c files without a corresponding compilation unit, starting
# with all c files
unidentified_c_files = set(all_c_files)

# remove kernel compilation units
unidentified_c_files.difference_update([otoc(filename)
                                     for filename in compilation_units])

# remove library compilation units
unidentified_c_files.difference_update([otoc(filename)
                                     for filename in library_units])

# remove hostprog compilation units
unidentified_c_files.difference_update([hostprog_otoc(filename)
                                     for filename in hostprog_units])

# remove unconfigurable compilation units
unidentified_c_files.difference_update([hostprog_otoc(filename)
                                     for filename in unconfigurable_units])

# remove unconfigurable compilation units
unidentified_c_files.difference_update([hostprog_otoc(filename)
                                     for filename in extra_targets])

# remove unconfigurable compilation units
unidentified_c_files.difference_update([filename
                                     for filename in clean_files])

# get source files that include c files
included_c_files = set()
p = subprocess.Popen(r'find . -name "*.[c|h]" | xargs grep -H "^#.*include.*\.c[\">]"',
                     shell=True,
                     stdout=subprocess.PIPE)
out, _ = p.communicate()
for line in out.split("\n"):
  parts = line.split(":", 1)
  if parts is not None:
    infile = parts[0]
    if len(parts) > 1:
      m = re.search(r"\".*\.c\"", parts[1])
      if m is not None:
        included = m.group(0)[1:-1]
        included = os.path.join(os.path.dirname(infile), included)
        included = os.path.relpath(os.path.realpath(included))
        included_c_files.add(included)

# only need the files in the current source subtree
included_c_files.intersection_update(all_c_files)

# remove .c files that aren't compilation units, because they are
# included in other c files
unidentified_c_files.difference_update(included_c_files)

# separate out .c files from the staging directory, which can be a
# mess
unidentified_staging_c_files = [ x for x in unidentified_c_files
                              if "drivers/staging" in os.path.dirname(x) ]

unidentified_c_files.difference_update(unidentified_staging_c_files)

# separate out .c files with "skeleton" in their name.  this is a
# heuristic to find example drivers that aren't actually compiled.
unidentified_skeleton_c_files = [ x for x in unidentified_c_files
                               if "skeleton" in os.path.basename(x) ]

unidentified_c_files.difference_update(unidentified_skeleton_c_files)

# separate out generators heuristically.  look for "mk" or
# "gen[^a-zA-Z]" in their name

# perhaps we can find generators a better way, e.g., by looking for
# the c file in the makefile

# look for unexpanded variables or function calls
re_unexpanded = re.compile(r'.*\$\(.*\).*')
unexpanded_compilation_units = [ x for x in compilation_units
                                 if re_unexpanded.match(x) ]
unexpanded_library_units = [ x for x in library_units
                             if re_unexpanded.match(x) ]
unexpanded_hostprog_units = [ x for x in hostprog_units
                              if re_unexpanded.match(x) ]
unexpanded_unconfigurable_units = [ x for x in unconfigurable_units
                                    if re_unexpanded.match(x) ]
unexpanded_extra_targets = [ x for x in extra_targets
                                 if re_unexpanded.match(x) ]
unexpanded_clean_files = [ x for x in clean_files
                             if re_unexpanded.match(x) ]
unexpanded_subdirectories = [ x for x in subdirectories
                              if re_unexpanded.match(x) ]

# remove compilation units with unexpanded variable names
unmatched_units.difference_update([ otoc(x)
                                    for x in unexpanded_compilation_units ])

# remove library units with unexpanded variable names
unmatched_units.difference_update([ otoc(x)
                                    for x in unexpanded_library_units ])

# remove hostprog units with unexpanded variable names
unmatched_units.difference_update([ hostprog_otoc(x)
                                    for x in unexpanded_hostprog_units ])

# remove unconfigurable units with unexpanded variable names
unmatched_units.difference_update([ hostprog_otoc(x)
                                    for x in unexpanded_unconfigurable_units ])

# remove extra targets with unexpanded variable names
unmatched_units.difference_update([ hostprog_otoc(x)
                                    for x in unexpanded_extra_targets ])

# remove clean targets with unexpanded variable names
unmatched_units.difference_update([ hostprog_otoc(x)
                                    for x in unexpanded_clean_files ])

# remove c files specified in the clean-files and in targets, since
# these can be auto-generated c files
generated_c_files = set([])
for c in (clean_files | c_file_targets):
  pattern = re.compile(fnmatch.translate(c))
  for filename in unmatched_units:
    if pattern.match(filename):
      generated_c_files.add(filename)
unmatched_units.difference_update(generated_c_files)

# cache the list of working kbuild files
if args.excludes_file != None:
  with open(args.excludes_file, "w") as f:
    pickle.dump(excludes, f)

print_set(subdirectories, "subdirectory")
print_set(compilation_units, "compilation_units")
print_set(library_units, "library_units")
print_set(hostprog_units, "hostprog_units")
print_set(unconfigurable_units, "unconfigurable_units")
print_set(extra_targets, "extra_targets")
print_set(clean_files, "clean_files")
print_set(generated_c_files, "generated_c_files")
print_set(unmatched_units, "unmatched_units")
print_set(included_c_files, "included_c_files")
print_set(unidentified_c_files, "unidentified_c_files")
print_set(unidentified_staging_c_files, "unidentified_staging_c_files")
print_set(unidentified_skeleton_c_files, "unidentified_skeleton_c_files")
print_set(unexpanded_compilation_units, "unexpanded_compilation_units")
print_set(unexpanded_library_units, "unexpanded_library_units")
print_set(unexpanded_hostprog_units, "unexpanded_hostprog_units")
print_set(unexpanded_unconfigurable_units, "unexpanded_unconfigurable_units")
print_set(unexpanded_extra_targets, "unexpanded_extra_targets")
print_set(unexpanded_subdirectories, "unexpanded_subdirectories")
print_set(broken, "broken")
