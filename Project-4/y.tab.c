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
	#include <string>
	#include <iostream>

	using namespace std;
	int yyerror(char *msg);

	#include "symboltable.h"
	#include "lex.yy.c"

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table
	#define MEM_ALLOC (content_t*)malloc(sizeof(content_t))
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
	int temp_var_number = 0;
  content_t* ret;
	char* code;
	char numconcat[10];

	void type_check(int,int,int);
	content_t* do_whats_necessary(content_t*, char, content_t*);
	char * newTemp();


#line 106 "y.tab.c" /* yacc.c:339  */

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
#line 42 "parser.y" /* yacc.c:355  */

	int data_type;
	entry_t* entry;
	content_t* content;

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
       0,   105,   105,   106,   109,   110,   115,   121,   114,   135,
     137,   141,   142,   145,   146,   149,   150,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   167,   168,   171,
     172,   176,   180,   181,   186,   186,   196,   206,   210,   211,
     212,   213,   214,   215,   224,   225,   227,   237,   237,   238,
     238,   241,   242,   245,   245,   248,   250,   251,   254,   255,
     258,   259,   260,   264,   265,   268,   269,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   288,
     302,   303,   304,   305,   308,   309,   310,   311,   313,   315,
     318,   334,   335,   336,   337,   338,   339,   342,   343,   344,
     345,   346,   347,   348,   356,   364,   365,   366,   367,   370,
     401,   402,   405,   411,   419,   420,   423,   424
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

#define YYPACT_NINF -22

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-22)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     376,   -22,    20,    20,    -2,   -22,    19,    37,   -22,   -22,
     -22,   -22,   -22,   392,   -22,   -22,    16,    24,   420,   -22,
     -22,     1,   -22,   -22,   338,   409,   116,     9,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,    17,   409,    84,    24,   -22,
     -22,    16,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
      16,   331,   -22,   -22,   242,   -22,    15,   -22,   -22,   -22,
      50,   -22,   -22,   -22,   -22,   125,   -22,    -3,   342,   -22,
     -22,   -22,   -22,   -22,    21,   407,   -22,   -22,   268,   125,
     125,   125,   125,   125,   -22,    20,    34,    59,   -22,   -22,
     326,   -22,   350,   -22,   409,   -11,   342,   -22,   -18,   -22,
      31,    31,   -22,   -22,   -22,   -22,   -22,   407,   -22,   326,
     326,   326,   326,   326,   326,   326,   326,   302,   -22,    60,
     -22,    18,   369,   -22,   -22,     3,     3,   -22,   -22,   -22,
     -22,   -22,   -22,   198,    61,    70,    72,    79,    88,    95,
     -22,    16,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   320,
      91,   326,   104,   326,   -22,   -22,   -22,   287,   -22,   -12,
     350,   -22,   104,    29,    65,   -22,   326,   233,   274,   -22,
     -22,   350,    98,   -22,    68,   233,   233,   233,   -22,   -22,
     -22,   -22,   233,   -22
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
       0,   105,   106,   107,   108,     0,    82,   103,    79,   104,
      80,    81,   111,   110,     0,    28,   103,   102,     0,     0,
       0,     0,     0,     0,   109,     0,     0,    27,    30,   117,
       0,   113,   116,    77,    78,   103,    76,    89,     0,   115,
      97,    98,    99,   100,   101,    31,     7,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
      29,    73,    74,    71,    72,    69,    70,    68,    67,   114,
      34,     8,    37,     0,     0,     0,     0,     0,     0,     0,
      35,     0,    36,    32,    33,    39,    38,    40,    41,    88,
       0,     0,     0,     0,    44,    45,    43,     0,    42,     0,
      66,    64,     0,     0,     0,    46,     0,     0,     0,    63,
      53,    65,    51,    47,     0,     0,     0,     0,    49,    54,
      52,    48,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -22,   -22,   136,   -22,   -22,   -22,    12,   115,   -22,   -22,
     139,   -22,   -22,    53,   137,    42,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   114,   -15,   121,     2,     5,
     -21,    33,    11,   -22,     0,   140,   161,   126,    22,   -22,
     118,   -22,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    56,   119,   141,    39,    17,    18,
      19,    86,    87,    88,   142,   143,   132,   133,   144,   145,
     177,   182,   146,   147,   175,   148,    21,    22,   162,   163,
     160,    93,    94,    25,    95,    50,    96,    69,    97,    74,
     150,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    35,    28,    29,   -88,   -88,   -88,   -88,   -88,    52,
      53,    24,    16,    26,   111,   112,    37,    52,    53,     1,
     117,    30,    27,     1,    24,    16,   166,    36,   -88,   111,
     112,   113,   114,    23,   118,    27,     2,     3,    27,    41,
     167,    26,    31,   115,   116,    54,    23,   -62,    78,    23,
      60,    67,    36,    54,    72,    41,    42,    92,   115,   116,
      32,    59,    66,    27,   -62,    76,    75,   166,    38,   108,
      52,    53,    55,    70,    23,    81,    82,    83,    84,    76,
      76,    76,    76,    76,   169,   105,   106,    85,   121,   122,
     123,   124,   125,   126,   127,   128,    92,   107,     1,    61,
      62,    63,    64,   166,    52,    53,   166,     1,    61,    62,
      63,    64,   151,   130,    20,     2,     3,   170,   157,    85,
     178,   152,   -61,   153,     2,     3,    35,    20,     1,    61,
      62,    63,    64,   149,   154,    -6,    52,    53,    65,   -61,
      54,    26,    90,   155,    24,   171,   158,    65,   176,    34,
     156,    90,    36,    57,   -61,    27,   159,    40,   164,   161,
     120,   131,    58,    27,   168,    51,    23,   149,    65,    71,
       0,   -61,    54,   174,    23,   149,   149,   149,    24,   129,
      73,     0,   149,     0,     0,     0,    24,    24,    24,    27,
       0,     0,     0,    24,     0,     0,     0,    27,    27,    27,
      23,     1,     0,     0,    27,     0,     0,     0,    23,    23,
      23,     0,    68,     0,     0,    23,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    77,    10,    11,    12,
     134,   135,   136,   137,   138,   139,     1,     0,     0,     0,
     100,   101,   102,   103,   104,     1,    61,    62,    63,    64,
       0,   130,   140,     2,     3,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,   134,   135,   136,   137,   138,
     139,     1,    61,    62,    63,    64,    89,     1,    61,    62,
      63,    64,     0,     0,     0,     0,   130,     0,     2,     3,
       0,     0,     0,     0,     2,     3,   109,   110,   111,   112,
     113,   114,     0,     0,   172,     1,    61,    62,    63,    64,
      89,    65,   179,   180,   181,    90,     0,    65,     0,   183,
      91,    90,     2,     3,     0,     0,   173,   115,   116,     1,
      61,    62,    63,    64,     1,    61,    62,    63,    64,     0,
      52,    53,   165,     0,     0,    65,     2,     3,     0,    90,
       0,     2,     3,    43,    44,    45,    46,    47,   -61,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,    65,
       0,    78,     0,    90,    65,   -61,    54,    48,   109,     1,
     111,   112,   113,   114,    79,    80,    81,    82,    83,     0,
     115,   116,    33,    49,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,   115,
     116,     0,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,    43,    44,    45,    46,    47,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     0,
       0,     0,     4,     5,     6,     7,     0,     0,    48,    10,
      11,    12
};

static const yytype_int16 yycheck[] =
{
       0,    16,     2,     3,    15,    16,    17,    18,    19,    20,
      21,     0,     0,    13,    11,    12,    16,    20,    21,     3,
      38,    23,     0,     3,    13,    13,    38,    16,    39,    11,
      12,    13,    14,     0,    52,    13,    20,    21,    16,    38,
      52,    41,    23,    40,    41,    56,    13,    38,    51,    16,
      50,    51,    41,    56,    54,    38,    55,    78,    40,    41,
      23,    50,    51,    41,    55,    65,    51,    38,    44,    90,
      20,    21,    55,    51,    41,    44,    45,    46,    57,    79,
      80,    81,    82,    83,    55,    85,    52,    75,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    38,     3,     4,
       5,     6,     7,    38,    20,    21,    38,     3,     4,     5,
       6,     7,    51,    53,     0,    20,    21,    52,   139,   107,
      52,    51,    38,    51,    20,    21,   141,    13,     3,     4,
       5,     6,     7,   133,    55,    51,    20,    21,    43,    55,
      56,   141,    47,    55,   133,   166,    55,    43,    50,    13,
      55,    47,   141,    38,    38,   133,   151,    18,   153,    55,
     107,   119,    41,   141,   162,    25,   133,   167,    43,    51,
      -1,    55,    56,   168,   141,   175,   176,   177,   167,   117,
      54,    -1,   182,    -1,    -1,    -1,   175,   176,   177,   167,
      -1,    -1,    -1,   182,    -1,    -1,    -1,   175,   176,   177,
     167,     3,    -1,    -1,   182,    -1,    -1,    -1,   175,   176,
     177,    -1,    51,    -1,    -1,   182,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    65,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     3,    -1,    -1,    -1,
      79,    80,    81,    82,    83,     3,     4,     5,     6,     7,
      -1,    53,    54,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    53,    -1,    20,    21,
      -1,    -1,    -1,    -1,    20,    21,     9,    10,    11,    12,
      13,    14,    -1,    -1,   167,     3,     4,     5,     6,     7,
       8,    43,   175,   176,   177,    47,    -1,    43,    -1,   182,
      52,    47,    20,    21,    -1,    -1,    52,    40,    41,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
      20,    21,    55,    -1,    -1,    43,    20,    21,    -1,    47,
      -1,    20,    21,    15,    16,    17,    18,    19,    38,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    43,
      -1,    51,    -1,    47,    43,    55,    56,    39,     9,     3,
      11,    12,    13,    14,    42,    43,    44,    45,    46,    -1,
      40,    41,     0,    55,    -1,     3,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    40,
      41,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    15,    16,    17,    18,    19,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    39,    29,
      30,    31
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
      92,     4,     5,     6,     7,    43,    90,    92,    94,    95,
      96,    98,    92,    95,    97,    51,    92,    94,    51,    42,
      43,    44,    45,    46,    57,    64,    69,    70,    71,     8,
      47,    52,    88,    89,    90,    92,    94,    96,    99,   100,
      94,    94,    94,    94,    94,    92,    52,    38,    88,     9,
      10,    11,    12,    13,    14,    40,    41,    38,    52,    63,
      71,    88,    88,    88,    88,    88,    88,    88,    88,   100,
      53,    73,    74,    75,    32,    33,    34,    35,    36,    37,
      54,    64,    72,    73,    76,    77,    80,    81,    83,    92,
      98,    51,    51,    51,    55,    55,    55,    88,    55,    87,
      88,    55,    86,    87,    87,    55,    38,    52,    86,    55,
      52,    88,    72,    52,    87,    82,    50,    78,    52,    72,
      72,    72,    79,    72
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
      94,    94,    94,    94,    94,    95,    95,    95,    95,    96,
      97,    97,    98,    98,    99,    99,   100,   100
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
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     4,     3,     3,     1,     1,     1
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
        case 5:
#line 110 "parser.y" /* yacc.c:1646  */
    {/*if($1 != NULL && $1->code != NULL) cout<<$1->code<<endl; else printf("Hmm\n");*/ }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    {
																						func_type = current_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();
																					}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "parser.y" /* yacc.c:1646  */
    {
																						is_declaration = 0;
																						fill_parameter_list((yyvsp[-4].entry),param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "parser.y" /* yacc.c:1646  */
    {
																						is_func = 0;
																					}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "parser.y" /* yacc.c:1646  */
    {is_declaration = 1; }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "parser.y" /* yacc.c:1646  */
    {current_dtype = INT;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 154 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "parser.y" /* yacc.c:1646  */
    {current_dtype = SHORT;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 157 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG;}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 158 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "parser.y" /* yacc.c:1646  */
    {current_dtype = LONG_LONG;}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 160 "parser.y" /* yacc.c:1646  */
    {current_dtype = CHAR;}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 161 "parser.y" /* yacc.c:1646  */
    {current_dtype = FLOAT;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "parser.y" /* yacc.c:1646  */
    {current_dtype = VOID;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = (yyvsp[0].entry)->data_type;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.content)=(yyvsp[0].content);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 186 "parser.y" /* yacc.c:1646  */
    {
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 193 "parser.y" /* yacc.c:1646  */
    {current_scope = exit_scope();}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "parser.y" /* yacc.c:1646  */
    {
											if((yyvsp[-1].content)->code == NULL)
												(yyval.content)->code = (yyvsp[0].content)->code;
											else{
											string code((yyvsp[-1].content)->code);
											string st((yyvsp[0].content)->code);
											code = code + st;
											(yyval.content)->code = (char *)code.c_str();
										}
}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.content)=(yyvsp[0].content);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 215 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 224 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of continue");}}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 225 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of break");}}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 227 "parser.y" /* yacc.c:1646  */
    {
																	if(is_func)
																	{
																		if(func_type != (yyvsp[-1].content)->data_type)
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 237 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 237 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 238 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 238 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 245 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 249 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0; }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.content)=(yyvsp[-1].content);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.content)=(yyvsp[0].content);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.content)=(yyvsp[0].content);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 273 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 274 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 275 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 276 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 277 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 278 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 279 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 280 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,2); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-2].content)->data_type;}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = (yyvsp[0].content);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type; (yyval.content) = (yyvsp[0].content);}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 288 "parser.y" /* yacc.c:1646  */
    {
																	type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1);
																//	cout<<"Here"<<endl;

																	rhs=0;
																	string code((yyvsp[0].content)->code);
																	if(code[0]!=0) code = code + "\n";
																	code = code + (yyvsp[-2].content)->code + (yyvsp[-1].content)->code + (yyvsp[0].content)->addr;
																	//cout<<code<<endl;
																	(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;
																	(yyval.content)->code = (char *)malloc(code.length()+1);
																	(yyval.content)->code = (char *)code.c_str();
																	cout<<(yyval.content)->code<<endl;
																}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 302 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;rhs=0;}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 303 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].data_type),1); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].data_type);rhs=0;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 304 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;rhs=0;}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 305 "parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].content)->data_type,(yyvsp[0].content)->data_type,1); (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;rhs=0;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-1].entry)->data_type;}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-1].entry)->data_type;}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].entry)->data_type;}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].entry)->data_type;}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].entry)->data_type;
																												 (yyval.content)->code = (char *)malloc(strlen((yyvsp[0].entry)->lexeme)+1);(yyval.content)->code = (yyvsp[0].entry)->lexeme; }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type; }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 318 "parser.y" /* yacc.c:1646  */
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
                                                                    }
                                                                    (yyval.entry) = (yyvsp[0].entry);
                                                            }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 334 "parser.y" /* yacc.c:1646  */
    {rhs=1;   (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" = ");}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 335 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" += ");}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 336 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" -= ");}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 337 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" *= ");}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 338 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" /= ");}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 339 "parser.y" /* yacc.c:1646  */
    {rhs=1; (yyval.content) = MEM_ALLOC; (yyval.content)->code = strdup(" %= ");}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = do_whats_necessary( (yyvsp[-2].content), '+', (yyvsp[0].content));	}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = do_whats_necessary( (yyvsp[-2].content), '-', (yyvsp[0].content));	}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = do_whats_necessary( (yyvsp[-2].content), '*', (yyvsp[0].content));	}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = do_whats_necessary( (yyvsp[-2].content), '/', (yyvsp[0].content));	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = do_whats_necessary( (yyvsp[-2].content), '%', (yyvsp[0].content));	}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].content)->data_type;}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 348 "parser.y" /* yacc.c:1646  */
    {
																								(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].entry)->data_type;
																								(yyval.content)->addr = (char*) malloc(sizeof(char)*(strlen((yyvsp[0].entry)->lexeme)+1));
																							  (yyval.content)->addr = (yyvsp[0].entry)->lexeme;
																							  (yyval.content)->code = (char *) malloc(20);
																								(yyval.content)->code[0] = 0;

																							}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 356 "parser.y" /* yacc.c:1646  */
    {
																								(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[0].entry)->data_type;
																								(yyval.content)->addr = (char*) malloc(sizeof(char)*(strlen((yyvsp[0].entry)->lexeme)+1));
																							  (yyval.content)->addr = (yyvsp[0].entry)->lexeme;
																								(yyval.content)->code = (char *) malloc(20);
																								(yyval.content)->code[0] = 0;}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].entry)->is_constant=1; (yyval.entry) = (yyvsp[0].entry);}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 370 "parser.y" /* yacc.c:1646  */
    {
																															if(is_declaration)
																															{
																																if((yyvsp[-1].entry)->value <= 0)
																																	yyerror("size of array is not positive");

																																else
                                                                                                                                if((yyvsp[-1].entry)->is_constant && !rhs)
																																	(yyvsp[-3].entry)->array_dimension = (yyvsp[-1].entry)->value;
																																	else if(rhs){
																																	{
																																if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[-1].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															}
																															}

																															else if((yyvsp[-1].entry)->is_constant)
																															{
																																if((yyvsp[-1].entry)->value > (yyvsp[-3].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[-1].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															(yyval.content) = MEM_ALLOC; (yyval.content)->data_type = (yyvsp[-3].entry)->data_type;
																														}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 401 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 402 "parser.y" /* yacc.c:1646  */
    {(yyval.entry) = (yyvsp[0].entry);}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 405 "parser.y" /* yacc.c:1646  */
    {
																													(yyval.data_type) = (yyvsp[-3].entry)->data_type;
																													check_parameter_list((yyvsp[-3].entry),param_list,p_idx);
																													p_idx = 0;
																												}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 411 "parser.y" /* yacc.c:1646  */
    {
							 																						 (yyval.data_type) = (yyvsp[-2].entry)->data_type;
																													 check_parameter_list((yyvsp[-2].entry),param_list,p_idx);
																													 p_idx = 0;
																												}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 423 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = (yyvsp[0].content)->data_type;}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 424 "parser.y" /* yacc.c:1646  */
    {param_list[p_idx++] = STRING;}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2145 "y.tab.c" /* yacc.c:1646  */
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
#line 426 "parser.y" /* yacc.c:1906  */


char * new_var()
	{

	char *temp = (char *)malloc(to_string(temp_var_number).length()+2);
	strcpy(temp,"t");
	snprintf(numconcat, 10,"%d",temp_var_number);
	strcat(temp,numconcat);

	temp_var_number++;
	return temp;
}

content_t* do_whats_necessary(content_t *a, char b, content_t *c)
{

				type_check(a->data_type,c->data_type,0);
				string left(a->code);
				string leftaddr(a->addr);
				string right(c->code);
				string rightaddr(c->addr);

				ret = MEM_ALLOC; ret->data_type = a->data_type;
				ret->addr = (char*) malloc(to_string(temp_var_number).length()+2);
				ret->addr = new_var();
				string addr(ret->addr);
				string exp = addr + " = " + leftaddr + " " + b + " " + rightaddr;

				if(left[0]!=0) left = left + "\n";
				if(right[0]!=0) right = right + "\n";

				code = (char *) malloc(left.length() + right.length()+ exp.length() + 1);
				strcat(code, left.c_str());
				strcat(code, right.c_str());
				strcat(code, exp.c_str());

				ret->code = (char *)malloc(sizeof(char)*(strlen(code) + 1));
				ret->code = code;
				return ret;
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

int main(int argc, char *argv[])
{
	 int i;
	 //cout<<"HI"<<endl;

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
/*

	printf("SYMBOL TABLES\n\n");
	//display_all();

	printf("CONSTANT TABLE");
	//display_constant_table(constant_table);
*/

	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
