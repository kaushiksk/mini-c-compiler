%{

#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "tokens.h"

entry_t** symbol_table;
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
%x PREPROC

%%
  /* Keywords*/
"int"                             {insert( symbol_table,yytext,INT);}
"long"                            {insert( symbol_table,yytext,LONG);}
"long long"                            {insert( symbol_table,yytext,LONG_LONG);}
"short"                           {insert( symbol_table,yytext,SHORT);}
"signed"                          {insert( symbol_table,yytext,SIGNED);}
"unsigned"                        {insert( symbol_table,yytext,UNSIGNED);}
"for"                             {insert( symbol_table,yytext,FOR);}
"break"                           {insert( symbol_table,yytext,BREAK);}
"continue"                        {insert( symbol_table,yytext,CONTINUE);}
"if"                              {insert( symbol_table,yytext,IF);}
"else"                            {insert( symbol_table,yytext,ELSE);}
"return"                          {insert( symbol_table,yytext,RETURN);}

{identifier}                      {insert( symbol_table,yytext,IDENTIFIER);}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?        {insert( constant_table,yytext,HEX_CONSTANT);}
[+\-]?{digit}+[lLuU]?              {insert( constant_table,yytext,DEC_CONSTANT);}
"/*"                              {cmnt_strt = yylineno; BEGIN CMNT;}
<CMNT>.|{ws}                      ;
<CMNT>\n                          {yylineno++;}
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
<CMNT><<EOF>>                     {printf("Line %3d: Unterminated comment\n", cmnt_strt); yyterminate();}
^"#include"                       {BEGIN PREPROC;}
<PREPROC>"<"[^>\n]+">"            {insert( symbol_table,yytext,HEADER_FILE);}
<PREPROC>{ws}                       ;
<PREPROC>\"[^"\n]+\"              {insert( symbol_table,yytext,HEADER_FILE);}
<PREPROC>\n                       {yylineno++; BEGIN INITIAL;}
<PREPROC>.                        {printf("Line %3d: Illegal header file format \n",yylineno); yyterminate();}
"//".*                            ;

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was */
    yymore();
  }
  else
  insert( constant_table,yytext,STRING);
 }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	        {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}
"--"			                {insert( symbol_table,yytext,DECREMENT);}
"++"			                {insert( symbol_table,yytext,INCREMENT);}
"->"			                {insert( symbol_table,yytext,PTR_SELECT);}
"&&"			                {insert( symbol_table,yytext,LOGICAL_AND);}
"||"			                {insert( symbol_table,yytext,LOGICAL_OR);}
"<="			                {insert( symbol_table,yytext,LS_THAN_EQ);}
">="			                {insert( symbol_table,yytext,GR_THAN_EQ);}
"=="			                {insert( symbol_table,yytext,EQ);}
"!="		                    {insert( symbol_table,yytext,NOT_EQ);}
";"			                    {insert( symbol_table,yytext,DELIMITER);}
"{"                             {insert( symbol_table,yytext,OPEN_BRACES);}
"}"                             {insert( symbol_table,yytext,CLOSE_BRACES);}
","			                    {insert( symbol_table,yytext,COMMA);}
"="			                    {insert( symbol_table,yytext,ASSIGN);}
"("			                    {insert( symbol_table,yytext,OPEN_PAR);}
")"			                    {insert( symbol_table,yytext,CLOSE_PAR);}
"["                             {insert( symbol_table,yytext,OPEN_SQ_BRKT);}
"]"                             {insert( symbol_table,yytext,CLOSE_SQ_BRKT);}
"-"			                    {insert( symbol_table,yytext,MINUS);}
"+"			                    {insert( symbol_table,yytext,PLUS);}
"*"			                    {insert( symbol_table,yytext,STAR);}
"/"		                        {insert( symbol_table,yytext,FW_SLASH);}
"%"			                    {insert( symbol_table,yytext,MODULO);}
"<"			                    {insert( symbol_table,yytext,LS_THAN);}
">"			                    {insert( symbol_table,yytext,GR_THAN);}
.                               {printf("Line %3d: Illegal character %s\n",yylineno,yytext);}

%%

int main()
{
  yyin=fopen("testcases/test-case-5.c","r");
  symbol_table=create_table();
  constant_table=create_table();
  yylex();
  printf("\n\tSymbol table\n");
  display(symbol_table);
  printf("\n\n\tConstants Table\n");
  display(constant_table);
}
