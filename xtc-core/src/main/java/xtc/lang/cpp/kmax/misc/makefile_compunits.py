import os
import re

dir = "."
pattern = re.compile("[^ \t\n\r]+\.o")

for root, dirs, files in os.walk(dir):
  for m in [ os.path.join(root, x) for x in files \
               if x == "Makefile" or x == "Kbuild" ]:
    with open(m, 'rb') as f:
      for line in f:
        for c in pattern.findall(line):
          path = os.path.join(root,c[:-2] + ".c")
          if os.path.isfile(path):
            print path
