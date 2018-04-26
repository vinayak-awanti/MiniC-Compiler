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
#line 1 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include "st.h"
void yyerror(const char *error_msg);
int yylex();

void func1(char *s);
void func2(char *s);
void func3(char *s);
void func4(char *s);
void func5();

int labels[20];
int label_num = 0;
int label_top = 0;

int num_scope = 0;
int current_scope = 0;
int parent_scope = -1;
int scope_stack_top = 1;
int scope_stack[50];

static int temp_nb;
char* new_temp();
int is_number(char *num);

FILE *ic_file, *ast_file;

// ast
typedef struct {
	char val[50];
	int num_child;
	int child[50];
} ast_node_t;

ast_node_t ast[500];
char ast_value[50];

int num_node = 0;
int current_node = 1;
int parent_node = 0;
int node_stack_top = 0;
int node_stack[50];

void add_child(int parent_node, int child_node, char *val);
void dfs(int cur_node);
void add_node(char *x,char *val);
void create_space();

#line 117 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 52 "parser.y" /* yacc.c:355  */

	typedef struct {
		char *str;
		char *addr;
	} attrib_t;

#line 154 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCLUDE = 258,
    SEMI_COLON = 259,
    COMMA = 260,
    EQUAL = 261,
    ID = 262,
    OPEN_SQUARE = 263,
    CLOSE_SQUARE = 264,
    NUMCONST = 265,
    CHARCONST = 266,
    INT = 267,
    BOOL = 268,
    CHAR = 269,
    OPEN_FLOWER = 270,
    CLOSE_FLOWER = 271,
    PRINTF = 272,
    SCANF = 273,
    OPEN_SIMPLE = 274,
    CLOSE_SIMPLE = 275,
    IF = 276,
    WHILE = 277,
    BREAK = 278,
    RETURN = 279,
    PLUS_EQUAL = 280,
    MINUS_EQUAL = 281,
    MUL_EQUAL = 282,
    DIV_EQUAL = 283,
    PLUS_PLUS = 284,
    ELSE = 285,
    INT_MAIN = 286,
    MINUS_MINUS = 287,
    LOGIC_OR = 288,
    LOGIC_AND = 289,
    NOT = 290,
    LESS_EQUAL = 291,
    GREAT_EQUAL = 292,
    LESS = 293,
    GREAT = 294,
    NOT_EQUAL = 295,
    EQUAL_EQUAL = 296,
    PLUS = 297,
    MINUS = 298,
    STAR = 299,
    DIV = 300,
    MOD = 301,
    TRUE = 302,
    FALSE = 303
  };
#endif
/* Tokens.  */
#define INCLUDE 258
#define SEMI_COLON 259
#define COMMA 260
#define EQUAL 261
#define ID 262
#define OPEN_SQUARE 263
#define CLOSE_SQUARE 264
#define NUMCONST 265
#define CHARCONST 266
#define INT 267
#define BOOL 268
#define CHAR 269
#define OPEN_FLOWER 270
#define CLOSE_FLOWER 271
#define PRINTF 272
#define SCANF 273
#define OPEN_SIMPLE 274
#define CLOSE_SIMPLE 275
#define IF 276
#define WHILE 277
#define BREAK 278
#define RETURN 279
#define PLUS_EQUAL 280
#define MINUS_EQUAL 281
#define MUL_EQUAL 282
#define DIV_EQUAL 283
#define PLUS_PLUS 284
#define ELSE 285
#define INT_MAIN 286
#define MINUS_MINUS 287
#define LOGIC_OR 288
#define LOGIC_AND 289
#define NOT 290
#define LESS_EQUAL 291
#define GREAT_EQUAL 292
#define LESS 293
#define GREAT 294
#define NOT_EQUAL 295
#define EQUAL_EQUAL 296
#define PLUS 297
#define MINUS 298
#define STAR 299
#define DIV 300
#define MOD 301
#define TRUE 302
#define FALSE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "parser.y" /* yacc.c:355  */

    char *str;
    attrib_t attrib;

#line 267 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 284 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    74,    75,    77,    78,    79,    81,    83,
      85,    85,    98,    99,   101,   104,   111,   124,   138,   152,
     167,   168,   169,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   181,   181,   205,   206,   208,   210,   212,   214,
     215,   217,   218,   220,   222,   220,   225,   227,   231,   231,
     227,   240,   245,   240,   258,   259,   261,   263,   270,   276,
     282,   288,   294,   300,   305,   307,   312,   314,   315,   317,
     318,   320,   320,   320,   341,   343,   357,   370,   382,   396,
     410,   425,   426,   428,   429,   431,   432,   434,   435,   436,
     438,   439,   441,   442,   444,   445,   447,   454,   461,   462,
     464,   465,   466,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "SEMI_COLON", "COMMA",
  "EQUAL", "ID", "OPEN_SQUARE", "CLOSE_SQUARE", "NUMCONST", "CHARCONST",
  "INT", "BOOL", "CHAR", "OPEN_FLOWER", "CLOSE_FLOWER", "PRINTF", "SCANF",
  "OPEN_SIMPLE", "CLOSE_SIMPLE", "IF", "WHILE", "BREAK", "RETURN",
  "PLUS_EQUAL", "MINUS_EQUAL", "MUL_EQUAL", "DIV_EQUAL", "PLUS_PLUS",
  "ELSE", "INT_MAIN", "MINUS_MINUS", "LOGIC_OR", "LOGIC_AND", "NOT",
  "LESS_EQUAL", "GREAT_EQUAL", "LESS", "GREAT", "NOT_EQUAL", "EQUAL_EQUAL",
  "PLUS", "MINUS", "STAR", "DIV", "MOD", "TRUE", "FALSE", "$accept",
  "program", "declarationList", "declaration", "headerDeclaration",
  "mainDeclaration", "varDeclaration", "$@1", "varDeclList",
  "varDeclInitialize", "varDeclId", "typeSpecifier", "statement",
  "compoundStmt", "$@2", "statementList", "declStmt", "printfStmt",
  "scanfStmt", "args", "argList", "expressionStmt", "$@3", "$@4",
  "selectionStmt", "$@5", "$@6", "$@7", "iterationStmt", "$@8", "$@9",
  "returnStmt", "breakStmt", "expression", "simpleExpression",
  "andExpression", "unaryRelExpression", "relExpression", "$@10", "$@11",
  "relop", "sumExpression", "sumop", "term", "mulop", "unaryExpression",
  "unaryop", "factor", "mutable", "immutable", "constant", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -63,   125,    13,    20,   -63,   -63,   -63,   -63,    54,
     -63,   -63,    -4,    -2,   -63,    24,     0,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,    11,   -63,    17,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,    -5,   -63,    11,    11,    21,
     -63,   -63,   -63,   -63,   -63,    11,    11,   -63,   -63,   -63,
     -63,    28,    29,    19,   -63,   -63,    65,   -20,   -63,    53,
     -63,    84,   -63,   -63,   -63,    46,    63,    66,    45,   -63,
      69,   110,    68,    78,   -63,    73,    11,    82,   -63,    81,
     -63,    11,    11,   -63,   -63,   114,    53,   -63,   -63,   -63,
      53,   -63,    11,    11,    11,    11,    11,    11,   -63,   -63,
      99,    11,    94,   -63,   -63,    -5,    11,   -63,   -63,   101,
      11,   102,    29,   -63,    19,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -20,   -63,   -63,   106,   -63,   -63,   -63,
     -63,   -63,    29,   108,   -63,    29,   -63,   -63,   -63,    98,
      53,   -63,   100,   111,   125,    44,   125,   120,   -63,   -63,
     112,   105,   -63,   125,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     8,    43,     0,    10,     4,     7,     6,     5,     0,
      46,    32,     0,     0,    51,     0,     0,    36,     9,    25,
      23,    30,    31,    24,     0,    26,     0,    27,    28,    29,
       1,     3,    20,    21,    22,     0,    35,    40,    40,     0,
      56,    54,    96,   100,   101,     0,     0,    92,    93,   102,
     103,     0,    64,    66,    68,    70,    71,    82,    86,     0,
      91,    95,    94,    99,    44,     0,    16,     0,     0,    13,
      14,    43,     0,    39,    42,     0,     0,     0,    69,    95,
      55,     0,     0,    83,    84,     0,     0,    87,    88,    89,
       0,    90,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,     0,    19,    11,     0,     0,    33,    34,     0,
       0,     0,    52,    98,    65,    67,    75,    78,    76,    77,
      80,    79,    72,    81,    85,    57,     0,    58,    59,    60,
      61,    45,    48,     0,    12,    15,    37,    41,    38,     0,
       0,    97,     0,    17,    43,    73,    43,     0,    53,    49,
       0,     0,    18,    43,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   132,   -63,   -63,    12,   -63,   -63,    36,
     -63,   -63,   -62,   -63,   -63,   -63,   -63,   -63,   -63,   107,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -16,   -49,    75,   -40,   -63,   -63,   -63,
     -63,     4,   -63,    71,   -63,   -56,   -63,   -63,   -45,   -63,
     -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    17,     9,    68,    69,
      70,    35,    18,    19,    36,    71,    20,    21,    22,    72,
      73,    23,    24,   100,    25,    26,   142,   151,    27,    39,
     139,    28,    29,    74,    52,    53,    54,    55,    85,   140,
     122,    56,    86,    57,    90,    58,    59,    60,    61,    62,
      63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    79,    66,    91,    41,     1,    78,    42,    64,   108,
      43,    44,     8,    30,    79,    37,     8,    38,    42,    45,
      -2,    43,    44,     1,    87,    88,    89,   112,    40,    77,
      45,    79,    80,     2,   124,    46,    79,    79,    65,    67,
      76,    79,   115,    47,    48,    79,    46,    49,    50,   104,
     105,     2,   132,    82,    47,    48,    79,   135,    49,    50,
      42,    79,    81,    43,    44,   101,    32,    33,    34,   -74,
     -74,   102,    45,   103,   -74,   106,   125,   126,   127,   128,
     129,   130,   148,   110,   149,   -74,    83,    84,   109,    93,
      92,   154,    93,   111,   137,    79,    47,    48,   -74,   -74,
      49,    50,   113,   131,   133,   136,   138,    83,    84,    94,
      95,    96,    97,    98,    10,   141,    99,   143,   144,   147,
     146,   152,   -10,   -10,   -10,    11,   107,    12,    13,    10,
     150,   -47,    14,    15,    16,   153,    31,   -10,   -10,   -10,
      11,   134,    12,    13,   145,    75,   -47,    14,    15,    16,
     116,   117,   118,   119,   120,   121,   114,   123
};

static const yytype_uint8 yycheck[] =
{
      16,    46,     7,    59,     4,     3,    46,     7,    24,    71,
      10,    11,     0,     0,    59,    19,     4,    19,     7,    19,
       0,    10,    11,     3,    44,    45,    46,    76,     4,    45,
      19,    76,     4,    31,    90,    35,    81,    82,    21,    44,
      19,    86,    82,    43,    44,    90,    35,    47,    48,     4,
       5,    31,   101,    34,    43,    44,   101,   106,    47,    48,
       7,   106,    33,    10,    11,    19,    12,    13,    14,     4,
       5,     8,    19,     7,     9,     6,    92,    93,    94,    95,
      96,    97,   144,     5,   146,    20,    42,    43,    20,     8,
       6,   153,     8,    20,   110,   140,    43,    44,    33,    34,
      47,    48,    20,     4,    10,     4,     4,    42,    43,    25,
      26,    27,    28,    29,     4,     9,    32,     9,    20,     8,
      20,     9,    12,    13,    14,    15,    16,    17,    18,     4,
      10,    21,    22,    23,    24,    30,     4,    12,    13,    14,
      15,   105,    17,    18,   140,    38,    21,    22,    23,    24,
      36,    37,    38,    39,    40,    41,    81,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    50,    51,    52,    53,    54,    55,    56,
       4,    15,    17,    18,    22,    23,    24,    55,    61,    62,
      65,    66,    67,    70,    71,    73,    74,    77,    80,    81,
       0,    52,    12,    13,    14,    60,    63,    19,    19,    78,
       4,     4,     7,    10,    11,    19,    35,    43,    44,    47,
      48,    82,    83,    84,    85,    86,    90,    92,    94,    95,
      96,    97,    98,    99,    82,    21,     7,    44,    57,    58,
      59,    64,    68,    69,    82,    68,    19,    82,    85,    97,
       4,    33,    34,    42,    43,    87,    91,    44,    45,    46,
      93,    94,     6,     8,    25,    26,    27,    28,    29,    32,
      72,    19,     8,     7,     4,     5,     6,    16,    61,    20,
       5,    20,    83,    20,    84,    85,    36,    37,    38,    39,
      40,    41,    89,    92,    94,    82,    82,    82,    82,    82,
      82,     4,    83,    10,    58,    83,     4,    82,     4,    79,
      88,     9,    75,     9,    20,    90,    20,     8,    61,    61,
      10,    76,     9,    30,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    53,    54,
      56,    55,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    63,    62,    64,    64,    65,    66,    67,    68,
      68,    69,    69,    71,    72,    70,    70,    74,    75,    76,
      73,    78,    79,    77,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    87,    88,    86,    86,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     4,     3,     1,     1,     3,     1,     4,     7,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     1,     5,     5,     1,
       0,     3,     1,     0,     0,     4,     1,     0,     0,     0,
      10,     0,     0,     7,     2,     3,     2,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     1,     3,     1,     2,
       1,     0,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     1
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
        case 10:
#line 85 "parser.y" /* yacc.c:1646  */
    {
	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;
}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "parser.y" /* yacc.c:1646  */
    {
	fprintf(ic_file, "%s %s \n", (yyvsp[-2].str), (yyvsp[-1].str));
	current_node = parent_node;
	char decl_val[50] = {0};
	sprintf(decl_val, "decl (%d)", current_node);
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, decl_val);
}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "parser.y" /* yacc.c:1646  */
    {sprintf((yyval.str), "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 99 "parser.y" /* yacc.c:1646  */
    {sprintf((yyval.str), "%s", (yyvsp[0].str));}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "parser.y" /* yacc.c:1646  */
    {
	(yyval.str) = (yyvsp[0].attrib).str;
}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "parser.y" /* yacc.c:1646  */
    {
 	if (is_number((yyvsp[0].attrib).str)) {
 		set_value((yyvsp[-2].attrib).str, (yyvsp[0].attrib).str, current_scope);
 	}
 	sprintf((yyval.str), "%s = %s", (yyvsp[-2].attrib).str, (yyvsp[0].attrib).str);
}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 111 "parser.y" /* yacc.c:1646  */
    {
	char type[20] = {0};
	sprintf(type, "%s", (strcmp((yyvsp[-1].str), ",") ? (yyvsp[-1].str) : (yyvsp[(-2) - (1)].str)));
	if(load_token((yyvsp[0].str), type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", (yyvsp[0].str));
		yyerror(buf);
		YYABORT;
	}
	memset(ast_value, 0, sizeof(ast_value));
	current_node = ++num_node;
	sprintf(ast_value, "%s %s (%d)", type, (yyvsp[0].str), current_node);
	add_child(parent_node, current_node, ast_value);
}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "parser.y" /* yacc.c:1646  */
    {
	char type[20] = {0};
	sprintf(type, "%s[%s]", (strcmp((yyvsp[-4].str), ",") ? (yyvsp[-4].str) : (yyvsp[(-2) - (4)].str)), (yyvsp[-1].str));
	if(load_token((yyvsp[-3].str), type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", (yyvsp[-3].str));
		yyerror(buf);
		YYABORT;
	}
	memset(ast_value, 0, sizeof(ast_value));
	current_node = ++num_node;
	sprintf(ast_value, "%s %s (%d)", type, (yyvsp[-3].str), current_node);
	add_child(parent_node, current_node, ast_value);
	sprintf((yyval.attrib).str, "%s%s%s%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "parser.y" /* yacc.c:1646  */
    {
	char type[20] = {0};
	sprintf(type, "%s[%s][%s]", (strcmp((yyvsp[-7].str), ",") ? (yyvsp[-7].str) : (yyvsp[(-2) - (7)].str)), (yyvsp[-4].str), (yyvsp[-1].str));
	if(load_token((yyvsp[-6].str), type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", (yyvsp[-6].str));
		yyerror(buf);
		YYABORT;
	}
	memset(ast_value, 0, sizeof(ast_value));
	current_node = ++num_node;
	sprintf(ast_value, "%s %s (%d)", type, (yyvsp[-6].str), current_node);
	add_child(parent_node, current_node, ast_value);
	sprintf((yyval.attrib).str, "%s%s%s%s%s%s%s", (yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "parser.y" /* yacc.c:1646  */
    {
	char type[20] = {0};
	sprintf(type, "%s*", (strcmp((yyvsp[-2].str), ",") ? (yyvsp[-2].str) : (yyvsp[(-2) - (2)].str)));
	if(load_token((yyvsp[0].str), type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", (yyvsp[0].str));
		yyerror(buf);
		YYABORT;
	}
	sprintf((yyval.attrib).str, "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
	memset(ast_value, 0, sizeof(ast_value));
	current_node = ++num_node;
	sprintf(ast_value, "%s %s (%d)", type, (yyvsp[0].str), current_node);
	add_child(parent_node, current_node, ast_value);
}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "parser.y" /* yacc.c:1646  */
    {}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "parser.y" /* yacc.c:1646  */
    {}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "parser.y" /* yacc.c:1646  */
    {
			// maintaining scope
			parent_scope = scope_stack[scope_stack_top - 1];
			scope_stack[scope_stack_top++] = ++num_scope;
			current_scope = num_scope;
			set_parent_scope(current_scope, parent_scope);
			
			// maintaining ast nodes
			node_stack[node_stack_top++] = parent_node;
			current_node = ++num_node;
			parent_node = current_node;
		}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "parser.y" /* yacc.c:1646  */
    {
			// maintaining scope
			current_scope = parent_scope;
			--scope_stack_top;
			
			// maintaining ast nodes
			current_node = parent_node;
			char stmt_val[50] = {0};
			sprintf(stmt_val, "stmt_list (%d)", current_node);
			parent_node = node_stack[--node_stack_top];
			add_child(parent_node, current_node, stmt_val);
		}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "parser.y" /* yacc.c:1646  */
    {
	
}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 222 "parser.y" /* yacc.c:1646  */
    {

}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 227 "parser.y" /* yacc.c:1646  */
    {
	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;
}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 231 "parser.y" /* yacc.c:1646  */
    {func1((yyvsp[0].attrib).str);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 231 "parser.y" /* yacc.c:1646  */
    {func2((yyvsp[0].str));}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 231 "parser.y" /* yacc.c:1646  */
    {
	current_node = parent_node;
	char if_val[50] = {0};
	sprintf(if_val, "branch (%d)", current_node);
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, if_val);
	func3((yyvsp[0].str));
}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 240 "parser.y" /* yacc.c:1646  */
    {
	fprintf(ic_file, "L%d:\n",label_num + 1);
	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;
}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 245 "parser.y" /* yacc.c:1646  */
    {

	func4((yyvsp[0].attrib).str);
	
}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 249 "parser.y" /* yacc.c:1646  */
    {
	func5();
	current_node = parent_node;
	char while_val[50] = {0};
	sprintf(while_val, "while (%d)", current_node);
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, while_val);	

}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 263 "parser.y" /* yacc.c:1646  */
    {
	fprintf(ic_file, "%s %s %s\n", (yyvsp[-2].attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);
	
	if (is_number((yyvsp[0].attrib).str)) {
		set_value((yyvsp[-2].attrib).str, (yyvsp[0].attrib).str, current_scope);
	}
}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 270 "parser.y" /* yacc.c:1646  */
    {
	
	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s + %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[0].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-2].attrib).str, (yyval.attrib).str);
}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 276 "parser.y" /* yacc.c:1646  */
    {

	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s - %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[0].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-2].attrib).str, (yyval.attrib).str);
}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 282 "parser.y" /* yacc.c:1646  */
    {

	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s * %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[0].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-2].attrib).str, (yyval.attrib).str);
}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 288 "parser.y" /* yacc.c:1646  */
    {
           
	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s / %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[0].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-2].attrib).str, (yyval.attrib).str);
}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 294 "parser.y" /* yacc.c:1646  */
    {
	
	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s + 1\n", (yyval.attrib).str, (yyvsp[-1].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-1].attrib).str, (yyval.attrib).str);
}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 300 "parser.y" /* yacc.c:1646  */
    {
	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s - 1\n", (yyval.attrib).str, (yyvsp[-1].attrib).str);
	fprintf(ic_file, "%s = %s\n", (yyvsp[-1].attrib).str, (yyval.attrib).str);
}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 307 "parser.y" /* yacc.c:1646  */
    {
				(yyval.attrib).str = new_temp();
				fprintf(ic_file, "%s = %s %s %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);

}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = new_temp(); fprintf(ic_file, "%s = %s %s\n", (yyval.attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 320 "parser.y" /* yacc.c:1646  */
    {create_space();}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 320 "parser.y" /* yacc.c:1646  */
    {}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 320 "parser.y" /* yacc.c:1646  */
    {
	
	(yyval.attrib).str = new_temp();
	fprintf(ic_file, "%s = %s %s %s\n", (yyval.attrib).str, (yyvsp[-4].attrib).str, (yyvsp[-2].str), (yyvsp[0].attrib).str);
/*	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;

	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (==)" );
	printf("STTOP %d\n",node_stack_top);
	--node_stack_top;
	parent_node = node_stack[--node_stack_top];

	add_child(parent_node, current_node, cond_val);


*/

	}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 344 "parser.y" /* yacc.c:1646  */
    {
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (<=)" );

	parent_node = node_stack[node_stack_top--];
	add_child(parent_node, current_node, cond_val);
    //create_space();
    //create_space();

	
}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 357 "parser.y" /* yacc.c:1646  */
    {
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (<)" );
	parent_node = node_stack[node_stack_top-1];
	add_child(parent_node, current_node, cond_val);

    //create_space();
    //create_space();

	
}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 370 "parser.y" /* yacc.c:1646  */
    {
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (>)" );
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, cond_val);
        //create_space();
    //create_space();

	
}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 382 "parser.y" /* yacc.c:1646  */
    {
      
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (<=)" );
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, cond_val);
        //create_space();
    //create_space();

	

      }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 396 "parser.y" /* yacc.c:1646  */
    {
      {
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (==)" );
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, cond_val);
        //create_space();
    //create_space();

	
}
      }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 410 "parser.y" /* yacc.c:1646  */
    {
      {
     
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "op = (!=)" );
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, cond_val);
        //create_space();
    //create_space();

	
}
      }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 425 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 426 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 431 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", (yyval.attrib).str, (yyvsp[-2].attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 432 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].attrib).str;}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 438 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = new_temp(); fprintf(ic_file, "%s = %s%s\n", (yyval.attrib).str, (yyvsp[-1].str), (yyvsp[0].attrib).str);}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 439 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = (yyvsp[0].str);}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 444 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.str), (yyvsp[0].attrib).str);}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 445 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.str), (yyvsp[0].attrib).str);}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 447 "parser.y" /* yacc.c:1646  */
    {
	(yyval.attrib).str = strdup((yyvsp[0].str));
	if (fetch_token((yyvsp[0].str), current_scope)) {
		printf("undeclared variable %s\n", (yyvsp[0].str));
		YYABORT;
	}
}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 454 "parser.y" /* yacc.c:1646  */
    {
        
	char *idx = new_temp();
	fprintf(ic_file, "%s = 4 * %s\n", idx, (yyvsp[-1].attrib).str);
	sprintf((yyval.attrib).str, "%s[%s]", (yyvsp[-3].attrib).str, idx);
}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 461 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = strdup((yyvsp[-1].attrib).str);}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 462 "parser.y" /* yacc.c:1646  */
    {(yyval.attrib).str = strdup((yyvsp[0].str));}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2114 "y.tab.c" /* yacc.c:1646  */
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
#line 469 "parser.y" /* yacc.c:1906  */

char* new_temp() {
	char* tmp = malloc(10);
	tmp[0] = 't';
	sprintf(tmp + 1, "%d", temp_nb);
	++temp_nb;
	strcat(tmp, "\0");
	return tmp;
}

void yyerror(const char *error_msg) {
	printf("error_msg: %s\n", error_msg);
}

int main() {
	set_parent_scope(0, -1);
	ic_file = fopen("ic", "w");
	ast_file = fopen("ast.dot", "w");
	fprintf(ast_file, "digraph ast {\n");
	if (!yyparse()) {
		printf("\n\nClean code after removing comments :-> \n");
		printf("**********************************************\n");
		printf("\n%s\n",code);
		printf("**********************************************\n\n\n");
		printf("Symbol Table :->\n\n");
		show_me();
		printf("successful\n");
	} else {
		printf("unsuccessful\n");
	}
	dfs(0);
	fprintf(ast_file, "}\n");
	fclose(ic_file);
	fclose(ast_file);
	return 0;
}

void func1( char *s ) {
	label_num++;
	char * temp = new_temp();
	fprintf(ic_file, "%s = not %s\n", temp, s);
	fprintf(ic_file, "if %s goto L%d\n", temp, label_num);
	labels[++label_top]=label_num;
}


void func2( char *s ) {
	label_num++;
	int x = labels[label_top--];
	fprintf(ic_file, "goto L%d\n",label_num);
	fprintf(ic_file, "L%d: \n",x);
	labels[++label_top] = label_num;	
}

void func3( char *s) {
	int y = labels[label_top];
	label_top--;
	fprintf(ic_file, "L%d: \n",y); 
}

void func4(char *s){
	char * temp = new_temp();
	fprintf(ic_file, "%s = not %s\n", temp, s);
	fprintf(ic_file, "if %s goto L%d\n", temp, label_num + 2);
	labels[++label_top] = label_num + 2;
	labels[++label_top] = label_num + 1;
	label_num += 2;
}

void func5() {
	fprintf(ic_file, "goto L%d\n", labels[label_top]);
	label_top--;
	fprintf(ic_file, "L%d:\n", labels[label_top]);
	label_top--;
}

int is_number(char *num) {
	return (strcmp("0", num) == 0 || atoi(num));
}

void add_child(int parent_node, int child_node, char val[]) {
//	printf("par_nod: %d, child_nod: %d, val: %s num_child: %d\n", parent_node, child_node, val, ast[parent_node].num_child);
	strcpy(ast[child_node].val, val);
	ast[parent_node].child[ast[parent_node].num_child] = child_node;
	++ast[parent_node].num_child;
}

void dfs(int cur_node) {
//	printf("node: %d val: %s num_chlid: %d\n\n", cur_node, ast[cur_node].val, ast[cur_node].num_child);
	for (int i = 0; i < ast[cur_node].num_child; ++i) {
		fprintf(ast_file, "\t\"%s\" -> \"%s\";\n", ast[cur_node].val, ast[ast[cur_node].child[i]].val);
		dfs(ast[cur_node].child[i]);
	}
}

void create_space(){
	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;
}
void add_node(char *x,char *val){
	 
	current_node = parent_node;
	char cond_val[50] = {0};
	sprintf(cond_val, "%s %s",x,val);
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, cond_val);
}
