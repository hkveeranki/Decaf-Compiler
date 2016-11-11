/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "decaf.y" /* yacc.c:339  */

#include "ClassDefs.h"
#include <bits/stdc++.h>

  extern "C" int yylex();
  extern "C" int yyparse();
  extern "C" FILE *yyin;
  extern "C" int line_num;
  extern union Node yylval;
  extern "C" int errors;
  void yyerror(const char *s);
  class Prog* start = NULL;
  int errors=0;

#line 81 "decaf.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "decaf.tab.h".  */
#ifndef YY_YY_DECAF_TAB_H_INCLUDED
# define YY_YY_DECAF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    CALLOUT = 259,
    RETURN = 260,
    BREAK = 261,
    CONTINUE = 262,
    IF = 263,
    ELSE = 264,
    FOR = 265,
    COMMA = 266,
    SC = 267,
    BOOLEAN = 268,
    CHAR = 269,
    STRING = 270,
    TYPE = 271,
    ID = 272,
    VOID = 273,
    INTEGER = 274,
    OB = 275,
    CB = 276,
    OSB = 277,
    CSB = 278,
    OP = 279,
    CP = 280,
    COND_AND = 281,
    COND_OR = 282,
    NOT = 283,
    ADD = 284,
    SUB = 285,
    MUL = 286,
    DIV = 287,
    MOD = 288,
    LT = 289,
    GT = 290,
    LE = 291,
    GE = 292,
    EQUAL = 293,
    NOT_EQUAL = 294,
    EQ = 295,
    ADDEQ = 296,
    SUBEQ = 297
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DECAF_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "decaf.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    74,    77,    80,    83,    84,    87,    88,
      91,    94,    97,    98,   101,   102,   110,   113,   120,   126,
     129,   132,   139,   142,   146,   149,   152,   153,   154,   155,
     156,   159,   160,   161,   162,   163,   166,   167,   168,   171,
     172,   175,   176,   180,   181,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   206,   207,   210,   211,   214,   215,
     216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "CALLOUT", "RETURN", "BREAK",
  "CONTINUE", "IF", "ELSE", "FOR", "COMMA", "SC", "BOOLEAN", "CHAR",
  "STRING", "TYPE", "ID", "VOID", "INTEGER", "OB", "CB", "OSB", "CSB",
  "OP", "CP", "COND_AND", "COND_OR", "NOT", "ADD", "SUB", "MUL", "DIV",
  "MOD", "LT", "GT", "LE", "GE", "EQUAL", "NOT_EQUAL", "EQ", "ADDEQ",
  "SUBEQ", "$accept", "Program", "Field_declarations", "Field_declaration",
  "Variables", "Variable", "Method_declarations", "Method_declaration",
  "Method_Args", "Method_Arg", "Block", "Var_declarations",
  "Var_declaration", "Var_names", "Statements", "Statement", "Assignment",
  "Method_Call", "Params", "Location", "Expression", "Callout_Args",
  "Callout_Arg", "Literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,     4,    11,    27,   -69,   -69,     6,    31,    35,    41,
      42,    22,    38,    55,   -69,    68,   -69,   -69,    51,   -69,
      75,    -2,    76,    78,    76,    68,    79,    81,   -69,    83,
     -69,    96,   -69,   -69,   -69,   108,   103,   -69,   111,   109,
      99,   115,    80,    83,   110,   -69,   112,   -69,   104,    37,
     118,   133,   122,   144,    69,   -69,   -69,   -69,   -69,   150,
     -33,   -69,   108,   115,   163,   -69,   -69,   -69,   -69,   181,
     181,   181,   -69,   -69,    77,   -69,   -69,   -69,   181,   125,
     181,   181,   -69,   181,   181,   181,   -69,   -69,   -69,   218,
     -69,    26,   -69,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   233,   181,   203,    -6,
     247,   105,   121,   137,    -5,   -69,   270,   270,    26,    26,
     -69,   -69,   -69,    13,    13,    13,    13,   261,   261,    76,
      44,   -69,   181,   -69,   -69,   -69,   -69,   173,   -69,   170,
     181,   247,   -69,   247,   -69,    76,   186,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,    10,     0,     0,     0,
       0,    10,     8,     5,     6,     0,     4,     2,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    19,
      12,     8,     7,    13,     9,    16,     0,    24,     0,     0,
       0,    22,     0,    19,     0,    15,     0,    21,     0,     0,
       0,     0,     0,     0,    43,    18,    35,    25,    26,     0,
       0,    20,    16,    22,     0,    31,    70,    69,    68,     0,
       0,     0,    46,    45,     0,    47,    33,    34,     0,     0,
       0,     0,    27,     0,     0,     0,    17,    23,    64,     0,
      62,    61,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    63,    60,    59,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,    44,     0,    39,    36,    38,    37,     0,    40,    28,
       0,    42,    67,    66,    65,     0,     0,    29,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -69,   157,   171,   -69,   166,   127,
     -24,   140,   -69,   128,   -69,   -69,   -69,   142,   -69,   151,
     -68,   -69,   -69,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     9,    13,    14,    10,    11,    22,    40,
      30,    37,    38,    47,    42,    57,    58,    72,   109,    73,
      74,   114,   144,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    89,    90,    91,     1,   132,   137,    83,    84,    85,
     106,     4,   108,   110,    27,   111,   112,   113,    56,   133,
     138,     3,     7,    28,     8,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    18,   130,
       8,    48,    95,    96,    97,    98,    99,     5,    12,    65,
      66,    67,    15,    16,    54,   140,    68,    97,    98,    99,
      20,    69,    21,    17,   141,    70,    23,    71,    25,   143,
      93,    94,   146,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    48,    49,    50,    51,    52,    92,
      53,    80,    21,    81,    26,    31,    29,    54,    35,    36,
      29,    55,    34,    93,    94,   139,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   134,    20,    39,
      41,   147,   148,    43,    45,    44,    46,    62,    64,    63,
      76,    93,    94,   135,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    77,    78,    93,    94,   136,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    79,    82,    93,    94,   107,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    48,    88,   145,
      32,    24,    19,    61,    59,    48,    66,    67,   142,    86,
      54,    87,    68,    60,    66,    67,     0,    69,    54,     0,
      68,    70,     0,    71,     0,    69,    29,     0,     0,    70,
       0,    71,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   131,     0,     0,    93,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   115,    93,    94,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   129,    93,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    93,    94,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    95,
      96,    97,    98,    99,   100,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      24,    69,    70,    71,     3,    11,    11,    40,    41,    42,
      78,     0,    80,    81,    16,    83,    84,    85,    42,    25,
      25,    17,    16,    25,    18,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    16,   107,
      18,     4,    29,    30,    31,    32,    33,    20,    17,    12,
      13,    14,    17,    12,    17,    11,    19,    31,    32,    33,
      22,    24,    24,    21,   132,    28,    11,    30,    17,   137,
      26,    27,   140,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     4,     5,     6,     7,     8,    12,
      10,    22,    24,    24,    19,    17,    20,    17,    17,    16,
      20,    21,    23,    26,    27,   129,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    12,    22,    11,
      17,   145,   146,    12,    25,    16,    11,    17,    24,    17,
      12,    26,    27,    12,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    12,    24,    26,    27,    12,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    17,    12,    26,    27,    40,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     4,    15,     9,
      23,    15,    11,    43,    42,     4,    13,    14,    15,    62,
      17,    63,    19,    42,    13,    14,    -1,    24,    17,    -1,
      19,    28,    -1,    30,    -1,    24,    20,    -1,    -1,    28,
      -1,    30,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    23,    -1,    -1,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    29,
      30,    31,    32,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    17,     0,    20,    45,    16,    18,    46,
      49,    50,    17,    47,    48,    17,    12,    21,    16,    49,
      22,    24,    51,    11,    51,    17,    19,    16,    25,    20,
      53,    17,    48,    53,    23,    17,    16,    54,    55,    11,
      52,    17,    57,    12,    16,    25,    11,    56,     4,     5,
       6,     7,     8,    10,    17,    21,    53,    58,    59,    60,
      62,    54,    17,    17,    24,    12,    13,    14,    19,    24,
      28,    30,    60,    62,    63,    66,    12,    12,    24,    17,
      22,    24,    12,    40,    41,    42,    52,    56,    15,    63,
      63,    63,    12,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    63,    40,    63,    61,
      63,    63,    63,    63,    64,    25,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    25,
      63,    23,    11,    25,    12,    12,    12,    11,    25,    53,
      11,    63,    15,    63,    65,     9,    63,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     3,     2,     1,     3,     1,     4,
       0,     2,     4,     4,     2,     5,     0,     4,     4,     0,
       3,     3,     0,     3,     0,     2,     1,     2,     5,     7,
       7,     2,     3,     2,     2,     1,     4,     4,     4,     4,
       5,     1,     3,     1,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     0,     3,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 68 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.prog) = new Prog(string((yyvsp[-4].value)),(yyvsp[-2].fields),(yyvsp[-1].methods));
    start = (yyval.prog);
  }
#line 1382 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.fields) = new fieldDecls();
  }
#line 1390 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "decaf.y" /* yacc.c:1646  */
    {(yyval.fields)->push_back((yyvsp[-1].field));}
#line 1396 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "decaf.y" /* yacc.c:1646  */
    {(yyval.field) = new fieldDecl(string((yyvsp[-1].value)),(yyvsp[0].vars));}
#line 1402 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "decaf.y" /* yacc.c:1646  */
    {(yyval.vars) = new Vars();(yyval.vars)->push_back((yyvsp[0].var));}
#line 1408 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "decaf.y" /* yacc.c:1646  */
    { (yyval.vars)->push_back((yyvsp[0].var)); }
#line 1414 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "decaf.y" /* yacc.c:1646  */
    { (yyval.var) = new Var(string("Normal"),string((yyvsp[0].value)));}
#line 1420 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 88 "decaf.y" /* yacc.c:1646  */
    { (yyval.var) = new Var(string("Array"),string((yyvsp[-3].value)),(yyvsp[-1].number));}
#line 1426 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.methods) = new methodDecls();
  }
#line 1434 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 94 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[0].methods)->push_back((yyvsp[-1].method));(yyval.methods) = (yyvsp[0].methods);}
#line 1440 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "decaf.y" /* yacc.c:1646  */
    {(yyval.method) = new methodDecl(string((yyvsp[-3].value)),(yyvsp[-2].value),(yyvsp[-1].method_args),(yyvsp[0].block));}
#line 1446 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "decaf.y" /* yacc.c:1646  */
    {(yyval.method) = new methodDecl(string((yyvsp[-3].value)),(yyvsp[-2].value),(yyvsp[-1].method_args),(yyvsp[0].block));}
#line 1452 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "decaf.y" /* yacc.c:1646  */
    {(yyval.method_args) = new methodArgs();}
#line 1458 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "decaf.y" /* yacc.c:1646  */
    {
    methodArg* arg = new methodArg(string((yyvsp[-3].value)),string((yyvsp[-2].value)));
    (yyvsp[-1].method_args)->push_back(arg);
    (yyval.method_args) = (yyvsp[-1].method_args);
  }
#line 1468 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.method_args) = new methodArgs();
  }
#line 1476 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "decaf.y" /* yacc.c:1646  */
    {
    methodArg* arg = new methodArg(string((yyvsp[-2].value)),string((yyvsp[-1].value)));
    (yyvsp[0].method_args)->push_back(arg);
    (yyval.method_args) = (yyvsp[0].method_args);
  }
#line 1486 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.block) = new Block((yyvsp[-2].var_decls),(yyvsp[-1].stmts));
  }
#line 1494 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.var_decls) = new varDecls();
  }
#line 1502 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 129 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[0].var_decls)->push_back((yyvsp[-2].var_decl));(yyval.var_decls) = (yyvsp[0].var_decls);}
#line 1508 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "decaf.y" /* yacc.c:1646  */
    {
    (yyvsp[0].mylist)->push_back((yyvsp[-1].value));
    (yyval.var_decl) = new varDecl(string((yyvsp[-2].value)),(yyvsp[0].mylist));
  }
#line 1517 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "decaf.y" /* yacc.c:1646  */
    {
        (yyval.mylist) = new stringList();
  }
#line 1525 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[0].mylist)->push_back(string((yyvsp[-1].value)));(yyval.mylist) = (yyvsp[0].mylist);}
#line 1531 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 146 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.stmts) = new Stmts();
  }
#line 1539 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmts)->push_back((yyvsp[0].stmt));}
#line 1545 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].assignment);}
#line 1551 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[-1].method_call);}
#line 1557 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new ifElseStmt((yyvsp[-2].expr),(yyvsp[0].block),NULL);}
#line 1563 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 155 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new ifElseStmt((yyvsp[-4].expr),(yyvsp[-2].block),(yyvsp[0].block));}
#line 1569 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 156 "decaf.y" /* yacc.c:1646  */
    {
    (yyval.stmt) = new forStmt(string((yyvsp[-5].value)),(yyvsp[-3].expr),(yyvsp[-1].expr),(yyvsp[0].block));
  }
#line 1577 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 159 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new returnStmt(NULL);}
#line 1583 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new returnStmt((yyvsp[-1].expr));}
#line 1589 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 161 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new breakStmt();}
#line 1595 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = new continueStmt();}
#line 1601 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "decaf.y" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].block);}
#line 1607 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 166 "decaf.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-3].location),string((yyvsp[-2].value)),(yyvsp[-1].expr));}
#line 1613 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 167 "decaf.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-3].location),string((yyvsp[-2].value)),(yyvsp[-1].expr));}
#line 1619 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "decaf.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-3].location),string((yyvsp[-2].value)),(yyvsp[-1].expr));}
#line 1625 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 171 "decaf.y" /* yacc.c:1646  */
    {(yyval.method_call) = new Method(string((yyvsp[-3].value)),(yyvsp[-1].parameters));}
#line 1631 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 172 "decaf.y" /* yacc.c:1646  */
    {(yyval.method_call) = new calloutCall(string((yyvsp[-2].value)),(yyvsp[-1].callout_args));}
#line 1637 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "decaf.y" /* yacc.c:1646  */
    {(yyval.parameters) = new Params();(yyval.parameters)->push_back((yyvsp[0].expr));}
#line 1643 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "decaf.y" /* yacc.c:1646  */
    {(yyval.parameters)->push_back((yyvsp[0].expr));}
#line 1649 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 180 "decaf.y" /* yacc.c:1646  */
    {(yyval.location) = new Location(string((yyvsp[0].value)),string("Normal"));}
#line 1655 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "decaf.y" /* yacc.c:1646  */
    {(yyval.location) = new Location(string((yyvsp[-3].value)),string("Array"),(yyvsp[-1].expr));}
#line 1661 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 184 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].location);}
#line 1667 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 185 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].method_call);}
#line 1673 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 186 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].literal);}
#line 1679 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 187 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1685 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 188 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1691 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 189 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1697 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 190 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1703 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 191 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1709 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 192 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1715 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 193 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1721 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1727 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1733 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 196 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1739 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 197 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1745 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 198 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1751 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new binExpr((yyvsp[-2].expr),string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1757 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 200 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new unExpr(string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1763 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 201 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new unExpr(string((yyvsp[-1].value)),(yyvsp[0].expr));}
#line 1769 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 202 "decaf.y" /* yacc.c:1646  */
    {(yyval.expr) = new EnclExpr((yyvsp[-1].expr));}
#line 1775 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 206 "decaf.y" /* yacc.c:1646  */
    {(yyval.callout_args) = new calloutArgs();}
#line 1781 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 207 "decaf.y" /* yacc.c:1646  */
    {(yyval.callout_args)->push_back((yyvsp[0].callout_arg));}
#line 1787 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 210 "decaf.y" /* yacc.c:1646  */
    {(yyval.callout_arg) = new calloutArg((yyvsp[0].expr));}
#line 1793 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 211 "decaf.y" /* yacc.c:1646  */
    {(yyval.callout_arg) = new calloutArg(string((yyvsp[0].value)));}
#line 1799 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 214 "decaf.y" /* yacc.c:1646  */
    {(yyval.literal) = new intLiteral((yyvsp[0].number));}
#line 1805 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 215 "decaf.y" /* yacc.c:1646  */
    {(yyval.literal) = new charLiteral(string((yyvsp[0].value)));}
#line 1811 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 216 "decaf.y" /* yacc.c:1646  */
    {(yyval.literal) = new boolLiteral(string((yyvsp[0].value)));}
#line 1817 "decaf.tab.c" /* yacc.c:1646  */
    break;


#line 1821 "decaf.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 218 "decaf.y" /* yacc.c:1906  */

int main(int argc, char **argv) {
  if(argc == 1) {
		printf("No Input File Given\n");
		exit(-1);
	}

	FILE *input = fopen(argv[1], "r");

	if (input == NULL){
		printf("Can't open the given file!\n");
		exit(-1);
	}
	yyin = input;
	do {
		yyparse();
	} while (!feof(yyin));
	printf("Semantical Analysis Success\n");
	if(start){
    start->traverse(); /* Traversals */
    /* Do the code generation part */
		start->codegen();
    if(errors == 0){
      /* Print the code */
      start->generateCode();
    }
    else{
      cout << errors << " Errors found\n";
    }
	}
}
void yyerror(const char *s){
	errors++;
	printf("Error:%s at %d\n",s,line_num);
  exit(-1);
}
