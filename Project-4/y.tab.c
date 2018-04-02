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

	#include <bits/stdc++.h>
	#include "symboltable.h"
	#include "lex.yy.c"

	using namespace std;

	int yyerror(char *msg);

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  extern entry_t** constant_table;

	int current_dtype;

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];
	int p_idx = 0;
	int p=0;
  int rhs = 0;

	void type_check(int,int,int);
	vector<int> merge(vector<int>& v1, vector<int>& v2);
	void backpatch(vector<int>&, int);
	void gencode(string);
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void printlist(vector<int>);

	int nextinstr = 0;
	int temp_var_number = 0;

	vector<string> ICG;


#line 108 "y.tab.c" /* yacc.c:339  */

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    DEC_CONSTANT = 259,
    HEX_CONSTANT = 260,
    CHAR_CONSTANT = 261,
    FLOAT_CONSTANT = 262,
    STRING = 263,
    LOGICAL_AND = 264,
    LOGICAL_OR = 265,
    LS_EQ = 266,
    GR_EQ = 267,
    EQ = 268,
    NOT_EQ = 269,
    MUL_ASSIGN = 270,
    DIV_ASSIGN = 271,
    MOD_ASSIGN = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    INCREMENT = 275,
    DECREMENT = 276,
    SHORT = 277,
    INT = 278,
    LONG = 279,
    LONG_LONG = 280,
    SIGNED = 281,
    UNSIGNED = 282,
    CONST = 283,
    VOID = 284,
    CHAR = 285,
    FLOAT = 286,
    CHAR_STAR = 287,
    IF = 288,
    FOR = 289,
    WHILE = 290,
    CONTINUE = 291,
    BREAK = 292,
    RETURN = 293,
    UMINUS = 294,
    LOWER_THAN_ELSE = 295,
    ELSE = 296
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define SHORT 277
#define INT 278
#define LONG 279
#define LONG_LONG 280
#define SIGNED 281
#define UNSIGNED 282
#define CONST 283
#define VOID 284
#define CHAR 285
#define FLOAT 286
#define CHAR_STAR 287
#define IF 288
#define FOR 289
#define WHILE 290
#define CONTINUE 291
#define BREAK 292
#define RETURN 293
#define UMINUS 294
#define LOWER_THAN_ELSE 295
#define ELSE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "parser.y" /* yacc.c:355  */

	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;

#line 239 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      52,    53,    45,    43,    39,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   123,   124,   129,   137,   128,   151,
     153,   157,   158,   161,   162,   165,   166,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   184,   185,
     188,   189,   193,   201,   202,   207,   207,   225,   234,   240,
     246,   252,   257,   258,   259,   268,   278,   286,   296,   296,
     296,   313,   323,   338,   338,   338,   350,   351,   352,   355,
     356,   359,   360,   361,   365,   366,   369,   370,   375,   382,
     389,   396,   403,   410,   418,   429,   440,   448,   449,   450,
     454,   466,   478,   480,   492,   505,   514,   522,   530,   538,
     539,   542,   562,   563,   564,   565,   566,   567,   570,   578,
     586,   595,   603,   611,   619,   630,   637,   645,   646,   647,
     648,   651,   681,   682,   685,   693,   703,   704,   707,   711,
     717,   720
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT", "STRING",
  "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "SHORT", "INT", "LONG", "LONG_LONG", "SIGNED",
  "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "CHAR_STAR", "IF", "FOR",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "','", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "LOWER_THAN_ELSE",
  "ELSE", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept",
  "starter", "builder", "function", "$@1", "$@2", "type", "pointer",
  "data_type", "sign_specifier", "type_specifier", "argument_list",
  "arguments", "arg", "stmt", "compound_stmt", "$@3", "statements",
  "single_stmt", "for_block", "$@4", "$@5", "if_block", "while_block",
  "$@6", "$@7", "declaration", "declaration_list", "sub_decl",
  "expression_stmt", "expression", "sub_expr", "assignment_expr",
  "unary_expr", "lhs", "identifier", "assign", "arithmetic_expr",
  "constant", "array_access", "array_index", "function_call",
  "parameter_list", "parameter", "M", "N", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    44,
      61,    60,    62,    43,    45,    42,    47,    37,    33,   294,
     295,   296,    40,    41,   123,   125,    59,    91,    93
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -90

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     389,  -135,    10,    10,    -7,  -135,    11,    18,  -135,  -135,
    -135,  -135,  -135,  -135,   376,  -135,  -135,    44,     8,   419,
    -135,  -135,   -34,  -135,  -135,   291,   407,    23,   -24,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,    17,   407,   132,     8,
    -135,  -135,    44,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,    44,   334,  -135,  -135,   378,  -135,    22,  -135,  -135,
    -135,     5,  -135,  -135,  -135,  -135,    24,    24,  -135,    57,
     409,  -135,  -135,  -135,  -135,  -135,    -8,   405,  -135,  -135,
     327,   272,    24,    24,    24,    24,    24,  -135,    10,    16,
      53,  -135,  -135,  -135,   284,  -135,   347,  -135,   407,   118,
     409,  -135,     7,  -135,   136,   136,  -135,  -135,  -135,  -135,
    -135,   405,  -135,  -135,  -135,   284,   284,   284,   284,   284,
     284,   278,  -135,    59,  -135,   284,   284,  -135,  -135,    79,
      79,  -135,  -135,  -135,  -135,  -135,   301,   353,  -135,    52,
    -135,   220,    65,    66,  -135,    67,    84,   124,    44,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   174,    86,   284,   215,
      91,  -135,  -135,  -135,    -2,  -135,    48,   347,  -135,  -135,
      50,   284,  -135,   284,  -135,   215,  -135,    63,   347,   220,
    -135,  -135,    95,   284,  -135,  -135,    69,   220,  -135,  -135,
    -135,   220,  -135,  -135,  -135,  -135,   220,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,    27,     0,     3,     4,     0,    10,     0,
      14,     5,     0,    60,    61,     0,     0,    89,    90,    88,
      87,    18,    21,    23,     1,     2,     0,     0,    89,    12,
       9,    13,     0,    57,    95,    96,    97,    93,    94,    92,
      58,     0,     0,    85,    86,     0,    56,     0,    11,    59,
      84,     0,   107,   108,   109,   110,     0,     0,    83,   105,
      80,   106,    81,    82,   113,   112,     0,    29,   105,   104,
       0,     0,     0,     0,     0,     0,     0,   111,     0,     0,
      28,    31,   103,   119,     0,   115,   118,    78,    79,   105,
      77,    90,     0,   117,    98,    99,   100,   101,   102,    32,
       7,     0,    76,   120,   120,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    30,     0,     0,    73,    72,    70,
      71,    69,    68,   116,    35,     8,    74,    75,    38,   120,
      36,     0,     0,     0,   120,     0,     0,     0,     0,    37,
      33,    34,    40,    39,    41,    42,    89,     0,     0,     0,
       0,    45,    46,    44,     0,    43,     0,    67,    65,   120,
       0,     0,    47,     0,   120,     0,    64,     0,    66,     0,
     120,   120,    51,     0,    53,   121,     0,     0,   120,    48,
      54,     0,   121,    55,    52,   120,     0,    49,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   141,  -135,  -135,  -135,     4,   111,  -135,  -135,
     137,  -135,  -135,    54,   -30,    36,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   110,   -16,   121,   -11,
    -134,   -22,    21,     6,  -135,     0,   144,   267,   119,    19,
    -135,   125,  -135,    71,   -69,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    57,   123,   148,    40,    18,    19,
      20,    89,    90,    91,   149,   150,   138,   139,   151,   152,
     192,   198,   153,   154,   187,   193,   155,    22,    23,   169,
     170,   167,    97,    98,    26,    99,    51,   100,    71,   101,
      76,   157,   102,   103,   125,   188
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    36,    29,    30,    17,    42,    25,   113,   114,   115,
     116,   117,   118,     1,    27,   -63,    31,    38,    17,    28,
      25,    24,    43,    37,   166,    53,    54,     1,    62,    63,
      64,    65,   -63,    28,    32,    24,    28,   177,    24,   119,
     120,    33,    27,    53,    54,   126,   121,     1,    37,   186,
      87,    61,    69,    39,   172,    74,    42,    60,    68,    96,
     122,    28,   -62,    24,     2,     3,    78,    78,    66,   110,
     141,    72,   112,    56,    77,   160,    67,    53,    54,   -62,
      55,    88,    78,    78,    78,    78,    78,   173,   109,   173,
     115,   116,   111,   127,   128,   129,   130,   131,   132,    96,
     175,   174,   173,   136,   137,   179,   176,   140,   173,    81,
      21,   183,   184,   134,    55,    88,   181,   158,   159,   191,
     119,   120,   189,   161,    21,   164,   196,     1,    62,    63,
      64,    65,    36,   -89,   -89,   -89,   -89,   -89,    53,    54,
     162,   156,   165,   171,     2,     3,   185,    25,    27,   182,
      58,   178,    53,    54,    37,    35,    41,   190,   -89,   135,
      28,   194,    24,    59,   180,   124,   197,    28,    66,    24,
      52,   -62,    94,   195,    75,    55,    67,    73,     0,   156,
     163,    84,    85,    86,    -6,    25,     0,   156,   -62,    55,
       0,   156,   133,    25,    53,    54,   156,    25,    28,     0,
      24,     0,    25,     0,     0,     0,    28,     0,    24,     0,
      28,     0,    24,   -62,     0,    28,     0,    24,     1,    62,
      63,    64,    65,     1,     0,     0,    81,     0,     0,     0,
     -62,    55,     0,     0,     0,     2,     3,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,   142,   143,   144,   145,   146,   147,    66,
       0,     0,     0,    94,     0,     0,     0,    67,     0,     0,
       0,   168,     0,     0,   134,     1,    62,    63,    64,    65,
      93,     1,    62,    63,    64,    65,    93,     1,    62,    63,
      64,    65,     2,     3,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     2,     3,    44,    45,    46,    47,
      48,     0,   115,   116,   117,   118,    66,     0,     0,    70,
      94,     0,    66,     0,    67,    95,    94,     0,    66,     0,
      67,    49,    94,    79,    80,     0,    67,     1,    62,    63,
      64,    65,   119,   120,     0,     0,     0,    50,     0,   104,
     105,   106,   107,   108,     2,     3,   113,   114,   115,   116,
     117,   118,   113,     0,   115,   116,   117,   118,     0,     0,
      82,    83,    84,    85,    86,     0,    34,     0,    66,     1,
      92,     1,    62,    63,    64,    65,    67,     0,   119,   120,
       0,     0,     1,     0,   119,   120,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    13,     2,
       3,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    44,    45,    46,    47,    48,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,    13,     0,     0,
       0,     4,     5,     6,     7,     0,     0,    49,    10,    11,
      12,    13,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       0,    17,     2,     3,     0,    39,     0,     9,    10,    11,
      12,    13,    14,     3,    14,    39,    23,    17,    14,     0,
      14,     0,    56,    17,   158,    20,    21,     3,     4,     5,
       6,     7,    56,    14,    23,    14,    17,   171,    17,    41,
      42,    23,    42,    20,    21,   114,    39,     3,    42,   183,
      58,    51,    52,    45,    56,    55,    39,    51,    52,    81,
      53,    42,    39,    42,    20,    21,    66,    67,    44,    53,
     139,    52,    94,    56,    52,   144,    52,    20,    21,    56,
      57,    77,    82,    83,    84,    85,    86,    39,    88,    39,
      11,    12,    39,   115,   116,   117,   118,   119,   120,   121,
     169,    53,    39,   125,   126,   174,    56,    55,    39,    52,
       0,   180,   181,    54,    57,   111,    53,    52,    52,   188,
      41,    42,    53,    56,    14,   147,   195,     3,     4,     5,
       6,     7,   148,    15,    16,    17,    18,    19,    20,    21,
      56,   141,    56,    52,    20,    21,    51,   141,   148,   179,
      39,   173,    20,    21,   148,    14,    19,   187,    40,   123,
     141,   191,   141,    42,   175,   111,   196,   148,    44,   148,
      26,    39,    48,   192,    55,    57,    52,    52,    -1,   179,
      56,    45,    46,    47,    52,   179,    -1,   187,    56,    57,
      -1,   191,   121,   187,    20,    21,   196,   191,   179,    -1,
     179,    -1,   196,    -1,    -1,    -1,   187,    -1,   187,    -1,
     191,    -1,   191,    39,    -1,   196,    -1,   196,     3,     4,
       5,     6,     7,     3,    -1,    -1,    52,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    56,    -1,    -1,    54,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,    20,    21,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    20,    21,    15,    16,    17,    18,
      19,    -1,    11,    12,    13,    14,    44,    -1,    -1,    52,
      48,    -1,    44,    -1,    52,    53,    48,    -1,    44,    -1,
      52,    40,    48,    66,    67,    -1,    52,     3,     4,     5,
       6,     7,    41,    42,    -1,    -1,    -1,    56,    -1,    82,
      83,    84,    85,    86,    20,    21,     9,    10,    11,    12,
      13,    14,     9,    -1,    11,    12,    13,    14,    -1,    -1,
      43,    44,    45,    46,    47,    -1,     0,    -1,    44,     3,
      53,     3,     4,     5,     6,     7,    52,    -1,    41,    42,
      -1,    -1,     3,    -1,    41,    42,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    15,    16,    17,    18,    19,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    40,    29,    30,
      31,    32,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    60,    61,    62,    65,    67,    68,
      69,    85,    86,    87,    91,    92,    93,    94,    98,    94,
      94,    23,    23,    23,     0,    61,    86,    92,    94,    45,
      66,    69,    39,    56,    15,    16,    17,    18,    19,    40,
      56,    95,    95,    20,    21,    57,    56,    63,    66,    87,
      92,    94,     4,     5,     6,     7,    44,    52,    92,    94,
      96,    97,    98,   100,    94,    97,    99,    52,    94,    96,
      96,    52,    43,    44,    45,    46,    47,    58,    65,    70,
      71,    72,    53,     8,    48,    53,    90,    91,    92,    94,
      96,    98,   101,   102,    96,    96,    96,    96,    96,    94,
      53,    39,    90,     9,    10,    11,    12,    13,    14,    41,
      42,    39,    53,    64,    72,   103,   103,    90,    90,    90,
      90,    90,    90,   102,    54,    74,    90,    90,    75,    76,
      55,   103,    33,    34,    35,    36,    37,    38,    65,    73,
      74,    77,    78,    81,    82,    85,    94,   100,    52,    52,
     103,    56,    56,    56,    90,    56,    89,    90,    56,    88,
      89,    52,    56,    39,    53,   103,    56,    89,    90,   103,
      88,    53,    73,   103,   103,    51,    89,    83,   104,    53,
      73,   103,    79,    84,    73,   104,   103,    73,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    64,    62,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    80,
      78,    81,    81,    83,    84,    82,    85,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    93,
      93,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     1,     0,     4,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     0,     0,
      13,     6,    10,     0,     0,     9,     3,     2,     2,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     4,     4,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     4,     3,     3,     1,     1,     1,
       0,     0
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
        case 6:
#line 129 "parser.y" /* yacc.c:1646  */
    {
																						func_type = current_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();

																						gencode((yyvsp[0].entry)->lexeme + string(":"));
																					}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "parser.y" /* yacc.c:1646  */
    {
																						is_declaration = 0;
																						fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 145 "parser.y" /* yacc.c:1646  */
    {
																						is_func = 0;
																					}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "parser.y" /* yacc.c:1646  */
    {current_dtype = INT;}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 171 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 172 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 174 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "parser.y" /* yacc.c:1646  */
    {current_dtype = CHAR;}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 177 "parser.y" /* yacc.c:1646  */
    {current_dtype = FLOAT;}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 178 "parser.y" /* yacc.c:1646  */
    {current_dtype = VOID;}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 179 "parser.y" /* yacc.c:1646  */
    {current_dtype = STRING;}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "parser.y" /* yacc.c:1646  */
    {
																				param_list[p_idx++] = (yyvsp[0].entry)->data_type;

																				gencode(string("arg ") + (yyvsp[0].entry)->lexeme);
																			}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)=(yyvsp[0].content);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "parser.y" /* yacc.c:1646  */
    {
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 214 "parser.y" /* yacc.c:1646  */
    {
																	current_scope = exit_scope();

																	(yyval.content) = new content_t();
																	(yyval.content) = (yyvsp[-1].content);
																//	printlist($3->nextlist);
																	//cout<<yytext<<endl;

																}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "parser.y" /* yacc.c:1646  */
    {
																	backpatch((yyvsp[-2].content)->nextlist,(yyvsp[-1].instr));

																	(yyval.content) = new content_t();
																	(yyval.content)->nextlist = (yyvsp[0].content)->nextlist;
																	(yyval.content)->breaklist = merge((yyvsp[-2].content)->breaklist,(yyvsp[0].content)->breaklist);
																	(yyval.content)->continuelist = merge((yyvsp[-2].content)->continuelist,(yyvsp[0].content)->continuelist);
																}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 234 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.content) = new content_t();
																}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.content) = new content_t();
																  (yyval.content) = (yyvsp[0].content);
																  backpatch((yyval.content)->nextlist, nextinstr);
															  }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 246 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.content) = new content_t();
																	(yyval.content) = (yyvsp[0].content);
																	backpatch((yyval.content)->nextlist, nextinstr);
																}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "parser.y" /* yacc.c:1646  */
    {
																	(yyval.content) = new content_t();
																	(yyval.content) = (yyvsp[0].content);
																	backpatch((yyval.content)->nextlist, nextinstr);
																}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t();}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 259 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "parser.y" /* yacc.c:1646  */
    {
																	if(!is_loop)
																		yyerror("Illegal use of continue");

																	(yyval.content) = new content_t();
																	(yyval.content)->continuelist = {nextinstr};

																	gencode("goto _");
															 }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 278 "parser.y" /* yacc.c:1646  */
    {
																		if(!is_loop) {yyerror("Illegal use of break");}
																		(yyval.content) = new content_t();
																		(yyval.content)->breaklist = {nextinstr};

																		gencode("goto _");
															 }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 286 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != (yyvsp[-1].content)->data_type)
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 296 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 296 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 297 "parser.y" /* yacc.c:1646  */
    {
																																																						 backpatch((yyvsp[-8].content)->truelist,(yyvsp[-2].instr));
																																																						 backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
																																																						 backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));
																																																						 backpatch((yyvsp[-3].content)->nextlist, (yyvsp[-9].instr));

																																																						 (yyval.content) = new content_t();
																																																						 (yyval.content)->nextlist = merge((yyvsp[-8].content)->falselist,(yyvsp[-1].content)->breaklist);

																																																						 gencode(string("goto ") + to_string((yyvsp[-7].instr)));
				 																																																	 }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 313 "parser.y" /* yacc.c:1646  */
    {
																																		backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));

																																		(yyval.content) = new content_t();
																																		(yyval.content)->nextlist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->nextlist);
																																		(yyval.content)->breaklist = (yyvsp[0].content)->breaklist;
																																		(yyval.content)->continuelist = (yyvsp[0].content)->continuelist;
																																		//printlist($$->breaklist);
																																	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 323 "parser.y" /* yacc.c:1646  */
    {
																																		backpatch((yyvsp[-7].content)->truelist,(yyvsp[-5].instr));
																																		backpatch((yyvsp[-7].content)->falselist,(yyvsp[-1].instr));

																																		(yyval.content) = new content_t();

																																		vector<int> temp = merge((yyvsp[-4].content)->nextlist,(yyvsp[-2].content)->nextlist);
																																	//	printlist($8->nextlist);
																																		(yyval.content)->nextlist = merge(temp,(yyvsp[0].content)->nextlist);
																																		(yyval.content)->breaklist = merge((yyvsp[0].content)->breaklist,(yyvsp[-4].content)->breaklist);
																																		(yyval.content)->continuelist = merge((yyvsp[0].content)->continuelist,(yyvsp[-4].content)->continuelist);
																																	//	printlist($$->nextlist);
																																	}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 338 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 338 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 338 "parser.y" /* yacc.c:1646  */
    {
																																									backpatch((yyvsp[-1].content)->nextlist,(yyvsp[-7].instr));
																																									backpatch((yyvsp[-5].content)->truelist,(yyvsp[-3].instr));
																																									backpatch((yyvsp[-1].content)->continuelist, (yyvsp[-7].instr));

																																									(yyval.content) = new content_t();
																																									(yyval.content)->nextlist = merge((yyvsp[-5].content)->falselist,(yyvsp[-1].content)->breaklist);

																																									gencode(string("goto ") + to_string((yyvsp[-7].instr)));
																																								}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 350 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0;}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->truelist = (yyvsp[-1].content)->truelist; (yyval.content)->falselist = (yyvsp[-1].content)->falselist;}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t();}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->truelist = (yyvsp[0].content)->truelist; (yyval.content)->falselist = (yyvsp[0].content)->falselist;}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->truelist = (yyvsp[0].content)->truelist; (yyval.content)->falselist = (yyvsp[0].content)->falselist;}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 375 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" > "));
																												}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 382 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" < "));
																												}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 389 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" == "));
																												}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 396 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" != "));
																												}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 403 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" >= "));
																												}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 410 "parser.y" /* yacc.c:1646  */
    {

																													type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													gencode_rel((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" <= "));
																												}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 418 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[-3].content)->data_type;

																													backpatch((yyvsp[-3].content)->truelist,(yyvsp[-1].instr));
																													(yyval.content)->truelist = (yyvsp[0].content)->truelist;
																													(yyval.content)->falselist = merge((yyvsp[-3].content)->falselist,(yyvsp[0].content)->falselist);
																												}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 429 "parser.y" /* yacc.c:1646  */
    {
																													type_check((yyvsp[-3].content)->data_type,(yyvsp[0].content)->data_type,2);

																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[-3].content)->data_type;

																													backpatch((yyvsp[-3].content)->falselist,(yyvsp[-1].instr));
																													(yyval.content)->truelist = merge((yyvsp[-3].content)->truelist,(yyvsp[0].content)->truelist);
																													(yyval.content)->falselist = (yyvsp[0].content)->falselist;
																												}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 440 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[0].content)->data_type;

																													(yyval.content)->truelist = (yyvsp[0].content)->falselist;
																													(yyval.content)->falselist = (yyvsp[0].content)->truelist;
																												}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 448 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->data_type = (yyvsp[0].content)->data_type; (yyval.content)->addr = (yyvsp[0].content)->addr;}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 449 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->data_type = (yyvsp[0].content)->data_type;}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->data_type = (yyvsp[0].content)->data_type;}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 454 "parser.y" /* yacc.c:1646  */
    {
																											 type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);

																											 (yyval.content) = new content_t();
																											 (yyval.content)->data_type = (yyvsp[0].content)->data_type;

																											 (yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->addr;
																											 gencode((yyval.content)->code);

																											 rhs = 0;
																											}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 466 "parser.y" /* yacc.c:1646  */
    {
																											 type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);

																											 (yyval.content) = new content_t();
																											 (yyval.content)->data_type = (yyvsp[0].content)->data_type;

																											 (yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
																											 gencode((yyval.content)->code);

																											 rhs = 0;
																											}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 478 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].data_type),1); (yyval.content) = new content_t(); (yyval.content)->data_type = (yyvsp[0].data_type);}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 480 "parser.y" /* yacc.c:1646  */
    {
																											 type_check((yyvsp[-2].content)->entry->data_type,(yyvsp[0].content)->data_type,1);

																											 (yyval.content) = new content_t();
																											 (yyval.content)->data_type = (yyvsp[0].content)->data_type;

																											 (yyval.content)->code = (yyvsp[-2].content)->entry->lexeme + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
																											 gencode((yyval.content)->code);

																											 rhs = 0;
																										 	}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 492 "parser.y" /* yacc.c:1646  */
    {
																											 type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1);

																											 (yyval.content) = new content_t();
																											 (yyval.content)->data_type = (yyvsp[0].content)->data_type;

																											 (yyval.content)->code = (yyvsp[-2].content)->code + *(yyvsp[-1].op) + (yyvsp[0].content)->code;
																											 gencode((yyval.content)->code);

																											 rhs = 0;
																										 	}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 505 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;

																													(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("++");

																													gencode((yyval.content)->code);
																												}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 514 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[-1].entry)->data_type;

																													(yyval.content)->code = string((yyvsp[-1].entry)->lexeme) + string("--");
																													gencode((yyval.content)->code);
																												}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 522 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
																													(yyval.content)->code = string("--") + string((yyvsp[0].entry)->lexeme);

																													gencode((yyval.content)->code);
																												}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 530 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.content) = new content_t();
																													(yyval.content)->data_type = (yyvsp[0].entry)->data_type;
																													(yyval.content)->code = string("++") + string((yyvsp[0].entry)->lexeme);

																													gencode((yyval.content)->code);
																												}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 538 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->entry = (yyvsp[0].entry);}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 539 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = new content_t(); (yyval.content)->code = (yyvsp[0].content)->code;}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 542 "parser.y" /* yacc.c:1646  */
    {
                                                          if(is_declaration && !rhs)
                                                          {
                                                            (yyvsp[0].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
																														/* display_symbol_table(SYMBOL_TABLE); */

                                                            if((yyvsp[0].entry) == NULL) yyerror("Redeclaration of variable");
                                                          }
                                                          else
                                                          {
                                                            (yyvsp[0].entry) = search_recursive(yytext);
                                                            if((yyvsp[0].entry) == NULL) yyerror("Variable not declared");

																														/* display_symbol_table(SYMBOL_TABLE); */
                                                          }

                                                          (yyval.entry) = (yyvsp[0].entry);
                                                         }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 562 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" = ");}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 563 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" += ");}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 564 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" -= ");}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 565 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" *= ");}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 566 "parser.y" /* yacc.c:1646  */
    {rhs=1;	(yyval.op) = new string(" /= ");}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 567 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.op) = new string(" %= ");}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 570 "parser.y" /* yacc.c:1646  */
    {
																																			type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
																																			(yyval.content) = new content_t();

																																			(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
																																			gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" + "));
																																		 }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 578 "parser.y" /* yacc.c:1646  */
    {
																																			 type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
																																			 (yyval.content) = new content_t();

																																			 (yyval.content)->data_type = (yyvsp[-2].content)->data_type;
																																			 gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" - "));
								 																										 }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 586 "parser.y" /* yacc.c:1646  */
    {
																																			 type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
																																			 (yyval.content) = new content_t();

																																			 (yyval.content)->data_type = (yyvsp[-2].content)->data_type;
																																			 gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" * "));
								 																										 }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 595 "parser.y" /* yacc.c:1646  */
    {
																																			type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
																																			(yyval.content) = new content_t();

																																			(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
																																			gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" / "));
																																		 }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 603 "parser.y" /* yacc.c:1646  */
    {
																																				type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,0);
																																				(yyval.content) = new content_t();

																																				(yyval.content)->data_type = (yyvsp[-2].content)->data_type;
																																				gencode_math((yyval.content), (yyvsp[-2].content), (yyvsp[0].content), string(" % "));
																																		 }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 611 "parser.y" /* yacc.c:1646  */
    {
								 																											(yyval.content) = new content_t();
								 																											(yyval.content)->data_type = (yyvsp[-1].content)->data_type;

																																			(yyval.content)->addr = (yyvsp[-1].content)->addr;
																																			(yyval.content)->code = (yyvsp[-1].content)->code;
																																		 }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 619 "parser.y" /* yacc.c:1646  */
    {
								 																											(yyval.content) = new content_t();
								 																											(yyval.content)->data_type = (yyvsp[0].content)->data_type;

																																			(yyval.content)->addr = "t" + to_string(temp_var_number);
																																			std::string expr = (yyval.content)->addr + " = " + "minus " + (yyvsp[0].content)->addr;
																																			(yyval.content)->code = (yyvsp[0].content)->code + expr;

																																			temp_var_number++;
																																		 }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 630 "parser.y" /* yacc.c:1646  */
    {
								 																											(yyval.content) = new content_t();
								 																										  (yyval.content)->data_type = (yyvsp[0].entry)->data_type;

																																		 	(yyval.content)->addr = (yyvsp[0].entry)->lexeme;
																																	   }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 637 "parser.y" /* yacc.c:1646  */
    {
								 																											(yyval.content) = new content_t();
								 																											(yyval.content)->data_type = (yyvsp[0].entry)->data_type;

																																			(yyval.content)->addr = to_string((yyvsp[0].entry)->value);
																																		 }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 645 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 646 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 647 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 648 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 651 "parser.y" /* yacc.c:1646  */
    {
																															if(is_declaration)
																															{
																																if((yyvsp[-1].entry)->value <= 0)
																																	yyerror("size of array is not positive");

																																else if((yyvsp[-1].entry)->is_constant)
																																	(yyvsp[-3].entry)->array_dimension = (yyvsp[-1].entry)->value;
																															}

																															else if((yyvsp[-1].entry)->is_constant)
																															{
																																if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[-1].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}

																															(yyval.content) = new content_t();
																															(yyval.content)->data_type = (yyvsp[-3].entry)->data_type;

																															if((yyvsp[-1].entry)->is_constant)
																																(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + to_string((yyvsp[-1].entry)->value) + string("]");
																															else
																																(yyval.content)->code = string((yyvsp[-3].entry)->lexeme) + string("[") + string((yyvsp[-1].entry)->lexeme) + string("]");

																															(yyval.content)->entry = (yyvsp[-3].entry);
																														}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 681 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 682 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 685 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.data_type) = (yyvsp[-3].entry)->data_type;
																													check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
																													p_idx = 0;

																													gencode(string("call ") + (yyvsp[-3].entry)->lexeme);
																												}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 693 "parser.y" /* yacc.c:1646  */
    {
							 																						 (yyval.data_type) = (yyvsp[-2].entry)->data_type;
																													 check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
																													 p_idx = 0;

																													 gencode(string("call ") + (yyvsp[-2].entry)->lexeme);
																												}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 707 "parser.y" /* yacc.c:1646  */
    {
																													param_list[p_idx++] = (yyvsp[0].content)->data_type;
																													gencode(string("param ") + (yyvsp[0].content)->addr);
																												}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 711 "parser.y" /* yacc.c:1646  */
    {
					 																								param_list[p_idx++] = STRING;
																													gencode(string("param ") + (yyvsp[0].entry)->lexeme);
																												}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 717 "parser.y" /* yacc.c:1646  */
    {(yyval.instr) = nextinstr;}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 720 "parser.y" /* yacc.c:1646  */
    {
					(yyval.content) = new content_t;
					(yyval.content)->nextlist = {nextinstr};

					gencode("goto _");
				}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2477 "y.tab.c" /* yacc.c:1646  */
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
#line 728 "parser.y" /* yacc.c:1906  */


void gencode(string x)
{
	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + x;
	ICG.push_back(instruction);
	nextinstr++;
}


void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string code;

	code = string("if ") + arg1->addr + op + arg2->addr + string(" goto _");
	gencode(code);

	code = string("goto _");
	gencode(code);
}

void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string(" = ") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	gencode(expr);
}

void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			ICG[v1[i]] = instruction;
		}
	}
}

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
}

void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++)
	outfile << ICG[i] <<endl;
	outfile<<nextinstr<<": exit";
	outfile.close();
}

void printlist(vector<int> v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<"Next: "<<nextinstr<<endl;
}

int main(int argc, char *argv[])
{
	 int i;
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}

	/* printf("SYMBOL TABLES\n\n");
	display_all(); */

	/* printf("CONSTANT TABLE");
	display_constant_table(constant_table);  */

	/* display_all(); */

	displayICG();


	fclose(yyin);
	return 0;
}

int yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
