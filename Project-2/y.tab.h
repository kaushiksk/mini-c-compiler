/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    STRING = 259,
    PTR_SELECT = 260,
    INCREMENT = 261,
    DECREMENT = 262,
    LOGICAL_AND = 263,
    LOGICAL_OR = 264,
    LS_EQ = 265,
    GR_EQ = 266,
    EQ = 267,
    NOT_EQ = 268,
    MUL_ASSIGN = 269,
    DIV_ASSIGN = 270,
    MOD_ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    LEFT_ASSIGN = 274,
    RIGHT_ASSIGN = 275,
    AND_ASSIGN = 276,
    XOR_ASSIGN = 277,
    OR_ASSIGN = 278,
    DEC_CONSTANT = 279,
    HEX_CONSTANT = 280,
    TYPEDEF = 281,
    EXTERN = 282,
    STATIC = 283,
    AUTO = 284,
    REGISTER = 285,
    SHORT = 286,
    INT = 287,
    LONG = 288,
    LONG_LONG = 289,
    SIGNED = 290,
    UNSIGNED = 291,
    CONST = 292,
    DEFAULT = 293,
    IF = 294,
    ELSE = 295,
    FOR = 296,
    CONTINUE = 297,
    BREAK = 298,
    RETURN = 299,
    UMINUS = 300
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define PTR_SELECT 260
#define INCREMENT 261
#define DECREMENT 262
#define LOGICAL_AND 263
#define LOGICAL_OR 264
#define LS_EQ 265
#define GR_EQ 266
#define EQ 267
#define NOT_EQ 268
#define MUL_ASSIGN 269
#define DIV_ASSIGN 270
#define MOD_ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define LEFT_ASSIGN 274
#define RIGHT_ASSIGN 275
#define AND_ASSIGN 276
#define XOR_ASSIGN 277
#define OR_ASSIGN 278
#define DEC_CONSTANT 279
#define HEX_CONSTANT 280
#define TYPEDEF 281
#define EXTERN 282
#define STATIC 283
#define AUTO 284
#define REGISTER 285
#define SHORT 286
#define INT 287
#define LONG 288
#define LONG_LONG 289
#define SIGNED 290
#define UNSIGNED 291
#define CONST 292
#define DEFAULT 293
#define IF 294
#define ELSE 295
#define FOR 296
#define CONTINUE 297
#define BREAK 298
#define RETURN 299
#define UMINUS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "parser.y" /* yacc.c:1909  */

	long dval;
	entry_t* entry;

#line 149 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
