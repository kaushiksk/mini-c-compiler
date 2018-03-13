%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symboltable.h"

	#include "lex.yy.c"

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  extern entry_t** constant_table;

	int current_dtype;
	int yyerror(char *msg);

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;
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
%token INCREMENT DECREMENT

 /* Data types */
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST VOID

 /* Keywords */
%token IF FOR WHILE CONTINUE BREAK RETURN

%type <entry> identifier
 /* %type <dval> expression
 %type <dval> sub_expr
 %type <dval> constant
 %type <dval> unary_expr
 %type <dval> arithmetic_expr
 %type <dval> assignment_expr
 %type <ival> assign_op */

%start starter

%left ','
%right '='
%left LOGICAL_OR
%left LOGICAL_AND
%left EQ NOT_EQ
%left '<' '>' LS_EQ GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'


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
function: type {func_type = current_dtype; is_declaration=1;} identifier {is_declaration = 0;} '(' argument_list ')' {is_func = 1;} compound_stmt {is_func = 0;}
        ;
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

type_specifier :INT                    {current_dtype = INT;}
    |SHORT INT                         {current_dtype = SHORT;}
    |SHORT                             {current_dtype = SHORT;}
    |LONG                              {current_dtype = LONG;}
		|LONG INT                          {current_dtype = LONG;}
    |LONG_LONG                         {current_dtype = LONG_LONG;}
    |LONG_LONG INT                     {current_dtype = LONG_LONG;}
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
arg :type identifier
   ;

 /* Generic statement. Can be compound or a single statement */
stmt:compound_stmt
    |single_stmt
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :'{' {current_scope = create_new_scope();} statements '}' {current_scope = exit_scope();}
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
		|RETURN ';'								  {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}

		|CONTINUE ';'							 {if(!is_loop) {yyerror("Illegal use of continue");}}
		|BREAK ';'                 {if(!is_loop) {yyerror("Illegal use of break");}}

		|RETURN sub_expr ';'			 {
																	if(is_func)
																	{
																		if(func_type != INT)
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
    ;

for_block:FOR  '(' expression_stmt  expression_stmt ')' {is_loop = 1;} stmt {is_loop = 0;}
    |FOR '(' expression_stmt expression_stmt expression ')' stmt
    ;

if_block:IF '(' expression ')' stmt %prec LOWER_THAN_ELSE
				|IF '(' expression ')' stmt ELSE stmt
    ;

while_block: WHILE '(' expression	')' {is_loop = 1;} stmt {is_loop = 0;}
		;

declaration:type {is_declaration = 1;} declaration_list ';' {is_declaration = 0;}
					 |declaration_list ';'
					 | unary_expr ';'

declaration_list: declaration_list ',' sub_decl
		|sub_decl;

sub_decl: assignment_expr
    |identifier
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
		;

sub_expr:
    sub_expr '>' sub_expr
    |sub_expr '<' sub_expr
    |sub_expr EQ sub_expr
    |sub_expr NOT_EQ sub_expr
    |sub_expr LS_EQ sub_expr
    |sub_expr GR_EQ sub_expr
		|sub_expr LOGICAL_AND sub_expr
		|sub_expr LOGICAL_OR sub_expr
		|'!' sub_expr
		|arithmetic_expr
    |assignment_expr
		|unary_expr
    ;


assignment_expr :identifier assign_op arithmetic_expr
    |identifier assign_op array_index
    |identifier assign_op function_call
		|identifier assign_op unary_expr
		|unary_expr assign_op unary_expr
    ;

unary_expr:	identifier INCREMENT
		|identifier DECREMENT
		|DECREMENT identifier
		|INCREMENT identifier

identifier:IDENTIFIER                                    {
																														if(is_declaration)
																														{
																															$1 = insert(SYMBOL_TABLE,yytext,IDENTIFIER);
																															if($1 == NULL) yyerror("Re-declaration of variable");
																														}
																														else
																														{
																															$1 = search_recursive(yytext);
																															if($1 == NULL) yyerror("Variable not declared in scope");
																														}
																														$$ = $1;

																														if($1!=NULL && !$1->data_type)
																														$1->data_type = current_dtype;

																												}
    ;

assign_op:'='
    |ADD_ASSIGN
    |SUB_ASSIGN
    |MUL_ASSIGN
    |DIV_ASSIGN
    |MOD_ASSIGN
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr
    |arithmetic_expr '-' arithmetic_expr
    |arithmetic_expr '*' arithmetic_expr
    |arithmetic_expr '/' arithmetic_expr
		|arithmetic_expr '%' arithmetic_expr
		|'(' arithmetic_expr ')'
    |'-' arithmetic_expr %prec UMINUS
    |identifier
    |constant
    ;

constant: DEC_CONSTANT
    |HEX_CONSTANT
    ;

array_index: identifier '[' sub_expr ']'

function_call: identifier '(' parameter_list ')'
             |identifier '(' ')'
             ;

parameter_list:
              parameter_list ','  parameter
              |parameter
              ;

parameter: sub_expr
					|STRING

        ;
%%


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
		printf("\nParsing complete\n");
	}
	else
	{
			printf("\nParsing failed\n");
	}


	printf("\n\tSymbol table");
	display_all();


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
