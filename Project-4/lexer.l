%{

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "y.tab.h"

entry_t** constant_table;

int cmnt_strt = 0;

%}

letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

 /* Exclusive states */
%x CMNT

%%
  /* Keywords*/
"int"                             {return INT;}
"char"                            {return CHAR;}
"char*"                           {return CHAR_STAR;}
"float"                           {return FLOAT;}
"void"                            {return VOID;}
"long"                            {return LONG;}
"long long"                       {return LONG_LONG;}
"short"                           {return SHORT;}
"signed"                          {return SIGNED;}
"unsigned"                        {return UNSIGNED;}
"for"                             {return FOR;}
"while"                           {return WHILE;}
"break"                           {return BREAK;}
"continue"                        {return CONTINUE;}
"if"                              {return IF;}
"else"                            {return ELSE;}
"return"                          {return RETURN;}

{identifier}                      {return  IDENTIFIER;}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?       { yylval.entry = insert(constant_table,yytext,(int)strtol(yytext, NULL, 16),INT); return  HEX_CONSTANT;}
'({letter}|{digit})'              { yylval.entry = insert(constant_table,yytext,yytext[1],CHAR); return CHAR_CONSTANT;}
[+\-]?{digit}+[lLuU]?             { yylval.entry = insert(constant_table,yytext,atoi(yytext),INT); return  DEC_CONSTANT;}
[+\-]?{digit}*\.{digit}+          { yylval.entry = insert(constant_table,yytext,atof(yytext),FLOAT); return FLOAT_CONSTANT;}

"/*"                              {cmnt_strt = yylineno; BEGIN CMNT;}
<CMNT>.|{ws}                      ;
<CMNT>\n                          {yylineno++;}
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
<CMNT><<EOF>>                     {printf("Line %3d: Unterminated comment\n", cmnt_strt); yyterminate();}

"//".*                            ;

\"[^\"\n]*\"                      {
                                    if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
                                    {
                                      yyless(yyleng-1);       /* push the quote back if it was escaped */
                                      yymore();
                                    }
                                    else
                                    {
                                      yylval.entry = insert(constant_table,yytext,INT_MAX,STRING);
                                      return STRING;
                                    }
                                  }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	          {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}

"--"			                {return DECREMENT;}
"++"			                {return INCREMENT;}
"+="                      {return ADD_ASSIGN;}
"-="                      {return SUB_ASSIGN;}
"*="                      {return MUL_ASSIGN;}
"/="                      {return DIV_ASSIGN;}
"%="                      {return MOD_ASSIGN;}


"&&"			                {return LOGICAL_AND;}
"||"			                {return LOGICAL_OR;}
"<="			                {return LS_EQ;}
">="			                {return GR_EQ;}
"=="			                {return EQ;}
"!="		                  {return NOT_EQ;}

.                         {return yytext[0];}

%%
