%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symboltable.h"

	entry_t** symbol_table;
  entry_t** constant_table;
%}

%union
{
	double dval;
	entry_t* entry;
}

%token <entry> IDENTIFIER

 /* Constants */
%token <dval> DEC_CONSTANT HEX_CONSTANT
%token STRING

 /* Logical and Relational operators */
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

 /* Short hand assignment operators */
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token PTR_SELECT INCREMENT DECREMENT

 /* Data types */
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST

 /* Keywords */
%token DEFAULT IF FOR WHILE CONTINUE BREAK RETURN

%start starter
%left '+' '-'
%left '*' '/' '%'
%right '='
%left '<' '>' EQ NOT_EQ LS_EQ GR_EQ ','

%nonassoc UMINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

 /* Program is made up of multiple builder blocks. */
starter: starter builder
			 |builder;

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
    |SHORT INT
    |SHORT
    |LONG
		|LONG INT
    |LONG_LONG
    |LONG_LONG INT
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

statements:statements stmt
    |
    ;

 /* Grammar for what constitutes every individual statement */
single_stmt :if_block
    |for_block
    |while_block
    |declaration
    |function_call ';'
    ;

for_block:FOR '(' expression_stmt  expression_stmt ')' stmt
    |FOR '(' expression_stmt expression_stmt expression ')' stmt
    ;

if_block:IF '(' expression ')' stmt %prec LOWER_THAN_ELSE
				|IF '(' expression ')' stmt ELSE stmt
    ;

while_block: WHILE '(' expression	')' stmt
		;

declaration:type declaration_list ';'
           | assignment_expr ';'
					 | unary_expr ';'

declaration_list: declaration_list ',' sub_decl
		|sub_decl;

sub_decl: assignment_expr
    |IDENTIFIER
    |array_index
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
		|unary_expr
    |IDENTIFIER
    |constant
		|array_index
    ;


assignment_expr :lhs assign_op arithmetic_expr
    |lhs assign_op array_index
    |lhs assign_op function_call
		|lhs assign_op unary_expr
		|unary_expr assign_op unary_expr
    ;

unary_expr:	lhs INCREMENT
		|lhs DECREMENT
		|DECREMENT lhs
		|INCREMENT lhs

lhs:IDENTIFIER
    |array_index
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
array_index: IDENTIFIER '[' sub_expr ']'

function_call: IDENTIFIER '(' parameter_list ')'
             IDENTIFIER '(' ')'
             ;

parameter_list:
              parameter_list ','  parameter|
              parameter
              ;

parameter: sub_expr
        ;
%%

#include "lex.yy.c"
#include <ctype.h>

int main(int argc, char *argv[])
{
	symbol_table = create_table();
	constant_table = create_table();

	yyin = fopen(argv[1], "r");

	if(!yyparse())
	printf("\nParsing complete\n");
	else{
			yyerror ("Error message printed");
			printf("\nParsing failed\n");
	}


	fclose(yyin);
	return 0;
}

yyerror(char *msg)
{
	printf("%d : %s %s\n", yylineno, msg, yytext);
}
