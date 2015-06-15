# Makefile 2 
#***************************************************************************
# 
# Java development root directory.
# 
# (C) 1999 Jacob Dreyer - Geotechnical Software Services
# jacob.dreyer@geosoft.no - http://geosoft.no
#
# Modifications Copyright (C) 2001, 2004 Robert Grimm 
# rgrimm@alum.mit.edu
#
# Modifications Copyright (C) 2007 New York University
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
#***************************************************************************




#***************************************************************************
#
# This section describes the current package.
#
# o PACKAGE     - The complete package name. 
# o PACKAGE_LOC - Same as PACKAGE but with "/"s instead of "."s.
# o SOURCE      - List of the source files. Remember extension.
# o JNI_SOURCE  - Files from SOURCE that are to be built with the JAVAH 
#                 compiler.
# o JAR_EXTRAS  - None-class files and directories that are to be bundled
#                 into the jar archive.
#
#***************************************************************************

PACKAGE     = xtc.lang.cpp
PACKAGE_LOC = xtc/lang/cpp

SOURCE = \
	BuiltinsGenerator.java \
	Builtins.java \
	PresenceConditionManager.java \
	Syntax.java \
	ParseTables.java \
	SemanticValues.java \
	SemanticActions.java \
	ParsingContext.java \
	GenerateValuesClass.java \
	GenerateActionsClass.java \
	DirectiveParser.java \
	HeaderFileManager.java \
	MacroTable.java \
	Preprocessor.java \
	ForkMergeParser.java \
	TokenFilter.java \
	FilenameService.java \
	StreamTimer.java \
	StopWatch.java \
	ExpressionParseTables.java \
	ExpressionSemanticValues.java \
	ExpressionActionsInterface.java \
	ExpressionActions.java \
	ExpressionRats.java \
	TreeComparator.java \
	ExpressionParser.java \
	ConditionEvaluator.java \
	CTag.java \
	CLexer.java \
	CParseTables.java \
	CTokenCreator.java \
	CSemanticValues.java \
	CActionsInterface.java \
	CSemanticActions.java \
	CParsingContext.java \
	GCCShunt.java \
	cdiff.java \
	SuperC.java


JNI_SOURCE =

JAR_EXTRAS =


#***************************************************************************
#
# Include common part of makefile
#
#***************************************************************************

ifdef JAVA_DEV_ROOT
include $(JAVA_DEV_ROOT)/Makerules

manual: manual.pdf

manual.pdf: manual.tex
	pdflatex manual.tex
	pdflatex manual.tex
	pdflatex manual.tex

configure:
	if [ -f Builtins.java ]; then $(RM) Builtins.java; fi
	$(MAKE) BuiltinsGenerator.class
	$(MAKE) Builtins.java
	$(MAKE) Builtins.class
	if [ -f ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/SuperC.class ]; then $(RM) ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/SuperC.class; $(MAKE) SuperC.class; fi

Builtins.java:
	$(CPP) $(CPPFLAGS) -v empty.c 2> sysdirs > /dev/null
	$(CPP) $(CPPFLAGS) -dM empty.c > builtins 2> /dev/null
	$(JAVA) xtc.lang.cpp.BuiltinsGenerator sysdirs builtins > Builtins.java
	$(RM) sysdirs
	$(RM) builtins

parsers:
	@# c parse tables
	bison -o c.tab.c c.y
	$(CC) $(CFLAGS) -DBISON_PARSER_FILE=c.tab.c -DCLASS_NAME=CParseTables -o gen_c_tables gen_tables.c
	./gen_c_tables > CParseTables.java
	$(RM) gen_c_tables
	$(MAKE) CParseTables.class
	@#
	@# C lexer and token tags
	$(CPP) $(CPPFLAGS) -DLANGUAGE_TAGS - < c.l | grep -v "^#" > CTag.java
	$(MAKE) CTag.class
	@#
	@# lexer
	@#   filter out line directives for java compilation
	$(CPP) $(CPPFLAGS) - < c.l | grep -v "^#" > c.l.lexer
	$(JAVA) -jar $(JAVA_DEV_ROOT)/bin/JFlex.jar c.l.lexer
	$(RM) c.l.lexer
	$(MAKE) CLexer.class
	@#
	@# C semantic actions
	$(MAKE) GenerateValuesClass.class
	./extract_annotations.pl < c.y | $(JAVA) xtc.lang.cpp.GenerateValuesClass CSemanticValues xtc.lang.cpp.CParseTables > CSemanticValues.java
	$(MAKE) GenerateActionsClass.class
	./extract_annotations.pl < c.y | $(JAVA) xtc.lang.cpp.GenerateActionsClass CActionsInterface xtc.lang.cpp.CParseTables > CActionsInterface.java
	$(MAKE) CSemanticValues.class
	$(MAKE) CActionsInterface.class
	@#
	@# expression parser
	bison -o expression.tab.c expression.y
	$(CC) $(CFLAGS) -DBISON_PARSER_FILE=expression.tab.c -DCLASS_NAME=ExpressionParseTables -o gen_expression_tables gen_tables.c
	./gen_expression_tables > ExpressionParseTables.java
	$(RM) gen_expression_tables
	$(MAKE) ExpressionParseTables.class
	@#
	./extract_annotations.pl < expression.y | $(JAVA) xtc.lang.cpp.GenerateValuesClass ExpressionSemanticValues xtc.lang.cpp.ExpressionParseTables > ExpressionSemanticValues.java
	./extract_annotations.pl < expression.y | $(JAVA) xtc.lang.cpp.GenerateActionsClass ExpressionActionsInterface xtc.lang.cpp.ExpressionParseTables > ExpressionActionsInterface.java
	$(MAKE) ExpressionSemanticValues.class
	$(MAKE) ExpressionActionsInterface.class
	@#
	@# expression parser (rats)
	$(RATS) -option 'parser(xtc.lang.cpp.ExpressionRats)' Condition.rats
	$(MAKE) ExpressionRats.class
	$(RM) ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/ForkMergeParser.class
	$(MAKE) ForkMergeParser.class

clobber-parsers :
	$(RM) CLexer.java
	$(RM) c.tab.c
	$(RM) CActionsBase.java
	$(RM) ExpressionRats.java

endif
