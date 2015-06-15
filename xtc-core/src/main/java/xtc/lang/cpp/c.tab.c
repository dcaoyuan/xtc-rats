/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


/* Line 268 of yacc.c  */
#line 71 "c.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     DOUBLE = 259,
     INT = 260,
     STRUCT = 261,
     BREAK = 262,
     ELSE = 263,
     LONG = 264,
     SWITCH = 265,
     CASE = 266,
     ENUM = 267,
     REGISTER = 268,
     TYPEDEF = 269,
     CHAR = 270,
     EXTERN = 271,
     RETURN = 272,
     UNION = 273,
     CONST = 274,
     FLOAT = 275,
     SHORT = 276,
     UNSIGNED = 277,
     CONTINUE = 278,
     FOR = 279,
     SIGNED = 280,
     VOID = 281,
     DEFAULT = 282,
     GOTO = 283,
     SIZEOF = 284,
     VOLATILE = 285,
     DO = 286,
     IF = 287,
     STATIC = 288,
     WHILE = 289,
     IDENTIFIER = 290,
     STRINGliteral = 291,
     FLOATINGconstant = 292,
     INTEGERconstant = 293,
     CHARACTERconstant = 294,
     OCTALconstant = 295,
     HEXconstant = 296,
     TYPEDEFname = 297,
     ARROW = 298,
     ICR = 299,
     DECR = 300,
     LS = 301,
     RS = 302,
     LE = 303,
     GE = 304,
     EQ = 305,
     NE = 306,
     ANDAND = 307,
     OROR = 308,
     ELLIPSIS = 309,
     MULTassign = 310,
     DIVassign = 311,
     MODassign = 312,
     PLUSassign = 313,
     MINUSassign = 314,
     LSassign = 315,
     RSassign = 316,
     ANDassign = 317,
     ERassign = 318,
     ORassign = 319,
     LPAREN = 320,
     RPAREN = 321,
     COMMA = 322,
     HASH = 323,
     DHASH = 324,
     LBRACE = 325,
     RBRACE = 326,
     LBRACK = 327,
     RBRACK = 328,
     DOT = 329,
     AND = 330,
     STAR = 331,
     PLUS = 332,
     MINUS = 333,
     NEGATE = 334,
     NOT = 335,
     DIV = 336,
     MOD = 337,
     LT = 338,
     GT = 339,
     XOR = 340,
     PIPE = 341,
     QUESTION = 342,
     COLON = 343,
     SEMICOLON = 344,
     ASSIGN = 345,
     ASMSYM = 346,
     _BOOL = 347,
     _COMPLEX = 348,
     RESTRICT = 349,
     __ALIGNOF = 350,
     __ALIGNOF__ = 351,
     ASM = 352,
     __ASM = 353,
     __ASM__ = 354,
     AT = 355,
     USD = 356,
     __ATTRIBUTE = 357,
     __ATTRIBUTE__ = 358,
     __BUILTIN_OFFSETOF = 359,
     __BUILTIN_TYPES_COMPATIBLE_P = 360,
     __BUILTIN_VA_ARG = 361,
     __BUILTIN_VA_LIST = 362,
     __COMPLEX__ = 363,
     __CONST = 364,
     __CONST__ = 365,
     __EXTENSION__ = 366,
     INLINE = 367,
     __INLINE = 368,
     __INLINE__ = 369,
     __LABEL__ = 370,
     __RESTRICT = 371,
     __RESTRICT__ = 372,
     __SIGNED = 373,
     __SIGNED__ = 374,
     __THREAD = 375,
     TYPEOF = 376,
     __TYPEOF = 377,
     __TYPEOF__ = 378,
     __VOLATILE = 379,
     __VOLATILE__ = 380,
     PPNUM = 381,
     BACKSLASH = 382
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 240 "c.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5020

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  191
/* YYNRULES -- Number of rules.  */
#define YYNRULES  578
/* YYNRULES -- Number of states.  */
#define YYNSTATES  960

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   382

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      19,    21,    24,    31,    39,    42,    45,    49,    53,    57,
      61,    64,    68,    72,    76,    80,    83,    87,    91,    95,
      99,   107,   116,   120,   124,   128,   132,   136,   140,   144,
     148,   152,   156,   160,   164,   166,   169,   173,   177,   181,
     185,   192,   199,   208,   215,   222,   231,   233,   235,   237,
     239,   241,   243,   245,   247,   249,   251,   253,   256,   259,
     261,   264,   266,   268,   270,   272,   274,   276,   278,   280,
     282,   284,   286,   288,   290,   292,   294,   296,   298,   300,
     302,   305,   308,   311,   314,   316,   319,   322,   325,   328,
     331,   334,   336,   339,   342,   345,   348,   351,   353,   356,
     359,   362,   365,   368,   371,   373,   376,   379,   382,   387,
     392,   394,   396,   398,   401,   404,   407,   410,   412,   415,
     418,   421,   423,   425,   427,   429,   431,   433,   435,   437,
     439,   441,   443,   445,   447,   449,   451,   453,   455,   457,
     459,   461,   463,   465,   467,   469,   476,   484,   487,   495,
     504,   508,   510,   512,   513,   516,   519,   522,   525,   528,
     530,   534,   539,   543,   548,   551,   553,   556,   558,   559,
     561,   564,   569,   575,   578,   584,   591,   597,   604,   608,
     615,   623,   625,   629,   633,   637,   638,   641,   643,   647,
     649,   653,   655,   658,   663,   668,   670,   673,   678,   680,
     683,   688,   693,   695,   698,   703,   705,   709,   712,   714,
     716,   718,   721,   723,   726,   727,   730,   732,   735,   739,
     744,   746,   748,   751,   752,   756,   759,   761,   763,   765,
     768,   772,   778,   781,   784,   788,   794,   797,   799,   801,
     803,   805,   807,   809,   812,   814,   816,   819,   823,   827,
     832,   834,   839,   845,   848,   852,   856,   861,   866,   868,
     872,   874,   876,   878,   880,   883,   887,   889,   891,   893,
     898,   902,   905,   911,   914,   916,   920,   922,   924,   927,
     931,   938,   942,   947,   949,   951,   953,   955,   961,   962,
     964,   967,   971,   976,   978,   981,   984,   988,   992,   996,
    1000,  1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1024,
    1029,  1036,  1040,  1045,  1046,  1048,  1050,  1053,  1057,  1059,
    1063,  1064,  1067,  1069,  1071,  1073,  1075,  1078,  1081,  1087,
    1095,  1101,  1107,  1115,  1125,  1127,  1129,  1131,  1133,  1137,
    1142,  1145,  1148,  1152,  1154,  1156,  1158,  1160,  1162,  1164,
    1167,  1169,  1171,  1173,  1177,  1179,  1181,  1183,  1190,  1196,
    1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1217,  1221,
    1226,  1230,  1234,  1237,  1240,  1247,  1249,  1253,  1255,  1258,
    1261,  1264,  1267,  1272,  1274,  1276,  1278,  1280,  1282,  1289,
    1296,  1299,  1304,  1307,  1309,  1311,  1314,  1316,  1318,  1320,
    1322,  1324,  1326,  1328,  1333,  1335,  1339,  1343,  1347,  1349,
    1353,  1357,  1359,  1363,  1367,  1369,  1373,  1377,  1381,  1385,
    1387,  1391,  1395,  1397,  1401,  1403,  1407,  1409,  1413,  1415,
    1419,  1421,  1425,  1427,  1433,  1438,  1440,  1444,  1446,  1448,
    1450,  1452,  1454,  1456,  1458,  1460,  1462,  1464,  1466,  1467,
    1469,  1471,  1475,  1477,  1478,  1480,  1482,  1485,  1492,  1494,
    1496,  1497,  1499,  1502,  1507,  1508,  1511,  1515,  1517,  1519,
    1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,  1537,  1539,
    1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,  1559,
    1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,  1577,  1579,
    1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,  1597,  1599,
    1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,  1619,
    1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,  1637,  1639,
    1641,  1643,  1645,  1647,  1650,  1655,  1656,  1658,  1664,  1671,
    1678,  1686,  1692,  1696,  1698,  1699,  1701,  1703,  1707,  1712,
    1720,  1721,  1723,  1725,  1729,  1739,  1741,  1745,  1747,  1749,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     129,     0,    -1,   130,    -1,    -1,   130,   131,    -1,   133,
      -1,   141,    -1,   297,    -1,   132,    -1,    89,    -1,   134,
      -1,   111,   134,    -1,   136,   317,    70,   135,   315,    71,
      -1,   137,   317,   240,    70,   135,   315,    71,    -1,   234,
     238,    -1,   213,   312,    -1,   145,   213,   310,    -1,   146,
     213,   310,    -1,   147,   213,   310,    -1,   148,   213,   310,
      -1,   223,   312,    -1,   145,   223,   310,    -1,   146,   223,
     310,    -1,   147,   223,   310,    -1,   148,   223,   310,    -1,
     223,   312,    -1,   145,   223,   310,    -1,   146,   223,   310,
      -1,   147,   223,   310,    -1,   148,   223,   310,    -1,   139,
     317,    70,   234,   238,   315,    71,    -1,   140,   317,   240,
      70,   234,   238,   315,    71,    -1,   145,   213,   310,    -1,
     146,   213,   310,    -1,   147,   213,   310,    -1,   148,   213,
     310,    -1,   145,   223,   310,    -1,   146,   223,   310,    -1,
     147,   223,   310,    -1,   148,   223,   310,    -1,   145,   223,
     310,    -1,   146,   223,   310,    -1,   147,   223,   310,    -1,
     148,   223,   310,    -1,   142,    -1,   111,   142,    -1,   157,
     318,    89,    -1,   158,   318,    89,    -1,   144,   318,    89,
      -1,   143,   318,    89,    -1,   147,   213,   310,   299,   289,
     194,    -1,   148,   213,   310,   299,   289,   194,    -1,   143,
      67,   289,   213,   311,   299,   289,   194,    -1,   145,   204,
     310,   299,   289,   194,    -1,   146,   204,   310,   299,   289,
     194,    -1,   144,    67,   289,   204,   311,   299,   289,   194,
      -1,   155,    -1,   157,    -1,   159,    -1,   165,    -1,   161,
      -1,   156,    -1,   158,    -1,   160,    -1,   166,    -1,   162,
      -1,   168,    -1,   148,   168,    -1,   147,   149,    -1,   150,
      -1,   148,   150,    -1,   150,    -1,   168,    -1,   151,    -1,
     152,    -1,   153,    -1,   291,    -1,   154,    -1,    19,    -1,
     109,    -1,   110,    -1,    30,    -1,   124,    -1,   125,    -1,
      94,    -1,   116,    -1,   117,    -1,   112,    -1,   113,    -1,
     114,    -1,   156,   168,    -1,   147,   169,    -1,   155,   149,
      -1,   155,   169,    -1,   169,    -1,   148,   169,    -1,   156,
     150,    -1,   156,   169,    -1,   158,   168,    -1,   147,   172,
      -1,   157,   149,    -1,   172,    -1,   148,   172,    -1,   158,
     150,    -1,   160,   168,    -1,   147,    42,    -1,   159,   149,
      -1,    42,    -1,   148,    42,    -1,   160,   150,    -1,   162,
     168,    -1,   147,   163,    -1,   161,   149,    -1,   161,   163,
      -1,   163,    -1,   148,   163,    -1,   162,   150,    -1,   162,
     163,    -1,   164,    65,   193,    66,    -1,   164,    65,   287,
      66,    -1,   121,    -1,   122,    -1,   123,    -1,   166,   168,
      -1,   147,   167,    -1,   165,   149,    -1,   165,   167,    -1,
     167,    -1,   148,   167,    -1,   166,   150,    -1,   166,   167,
      -1,   107,    -1,    14,    -1,    16,    -1,    33,    -1,     3,
      -1,    13,    -1,    26,    -1,    15,    -1,    21,    -1,     5,
      -1,     9,    -1,    20,    -1,     4,    -1,   170,    -1,    22,
      -1,    92,    -1,   171,    -1,    25,    -1,   118,    -1,   119,
      -1,    93,    -1,   108,    -1,   173,    -1,   183,    -1,   174,
     314,    70,   175,   315,    71,    -1,   174,   192,   314,    70,
     175,   315,    71,    -1,   174,   192,    -1,   174,   290,   314,
      70,   175,   315,    71,    -1,   174,   290,   192,   314,    70,
     175,   315,    71,    -1,   174,   290,   192,    -1,     6,    -1,
      18,    -1,    -1,   175,   176,    -1,   178,    89,    -1,   177,
      89,    -1,   148,    89,    -1,   146,    89,    -1,    89,    -1,
     148,   180,   289,    -1,   177,    67,   180,   289,    -1,   146,
     179,   289,    -1,   178,    67,   179,   289,    -1,   204,   181,
      -1,   182,    -1,   213,   181,    -1,   182,    -1,    -1,   182,
      -1,    88,   288,    -1,    12,    70,   184,    71,    -1,    12,
     192,    70,   184,    71,    -1,    12,   192,    -1,    12,    70,
     184,    67,    71,    -1,    12,   192,    70,   184,    67,    71,
      -1,    12,   290,    70,   184,    71,    -1,    12,   290,   192,
      70,   184,    71,    -1,    12,   290,   192,    -1,    12,   290,
      70,   184,    67,    71,    -1,    12,   290,   192,    70,   184,
      67,    71,    -1,   185,    -1,   184,    67,   185,    -1,    35,
     313,   186,    -1,    42,   313,   186,    -1,    -1,    90,   288,
      -1,   188,    -1,   188,    67,    54,    -1,   189,    -1,   188,
      67,   189,    -1,   145,    -1,   145,   225,    -1,   145,   213,
     310,   289,    -1,   145,   207,   310,   289,    -1,   147,    -1,
     147,   225,    -1,   147,   213,   310,   289,    -1,   146,    -1,
     146,   225,    -1,   146,   213,   310,   289,    -1,   146,   207,
     310,   289,    -1,   148,    -1,   148,   225,    -1,   148,   213,
     310,   289,    -1,   191,    -1,   190,    67,   191,    -1,    35,
     312,    -1,    35,    -1,    42,    -1,   146,    -1,   146,   225,
      -1,   148,    -1,   148,   225,    -1,    -1,    90,   195,    -1,
     196,    -1,   199,   196,    -1,    70,   198,    71,    -1,    70,
     198,   195,    71,    -1,   284,    -1,   198,    -1,   198,   195,
      -1,    -1,   198,   195,    67,    -1,   200,    90,    -1,   202,
      -1,   203,    -1,   201,    -1,   200,   201,    -1,    72,   288,
      73,    -1,    72,   288,    54,   288,    73,    -1,    74,    35,
      -1,    74,    42,    -1,    72,   288,    73,    -1,    72,   288,
      54,   288,    73,    -1,    35,    88,    -1,   205,    -1,   213,
      -1,   206,    -1,   210,    -1,   207,    -1,    42,    -1,    42,
     226,    -1,   208,    -1,   209,    -1,    76,   207,    -1,    76,
     148,   207,    -1,    65,   208,    66,    -1,    65,   208,    66,
     226,    -1,   211,    -1,    76,    65,   212,    66,    -1,    76,
     148,    65,   212,    66,    -1,    76,   210,    -1,    76,   148,
     210,    -1,    65,   210,    66,    -1,    65,   212,   226,    66,
      -1,    65,   210,    66,   226,    -1,    42,    -1,    65,   212,
      66,    -1,   214,    -1,   215,    -1,   221,    -1,   216,    -1,
      76,   213,    -1,    76,   148,   213,    -1,   218,    -1,   220,
      -1,   217,    -1,    65,   215,    66,   226,    -1,    65,   215,
      66,    -1,   221,   219,    -1,    65,   314,   227,   316,    66,
      -1,   221,   228,    -1,   222,    -1,    65,   221,    66,    -1,
      35,    -1,   224,    -1,    76,   223,    -1,    76,   148,   223,
      -1,   221,    65,   314,   190,   316,    66,    -1,    65,   223,
      66,    -1,    65,   223,    66,   226,    -1,   229,    -1,   230,
      -1,   226,    -1,   228,    -1,    65,   314,   227,   316,    66,
      -1,    -1,   187,    -1,    72,    73,    -1,    72,   288,    73,
      -1,   228,    72,   288,    73,    -1,    76,    -1,    76,   148,
      -1,    76,   225,    -1,    76,   148,   225,    -1,    65,   229,
      66,    -1,    65,   230,    66,    -1,    65,   226,    66,    -1,
      65,   229,    66,   226,    -1,   232,    -1,   233,    -1,   241,
      -1,   242,    -1,   243,    -1,   244,    -1,   300,    -1,   192,
      88,   289,   231,    -1,    11,   288,    88,   231,    -1,    11,
     288,    54,   288,    88,   231,    -1,    27,    88,   231,    -1,
      70,   234,   238,    71,    -1,    -1,   235,    -1,   236,    -1,
     235,   236,    -1,   115,   237,    89,    -1,    35,    -1,   237,
      67,    35,    -1,    -1,   238,   239,    -1,   141,    -1,   231,
      -1,   138,    -1,   141,    -1,   240,   141,    -1,   286,    89,
      -1,    32,    65,   287,    66,   231,    -1,    32,    65,   287,
      66,   231,     8,   231,    -1,    10,    65,   287,    66,   231,
      -1,    34,    65,   287,    66,   231,    -1,    31,   231,    34,
      65,   287,    66,    89,    -1,    24,    65,   286,    89,   286,
      89,   286,    66,   231,    -1,   245,    -1,   246,    -1,   247,
      -1,   248,    -1,    28,   192,    89,    -1,    28,    76,   287,
      89,    -1,    23,    89,    -1,     7,    89,    -1,    17,   286,
      89,    -1,    37,    -1,    38,    -1,    40,    -1,    41,    -1,
      39,    -1,    36,    -1,   250,    36,    -1,   252,    -1,   249,
      -1,   250,    -1,    65,   287,    66,    -1,   254,    -1,   253,
      -1,    35,    -1,   106,    65,   284,    67,   193,    66,    -1,
      65,   314,   233,   315,    66,    -1,   251,    -1,   256,    -1,
     257,    -1,   258,    -1,   259,    -1,   260,    -1,   261,    -1,
     262,    -1,   255,    72,   287,    73,    -1,   255,    65,    66,
      -1,   255,    65,   263,    66,    -1,   255,    74,   192,    -1,
     255,    43,   192,    -1,   255,    44,    -1,   255,    45,    -1,
      65,   193,    66,    70,   197,    71,    -1,   284,    -1,   263,
      67,   284,    -1,   255,    -1,    44,   264,    -1,    45,   264,
      -1,   271,   272,    -1,    29,   264,    -1,    29,    65,   193,
      66,    -1,   270,    -1,   268,    -1,   267,    -1,   266,    -1,
     265,    -1,   105,    65,   193,    67,   193,    66,    -1,   104,
      65,   193,    67,   255,    66,    -1,   111,   272,    -1,   269,
      65,   193,    66,    -1,   269,   264,    -1,    96,    -1,    95,
      -1,    52,    35,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,   264,    -1,    65,   193,
      66,   272,    -1,   272,    -1,   273,    76,   272,    -1,   273,
      81,   272,    -1,   273,    82,   272,    -1,   273,    -1,   274,
      77,   273,    -1,   274,    78,   273,    -1,   274,    -1,   275,
      46,   274,    -1,   275,    47,   274,    -1,   275,    -1,   276,
      83,   275,    -1,   276,    84,   275,    -1,   276,    48,   275,
      -1,   276,    49,   275,    -1,   276,    -1,   277,    50,   276,
      -1,   277,    51,   276,    -1,   277,    -1,   278,    75,   277,
      -1,   278,    -1,   279,    85,   278,    -1,   279,    -1,   280,
      86,   279,    -1,   280,    -1,   281,    52,   280,    -1,   281,
      -1,   282,    53,   281,    -1,   282,    -1,   282,    87,   287,
      88,   283,    -1,   282,    87,    88,   283,    -1,   283,    -1,
     264,   285,   284,    -1,    90,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    64,    -1,    -1,   287,    -1,   284,
      -1,   287,    67,   284,    -1,   283,    -1,    -1,   290,    -1,
     291,    -1,   290,   291,    -1,   292,    65,    65,   293,    66,
      66,    -1,   102,    -1,   103,    -1,    -1,   294,    -1,   296,
     295,    -1,   294,    67,   296,   295,    -1,    -1,    65,    66,
      -1,    65,   263,    66,    -1,    35,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,   102,
      -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,
      -1,   118,    -1,   119,    -1,   120,    -1,   121,    -1,   122,
      -1,   123,    -1,   124,    -1,   125,    -1,   298,    89,    -1,
     309,    65,   250,    66,    -1,    -1,   298,    -1,   309,    65,
     301,    66,    89,    -1,   309,    28,    65,   307,    66,    89,
      -1,   309,   150,    65,   301,    66,    89,    -1,   250,    88,
     302,    88,   302,    88,   306,    -1,   250,    88,   302,    88,
     302,    -1,   250,    88,   302,    -1,   250,    -1,    -1,   303,
      -1,   304,    -1,   303,    67,   304,    -1,   250,    65,   287,
      66,    -1,    72,   296,    73,   250,    65,   287,    66,    -1,
      -1,   306,    -1,   250,    -1,   306,    67,   250,    -1,   250,
      88,   302,    88,   302,    88,   305,    88,   308,    -1,   191,
      -1,   308,    67,   191,    -1,    97,    -1,    98,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   173,   175,   179,   180,   181,   182,   186,
     190,   191,   195,   196,   202,   210,   211,   212,   213,   214,
     216,   217,   218,   219,   220,   224,   225,   226,   227,   228,
     235,   236,   240,   241,   242,   243,   245,   246,   247,   248,
     252,   253,   254,   255,   291,   292,   296,   297,   298,   299,
     306,   307,   308,   312,   313,   314,   318,   319,   320,   321,
     322,   326,   327,   328,   329,   330,   334,   335,   336,   340,
     341,   345,   346,   350,   351,   352,   353,   354,   358,   359,
     360,   364,   365,   366,   370,   371,   372,   376,   377,   378,
     382,   383,   384,   385,   389,   390,   391,   392,   396,   397,
     398,   402,   403,   404,   409,   410,   411,   415,   416,   417,
     421,   422,   423,   424,   428,   429,   430,   431,   435,   436,
     440,   441,   442,   446,   447,   448,   449,   453,   454,   455,
     456,   460,   464,   465,   466,   467,   468,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   486,   487,
     488,   492,   493,   497,   498,   502,   503,   505,   506,   507,
     509,   513,   514,   517,   519,   523,   524,   525,   526,   527,
     531,   532,   536,   537,   542,   543,   547,   548,   551,   553,
     557,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   579,   580,   584,   585,   588,   590,   594,   595,   599,
     600,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   625,   626,   630,   634,   635,
     639,   640,   641,   642,   645,   647,   651,   652,   661,   662,
     663,   667,   668,   671,   672,   676,   677,   678,   682,   683,
     687,   688,   689,   690,   694,   695,   699,   703,   704,   708,
     712,   713,   717,   718,   719,   726,   727,   728,   732,   733,
     740,   741,   742,   744,   745,   749,   750,   751,   755,   756,
     760,   764,   765,   769,   770,   771,   775,   776,   777,   778,
     782,   786,   790,   794,   798,   799,   803,   807,   808,   809,
     813,   814,   815,   819,   820,   821,   825,   826,   829,   831,
     835,   836,   837,   841,   842,   843,   844,   848,   849,   850,
     851,   857,   858,   859,   860,   861,   862,   863,   867,   868,
     869,   870,   881,   884,   886,   890,   891,   895,   899,   900,
     903,   904,   908,   909,   910,   914,   915,   924,   928,   929,
     930,   934,   935,   936,   941,   942,   943,   944,   948,   949,
     953,   957,   961,   968,   969,   973,   974,   975,   980,   981,
     987,   988,   989,   990,   991,   992,   996,  1000,  1004,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1019,  1023,  1024,
    1028,  1032,  1036,  1040,  1048,  1052,  1053,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1071,  1075,
    1079,  1083,  1084,  1088,  1089,  1093,  1097,  1098,  1099,  1100,
    1101,  1102,  1106,  1107,  1111,  1112,  1113,  1114,  1118,  1119,
    1120,  1124,  1125,  1126,  1130,  1131,  1132,  1133,  1134,  1138,
    1139,  1140,  1144,  1145,  1149,  1150,  1154,  1155,  1159,  1160,
    1164,  1165,  1169,  1170,  1172,  1177,  1178,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1195,  1197,
    1201,  1202,  1206,  1209,  1211,  1215,  1216,  1220,  1224,  1225,
    1228,  1230,  1234,  1235,  1238,  1240,  1241,  1245,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1316,  1320,  1323,  1325,  1329,  1331,  1332,
    1336,  1337,  1338,  1339,  1342,  1344,  1348,  1349,  1353,  1354,
    1357,  1359,  1363,  1364,  1368,  1372,  1373,  1377,  1378,  1379,
    1388,  1391,  1394,  1397,  1400,  1403,  1406,  1409,  1412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "DOUBLE", "INT", "STRUCT",
  "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER", "TYPEDEF",
  "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT", "SHORT",
  "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT", "GOTO",
  "SIZEOF", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "IDENTIFIER",
  "STRINGliteral", "FLOATINGconstant", "INTEGERconstant",
  "CHARACTERconstant", "OCTALconstant", "HEXconstant", "TYPEDEFname",
  "ARROW", "ICR", "DECR", "LS", "RS", "LE", "GE", "EQ", "NE", "ANDAND",
  "OROR", "ELLIPSIS", "MULTassign", "DIVassign", "MODassign", "PLUSassign",
  "MINUSassign", "LSassign", "RSassign", "ANDassign", "ERassign",
  "ORassign", "LPAREN", "RPAREN", "COMMA", "HASH", "DHASH", "LBRACE",
  "RBRACE", "LBRACK", "RBRACK", "DOT", "AND", "STAR", "PLUS", "MINUS",
  "NEGATE", "NOT", "DIV", "MOD", "LT", "GT", "XOR", "PIPE", "QUESTION",
  "COLON", "SEMICOLON", "ASSIGN", "ASMSYM", "_BOOL", "_COMPLEX",
  "RESTRICT", "__ALIGNOF", "__ALIGNOF__", "ASM", "__ASM", "__ASM__", "AT",
  "USD", "__ATTRIBUTE", "__ATTRIBUTE__", "__BUILTIN_OFFSETOF",
  "__BUILTIN_TYPES_COMPATIBLE_P", "__BUILTIN_VA_ARG", "__BUILTIN_VA_LIST",
  "__COMPLEX__", "__CONST", "__CONST__", "__EXTENSION__", "INLINE",
  "__INLINE", "__INLINE__", "__LABEL__", "__RESTRICT", "__RESTRICT__",
  "__SIGNED", "__SIGNED__", "__THREAD", "TYPEOF", "__TYPEOF", "__TYPEOF__",
  "__VOLATILE", "__VOLATILE__", "PPNUM", "BACKSLASH", "$accept",
  "TranslationUnit", "ExternalDeclarationList", "ExternalDeclaration",
  "EmptyDefinition", "FunctionDefinitionExtension", "FunctionDefinition",
  "FunctionCompoundStatement", "FunctionPrototype", "FunctionOldPrototype",
  "NestedFunctionDefinition", "NestedFunctionPrototype",
  "NestedFunctionOldPrototype", "DeclarationExtension", "Declaration",
  "DefaultDeclaringList", "DeclaringList", "DeclarationSpecifier",
  "TypeSpecifier", "DeclarationQualifierList", "TypeQualifierList",
  "DeclarationQualifier", "TypeQualifier", "ConstQualifier",
  "VolatileQualifier", "RestrictQualifier", "FunctionSpecifier",
  "BasicDeclarationSpecifier", "BasicTypeSpecifier",
  "SUEDeclarationSpecifier", "SUETypeSpecifier",
  "TypedefDeclarationSpecifier", "TypedefTypeSpecifier",
  "TypeofDeclarationSpecifier", "TypeofTypeSpecifier", "Typeofspecifier",
  "Typeofkeyword", "VarArgDeclarationSpecifier", "VarArgTypeSpecifier",
  "VarArgTypeName", "StorageClass", "BasicTypeName", "SignedKeyword",
  "ComplexKeyword", "ElaboratedTypeName", "StructOrUnionSpecifier",
  "StructOrUnion", "StructDeclarationList", "StructDeclaration",
  "StructDefaultDeclaringList", "StructDeclaringList", "StructDeclarator",
  "StructIdentifierDeclarator", "BitFieldSizeOpt", "BitFieldSize",
  "EnumSpecifier", "EnumeratorList", "Enumerator", "EnumeratorValueOpt",
  "ParameterTypeList", "ParameterList", "ParameterDeclaration",
  "IdentifierList", "Identifier", "IdentifierOrTypedefName", "TypeName",
  "InitializerOpt", "DesignatedInitializer", "Initializer",
  "InitializerList", "MatchedInitializerList", "Designation",
  "DesignatorList", "Designator", "ObsoleteArrayDesignation",
  "ObsoleteFieldDesignation", "Declarator", "TypedefDeclarator",
  "TypedefDeclaratorMain", "ParameterTypedefDeclarator",
  "CleanTypedefDeclarator", "CleanPostfixTypedefDeclarator",
  "ParenTypedefDeclarator", "ParenPostfixTypedefDeclarator",
  "SimpleParenTypedefDeclarator", "IdentifierDeclarator",
  "IdentifierDeclaratorMain", "UnaryIdentifierDeclarator",
  "PostfixIdentifierDeclarator", "AttributedDeclarator",
  "FunctionDeclarator", "PostfixingFunctionDeclarator", "ArrayDeclarator",
  "ParenIdentifierDeclarator", "SimpleDeclarator", "OldFunctionDeclarator",
  "PostfixOldFunctionDeclarator", "AbstractDeclarator",
  "PostfixingAbstractDeclarator", "ParameterTypeListOpt",
  "ArrayAbstractDeclarator", "UnaryAbstractDeclarator",
  "PostfixAbstractDeclarator", "Statement", "LabeledStatement",
  "CompoundStatement", "LocalLabelDeclarationListOpt",
  "LocalLabelDeclarationList", "LocalLabelDeclaration", "LocalLabelList",
  "DeclarationOrStatementList", "DeclarationOrStatement",
  "DeclarationList", "ExpressionStatement", "SelectionStatement",
  "IterationStatement", "JumpStatement", "GotoStatement",
  "ContinueStatement", "BreakStatement", "ReturnStatement", "Constant",
  "StringLiteralList", "PrimaryExpression", "PrimaryIdentifier",
  "VariableArgumentAccess", "StatementAsExpression", "PostfixExpression",
  "Subscript", "FunctionCall", "DirectSelection", "IndirectSelection",
  "Increment", "Decrement", "CompoundLiteral", "ExpressionList",
  "UnaryExpression", "TypeCompatibilityExpression", "OffsetofExpression",
  "ExtensionExpression", "AlignofExpression", "Alignofkeyword",
  "LabelAddressExpression", "Unaryoperator", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression", "LogicalAndExpression",
  "LogicalORExpression", "ConditionalExpression", "AssignmentExpression",
  "AssignmentOperator", "ExpressionOpt", "Expression",
  "ConstantExpression", "AttributeSpecifierListOpt",
  "AttributeSpecifierList", "AttributeSpecifier", "AttributeKeyword",
  "AttributeListOpt", "AttributeList", "AttributeExpressionOpt", "Word",
  "AssemblyDefinition", "AssemblyExpression", "AssemblyExpressionOpt",
  "AssemblyStatement", "Assemblyargument", "AssemblyoperandsOpt",
  "Assemblyoperands", "Assemblyoperand", "AssemblyclobbersOpt",
  "Assemblyclobbers", "AssemblyGotoargument", "AssemblyJumpLabels",
  "AsmKeyword", "BindIdentifier", "BindIdentifierInList", "BindVar",
  "BindEnum", "EnterScope", "ExitScope", "ExitReentrantScope",
  "ReenterScope", "KillReentrantScope", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   128,   129,   130,   130,   131,   131,   131,   131,   132,
     133,   133,   134,   134,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   137,   137,   137,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   142,   142,
     143,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   151,   151,
     151,   152,   152,   152,   153,   153,   153,   154,   154,   154,
     155,   155,   155,   155,   156,   156,   156,   156,   157,   157,
     157,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     161,   161,   161,   161,   162,   162,   162,   162,   163,   163,
     164,   164,   164,   165,   165,   165,   165,   166,   166,   166,
     166,   167,   168,   168,   168,   168,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     170,   171,   171,   172,   172,   173,   173,   173,   173,   173,
     173,   174,   174,   175,   175,   176,   176,   176,   176,   176,
     177,   177,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   188,
     188,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   190,   190,   191,   192,   192,
     193,   193,   193,   193,   194,   194,   195,   195,   196,   196,
     196,   197,   197,   198,   198,   199,   199,   199,   200,   200,
     201,   201,   201,   201,   202,   202,   203,   204,   204,   205,
     206,   206,   207,   207,   207,   208,   208,   208,   209,   209,
     210,   210,   210,   210,   210,   211,   211,   211,   212,   212,
     213,   214,   214,   215,   215,   215,   216,   216,   216,   216,
     217,   218,   219,   220,   221,   221,   222,   223,   223,   223,
     224,   224,   224,   225,   225,   225,   226,   226,   227,   227,
     228,   228,   228,   229,   229,   229,   229,   230,   230,   230,
     230,   231,   231,   231,   231,   231,   231,   231,   232,   232,
     232,   232,   233,   234,   234,   235,   235,   236,   237,   237,
     238,   238,   239,   239,   239,   240,   240,   241,   242,   242,
     242,   243,   243,   243,   244,   244,   244,   244,   245,   245,
     246,   247,   248,   249,   249,   249,   249,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   252,   253,   254,   255,
     255,   255,   255,   255,   255,   255,   255,   256,   257,   257,
     258,   259,   260,   261,   262,   263,   263,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   265,   266,
     267,   268,   268,   269,   269,   270,   271,   271,   271,   271,
     271,   271,   272,   272,   273,   273,   273,   273,   274,   274,
     274,   275,   275,   275,   276,   276,   276,   276,   276,   277,
     277,   277,   278,   278,   279,   279,   280,   280,   281,   281,
     282,   282,   283,   283,   283,   284,   284,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   286,
     287,   287,   288,   289,   289,   290,   290,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   295,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   297,   298,   299,   299,   300,   300,   300,
     301,   301,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   308,   308,   309,   309,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     6,     7,     2,     2,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       7,     8,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       6,     6,     8,     6,     6,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     4,     4,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     7,     2,     7,     8,
       3,     1,     1,     0,     2,     2,     2,     2,     2,     1,
       3,     4,     3,     4,     2,     1,     2,     1,     0,     1,
       2,     4,     5,     2,     5,     6,     5,     6,     3,     6,
       7,     1,     3,     3,     3,     0,     2,     1,     3,     1,
       3,     1,     2,     4,     4,     1,     2,     4,     1,     2,
       4,     4,     1,     2,     4,     1,     3,     2,     1,     1,
       1,     2,     1,     2,     0,     2,     1,     2,     3,     4,
       1,     1,     2,     0,     3,     2,     1,     1,     1,     2,
       3,     5,     2,     2,     3,     5,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     3,     3,     4,
       1,     4,     5,     2,     3,     3,     4,     4,     1,     3,
       1,     1,     1,     1,     2,     3,     1,     1,     1,     4,
       3,     2,     5,     2,     1,     3,     1,     1,     2,     3,
       6,     3,     4,     1,     1,     1,     1,     5,     0,     1,
       2,     3,     4,     1,     2,     2,     3,     3,     3,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       6,     3,     4,     0,     1,     1,     2,     3,     1,     3,
       0,     2,     1,     1,     1,     1,     2,     2,     5,     7,
       5,     5,     7,     9,     1,     1,     1,     1,     3,     4,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     3,     1,     1,     1,     6,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     6,     6,
       2,     4,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     3,     1,     0,     1,     1,     2,     6,     1,     1,
       0,     1,     2,     4,     0,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     0,     1,     5,     6,     6,
       7,     5,     3,     1,     0,     1,     1,     3,     4,     7,
       0,     1,     1,     3,     9,     1,     3,     1,     1,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     2,     1,   135,   143,   140,   161,   141,     0,
     136,   132,   138,   133,   162,    78,   142,   139,   145,   148,
     137,    81,   134,   286,   107,     0,     0,     9,   146,   151,
      84,   567,   568,   569,   468,   469,   131,   152,    79,    80,
       0,    87,    88,    89,    85,    86,   149,   150,   120,   121,
     122,    82,    83,     4,     8,     5,    10,   577,   577,     6,
      44,   578,   578,     0,     0,     0,     0,    69,    73,    74,
      75,    77,    56,    61,    57,    62,    58,    63,    60,    65,
     114,     0,    59,    64,   127,    66,    94,   144,   147,   101,
     153,   574,   154,   572,   270,   271,   273,   278,   276,   277,
     272,   284,   572,   287,    76,     0,     7,     0,     0,   218,
     219,     0,   183,     0,   465,     0,     0,     0,     0,   274,
     288,    11,    45,     0,     0,   463,     0,   463,     0,   252,
       0,     0,   570,   247,   249,   251,   254,   255,   250,   260,
     248,   570,   570,   248,   570,   105,    68,    71,   111,   124,
      72,    91,    99,   570,   570,   108,    70,   115,   128,    67,
      95,   102,   570,   570,    92,    93,    96,    90,    97,   100,
       0,   103,    98,     0,   106,   109,   104,   112,   113,   116,
     117,   110,     0,   125,   126,   129,   130,   123,   157,   574,
       0,    15,   574,     0,   281,   283,    25,     0,   543,     0,
     573,   573,     0,   191,     0,     0,   188,   466,   280,   285,
     291,   275,   289,   323,     0,   335,     0,     0,     0,     0,
       0,     0,   464,    49,     0,    48,   574,   253,   296,   268,
       0,     0,     0,     0,     0,     0,   256,   263,   545,    16,
      26,   545,    17,    27,   545,    28,   545,    29,    46,    47,
       0,   366,   358,   353,   354,   357,   355,   356,     0,     0,
       0,   574,   406,   407,   408,   409,   410,   411,   404,   403,
       0,     0,     0,     0,   220,   222,    61,    62,    63,    65,
      64,     0,   361,   362,   369,   360,   365,   364,   387,   370,
     371,   372,   373,   374,   375,   376,   412,   397,   396,   395,
     394,     0,   393,     0,   414,   418,   421,   424,   429,   432,
     434,   436,   438,   440,   442,   445,   460,     0,     0,   160,
       0,   163,   298,   300,   412,   462,     0,     0,   470,     0,
     195,   195,     0,   181,     0,     0,     0,   279,   292,     0,
     575,   330,   324,   325,     0,     0,   248,   272,     0,     0,
     570,   570,   323,   336,   571,   571,   298,     0,   258,   265,
       0,     0,     0,   257,   264,   546,   463,   463,   463,   463,
     574,   391,   574,   388,   389,   405,     0,     0,     0,     0,
       0,     0,   400,   574,   303,   221,   295,   293,   294,   223,
     118,   359,     0,   382,   383,     0,     0,     0,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   447,     0,
     574,   402,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,     0,   163,     0,   163,   575,   572,   201,
     208,   205,   212,    57,    62,   299,   197,   199,   576,   215,
     576,   301,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   477,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,     0,
     471,   474,   544,     0,   193,   194,   184,   192,     0,   182,
       0,   186,     0,   328,     0,     0,    14,   326,     0,     0,
       0,     0,   574,     0,   545,   545,   575,   545,   545,   576,
     269,   259,   267,   266,   261,     0,   224,   224,   224,   224,
       0,     0,     0,   363,   323,   575,     0,     0,     0,     0,
       0,     0,   304,   305,   381,   378,     0,   385,     0,   380,
     446,     0,   415,   416,   417,   419,   420,   422,   423,   427,
     428,   425,   426,   430,   431,   433,   435,   437,   439,   441,
       0,     0,   461,   575,   163,   575,   169,     0,     0,   164,
       0,     0,     0,   217,   574,   303,   570,   570,   202,   570,
     570,   209,   574,   303,   570,   206,   570,   213,     0,     0,
       0,     0,   302,     0,     0,     0,   472,   196,   185,   189,
       0,   187,     0,   327,    12,     0,     0,     0,   458,     0,
       0,     0,     0,   458,     0,     0,   366,   107,     0,   334,
     577,   577,   332,     0,     0,     0,     0,     0,   333,   311,
     312,   331,   313,   314,   315,   316,   344,   345,   346,   347,
       0,   459,   317,     0,     0,   298,     0,   463,   463,     0,
     262,     0,    53,    54,    50,    51,   392,     0,   233,   413,
     330,     0,     0,     0,     0,   309,   307,   308,   306,   379,
       0,   377,   401,   444,     0,     0,   575,     0,     0,   168,
     463,   175,   178,   167,   463,   177,   178,     0,   166,     0,
     165,   155,   304,   463,   463,   463,   463,   304,   463,   463,
     198,   200,   216,   290,   282,   467,   474,   475,     0,   190,
     329,   351,     0,     0,     0,   350,   458,   458,     0,     0,
       0,     0,     0,     0,     0,   248,   570,   248,   570,   570,
     570,   570,   570,   463,   337,     0,     0,     0,    13,   224,
     224,   297,   366,   233,     0,     0,   225,   226,     0,     0,
     238,   236,   237,   230,     0,   231,   458,   368,     0,     0,
       0,   310,   386,   443,   156,     0,   158,   180,   172,   174,
     179,   170,   176,   463,   463,   204,   203,   211,   210,   207,
     214,   473,   476,     0,     0,   458,   352,     0,   321,     0,
     348,     0,     0,     0,   323,     0,    32,    40,    33,    41,
     545,    42,   545,    43,   458,     0,   553,     0,     0,    52,
      55,   246,     0,     0,   242,   243,   227,     0,   235,   239,
     384,   232,   322,   399,   398,   367,   159,   171,   173,   458,
       0,   319,   458,   349,     0,   458,   458,   330,   323,   318,
       0,     0,   554,     0,     0,   228,     0,     0,   244,     0,
     234,   340,   458,     0,     0,   338,   341,   458,   330,   554,
       0,     0,     0,   552,   555,   556,   547,     0,   229,     0,
       0,   240,   320,   458,     0,   458,     0,   458,     0,   548,
       0,     0,   554,     0,   549,   245,     0,     0,   342,   339,
      30,     0,   554,     0,     0,   551,   557,   241,   458,    31,
       0,     0,   558,     0,   343,   560,     0,   562,   550,     0,
     561,     0,     0,     0,   559,   563,   565,   564,     0,   566
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    53,    54,    55,    56,   340,    57,    58,
     659,   660,   661,   662,    60,    61,    62,   216,   274,   218,
     275,   146,    67,    68,    69,    70,    71,    72,    73,    74,
     277,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   437,   609,   610,
     611,   720,   724,   809,   721,    92,   202,   203,   524,   445,
     446,   447,   448,   449,   667,   281,   692,   786,   787,   794,
     795,   788,   789,   790,   791,   792,   132,   133,   134,   135,
     136,   137,   138,   139,   233,   119,    94,    95,    96,    97,
      98,   194,    99,   347,   101,   117,   103,   573,   386,   450,
     228,   387,   388,   668,   669,   670,   341,   342,   343,   534,
     536,   671,   220,   672,   673,   674,   675,   676,   677,   678,
     679,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   576,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   409,   680,   681,
     326,   221,   222,   104,   105,   519,   520,   636,   521,   106,
     365,   368,   682,   847,   903,   904,   905,   949,   948,   881,
     957,   683,   238,   547,   191,   330,   356,   535,   630,   123,
     126
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -766
static const yytype_int16 yypact[] =
{
    -766,    29,  1982,  -766,  -766,  -766,  -766,  -766,  -766,    79,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,   238,  4043,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    2351,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,   112,   170,    26,    26,  2474,  2597,  -766,  -766,  -766,
    -766,  -766,  2040,  2040,  2170,  2170,  2293,  2293,  1161,  1161,
    -766,   -12,  1185,  1185,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,    39,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
      55,  -766,  -766,  -766,  -766,    47,  -766,    88,   138,  -766,
    -766,   341,   161,   136,  -766,   186,    34,   201,  4043,  -766,
    -766,  -766,  -766,   229,  3041,   294,   230,   294,   262,   378,
     175,  3885,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
     283,  -766,  -766,   283,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
     278,  -766,  -766,   286,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  3443,  -766,  -766,  -766,  -766,  -766,   308,    39,
     338,  -766,  -766,  4431,  -766,   258,   349,   368,  -766,   451,
    -766,  -766,   260,  -766,   341,   341,   382,  -766,   378,  -766,
     378,  -766,  -766,   374,  3321,  -766,   274,   274,  2720,  2843,
    2884,   305,   294,  -766,   274,  -766,  -766,  -766,   258,  -766,
     175,   432,   436,   378,   175,  3935,  -766,  -766,    -5,  -766,
     447,    -5,  -766,   449,   431,   461,   469,   470,  -766,  -766,
    4731,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  4809,  4809,
     547,  3443,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
     546,   560,   574,  4831,   375,  3687,  2532,  3510,  3510,  1683,
    2418,   588,  -766,   629,  -766,  -766,  -766,  -766,   623,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,   850,  -766,  -766,  -766,
    -766,  4909,  -766,  4831,  -766,   172,   485,   543,   242,   549,
     598,   590,   591,   637,   -18,  -766,  -766,   550,   611,   308,
     621,  -766,  3164,  -766,  -766,  -766,   632,  4831,  1736,    53,
     606,   606,    62,  -766,   320,   478,   341,  -766,  -766,   659,
    -766,  -766,   374,  -766,   389,  3977,  -766,   416,   305,  4086,
    -766,  -766,   374,  -766,  -766,  -766,  3321,   164,   378,   378,
     636,   327,   175,  -766,  -766,  -766,   294,   294,   294,   294,
    3443,  -766,  3443,  -766,  -766,  -766,   646,   556,   652,  3850,
    3850,  4831,  -766,   375,  3809,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,   479,  -766,  -766,  4453,  4831,   479,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  4831,
    3443,  -766,  -766,  4831,  4831,  4831,  4831,  4831,  4831,  4831,
    4831,  4831,  4831,  4831,  4831,  4831,  4831,  4831,  4831,  4831,
    4831,  4531,  -766,  4831,  -766,   654,  -766,  3728,  -766,   372,
     372,  2105,  2228,  2293,  2293,  -766,   661,  -766,   665,  -766,
    -766,  -766,   663,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,   660,
     667,   680,  -766,  4831,  -766,  -766,  -766,  -766,   234,  -766,
     271,  -766,   498,  -766,    83,   679,  1361,  -766,   389,   351,
     389,  4001,  -766,  4086,    -5,    -5,  -766,    -5,    -5,  -766,
    -766,  -766,  -766,  -766,  -766,   398,   662,   662,   662,   662,
     695,   724,  4553,  -766,   374,  -766,   725,   726,   732,   734,
     739,   741,  3809,  -766,  -766,  -766,   593,  -766,   220,  -766,
    -766,   743,  -766,  -766,  -766,   172,   172,   485,   485,   543,
     543,   543,   543,   242,   242,   549,   598,   590,   591,   637,
    4831,    28,  -766,  3728,  -766,  3728,  -766,   403,  3565,  -766,
     101,   122,   740,  -766,   276,   965,  -766,  -766,  -766,  -766,
    -766,  -766,   314,  3283,  -766,  -766,  -766,  -766,  3198,   777,
     748,   751,  -766,   754,  1736,  4631,  -766,  -766,  -766,  -766,
     363,  -766,   787,  -766,  -766,   735,   758,  4831,  4831,   737,
     762,   742,    31,  4197,   764,   766,   744,   749,  1859,  -766,
    -766,  -766,  -766,    26,    26,  2474,  2597,   750,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
     752,   775,  -766,  2665,   389,  3321,   773,   294,   294,   780,
    -766,  4353,  -766,  -766,  -766,  -766,   783,   783,  -766,  -766,
    -766,   790,   421,  3850,  3850,  -766,   378,  -766,  -766,  -766,
    4831,  -766,   783,  -766,  4831,   808,  3728,   809,  4831,  -766,
     294,  -766,   793,  -766,   294,  -766,   793,    25,  -766,   468,
    -766,  -766,   965,   294,   294,   294,   294,  3283,   294,   294,
    -766,  -766,  -766,  -766,  -766,  -766,   680,  -766,   595,  -766,
    -766,  -766,  4831,    63,   794,  -766,  4831,  4197,  4831,   797,
     848,  4831,  4831,   817,  3041,   283,  -766,   283,  -766,  -766,
    -766,  -766,  -766,   294,  -766,   823,   451,   825,  -766,   662,
     662,  -766,   803,  -766,  4831,   522,  -766,  -766,  4709,   381,
    -766,  -766,  -766,  -766,   822,  4353,  1490,  -766,   604,   835,
     836,  -766,  -766,  -766,  -766,   832,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,   294,   294,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -766,   634,  4831,  4197,  -766,   831,  -766,   133,
    -766,   857,   651,   653,   374,  3007,  -766,   854,  -766,   858,
     509,   867,   545,   871,  4197,   451,    -9,   861,   451,  -766,
    -766,  -766,  4275,   155,  -766,  -766,  -766,  4831,  -766,  -766,
    -766,   875,  -766,  -766,  -766,  -766,  -766,  -766,  -766,  4197,
     855,  -766,  4831,  -766,  4831,  4197,  4197,  -766,   374,  -766,
      27,   878,   -10,   864,   892,  -766,   526,  4831,   481,   311,
    -766,  -766,  4197,   872,   664,   952,  -766,  1613,  -766,   -10,
     874,  1736,   108,   876,   895,  -766,  -766,   879,  -766,   901,
    4831,  -766,  -766,  4831,   886,  4197,   894,  1613,   888,  -766,
     905,  4831,   -10,   -10,  -766,   581,   907,   915,  -766,  -766,
    -766,   911,   -10,   451,   688,   898,  -766,  -766,  4197,  -766,
     899,   110,  -766,   451,  -766,   451,  4831,   629,   916,   900,
     916,   693,   451,   777,  -766,   629,  -766,   923,   777,  -766
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -766,  -766,  -766,  -766,  -766,  -766,   953,   640,  -766,  -766,
    -766,  -766,  -766,     4,   -27,  -766,  -766,     1,    -1,     2,
      -2,     6,   873,  -766,  -766,  -766,  -766,  -766,   587,  -300,
       0,  -766,   624,  -766,   639,   -14,  -766,  -766,   643,   150,
      82,   119,  -766,  -766,   -20,  -766,  -766,  -379,  -766,  -766,
    -766,   272,   275,   273,  -588,  -766,  -156,  -260,   674,  -766,
    -766,   380,  -766,  -592,    12,  -227,  -482,  -765,   218,  -766,
     231,  -766,  -766,   223,  -766,  -766,   -55,  -766,  -766,   -95,
     -60,  -766,   -99,  -766,  -176,   194,  -766,    58,  -766,  -766,
    -766,  -766,  -766,   270,  -766,    45,  -766,    33,   430,   669,
     -72,  -340,  -333,   241,  -766,   638,  -549,  -766,   675,  -766,
    -675,  -766,   256,  -766,  -766,  -766,  -766,  -766,  -766,  -766,
    -766,  -766,  -166,  -766,  -766,  -766,  -766,   319,  -766,  -766,
    -766,  -766,  -766,  -766,  -766,   391,   448,  -766,  -766,  -766,
    -766,  -766,  -766,  -766,  -136,   357,   362,   153,   358,   601,
     602,   600,   603,   605,  -766,  -134,   137,  -766,  -630,  -175,
    -315,   116,    14,     5,  -766,  -766,  -766,   285,  -615,  -766,
    1031,  -230,  -766,   188,  -628,  -766,   115,  -766,    94,  -766,
    -766,     3,   353,   685,   -92,   841,   171,  -339,  -383,   -41,
     437
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -579
static const yytype_int16 yytable[] =
{
      66,    64,    75,    63,    65,   108,    59,   317,   366,   142,
     196,   367,   452,   122,   114,   700,   369,   124,   754,   746,
     725,   112,   443,   113,   118,   796,   252,   391,   195,     3,
     861,   232,   237,   329,   376,   430,   236,   742,    66,    64,
      75,    63,    65,   570,   195,   152,   161,   102,   334,   335,
     571,   148,   157,   182,   357,   603,   443,   605,   361,   325,
      23,    23,   901,   391,   178,   180,   109,   631,   129,   431,
     231,   120,   527,   110,   109,   693,   694,   695,   164,   882,
     169,   110,   174,   115,   177,   102,   377,   886,   183,   391,
     348,   130,    31,    32,    33,   433,   114,   200,   612,   192,
     209,   349,   131,   188,   201,   189,   193,   758,   141,   144,
     154,   163,   197,   718,   109,   899,   714,   824,   207,   522,
     192,   110,   219,   217,    75,   206,   827,   193,   215,   235,
     114,   232,   114,   526,   810,   232,   364,   382,   810,   725,
     363,    34,    35,   560,   391,   561,   391,   150,   159,   111,
     642,   825,   566,   567,   150,   167,   150,   172,   150,   176,
     150,   181,   142,   212,   150,   187,   689,   412,   727,   355,
     231,   109,   643,   921,   231,   946,   120,   198,   110,   125,
     532,    34,    35,   581,   151,   160,   555,   122,   115,   729,
     728,   165,   168,   325,   207,   377,    93,   377,   152,   161,
     433,   319,   897,   199,   148,   157,   205,   686,   637,   887,
      23,   730,   219,   217,    75,   149,   158,   229,   219,   217,
      75,   578,   873,   917,   353,   716,   701,   207,   888,   226,
     550,   204,   184,   186,    93,   377,   193,   127,    34,    35,
     230,   108,   893,   224,   108,   232,   237,   108,   413,   108,
     236,   131,   208,   414,   415,   161,   601,   140,   143,   153,
     162,   157,   190,   232,   715,   180,   717,   210,   527,   200,
     527,   918,   100,    23,   570,   195,   201,   582,   583,   584,
     212,   571,   570,   927,   231,   877,   920,   433,   115,   571,
     420,   421,   115,   711,   935,   116,   100,   849,   850,   213,
     150,   159,   231,    25,   940,   638,   200,   385,   389,    23,
     100,    23,   211,   201,    26,   369,   129,   687,   688,   223,
     442,   440,   444,   439,   441,   422,   423,   332,   443,   898,
     327,   333,   753,   100,   100,   100,   100,   151,   160,   344,
      23,   614,   639,   541,   616,   619,   613,   543,   193,    23,
     345,   225,   615,  -570,   442,   440,   444,   439,   441,   318,
     320,   956,   357,   322,   361,   910,   959,   248,   149,   158,
     348,   114,   114,   114,   114,   249,   200,   805,  -574,   622,
     527,   349,   572,   201,   911,   443,   193,   528,   100,   325,
     623,   529,   226,   554,   160,   168,    34,    35,   200,   193,
     116,   100,   115,   807,   574,   201,   115,    23,   321,   579,
     346,   346,   350,   351,   129,   354,   542,   209,   346,   -20,
     115,   152,   161,   193,    23,   158,   699,   148,   157,   211,
     186,   229,   378,   328,   749,   608,   607,   614,    23,   232,
     383,   232,   364,   226,   193,   129,   363,   193,   615,   169,
     193,   384,   336,   857,   538,   785,   251,   252,   253,   254,
     255,   256,   257,   226,   690,   345,   713,   195,   344,   853,
     193,   858,   618,   621,   625,   627,   799,   800,   231,   345,
     231,   542,   556,   557,   558,   559,   372,   252,   193,   339,
     435,   718,   719,   239,   240,   241,   242,   243,   358,   128,
     116,   -18,   359,    23,   116,   100,   244,   245,   555,   870,
     129,   170,   173,   325,   109,   246,   247,   -21,   568,   -22,
     236,   110,   382,   150,   159,   150,   172,   272,    31,    32,
      33,   -23,   577,   344,   666,   664,    75,   663,   665,   -19,
     -24,   378,   889,   378,   345,   530,   580,   108,   108,   531,
     108,   108,   722,  -240,   231,  -240,   718,   854,   916,   227,
     151,   160,   416,   417,   855,   640,    31,    32,    33,   641,
     602,  -240,   909,   589,   590,   591,   592,   823,   931,   -34,
     803,   378,   375,   829,   325,   232,   832,   833,   161,   418,
     419,   149,   158,   890,   157,   926,   115,   908,   115,   424,
     425,   608,   607,   608,   607,   708,    31,    32,    33,   142,
     846,   379,   369,   732,   539,   -35,   432,   433,   539,   763,
     764,   737,   563,   433,   231,   380,   442,   440,   444,   439,
     441,   122,   116,   617,   620,   624,   626,   363,   337,   381,
     338,   324,    31,    32,    33,   152,   161,   392,   393,   394,
     325,   148,   157,  -241,   390,  -241,   219,   217,    75,   709,
     710,   822,   710,   360,   759,   391,   392,   393,   394,   395,
     863,  -241,   115,   426,   722,   427,   396,   428,   397,   880,
     115,   434,   846,   442,   440,   444,   439,   441,   395,   429,
     325,   436,   114,   114,   533,   396,   523,   397,   371,   894,
     869,   433,   553,   544,   545,   451,   373,   374,   766,   768,
     770,   772,   562,   685,   608,   607,   902,   875,   433,   876,
     433,   324,   564,   325,   604,   114,   633,   160,   628,   114,
     914,   433,   629,   902,   634,   211,   632,   211,   114,   114,
     114,   114,   115,   114,   114,   635,   934,   150,   159,   411,
     644,   324,   691,   325,   942,   433,   902,   902,   158,   954,
     433,   696,   219,   217,    75,   708,   902,   941,   215,   276,
     708,   951,   577,   585,   586,   324,   325,   947,   114,   947,
     587,   588,   593,   594,   151,   160,   955,   360,   551,   552,
     697,   360,   702,   703,   666,   664,    75,   663,   665,   704,
     705,   346,   726,   779,   780,   706,   278,   707,   539,   712,
     539,   731,   438,   569,   743,   149,   158,   744,   114,   114,
     745,   279,   750,   752,   751,   280,   755,   756,   793,   761,
     757,   762,  -218,   219,   217,    75,   808,  -219,   773,   353,
     811,   774,   433,   108,   778,   108,   781,   802,   276,   815,
     816,   817,   818,   698,   819,   820,   797,   765,   767,   769,
     771,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   804,
     806,   718,   831,   826,   539,   278,   830,   834,   845,   844,
     848,   851,   539,   860,   760,   666,   664,    75,   663,   665,
     279,   864,   865,   866,   280,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   666,   664,    75,   663,   665,
     872,   726,   874,   346,   -36,   793,   211,   883,   -37,   867,
     868,   211,   793,   100,   100,   100,   100,   -38,   147,   156,
     408,   -39,   890,   892,   900,   147,   166,   147,   171,   147,
     175,   147,   179,   906,   539,   147,   185,   276,   907,   276,
     915,   913,   923,   919,   922,   930,   276,   276,   924,   733,
     734,   324,   735,   736,   925,   928,   932,   738,   933,   739,
     937,   938,   939,   952,    15,   360,   943,   945,   953,   793,
     958,   156,   546,   121,   278,    21,   278,   276,   828,   812,
      23,   814,   813,   278,   278,   525,   856,   129,   741,   279,
     324,   279,   859,   280,   852,   280,   565,   537,   279,   279,
     835,   798,   280,   280,   276,   549,   748,   595,   597,   596,
     614,   821,   598,   107,   278,   599,   884,   193,   936,   950,
     548,   615,   331,     0,   569,     0,     0,     0,   324,   279,
       0,     0,   569,   280,     0,     0,     0,     0,     0,    30,
       0,   278,     0,     0,     0,     0,   871,    34,    35,     0,
       0,     0,     0,     0,    38,    39,   279,    41,    42,    43,
     280,    44,    45,     0,     0,   879,     0,     0,     0,    51,
      52,   147,   156,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,     0,   156,     0,
     891,     0,     0,     0,     0,     0,   895,   896,   836,   837,
     838,   839,   840,   841,   842,   843,     0,     0,     0,     0,
       0,     0,     0,   912,     0,     0,   801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   166,
     171,   175,   179,   185,     0,     0,   929,     0,     0,     0,
       0,     0,   324,     0,     4,     0,   324,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,    13,     0,   944,
      15,     0,     0,     0,     0,     0,     0,     0,     4,     0,
     276,    21,   276,     0,    22,     0,     0,     0,    10,    11,
       0,    13,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,   278,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,   279,     0,   280,     0,   280,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
      38,    39,   324,    41,    42,    43,     0,    44,    45,    30,
       0,     0,    48,    49,    50,    51,    52,    34,    35,     0,
     276,   276,    36,     0,    38,    39,     0,    41,    42,    43,
       0,    44,    45,   276,     0,   324,     0,     0,     0,    51,
      52,     0,     0,     0,   147,   156,   147,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   278,     0,
       0,     0,     0,     0,     0,   324,     0,     0,     0,     0,
     278,     0,   279,   279,     0,     0,   280,   280,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,   324,   280,
       0,     0,     0,     0,     4,     5,     6,     7,   645,     0,
       8,   646,   647,     9,    10,    11,    12,    13,   648,    14,
      15,    16,    17,    18,   649,   650,    19,    20,   651,   652,
     250,    21,   653,   654,    22,   655,   656,   252,   253,   254,
     255,   256,   257,   657,     0,   258,   259,     0,     0,     0,
       0,     0,     0,   260,   156,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,   564,     0,     0,     0,     0,   262,   263,   264,   265,
     266,   267,     0,     0,     0,   156,     0,     0,     0,     0,
    -458,     0,     0,    28,    29,    30,   268,   269,    31,    32,
      33,     0,     0,    34,    35,   270,   271,   272,    36,    37,
      38,    39,   658,    41,    42,    43,     0,    44,    45,    46,
      47,   156,    48,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,   645,     0,     8,
     646,   647,     9,    10,    11,    12,    13,   648,    14,    15,
      16,    17,    18,   649,   650,    19,    20,   651,   652,   250,
      21,   653,   654,    22,   655,   656,   252,   253,   254,   255,
     256,   257,   657,     0,   258,   259,     0,     0,   147,   156,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   777,     0,     0,     0,
     564,   862,     0,     0,     0,   262,   263,   264,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,   268,   269,    31,    32,    33,
       0,     0,    34,    35,   270,   271,   272,    36,    37,    38,
      39,   658,    41,    42,    43,   156,    44,    45,    46,    47,
     156,    48,    49,    50,    51,    52,     4,     5,     6,     7,
     645,     0,     8,   646,   647,     9,    10,    11,    12,    13,
     648,    14,    15,    16,    17,    18,   649,   650,    19,    20,
     651,   652,   250,    21,   653,   654,    22,   655,   656,   252,
     253,   254,   255,   256,   257,   657,     0,   258,   259,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,     0,   564,  -575,     0,     0,     0,   262,   263,
     264,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    28,    29,    30,   268,   269,
      31,    32,    33,    21,     0,    34,    35,   270,   271,   272,
      36,    37,    38,    39,   658,    41,    42,    43,     0,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,    44,
      45,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,     0,     0,    19,    20,     0,     0,   250,    21,
       0,     0,    22,     0,   251,   252,   253,   254,   255,   256,
     257,    24,     0,   258,   259,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,   268,   269,     0,     0,     0,     0,
       0,    34,    35,   270,   271,   272,    36,    37,    38,    39,
     273,    41,    42,    43,     0,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,     0,     0,    19,    20,     0,
       0,     0,    21,     0,     0,    22,     0,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     0,    25,     0,     8,
       0,     0,     0,    10,    11,    12,    13,     0,    26,    15,
      16,    17,    18,     0,     0,    19,    20,     0,     0,     0,
      21,    27,     0,    22,    28,    29,    30,     0,     0,    31,
      32,    33,     0,     0,    34,    35,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    28,    29,    30,    21,     0,     0,    22,     0,
      23,     0,    34,    35,     0,     0,     0,   145,    37,    38,
      39,     0,    41,    42,    43,     0,    44,    45,    46,    47,
       0,     0,     0,     0,    51,    52,     0,     0,     0,     0,
     622,     0,     0,     4,     0,     0,     0,   193,     0,     0,
       0,   623,     0,    10,    11,     0,    13,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      21,     0,     0,    22,     0,     0,     0,    34,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,    51,
      52,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,    19,    20,     0,     0,     0,    21,  -578,
       0,    22,     0,    23,    30,     0,     0,     0,     0,     0,
     155,     0,    34,    35,     0,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,   622,    51,    52,     4,     0,     0,     0,
     193,     0,     0,     0,   623,     0,    10,    11,     0,    13,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    21,     0,     0,    22,     0,     0,     0,
      34,    35,     0,     0,     0,    36,    37,    38,    39,     0,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,     0,
       0,    21,     0,     0,    22,     0,    23,    30,     0,     0,
       0,     0,     0,    24,     0,    34,    35,     0,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,    25,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,    28,    29,    30,     0,     0,    21,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,     0,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,     0,     0,    19,
      20,     0,     0,     0,    21,     0,     0,    22,     0,    23,
       0,     0,    30,     0,     0,     0,   145,     0,     0,     0,
      34,    35,     0,     0,     0,    36,     0,    38,    39,     0,
      41,    42,    43,     0,    44,    45,     5,     6,     0,    25,
       0,     8,    51,    52,     0,     0,     0,    12,     0,     0,
      26,    15,    16,    17,    18,     0,     0,    19,    20,     0,
       0,     0,    21,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,     0,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
       0,     0,    19,    20,    28,    29,    30,    21,     0,     0,
      22,     0,    23,     0,    34,    35,     0,     0,     0,   155,
      37,    38,    39,     0,    41,    42,    43,     0,    44,    45,
      46,    47,     0,     0,     0,     0,    51,    52,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    28,
      29,    30,     0,   775,     0,    21,     0,     0,     0,    34,
      35,     0,     0,     0,    36,    37,    38,    39,     0,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,     4,     5,     6,     7,     0,     0,     8,
     776,     0,     9,    10,    11,    12,    13,     0,    14,    15,
      16,    17,    18,     0,     0,    19,    20,     0,     0,     0,
      21,     0,     0,    22,     0,    23,     0,     0,     0,    30,
       0,     0,   145,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,    44,    45,     0,     0,   348,     0,     0,     0,    51,
      52,     0,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,    18,     0,     0,    19,    20,
       0,     0,     0,    21,     0,     0,    22,     0,    23,     0,
       0,     0,     0,     0,     0,   155,     0,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,     0,   348,    19,
      20,     0,     0,     0,    21,     0,     0,    22,     0,   349,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
      36,    37,    38,    39,   352,    41,    42,    43,     0,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,   214,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
       0,     0,    19,    20,     0,     0,     0,    21,     0,     0,
      22,     0,     0,     0,     4,     5,     6,     7,     0,    24,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,     0,
       0,    21,     0,     0,    22,     0,     0,   878,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,    36,    37,    38,    39,   214,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,   214,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,     0,     0,    19,
      20,     0,     0,     0,    21,     0,     0,    22,     0,   438,
       0,     4,     5,     6,     7,     0,    24,     8,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,    19,    20,     0,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   740,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,     0,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
      34,    35,    15,     0,     0,    36,    37,    38,    39,     0,
      41,    42,    43,    21,    44,    45,    46,    47,    23,    48,
      49,    50,    51,    52,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    19,    20,   622,     0,
       0,    21,     0,     0,    22,   193,     0,     0,     0,   623,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    51,    52,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,     0,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,     5,     6,     7,
       0,     0,     8,     0,     0,     9,     0,     0,    12,     0,
       0,    14,    15,    16,    17,    18,     0,     0,    19,    20,
       0,     0,   250,    21,     0,     0,     0,     0,   251,   252,
     253,   254,   255,   256,   257,    24,     0,   258,   259,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,   263,
     264,   265,   266,   267,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,    28,    29,    30,   268,   269,
      21,     0,     0,     0,     0,    34,    35,   270,   271,   272,
      36,    37,    38,    39,   273,    41,    42,    43,     0,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,     5,
       6,     7,     0,     0,     8,     0,     0,     9,     0,     0,
      12,     0,     0,    14,    15,    16,    17,    18,     0,     0,
      19,    20,     0,     0,     0,    21,     0,     0,     0,     0,
      23,     0,     0,     0,    30,     0,     0,   155,     0,     0,
       0,     0,    34,    35,     0,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,    44,    45,     0,     0,
     348,     0,     0,     0,    51,    52,     0,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,   723,     0,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,    51,
      52,     5,     6,     7,     0,     0,     8,     0,     0,     9,
       0,     0,    12,     0,     0,    14,    15,    16,    17,    18,
       0,     0,    19,    20,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     5,     6,     7,     0,     0,     8,     0,     0,
       9,     0,     0,    12,     0,     0,    14,    15,    16,    17,
      18,     0,   383,    19,    20,     0,     0,     0,    21,   193,
       0,     0,     0,   384,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,    36,    37,    38,    39,     0,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,   606,     0,     0,
      28,    29,    30,     0,     0,     0,     0,     0,    15,     0,
      34,    35,     0,     0,     0,    36,    37,    38,    39,    21,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,     5,     6,     7,     0,     0,     8,
       0,     0,     9,     0,     0,    12,     0,     0,    14,    15,
      16,    17,    18,     0,   383,    19,    20,     0,     0,     0,
      21,   193,     0,     0,     0,   384,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    15,     0,     0,     0,     0,     0,
       0,    34,    35,     0,     0,    21,     0,     0,    38,    39,
      23,    41,    42,    43,     0,    44,    45,   129,     0,     0,
       0,     0,     0,    51,    52,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,     0,     0,     0,     0,
     234,     0,    34,    35,    15,     0,     0,    36,    37,    38,
      39,   131,    41,    42,    43,    21,    44,    45,    46,    47,
      23,    48,    49,    50,    51,    52,     0,   129,     0,    30,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,    38,    39,    15,    41,    42,    43,
     362,    44,    45,     0,     0,     0,     0,    21,     0,    51,
      52,   131,    23,     0,     0,     0,     0,     0,     0,   129,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    21,     0,     0,     0,     0,    23,    34,    35,     0,
       0,     0,   540,   129,    38,    39,     0,    41,    42,    43,
       0,    44,    45,   345,     0,     0,     0,     0,     0,    51,
      52,     0,    15,     0,     0,     0,   684,     0,     0,     0,
       0,    30,     0,    21,     0,     0,     0,   345,    23,    34,
      35,     0,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,    44,    45,    30,     0,     0,     0,     0,
       0,    51,    52,    34,    35,    15,     0,     0,    25,     0,
      38,    39,     0,    41,    42,    43,    21,    44,    45,    26,
       0,    23,     0,     0,     0,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,   348,    38,    39,     0,    41,    42,    43,     0,    44,
      45,     0,   349,     0,     0,     0,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,    44,    45,   645,     0,     0,   646,   647,     0,
      51,    52,     0,     0,   648,     0,     0,     0,     0,     0,
     649,   650,     0,     0,   651,   652,   250,     0,   653,   654,
       0,   655,   656,   252,   253,   254,   255,   256,   257,   110,
       0,   258,   259,     0,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,     0,   564,     0,     0,
       0,     0,   262,   263,   264,   265,   266,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   269,    31,    32,    33,     0,     0,     0,
       0,   270,   271,   272,   250,     0,     0,     0,   273,     0,
     782,   252,   253,   254,   255,   256,   257,     0,     0,   258,
     259,     0,     0,     0,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   783,   885,   784,     0,   785,
     262,   263,   264,   265,   266,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   269,     0,     0,     0,     0,     0,     0,     0,   270,
     271,   272,   250,     0,     0,     0,   273,     0,   782,   252,
     253,   254,   255,   256,   257,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,     0,   783,     0,   784,     0,   785,   262,   263,
     264,   265,   266,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,     0,     0,   270,   271,   272,
     250,     0,     0,     0,   273,     0,   251,   252,   253,   254,
     255,   256,   257,     0,     0,   258,   259,     0,     0,     0,
       0,     0,   250,   260,     0,     0,     0,     0,   251,   252,
     253,   254,   255,   256,   257,     0,   261,   258,   259,     0,
       0,     0,     0,     0,   323,   260,   262,   263,   264,   265,
     266,   267,     0,     0,     0,     0,     0,     0,   261,   575,
       0,     0,     0,     0,     0,     0,   268,   269,   262,   263,
     264,   265,   266,   267,     0,   270,   271,   272,     0,     0,
       0,     0,   273,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,     0,     0,   270,   271,   272,
     250,     0,     0,     0,   273,     0,   251,   252,   253,   254,
     255,   256,   257,     0,     0,   258,   259,     0,     0,     0,
       0,     0,   250,   260,     0,     0,     0,     0,   251,   252,
     253,   254,   255,   256,   257,     0,   261,   258,   259,     0,
       0,     0,     0,     0,     0,   260,   262,   263,   264,   265,
     266,   267,     0,     0,     0,     0,     0,     0,   261,   600,
       0,     0,     0,   698,     0,     0,   268,   269,   262,   263,
     264,   265,   266,   267,     0,   270,   271,   272,     0,     0,
       0,     0,   273,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,     0,     0,   270,   271,   272,
     250,     0,     0,     0,   273,     0,   251,   252,   253,   254,
     255,   256,   257,     0,     0,   258,   259,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   747,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,   265,
     266,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,     0,     0,
       0,     0,     0,     0,     0,   270,   271,   272,   250,     0,
       0,     0,   273,     0,   251,   252,   253,   254,   255,   256,
     257,     0,     0,   258,   259,     0,     0,     0,     0,     0,
     250,   260,     0,     0,     0,     0,   251,   252,   253,   254,
     255,   256,   257,     0,   261,   258,   259,     0,     0,   783,
       0,     0,     0,   260,   262,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     0,   370,     0,     0,     0,
       0,     0,     0,     0,   268,   269,   262,   263,   264,   265,
     266,   267,     0,   270,   271,   272,     0,     0,     0,     0,
     273,     0,     0,     0,     0,     0,   268,   269,     0,     0,
       0,     0,     0,     0,     0,   270,   271,   272,   250,     0,
       0,     0,   273,     0,   251,   252,   253,   254,   255,   256,
     257,     0,     0,   258,   259,     0,     0,     0,     0,     0,
     250,   260,     0,     0,     0,     0,   251,   252,   253,   254,
     255,   256,   257,     0,   372,   258,   259,     0,     0,     0,
       0,     0,     0,   260,   262,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,   268,   269,   262,   263,   264,   265,
     266,   267,     0,   270,   271,   272,     0,     0,     0,     0,
     273,     0,     0,     0,     0,     0,   268,   269,     0,     0,
       0,     0,     0,     0,     0,   270,   271,   272,   250,     0,
       0,     0,   273,     0,   251,   252,   253,   254,   255,   256,
     257,     0,     0,   258,   259,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   264,   265,   266,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   269,     0,     0,     0,     0,
       0,     0,     0,   270,   271,   272,     0,     0,     0,     0,
     273
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-766))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,     2,     2,     2,   182,   238,    64,
     102,   241,   327,    40,     9,   564,   246,    58,   648,   634,
     608,     9,   322,     9,    26,   700,    36,    36,   100,     0,
     795,   130,   131,   199,   261,    53,   131,   629,    40,    40,
      40,    40,    40,   383,   116,    65,    66,     2,   204,   205,
     383,    65,    66,    65,   230,   434,   356,   436,   234,   193,
      35,    35,    72,    36,    78,    79,    35,   450,    42,    87,
     130,    26,   332,    42,    35,   557,   558,   559,    72,    88,
      74,    42,    76,    25,    78,    40,   261,   852,    82,    36,
      65,    65,    97,    98,    99,    67,    91,    35,   437,    65,
      66,    76,    76,    91,    42,    91,    72,    76,    63,    64,
      65,    66,    65,    88,    35,    88,    88,    54,   113,    66,
      65,    42,   124,   124,   124,   113,   756,    72,   124,   131,
     125,   230,   127,    71,   722,   234,   235,   273,   726,   727,
     235,   102,   103,   370,    36,   372,    36,    65,    66,    70,
      67,    88,   379,   380,    72,    73,    74,    75,    76,    77,
      78,    79,   217,   118,    82,    83,   549,   303,    67,   224,
     230,    35,    89,    65,   234,    65,   131,    89,    42,    67,
     336,   102,   103,   410,    65,    66,   362,   214,   130,    67,
      89,    72,    73,   327,   189,   370,     2,   372,   218,   219,
      67,   189,   877,    65,   218,   219,    70,   546,   523,    54,
      35,    89,   214,   214,   214,    65,    66,    42,   220,   220,
     220,   396,    89,   898,   220,   604,   565,   222,    73,    65,
      66,    70,    82,    83,    40,   410,    72,    67,   102,   103,
      65,   238,   872,   127,   241,   344,   345,   244,    76,   246,
     345,    76,    66,    81,    82,   275,   431,    63,    64,    65,
      66,   275,    91,   362,   603,   279,   605,    66,   528,    35,
     530,   899,     2,    35,   614,   347,    42,   413,   414,   415,
     235,   614,   622,   913,   344,   834,   901,    67,   230,   622,
      48,    49,   234,    73,   922,    25,    26,   779,   780,    70,
     218,   219,   362,    65,   932,    71,    35,   274,   275,    35,
      40,    35,   118,    42,    76,   545,    42,   547,   548,    89,
     322,   322,   322,   322,   322,    83,    84,    67,   628,   878,
      72,    71,   647,    63,    64,    65,    66,   218,   219,    65,
      35,    65,    71,   345,   439,   440,   438,   349,    72,    35,
      76,    89,    76,    70,   356,   356,   356,   356,   356,   188,
     189,   953,   538,   192,   540,    54,   958,    89,   218,   219,
      65,   366,   367,   368,   369,    89,    35,   716,    70,    65,
     640,    76,   384,    42,    73,   685,    72,    67,   118,   523,
      76,    71,    65,    66,   275,   276,   102,   103,    35,    72,
     130,   131,   344,   718,   392,    42,   348,    35,    70,   397,
     216,   217,   218,   219,    42,   221,    65,    66,   224,    70,
     362,   441,   442,    72,    35,   275,   562,   441,   442,   235,
     280,    42,   261,    65,    71,   437,   437,    65,    35,   538,
      65,   540,   541,    65,    72,    42,   541,    72,    76,   443,
      72,    76,    70,    72,    65,    74,    35,    36,    37,    38,
      39,    40,    41,    65,    66,    76,   600,   539,    65,   784,
      72,    90,   439,   440,   441,   442,   703,   704,   538,    76,
     540,    65,   366,   367,   368,   369,    65,    36,    72,   115,
     319,    88,    89,   140,   141,   142,   143,   144,    66,    62,
     230,    70,    66,    35,   234,   235,   153,   154,   684,   824,
      42,    74,    75,   647,    35,   162,   163,    70,   381,    70,
     615,    42,   658,   441,   442,   443,   444,   106,    97,    98,
      99,    70,   395,    65,   536,   536,   536,   536,   536,    70,
      70,   370,   857,   372,    76,    67,   409,   544,   545,    71,
     547,   548,   607,    72,   614,    74,    88,    35,   897,   129,
     441,   442,    77,    78,    42,    67,    97,    98,    99,    71,
     433,    90,   887,   420,   421,   422,   423,   752,   917,    70,
     714,   410,    35,   758,   718,   684,   761,   762,   608,    46,
      47,   441,   442,    67,   608,   910,   538,    71,   540,    50,
      51,   603,   603,   605,   605,   572,    97,    98,    99,   664,
     776,    65,   842,   615,   344,    70,    66,    67,   348,   660,
     661,   623,    66,    67,   684,    65,   628,   628,   628,   628,
     628,   658,   362,   439,   440,   441,   442,   732,   208,    65,
     210,   193,    97,    98,    99,   665,   666,    43,    44,    45,
     784,   665,   666,    72,    66,    74,   658,   658,   658,    66,
      67,    66,    67,   233,   652,    36,    43,    44,    45,    65,
      66,    90,   614,    75,   729,    85,    72,    86,    74,   845,
     622,    70,   848,   685,   685,   685,   685,   685,    65,    52,
     824,    70,   687,   688,    35,    72,    90,    74,   250,   874,
      66,    67,    66,   350,   351,    73,   258,   259,   663,   664,
     665,   666,    66,   542,   716,   716,   882,    66,    67,    66,
      67,   273,    70,   857,    70,   720,    66,   608,    67,   724,
      66,    67,    67,   899,    67,   541,    73,   543,   733,   734,
     735,   736,   684,   738,   739,    65,   921,   665,   666,   301,
      71,   303,    90,   887,    66,    67,   922,   923,   608,    66,
      67,    66,   764,   764,   764,   732,   932,   933,   764,   182,
     737,   946,   635,   416,   417,   327,   910,   943,   773,   945,
     418,   419,   424,   425,   665,   666,   952,   357,   358,   359,
      66,   361,    67,    67,   796,   796,   796,   796,   796,    67,
      66,   607,   608,   687,   688,    66,   182,    66,   538,    66,
     540,    71,    35,   383,    66,   665,   666,    66,   813,   814,
      66,   182,    35,    65,    89,   182,    89,    65,   691,    65,
      88,    65,    88,   835,   835,   835,   720,    88,    88,   835,
     724,    89,    67,   840,    71,   842,    66,   710,   261,   733,
     734,   735,   736,    70,   738,   739,    66,   663,   664,   665,
     666,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,    71,
      71,    88,    34,    89,   614,   261,    89,    70,    65,   773,
      65,    88,   622,    71,   653,   897,   897,   897,   897,   897,
     261,    66,    66,    71,   261,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   917,   917,   917,   917,   917,
      89,   727,    65,   729,    70,   788,   732,    66,    70,   813,
     814,   737,   795,   663,   664,   665,   666,    70,    65,    66,
      90,    70,    67,    88,    66,    72,    73,    74,    75,    76,
      77,    78,    79,    89,   684,    82,    83,   370,    66,   372,
       8,    89,    67,    89,    88,    71,   379,   380,    89,   616,
     617,   523,   619,   620,    73,    89,    88,   624,    73,   626,
      73,    66,    71,    67,    19,   555,    88,    88,    88,   852,
      67,   118,   352,    40,   370,    30,   372,   410,   757,   726,
      35,   729,   727,   379,   380,   331,   788,    42,   628,   370,
     562,   372,   789,   370,   783,   372,   378,   342,   379,   380,
     764,   702,   379,   380,   437,   356,   635,   426,   428,   427,
      65,   746,   429,     2,   410,   430,   848,    72,   923,   945,
     355,    76,   201,    -1,   614,    -1,    -1,    -1,   600,   410,
      -1,    -1,   622,   410,    -1,    -1,    -1,    -1,    -1,    94,
      -1,   437,    -1,    -1,    -1,    -1,   825,   102,   103,    -1,
      -1,    -1,    -1,    -1,   109,   110,   437,   112,   113,   114,
     437,   116,   117,    -1,    -1,   844,    -1,    -1,    -1,   124,
     125,   218,   219,    -1,    -1,   647,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   658,    -1,   235,    -1,
     869,    -1,    -1,    -1,    -1,    -1,   875,   876,   765,   766,
     767,   768,   769,   770,   771,   772,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,    -1,   706,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
     277,   278,   279,   280,    -1,    -1,   915,    -1,    -1,    -1,
      -1,    -1,   714,    -1,     3,    -1,   718,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    16,    -1,   938,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
     603,    30,   605,    -1,    33,    -1,    -1,    -1,    13,    14,
      -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,   605,
      -1,    -1,   784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   603,    -1,   605,    -1,   603,    -1,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,
     109,   110,   824,   112,   113,   114,    -1,   116,   117,    94,
      -1,    -1,   121,   122,   123,   124,   125,   102,   103,    -1,
     703,   704,   107,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,   716,    -1,   857,    -1,    -1,    -1,   124,
     125,    -1,    -1,    -1,   441,   442,   443,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   703,   704,    -1,
      -1,    -1,    -1,    -1,    -1,   887,    -1,    -1,    -1,    -1,
     716,    -1,   703,   704,    -1,    -1,   703,   704,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   716,    -1,    -1,   910,   716,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,   541,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,   117,   118,
     119,   608,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,   665,   666,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,   683,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   732,   116,   117,   118,   119,
     737,   121,   122,   123,   124,   125,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    30,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
     117,   118,   119,    -1,   121,   122,   123,   124,   125,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    30,
      -1,    -1,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,   117,   118,   119,    -1,
     121,   122,   123,   124,   125,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    65,    -1,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    76,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    89,    -1,    33,    92,    93,    94,    -1,    -1,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,   117,
     118,   119,    -1,   121,   122,   123,   124,   125,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    92,    93,    94,    30,    -1,    -1,    33,    -1,
      35,    -1,   102,   103,    -1,    -1,    -1,    42,   108,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      65,    -1,    -1,     3,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    13,    14,    -1,    16,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      30,    -1,    -1,    33,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    89,
      -1,    33,    -1,    35,    94,    -1,    -1,    -1,    -1,    -1,
      42,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    65,   124,   125,     3,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    13,    14,    -1,    16,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    30,    -1,    -1,    33,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    94,    -1,    -1,
      -1,    -1,    -1,    42,    -1,   102,   103,    -1,    -1,    -1,
      -1,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    65,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    30,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      -1,    -1,    94,    -1,    -1,    -1,    42,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,    -1,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,     4,     5,    -1,    65,
      -1,     9,   124,   125,    -1,    -1,    -1,    15,    -1,    -1,
      76,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    92,    93,    94,    30,    -1,    -1,
      33,    -1,    35,    -1,   102,   103,    -1,    -1,    -1,    42,
     108,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    28,    -1,    30,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,   118,   119,    -1,   121,   122,
     123,   124,   125,     3,     4,     5,     6,    -1,    -1,     9,
      65,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    94,
      -1,    -1,    42,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    65,    -1,    -1,    -1,   124,
     125,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,   118,   119,
      -1,   121,   122,   123,   124,   125,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    65,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,    70,   112,   113,   114,    -1,   116,
     117,   118,   119,    -1,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    42,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,   118,   119,    -1,   121,   122,
     123,   124,   125,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      -1,     3,     4,     5,     6,    -1,    42,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    19,    -1,    -1,   107,   108,   109,   110,    -1,
     112,   113,   114,    30,   116,   117,   118,   119,    35,   121,
     122,   123,   124,   125,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    65,    -1,
      -1,    30,    -1,    -1,    33,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      30,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
     117,   118,   119,    -1,   121,   122,   123,   124,   125,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    94,    -1,    -1,    42,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      65,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    65,    25,    26,    -1,    -1,    -1,    30,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,   118,   119,    -1,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    19,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    30,
     112,   113,   114,    -1,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    65,    25,    26,    -1,    -1,    -1,
      30,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    19,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,    -1,    30,    -1,    -1,   109,   110,
      35,   112,   113,   114,    -1,   116,   117,    42,    -1,    -1,
      -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      65,    -1,   102,   103,    19,    -1,    -1,   107,   108,   109,
     110,    76,   112,   113,   114,    30,   116,   117,   118,   119,
      35,   121,   122,   123,   124,   125,    -1,    42,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,    -1,   109,   110,    19,   112,   113,   114,
      65,   116,   117,    -1,    -1,    -1,    -1,    30,    -1,   124,
     125,    76,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    30,    -1,    -1,    -1,    -1,    35,   102,   103,    -1,
      -1,    -1,    65,    42,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,    76,    -1,    -1,    -1,    -1,    -1,   124,
     125,    -1,    19,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    94,    -1,    30,    -1,    -1,    -1,    76,    35,   102,
     103,    -1,    -1,    -1,    -1,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,    94,    -1,    -1,    -1,    -1,
      -1,   124,   125,   102,   103,    19,    -1,    -1,    65,    -1,
     109,   110,    -1,   112,   113,   114,    30,   116,   117,    76,
      -1,    35,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,    65,   109,   110,    -1,   112,   113,   114,    -1,   116,
     117,    -1,    76,    -1,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,     7,    -1,    -1,    10,    11,    -1,
     124,   125,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    29,    -1,    -1,    -1,   111,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,    29,    -1,    -1,    -1,   111,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      29,    -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    29,    52,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    65,    44,    45,    -1,
      -1,    -1,    -1,    -1,    73,    52,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    75,    76,
      77,    78,    79,    80,    -1,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      29,    -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    29,    52,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    65,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    65,    88,
      -1,    -1,    -1,    70,    -1,    -1,    95,    96,    75,    76,
      77,    78,    79,    80,    -1,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      29,    -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,
      -1,    -1,   111,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      29,    52,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    65,    44,    45,    -1,    -1,    70,
      -1,    -1,    -1,    52,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    75,    76,    77,    78,
      79,    80,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,
      -1,    -1,   111,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      29,    52,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    65,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    75,    76,    77,    78,
      79,    80,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,
      -1,    -1,   111,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,
     111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   129,   130,     0,     3,     4,     5,     6,     9,    12,
      13,    14,    15,    16,    18,    19,    20,    21,    22,    25,
      26,    30,    33,    35,    42,    65,    76,    89,    92,    93,
      94,    97,    98,    99,   102,   103,   107,   108,   109,   110,
     111,   112,   113,   114,   116,   117,   118,   119,   121,   122,
     123,   124,   125,   131,   132,   133,   134,   136,   137,   141,
     142,   143,   144,   145,   146,   147,   148,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   183,   213,   214,   215,   216,   217,   218,   220,
     221,   222,   223,   224,   291,   292,   297,   298,   309,    35,
      42,    70,   192,   290,   291,   215,   221,   223,   148,   213,
     223,   134,   142,   317,   317,    67,   318,    67,   318,    42,
      65,    76,   204,   205,   206,   207,   208,   209,   210,   211,
     213,   223,   204,   213,   223,    42,   149,   150,   163,   167,
     168,   169,   172,   213,   223,    42,   150,   163,   167,   168,
     169,   172,   213,   223,   149,   169,   150,   168,   169,   149,
     318,   150,   168,   318,   149,   150,   168,   149,   163,   150,
     163,   168,    65,   149,   167,   150,   167,   168,   192,   290,
     314,   312,    65,    72,   219,   228,   312,    65,    89,    65,
      35,    42,   184,   185,    70,    70,   192,   291,    66,    66,
      66,   213,   223,    70,   111,   141,   145,   146,   147,   148,
     240,   289,   290,    89,   289,    89,    65,   226,   228,    42,
      65,   208,   210,   212,    65,   148,   207,   210,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,    89,    89,
      29,    35,    36,    37,    38,    39,    40,    41,    44,    45,
      52,    65,    75,    76,    77,    78,    79,    80,    95,    96,
     104,   105,   106,   111,   146,   148,   156,   158,   160,   162,
     166,   193,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   287,   314,   192,
     314,    70,   314,    73,   264,   283,   288,    72,    65,   250,
     313,   313,    67,    71,   184,   184,    70,   226,   226,   115,
     135,   234,   235,   236,    65,    76,   213,   221,    65,    76,
     213,   213,    70,   141,   213,   204,   314,   212,    66,    66,
     226,   212,    65,   207,   210,   298,   299,   299,   299,   299,
      65,   264,    65,   264,   264,    35,   193,   287,   314,    65,
      65,    65,   272,    65,    76,   225,   226,   229,   230,   225,
      66,    36,    43,    44,    45,    65,    72,    74,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    90,   285,
      65,   264,   272,    76,    81,    82,    77,    78,    46,    47,
      48,    49,    83,    84,    50,    51,    75,    85,    86,    52,
      53,    87,    66,    67,    70,   314,    70,   175,    35,   145,
     146,   147,   148,   157,   158,   187,   188,   189,   190,   191,
     227,    73,   288,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   293,
     294,   296,    66,    90,   186,   186,    71,   185,    67,    71,
      67,    71,   184,    35,   237,   315,   238,   236,    65,   221,
      65,   148,    65,   148,   310,   310,   135,   311,   311,   227,
      66,   226,   226,    66,    66,   212,   289,   289,   289,   289,
     193,   193,    66,    66,    70,   233,   193,   193,   284,   226,
     229,   230,   148,   225,   192,    66,   263,   284,   287,   192,
     284,   193,   272,   272,   272,   273,   273,   274,   274,   275,
     275,   275,   275,   276,   276,   277,   278,   279,   280,   281,
      88,   287,   284,   175,    70,   175,    89,   146,   148,   176,
     177,   178,   315,   312,    65,    76,   207,   213,   225,   207,
     213,   225,    65,    76,   213,   225,   213,   225,    67,    67,
     316,   316,    73,    66,    67,    65,   295,   288,    71,    71,
      67,    71,    67,    89,    71,     7,    10,    11,    17,    23,
      24,    27,    28,    31,    32,    34,    35,    42,   111,   138,
     139,   140,   141,   145,   146,   147,   148,   192,   231,   232,
     233,   239,   241,   242,   243,   244,   245,   246,   247,   248,
     286,   287,   300,   309,    65,   314,   315,   299,   299,   316,
      66,    90,   194,   194,   194,   194,    66,    66,    70,   272,
     234,   315,    67,    67,    67,    66,    66,    66,   225,    66,
      67,    73,    66,   283,    88,   315,   175,   315,    88,    89,
     179,   182,   204,    89,   180,   182,   213,    67,    89,    67,
      89,    71,   148,   310,   310,   310,   310,   148,   310,   310,
      54,   189,   191,    66,    66,    66,   296,    66,   263,    71,
      35,    89,    65,   288,   286,    89,    65,    88,    76,   192,
     231,    65,    65,   317,   317,   213,   223,   213,   223,   213,
     223,   213,   223,    88,    89,    28,    65,   150,    71,   289,
     289,    66,    35,    70,    72,    74,   195,   196,   199,   200,
     201,   202,   203,   284,   197,   198,   238,    66,   255,   193,
     193,   226,   284,   283,    71,   315,    71,   288,   289,   181,
     182,   289,   181,   180,   179,   289,   289,   289,   289,   289,
     289,   295,    66,   287,    54,    88,    89,   286,   231,   287,
      89,    34,   287,   287,    70,   240,   310,   310,   310,   310,
     310,   310,   310,   310,   289,    65,   250,   301,    65,   194,
     194,    88,   198,   288,    35,    42,   196,    72,    90,   201,
      71,   195,    71,    66,    66,    66,    71,   289,   289,    66,
     288,   231,    89,    89,    65,    66,    66,   234,    70,   231,
     250,   307,    88,    66,   301,    71,   195,    54,    73,   288,
      67,   231,    88,   286,   287,   231,   231,   238,   234,    88,
      66,    72,   250,   302,   303,   304,    89,    66,    71,   288,
      54,    73,   231,    89,    66,     8,   315,   238,   302,    89,
     296,    65,    88,    67,    89,    73,   288,   286,    89,   231,
      71,   315,    88,    73,   287,   302,   304,    73,    66,    71,
     302,   250,    66,    88,   231,    88,    65,   250,   306,   305,
     306,   287,    67,    88,    66,   250,   191,   308,    67,   191
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      

/* Line 1806 of yacc.c  */
#line 3289 "c.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



