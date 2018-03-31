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

	#include <stdlib.h>
	#include <stdio.h>
	int yyerror(char *msg);

	#include "symboltable.h"
	#include "lex.yy.c"

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

#line 95 "y.tab.c" /* yacc.c:339  */

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
    IF = 287,
    FOR = 288,
    WHILE = 289,
    CONTINUE = 290,
    BREAK = 291,
    RETURN = 292,
    UMINUS = 293,
    LOWER_THAN_ELSE = 294,
    ELSE = 295
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
#define IF 287
#define FOR 288
#define WHILE 289
#define CONTINUE 290
#define BREAK 291
#define RETURN 292
#define UMINUS 293
#define LOWER_THAN_ELSE 294
#define ELSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:355  */

	int data_type;
	entry_t* entry;

#line 220 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    46,     2,     2,
      51,    52,    44,    42,    38,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
      40,    39,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    87,    90,    91,    96,   102,    95,   116,
     118,   122,   123,   126,   127,   130,   131,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   148,   149,   152,
     153,   157,   161,   162,   167,   167,   177,   178,   182,   183,
     184,   185,   186,   187,   196,   197,   199,   209,   209,   210,
     210,   213,   214,   217,   217,   220,   222,   223,   226,   227,
     230,   231,   232,   236,   237,   240,   241,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   261,
     262,   263,   264,   265,   268,   269,   270,   271,   273,   274,
     277,   295,   296,   297,   298,   299,   300,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   314,   315,   316,   317,
     320,   341,   342,   345,   351,   359,   360,   363,   364
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
  "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "IF", "FOR", "WHILE",
  "CONTINUE", "BREAK", "RETURN", "','", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UMINUS", "LOWER_THAN_ELSE", "ELSE", "'('",
  "')'", "'{'", "'}'", "';'", "'['", "']'", "$accept", "starter",
  "builder", "function", "$@1", "$@2", "type", "pointer", "data_type",
  "sign_specifier", "type_specifier", "argument_list", "arguments", "arg",
  "stmt", "compound_stmt", "$@3", "statements", "single_stmt", "for_block",
  "$@4", "$@5", "if_block", "while_block", "$@6", "declaration",
  "declaration_list", "sub_decl", "expression_stmt", "expression",
  "sub_expr", "assignment_expr", "unary_expr", "lhs", "identifier",
  "assign_op", "arithmetic_expr", "constant", "array_access",
  "array_index", "function_call", "parameter_list", "parameter", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    44,    61,
      60,    62,    43,    45,    42,    47,    37,    33,   293,   294,
     295,    40,    41,   123,   125,    59,    91,    93
};
# endif

#define YYPACT_NINF -27

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-27)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     416,   -27,    31,    31,    32,   -27,    44,    45,   -27,   -27,
     -27,   -27,   -27,   404,   -27,   -27,    37,    -5,   436,   -27,
     -27,   -13,   -27,   -27,   342,   225,   119,    86,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,    99,   225,   317,    -5,   -27,
     -27,    37,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
      37,   100,   -27,   -27,    72,   -27,     9,   -27,   -27,   -27,
      16,   -27,   -27,   -27,   -27,     2,     2,   -27,     8,   203,
     -27,   -27,   -27,   -27,   -27,    13,   426,   -27,   -27,   366,
     271,     2,     2,     2,     2,     2,   -27,    31,    19,    59,
     -27,   -27,   -27,   305,   -27,   376,   -27,   225,   315,   203,
     -27,   -26,   -27,   -14,   -14,   -27,   -27,   -27,   -27,   -27,
     426,   -27,   305,   305,   305,   305,   305,   305,   305,   305,
     296,   -27,    64,   -27,     7,   382,   -27,   -27,     3,     3,
     -27,   -27,   -27,   -27,   -27,   -27,   201,    68,    71,    77,
      98,   104,    95,   -27,    37,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   324,   109,   305,   105,   305,   -27,   -27,   -27,
     121,   -27,    34,   376,   -27,   105,   127,    75,   -27,   305,
     236,   277,   -27,   -27,   376,    73,   -27,   111,   236,   236,
     236,   -27,   -27,   -27,   -27,   236,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,     0,     3,     4,     0,    10,     0,    14,
       5,     0,    59,    60,     0,     0,    88,    89,    87,    86,
      18,    21,    23,     1,     2,     0,     0,    88,    12,     9,
      13,     0,    56,    94,    95,    96,    92,    93,    91,    57,
       0,     0,    84,    85,     0,    55,     0,    11,    58,    83,
       0,   106,   107,   108,   109,     0,     0,    82,   104,    79,
     105,    80,    81,   112,   111,     0,    28,   104,   103,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,    27,
      30,   102,   118,     0,   114,   117,    77,    78,   104,    76,
      89,     0,   116,    97,    98,    99,   100,   101,    31,     7,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,    29,    73,    74,    71,    72,    69,    70,
      68,    67,   115,    34,     8,    37,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    36,    32,    33,    39,    38,
      40,    41,    88,     0,     0,     0,     0,    44,    45,    43,
       0,    42,     0,    66,    64,     0,     0,     0,    46,     0,
       0,     0,    63,    53,    65,    51,    47,     0,     0,     0,
       0,    49,    54,    52,    48,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   154,   -27,   -27,   -27,     4,   130,   -27,   -27,
     165,   -27,   -27,    62,   235,    65,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,    10,   -15,   143,    21,    17,
     -24,    33,    11,   -27,     0,   168,   318,   140,    22,   -27,
     144,   -27,    78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    56,   122,   144,    39,    17,    18,
      19,    88,    89,    90,   145,   146,   135,   136,   147,   148,
     180,   185,   149,   150,   178,   151,    21,    22,   165,   166,
     163,    96,    97,    25,    98,    50,    99,    70,   100,    75,
     153,   101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    35,    28,    29,    16,     1,    61,    62,    63,    64,
      20,    24,   120,    26,   114,   115,    37,    16,   114,   115,
     116,   117,    27,    20,    24,    41,   121,    36,    52,    53,
      83,    84,    85,    23,     1,    27,    52,    53,    27,    38,
       1,    26,    42,   118,   119,    65,    23,   118,   119,    23,
      60,    68,    36,    66,    73,    30,    95,     2,     3,    80,
      76,    59,    67,    27,    54,    77,    77,    31,    32,   111,
      86,   109,   169,    71,    23,     1,    61,    62,    63,    64,
      87,    77,    77,    77,    77,    77,   170,   108,   124,   125,
     126,   127,   128,   129,   130,   131,    95,   110,     1,    61,
      62,    63,    64,     1,    61,    62,    63,    64,     1,    61,
      62,    63,    64,   169,    87,     2,     3,   133,   160,   154,
       2,     3,   155,   179,   -62,     2,     3,   173,   156,    35,
     112,   113,   114,   115,   116,   117,   152,    41,    65,    52,
      53,   -62,    93,    65,    26,   174,    66,    24,    65,   169,
     159,    66,    93,   157,    55,    36,    66,   -61,    27,   158,
     164,   118,   119,   181,   161,   169,    27,    34,    57,    23,
     152,   162,   123,   167,   -61,    54,   168,    23,   152,   152,
     152,    24,   172,    40,    58,   152,   171,   134,   177,    24,
      24,    24,    27,    51,    74,    72,    24,     0,   132,     0,
      27,    27,    27,    23,     1,     0,     0,    27,     0,     0,
       0,    23,    23,    23,     0,     0,     0,     0,    23,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,   137,   138,   139,   140,   141,   142,     1,
      43,    44,    45,    46,    47,    81,    82,    83,    84,    85,
       0,     0,     0,     0,   133,   143,     2,     3,     4,     5,
       6,     7,     8,     9,    48,    10,    11,    12,   137,   138,
     139,   140,   141,   142,     1,    61,    62,    63,    64,    92,
       1,    61,    62,    63,    64,     0,     0,     0,     0,   133,
       0,     2,     3,     0,     0,     0,     0,     2,     3,     1,
      61,    62,    63,    64,    92,     0,     0,     0,     1,    61,
      62,    63,    64,     0,    65,     0,     2,     3,    93,     0,
      65,     0,    66,    94,    93,     2,     3,     0,    66,   176,
     -88,   -88,   -88,   -88,   -88,    52,    53,    52,    53,    65,
       0,     0,     0,    93,    52,    53,     0,    66,    65,     0,
       0,     0,    93,     0,   -88,   -61,    66,    43,    44,    45,
      46,    47,   -61,     0,     0,     0,     0,     0,    -6,    69,
       0,    54,   -61,    54,     0,    80,     0,     0,     0,   -61,
      54,    48,     0,    78,    79,   112,   113,   114,   115,   116,
     117,   112,     0,   114,   115,   116,   117,    49,     0,   103,
     104,   105,   106,   107,    33,   175,     0,     1,    81,    82,
      83,    84,    85,   182,   183,   184,   118,   119,    91,     1,
     186,     0,   118,   119,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     4,     5,
       6,     7,     0,     0,     0,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
       0,    16,     2,     3,     0,     3,     4,     5,     6,     7,
       0,     0,    38,    13,    11,    12,    16,    13,    11,    12,
      13,    14,     0,    13,    13,    38,    52,    16,    20,    21,
      44,    45,    46,     0,     3,    13,    20,    21,    16,    44,
       3,    41,    55,    40,    41,    43,    13,    40,    41,    16,
      50,    51,    41,    51,    54,    23,    80,    20,    21,    51,
      51,    50,    51,    41,    56,    65,    66,    23,    23,    93,
      57,    52,    38,    51,    41,     3,     4,     5,     6,     7,
      76,    81,    82,    83,    84,    85,    52,    87,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    38,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    38,   110,    20,    21,    53,   142,    51,
      20,    21,    51,    50,    38,    20,    21,    52,    51,   144,
       9,    10,    11,    12,    13,    14,   136,    38,    43,    20,
      21,    55,    47,    43,   144,   169,    51,   136,    43,    38,
      55,    51,    47,    55,    55,   144,    51,    38,   136,    55,
      55,    40,    41,    52,    55,    38,   144,    13,    38,   136,
     170,   154,   110,   156,    55,    56,    55,   144,   178,   179,
     180,   170,    55,    18,    41,   185,   165,   122,   171,   178,
     179,   180,   170,    25,    54,    51,   185,    -1,   120,    -1,
     178,   179,   180,   170,     3,    -1,    -1,   185,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     3,
      15,    16,    17,    18,    19,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    53,    54,    20,    21,    22,    23,
      24,    25,    26,    27,    39,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    53,
      -1,    20,    21,    -1,    -1,    -1,    -1,    20,    21,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    43,    -1,    20,    21,    47,    -1,
      43,    -1,    51,    52,    47,    20,    21,    -1,    51,    52,
      15,    16,    17,    18,    19,    20,    21,    20,    21,    43,
      -1,    -1,    -1,    47,    20,    21,    -1,    51,    43,    -1,
      -1,    -1,    47,    -1,    39,    38,    51,    15,    16,    17,
      18,    19,    38,    -1,    -1,    -1,    -1,    -1,    51,    51,
      -1,    56,    55,    56,    -1,    51,    -1,    -1,    -1,    55,
      56,    39,    -1,    65,    66,     9,    10,    11,    12,    13,
      14,     9,    -1,    11,    12,    13,    14,    55,    -1,    81,
      82,    83,    84,    85,     0,   170,    -1,     3,    42,    43,
      44,    45,    46,   178,   179,   180,    40,    41,    52,     3,
     185,    -1,    40,    41,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    59,    60,    61,    64,    66,    67,    68,
      83,    84,    85,    89,    90,    91,    92,    96,    92,    92,
      23,    23,    23,     0,    60,    84,    90,    92,    44,    65,
      68,    38,    55,    15,    16,    17,    18,    19,    39,    55,
      93,    93,    20,    21,    56,    55,    62,    65,    85,    90,
      92,     4,     5,     6,     7,    43,    51,    90,    92,    94,
      95,    96,    98,    92,    95,    97,    51,    92,    94,    94,
      51,    42,    43,    44,    45,    46,    57,    64,    69,    70,
      71,    52,     8,    47,    52,    88,    89,    90,    92,    94,
      96,    99,   100,    94,    94,    94,    94,    94,    92,    52,
      38,    88,     9,    10,    11,    12,    13,    14,    40,    41,
      38,    52,    63,    71,    88,    88,    88,    88,    88,    88,
      88,    88,   100,    53,    73,    74,    75,    32,    33,    34,
      35,    36,    37,    54,    64,    72,    73,    76,    77,    80,
      81,    83,    92,    98,    51,    51,    51,    55,    55,    55,
      88,    55,    87,    88,    55,    86,    87,    87,    55,    38,
      52,    86,    55,    52,    88,    72,    52,    87,    82,    50,
      78,    52,    72,    72,    72,    79,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    62,    63,    61,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    74,    73,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    78,    77,    79,
      77,    80,    80,    82,    81,    83,    83,    83,    84,    84,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      92,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       1,     2,     1,     1,     0,     4,     2,     0,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     0,     7,     0,
       8,     5,     7,     0,     6,     3,     2,     2,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     4,     3,     3,     1,     1,     1
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
#line 96 "parser.y" /* yacc.c:1646  */
    {
																						func_type = current_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();
																					}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "parser.y" /* yacc.c:1646  */
    {
																						is_declaration = 0;
																						fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.y" /* yacc.c:1646  */
    {
																						is_func = 0;
																					}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "parser.y" /* yacc.c:1646  */
    {current_dtype = INT;}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 138 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 141 "parser.y" /* yacc.c:1646  */
    {current_dtype = CHAR;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 142 "parser.y" /* yacc.c:1646  */
    {current_dtype = FLOAT;}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 143 "parser.y" /* yacc.c:1646  */
    {current_dtype = VOID;}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 157 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = (yyvsp[0].entry)->data_type;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 167 "parser.y" /* yacc.c:1646  */
    {
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 174 "parser.y" /* yacc.c:1646  */
    {current_scope = exit_scope();}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 187 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 196 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of continue");}}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 197 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of break");}}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 199 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != (yyvsp[-1].data_type))
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 209 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 209 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 210 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 217 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 217 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 221 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0; }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 248 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 252 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),2); (yyval.data_type) = (yyvsp[-2].data_type);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 261 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),1); (yyval.data_type) = (yyvsp[0].data_type);}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 262 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),1); (yyval.data_type) = (yyvsp[0].data_type);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 263 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),1); (yyval.data_type) = (yyvsp[0].data_type);}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 264 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),1); (yyval.data_type) = (yyvsp[0].data_type);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 265 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),1); (yyval.data_type) = (yyvsp[0].data_type);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[-1].entry)->data_type;}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[-1].entry)->data_type;}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].entry)->data_type;}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].entry)->data_type;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].entry)->data_type;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 277 "parser.y" /* yacc.c:1646  */
    {
                                                                    if(is_declaration
                                                                    && !rhs) 
                                                                    {
                                                                        (yyvsp[0].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                                                                        if((yyvsp[0].entry) == NULL) yyerror("Redeclaration of variable");
                                                                    }
                                                                    else
                                                                    {
                                                                        (yyvsp[0].entry) = search_recursive(yytext);
                                                                        if((yyvsp[0].entry) == NULL) yyerror("Variable not declared");
                                                                        if(rhs)
                                                                        rhs = 0;
                                                                    }
                                                                    (yyval.entry) = (yyvsp[0].entry);
                                                            }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 295 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 296 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 298 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 299 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 300 "parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 303 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),0);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 304 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),0);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 305 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),0);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 306 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),0);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 307 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].data_type),(yyvsp[0].data_type),0);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[-1].data_type);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].data_type);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].entry)->data_type;}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type) = (yyvsp[0].entry)->data_type;}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 320 "parser.y" /* yacc.c:1646  */
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
																															(yyval.data_type) = (yyvsp[-3].entry)->data_type;
																														}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 345 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.data_type) = (yyvsp[-3].entry)->data_type;
																													check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
																													p_idx = 0;
																												}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 351 "parser.y" /* yacc.c:1646  */
    {
							 																						 (yyval.data_type) = (yyvsp[-2].entry)->data_type;
																													 check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
																													 p_idx = 0;
																												}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 363 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = (yyvsp[0].data_type);}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 364 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = STRING;}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2056 "y.tab.c" /* yacc.c:1646  */
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
#line 366 "parser.y" /* yacc.c:1906  */


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


	printf("SYMBOL TABLES\n\n");
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
