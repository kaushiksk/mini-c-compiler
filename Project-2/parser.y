%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "symboltable.h"

	entry_t** symbol_table;
  entry_t** constant_table;

	double Evaluate (double lhs_value,int assign_type,double rhs_value);
	int current_dtype;
	int yyerror(char *msg);
%}

%union
{
	double dval;
	entry_t* entry;
	int ival;
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
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST

 /* Keywords */
%token IF FOR WHILE CONTINUE BREAK RETURN

%type <dval> expression
%type <dval> sub_expr
%type <dval> constant
%type <dval> unary_expr
%type <dval> arithmetic_expr
%type <dval> assignment_expr
%type <entry> lhs
%type <ival> assign_op

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
	|RETURN ';'
	|CONTINUE ';'
	|BREAK ';'
	|RETURN sub_expr ';'
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
			 |declaration_list ';'
			 | unary_expr ';'

declaration_list: declaration_list ',' sub_decl
		|sub_decl;

sub_decl: assignment_expr
    |IDENTIFIER                     {$1 -> data_type = current_dtype;}
    |array_index
    /*|struct_block ';'*/
    ;

/* This is because we can have empty expession statements inside for loops */
expression_stmt:expression ';'
    |';'
    ;

expression:
    expression ',' sub_expr								{$$ = $1,$3;}
    |sub_expr		                                    {$$ = $1;}
		;

sub_expr:
    sub_expr '>' sub_expr						{$$ = ($1 > $3);}
    |sub_expr '<' sub_expr						{$$ = ($1 < $3);}
    |sub_expr EQ sub_expr						{$$ = ($1 == $3);}
    |sub_expr NOT_EQ sub_expr                   {$$ = ($1 != $3);}
    |sub_expr LS_EQ sub_expr                    {$$ = ($1 <= $3);}
    |sub_expr GR_EQ sub_expr                    {$$ = ($1 >= $3);}
	|sub_expr LOGICAL_AND sub_expr              {$$ = ($1 && $3);}
	|sub_expr LOGICAL_OR sub_expr               {$$ = ($1 || $3);}
	|'!' sub_expr                               {$$ = (!$2);}
	|arithmetic_expr							{$$ = $1;}
    |assignment_expr                            {$$ = $1;}
	|unary_expr                                 {$$ = $1;}
    /* |IDENTIFIER                                     {$$ = $1->value;}
    |constant                                   {$$ = $1;} */
		//|array_index
    ;


assignment_expr :lhs assign_op arithmetic_expr     {$$ = $1->value = Evaluate($1->value,$2,$3);}
    |lhs assign_op array_index                     {$$ = 0;}
    |lhs assign_op function_call                   {$$ = 0;}
	|lhs assign_op unary_expr                      {$$ = $1->value = Evaluate($1->value,$2,$3);}
	|unary_expr assign_op unary_expr               {$$ = 0;}
    ;

unary_expr:	lhs INCREMENT                          {$$ = $1->value = ($1->value)++;}
	|lhs DECREMENT                                 {$$ = $1->value = ($1->value)--;}
	|DECREMENT lhs                                 {$$ = $2->value = --($2->value);}
	|INCREMENT lhs                                 {$$ = $2->value = ++($2->value);}

lhs:IDENTIFIER                                     {$$ = $1; if(! $1->data_type) $1->data_type = current_dtype;}
    //|array_index
    ;

assign_op:'='                                      {$$ = '=';}
    |ADD_ASSIGN                                    {$$ = ADD_ASSIGN;}
    |SUB_ASSIGN                                    {$$ = SUB_ASSIGN;}
    |MUL_ASSIGN                                    {$$ = MUL_ASSIGN;}
    |DIV_ASSIGN                                    {$$ = DIV_ASSIGN;}
    |MOD_ASSIGN                                    {$$ = MOD_ASSIGN;}
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr    {$$ = $1 + $3;}
    |arithmetic_expr '-' arithmetic_expr                {$$ = $1 - $3;}
    |arithmetic_expr '*' arithmetic_expr                {$$ = $1 * $3;}
    |arithmetic_expr '/' arithmetic_expr                {$$ = ($3 == 0) ? yyerror("Divide by 0!") : ($1 / $3);}
	|arithmetic_expr '%' arithmetic_expr                {$$ = (int)$1 % (int)$3;}
	|'(' arithmetic_expr ')'                            {$$ = $2;}
    |'-' arithmetic_expr %prec UMINUS                   {$$ = -$2;}
    |IDENTIFIER                                         {$$ = $1 -> value;}
    |constant                                           {$$ = $1;}
    ;

constant: DEC_CONSTANT                                  {$$ = $1;}
    |HEX_CONSTANT                                       {$$ = $1;}
    ;

array_index: IDENTIFIER '[' sub_expr ']'

function_call: IDENTIFIER '(' parameter_list ')'
             |IDENTIFIER '(' ')'
             ;

parameter_list:
              parameter_list ','  parameter
              |parameter
              ;

parameter: sub_expr
					|STRING

        ;
%%

#include "lex.yy.c"
#include <ctype.h>


double Evaluate (double lhs_value,int assign_type,double rhs_value)
{
	switch(assign_type)
	{
		case '=': return rhs_value;
		case ADD_ASSIGN: return (lhs_value + rhs_value);
		case SUB_ASSIGN: return (lhs_value - rhs_value);
		case MUL_ASSIGN: return (lhs_value * rhs_value);
		case DIV_ASSIGN: return (lhs_value / rhs_value);
		case MOD_ASSIGN: return ((int)lhs_value % (int)rhs_value);
	}
}

int main(int argc, char *argv[])
{
	symbol_table = create_table();
	constant_table = create_table();

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
	display(symbol_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
}
