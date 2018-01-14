%{

#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "tokens.h"

entry_t** hash_table;

%}

letter [a-zA-Z]
digit [0-9]
ws [ \t]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

 /* Exclusive states */
%x CMNT
%x PREPROC

%%
  /* Keywords*/
"int"                             {insert( hash_table,yytext,INT);}
"long"                            {insert( hash_table,yytext,LONG);}
"short"                           {insert( hash_table,yytext,SHORT);}
"signed"                          {insert( hash_table,yytext,SIGNED);}
"unsigned"                        {insert( hash_table,yytext,UNSIGNED);}
"for"                             {insert( hash_table,yytext,FOR);}
"break"                           {insert( hash_table,yytext,BREAK);}
"continue"                        {insert( hash_table,yytext,CONTINUE);}
"if"                              {insert( hash_table,yytext,IF);}
"else"                            {insert( hash_table,yytext,ELSE);}
"return"                          {insert( hash_table,yytext,RETURN);}
"char"                            {insert( hash_table,yytext,CHAR);}

{identifier}                      {insert( hash_table,yytext,IDENTIFIER);}
{ws}                              ;
[+-]?0[xX]{hex}+[lLuU]?           {insert( hash_table,yytext,HEX_CONSTANT);}
[+-]?{digit}+[lLuU]?              {insert( hash_table,yytext,DEC_CONSTANT);}
"/*"                              {BEGIN CMNT;}
<CMNT>.|\n                        ;
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
^"#include"                       {BEGIN PREPROC;}
<PREPROC>{ws}?"<"[^>\n]+">"       {insert( hash_table,yytext,HEADER_FILE);}
<PREPROC>{ws}?\"[^"\n]+\"         {insert( hash_table,yytext,HEADER_FILE);}
<PREPROC>\n                       {BEGIN INITIAL;}
<PREPROC>.*                       {printf("Line %3d: Illegal header file %s!\n",yylineno,yytext);}
"//".*                            ;

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was */
    yymore();
  }
  else
  insert( hash_table,yytext,STRING);
 }

\"[^\"\n]*$                     {printf("Line %3d: Illegal string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	        {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;} 
"--"			                {insert( hash_table,yytext,DECREMENT);}
"++"			                {insert( hash_table,yytext,INCREMENT);}
"->"			                {insert( hash_table,yytext,PTR_SELECT);}
"&&"			                {insert( hash_table,yytext,LOGICAL_AND);}
"||"			                {insert( hash_table,yytext,LOGICAL_OR);}
"<="			                {insert( hash_table,yytext,LS_THAN_EQ);}
">="			                {insert( hash_table,yytext,GR_THAN_EQ);}
"=="			                {insert( hash_table,yytext,EQ);}
"!="		                    {insert( hash_table,yytext,NOT_EQ);}
";"			                    {insert( hash_table,yytext,DELIMITER);}
"{"                             {insert( hash_table,yytext,OPEN_BRACES);}
"}"                             {insert( hash_table,yytext,CLOSE_BRACES);}
","			                    {insert( hash_table,yytext,COMMA);}
"="			                    {insert( hash_table,yytext,ASSIGN);}
"("			                    {insert( hash_table,yytext,OPEN_PAR);}
")"			                    {insert( hash_table,yytext,CLOSE_PAR);}
"["                             {insert( hash_table,yytext,OPEN_SQ_BRKT);}
"]"                             {insert( hash_table,yytext,CLOSE_SQ_BRKT);}
"-"			                    {insert( hash_table,yytext,MINUS);}
"+"			                    {insert( hash_table,yytext,PLUS);}
"*"			                    {insert( hash_table,yytext,STAR);}
"/"		                        {insert( hash_table,yytext,FW_SLASH);}
"%"			                    {insert( hash_table,yytext,MODULO);}
"<"			                    {insert( hash_table,yytext,LS_THAN);}
">"			                    {insert( hash_table,yytext,GR_THAN);}
.                               {printf("Line %3d: Illegal character %s\n",yylineno,yytext);}

%%

int main()
{
  yyin=fopen("test-case-9.c","r");
  hash_table=create_table();
  yylex();
  display(hash_table);
}
