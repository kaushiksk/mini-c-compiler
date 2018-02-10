%{

#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"
%}

%union{
	long dval;
	entry_t* entry;
}

%token <entry> IDENTIFIER
%token STRING

%token PTR_SELECT INCREMENT DECREMENT LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token <dval> DEC_CONSTANT
%token <dval> HEX_CONSTANT

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST

%token DEFAULT IF ELSE FOR CONTINUE BREAK RETURN

%start starter
%left '+' '-'
%left '*' '/'
%right '='
%left '<' '>' EQ NOT_EQ LS_EQ GR_EQ
%nonassoc UMINUS

%%

 /* Program is made up of multiple builder blocks. */
starter: starter builder|
       builder; 

 /* Each builder block is either a function or a declaration */
builder: function|
       declaration;

 /* This is how a function looks like */
function: type IDENTIFIER '(' argument_list ')' compound_stmt;

 /* Now we will define a grammar for how types can be specified */

type :data_type pointer
    |data_type;

pointer: '*' pointer
    |'*'
    ;

data_type :sign_specifier type_specifier
    |type_specifier
    ;

sign_specifier :SIGNED
    |UNSIGNED
    ;

type_specifier :INT
    /*|SHORT INT*/
    |SHORT
    |LONG
    |LONG_LONG
    /*|LONG_LONG INT*/
    ;

 /* grammar rules for argument list */
 /* argument list can be empty */
argument_list :arguments
    |
    ;
 /* arguments are comma separated TYPE ID pairs */
arguments :arguments ',' arg
    |arg
    ;

 /* Each arg is a TYPE ID pair */
arg :type IDENTIFIER
   ;

 /* Generic statement. Can be compound or a single statement */
stmt:compound_stmt
    |single_stmt
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' statements '}'
    ;

statements:statements single_stmt
    |
    ;

 /* Grammar for what constitutes every individual statement */
single_stmt :if_block
    |for_block
    /*|while_block*/
    |declaration
    |function_call
    ;

for_block:FOR '(' expression_stmt  expression_stmt ')' stmt 
    |FOR '(' expression_stmt expression_stmt expression ')' stmt
    ;

if_block:IF '(' expression ')' stmt
    ;

declaration:type assignment_expr ';'
    |type IDENTIFIER ';'
    |type array ';'
    |assignment_expr ';'
    /*|struct_block ';'*/
    ;

/* This is because we can have empty expession statements inside for loops */
expression_stmt:expression ';'
    |';'
    ;

expression:
    expression ',' sub_expr
    |sub_expr 
    |expression '>' expression
    |expression '<' expression
    |expression EQ expression
    |expression NOT_EQ expression
    |expression LS_EQ expression
    |expression GR_EQ expression
    ;

sub_expr:assignment_expr
    |IDENTIFIER
    |constant
    ;

assignment_expr :lhs assign_op arithmetic_expr
    |lhs assign_op array_assign
    |lhs assign_op function_call
    ;

lhs:IDENTIFIER
    |array_assign
    ;

assign_op:'='
    |LEFT_ASSIGN
    |RIGHT_ASSIGN
    |ADD_ASSIGN
    |SUB_ASSIGN
    |MUL_ASSIGN
    |DIV_ASSIGN
    |MOD_ASSIGN
    |AND_ASSIGN
    |OR_ASSIGN
    |XOR_ASSIGN
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr
    |arithmetic_expr '-' arithmetic_expr
    |arithmetic_expr '*' arithmetic_expr
    |arithmetic_expr '/' arithmetic_expr
    |'(' arithmetic_expr ')'
    |'-' arithmetic_expr %prec UMINUS
    |IDENTIFIER
    |constant    
    ;

constant: DEC_CONSTANT
    |HEX_CONSTANT
    ;
array_assign: IDENTIFIER '[' sub_expr ']'
array: IDENTIFIER '[' ']'
    |array_assign
    ;
/*struct_block: STRUCT IDENTIFIER '{' type */

function_call: IDENTIFIER '(' parameter_list ')' ';'
             IDENTIFIER '(' ')' ';'
             ;

parameter_list:
              parameter_list ','  parameter|
              parameter
              ;

parameter: IDENTIFIER
        |constant
        |array_assign
        |function_call
        ;
%%
#include"lex.yy.c"
#include<ctype.h>

int main(int argc, char *argv[])
{

entry_t** symbol_table;
entry_t** constant_table;
symbol_table = create_table();
constant_table = create_table();

	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");
	
	fclose(yyin);
    return 0;
}
    
yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         
