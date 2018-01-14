%{
#include<stdlib.h>
#include<stdio.h>
#include "symboltable.h"

enum{
  KEYWORD = 25,
  COSTANT,
  IDENTIFIER,
  SEMICOLON
};

enum{
  GR_OP = 30,
  GRE_OP,
  LS_OP,
  LSE_OP,
  EQ_OP,
  NEQ_OP
};

enum{
  OR = 40,
  AND,
  NOT,

};
enum{
  CURL_OPEN = 100,
  CURL_CLOSE,
  PAR_OPEN,
  PAR_CLOSE,
  SQUARE_OPEN,
  SQUARE_CLOSE
};

enum{
  MUL_OP = 120,
  ADD_OP,
  MINUS_OP,
  DIV_OP,
  MOD_OP,
  INC_OP,
  DEC_OP,
  ASSSIGN
};
%}

keywords int|long|short|signed|unsigned|for|break|continue|if|else|return|char
letter [a-zA-Z]
digit [0-9]
ws [ \t]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

%x CMNT
%x PREPROC

%%
"int"
"long"
"short"
"signed"
"unsigned"
"for"
"break"
"continue"
"if"
"else"
"return"
"char"
{keywords}                   {printf("%s:keyword\n",yytext);}
{identifier}                 {printf("%s:identfier\n",yytext);}
{ws}                         ;
[+-]?0[xX]{hex}+[lLuU]?      {printf("%s: constant\n", yytext);}
[+-]?{digit}+[lLuU]?         {printf("%s: constant\n", yytext);}
"/*"                         {BEGIN CMNT; printf("Begin comment\n");}
<CMNT>.|\n                   ECHO;
<CMNT>"*/"                   {BEGIN INITIAL; printf("End comment\n");}
<CMNT>"/*"                   {printf("Nested comments are not valid!\n"); exit(1);}
^"#include"                  {BEGIN PREPROC;}
<PREPROC>{ws}?"<"[^>\n]+">"  {printf("%s: Header file\n",yytext);}
<PREPROC>{ws}?\"[^"\n]+\"         {printf("%s: Header file\n",yytext);}
<PREPROC>\n                  {BEGIN INITIAL;}
<PREPROC>.*                   {printf("Illegal header file!\n"); exit(1);}
"//".*                       {printf("%s: Single line comment\n",yytext);}
\"[^\"\n]*\"                    {

  if(yytext[yyleng-2]=='\\')
  {
    yyless(yyleng-1);
    yymore();
  }
  else
  printf("%s:string\n",yytext);

                            }
\"[^\"\n]*$                   {printf("%s: Illegal string\n",yytext); exit(1);}
{digit}+({letter}|_)+	      {printf("%s: Illegal identifier name\n",yytext); exit(1);}
\n                           ;
"--"			                   {printf("%s:decrement\n",yytext);}
"->"			                   {printf("%s:pointer selection\n",yytext);}
"++"			                   {printf("%s:increment\n",yytext);}
"&&"			                   {printf("%s:logical AND\n",yytext);}
"||"			                   {printf("%s:logical OR\n",yytext);}
"<="			                   {printf("%s:Less than or equal\n",yytext);}
">="			                   {printf("%s:Greater than or equal\n",yytext);}
"=="			                   {printf("%s:Equal to\n",yytext);}
"!="		                     {printf("%s:Not equal to\n",yytext);}
";"			                     {printf("%s:Terminator\n",yytext);}
"{"                          {printf("%s:Open curly brackets\n",yytext);}
"}"                          {printf("%s:Close curly brackets\n",yytext);}
","			                     {printf("%s:Comma\n",yytext);}
"="			                     {printf("%s:Assignment\n",yytext);}
"("			                     {printf("%s:Open parantheses\n",yytext);}
")"			                     {printf("%s:Close parantheses\n",yytext);}
"["                          {printf("%s:Open square brackets\n",yytext);}
"]"                          {printf("%s:Close curly brackets\n",yytext);}
"-"			                     {printf("%s:Minus operator\n",yytext);}
"+"			                     {printf("%s:Plus operator\n",yytext);}
"*"			                     {printf("%s:Star operator\n",yytext);}
"/"		                       {printf("%s:Forward slash\n",yytext);}
"%"			                     {printf("%s:Modulo operator\n",yytext);}
"<"			                     {printf("%s:Less than operator\n",yytext);}
">"			                     {printf("%s:Greater than operator\n",yytext);}
.                            {printf("%s:Illegal charcter\n",yytext);}

%%

int main()
{
  yyin=fopen("test-case-9.c","r");
  yylex();
}
