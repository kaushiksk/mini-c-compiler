%{
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

%}

%union
{
	int data_type;
	entry_t* entry;
	content_t* content;
}

%token <entry> IDENTIFIER

 /* Constants */
%token <entry> DEC_CONSTANT HEX_CONSTANT CHAR_CONSTANT FLOAT_CONSTANT
%token STRING

 /* Logical and Relational operators */
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ

 /* Short hand assignment operators */
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token INCREMENT DECREMENT

 /* Data types */
%token SHORT INT LONG LONG_LONG SIGNED UNSIGNED CONST VOID CHAR FLOAT

 /* Keywords */
%token IF FOR WHILE CONTINUE BREAK RETURN

%type <entry> identifier
%type <entry> constant
%type <entry> array_index

%type <content> sub_expr
%type <content> unary_expr
%type <content> arithmetic_expr
%type <content> assignment_expr
%type <data_type> function_call
%type <content> array_access
%type <content> lhs
%type <content> sub_decl
%type <content> declaration
%type <content> declaration_list
%type <content> stmt
%type <content> single_stmt
%type <content> statements
%type <content> assign_op

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
			 | builder;

 /* Each builder block is either a function or a declaration */
builder: function
| declaration {/*if($1 != NULL && $1->code != NULL) cout<<$1->code<<endl; else printf("Hmm\n");*/ }
			 ;

 /* This is how a function looks like */
function: type
					identifier 											{
																						func_type = current_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();
																					}

					'(' argument_list ')' 					{
																						is_declaration = 0;
																						fill_parameter_list($2,param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}

					compound_stmt										{
																						is_func = 0;
																					}
          ;
 /* Now we will define a grammar for how types can be specified */

type : data_type pointer
     {is_declaration = 1; }
     | data_type
     {is_declaration = 1; }
		 ;

pointer: '*' pointer
    	 | '*'
       ;

data_type : sign_specifier type_specifier
    			| type_specifier
    			;

sign_specifier : SIGNED
    					 | UNSIGNED
    			 		 ;

type_specifier :INT                    {current_dtype = INT;}
    |SHORT INT                         {current_dtype = SHORT;}
    |SHORT                             {current_dtype = SHORT;}
    |LONG                              {current_dtype = LONG;}
		|LONG INT                          {current_dtype = LONG;}
    |LONG_LONG                         {current_dtype = LONG_LONG;}
    |LONG_LONG INT                     {current_dtype = LONG_LONG;}
		|CHAR 														 {current_dtype = CHAR;}
		|FLOAT 														 {current_dtype = FLOAT;}
		|VOID															 {current_dtype = VOID;}
    ;

 /* grammar rules for argument list */
 /* argument list can be empty */
argument_list : arguments
    					|
    					;
 /* arguments are comma separated TYPE ID pairs */
arguments : arguments ',' arg
    			| arg
    			;

 /* Each arg is a TYPE ID pair */
arg : type identifier									{param_list[p_idx++] = $2->data_type;}
    ;

 /* Generic statement. Can be compound or a single statement */
stmt:compound_stmt
    |single_stmt {$$=$1;}
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :
							'{' 							{
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}

							statements

							'}' 						{current_scope = exit_scope();}
    ;

statements:statements stmt  {
											if($1->code == NULL)
												$$->code = $2->code;
											else{
											string code($1->code);
											string st($2->code);
											code = code + st;
											$$->code = (char *)code.c_str();
										}
}
    |
    ;

 /* Grammar for what constitutes every individual statement */
single_stmt :if_block
    |for_block
    |while_block
    |declaration {$$=$1;}
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
																		if(func_type != $2->data_type)
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
    ;

for_block:FOR '(' expression_stmt  expression_stmt ')' {is_loop = 1;} stmt {is_loop = 0;}
    		 |FOR '(' expression_stmt expression_stmt expression ')' {is_loop = 1;} stmt {is_loop = 0;}
    		 ;

if_block:IF '(' expression ')' stmt 								%prec LOWER_THAN_ELSE
				|IF '(' expression ')' stmt ELSE stmt
    ;

while_block: WHILE '(' expression	')' {is_loop = 1;} stmt {is_loop = 0;}
		;

declaration: type  declaration_list ';'
           {is_declaration = 0; }
					 | declaration_list ';' {$$=$1;}
					 | unary_expr ';'


declaration_list: declaration_list ',' sub_decl
								|sub_decl    {$$=$1;}
								;

sub_decl: assignment_expr     {$$=$1;}
    		|identifier
    		|array_access
				;

/* This is because we can have empty expession statements inside for loops */
expression_stmt: expression ';'
    					 | ';'
    			 		 ;

expression: expression ',' sub_expr
    			| sub_expr
					;

sub_expr:
    sub_expr '>' sub_expr															  {type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |sub_expr '<' sub_expr															{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |sub_expr EQ sub_expr																{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |sub_expr NOT_EQ sub_expr														{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |sub_expr LS_EQ sub_expr														{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |sub_expr GR_EQ sub_expr														{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
		|sub_expr LOGICAL_AND sub_expr											{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
		|sub_expr LOGICAL_OR sub_expr												{type_check($1->data_type,$3->data_type,2); $$ = MEM_ALLOC; $$->data_type = $1->data_type;}
		|'!' sub_expr																				{$$ = MEM_ALLOC; $$->data_type = $2->data_type;}
		|arithmetic_expr																		{$$ = MEM_ALLOC; $$->data_type = $1->data_type;}
    |assignment_expr																		{$$ = $1;}
		|unary_expr																					{$$ = MEM_ALLOC; $$->data_type = $1->data_type; $$ = $1;}
    ;


assignment_expr :lhs assign_op  arithmetic_expr												{
																	type_check($1->data_type,$3->data_type,1);
																//	cout<<"Here"<<endl;

																	rhs=0;
																	string code($3->code);
																	if(code[0]!=0) code = code + "\n";
																	code = code + $1->code + $2->code + $3->addr;
																	//cout<<code<<endl;
																	$$ = MEM_ALLOC; $$->data_type = $3->data_type;
																	$$->code = (char *)malloc(code.length()+1);
																	$$->code = (char *)code.c_str();
																	cout<<$$->code<<endl;
																}
    |lhs assign_op  array_access													{type_check($1->data_type,$3->data_type,1); $$ = MEM_ALLOC; $$->data_type = $3->data_type;rhs=0;}
    |lhs assign_op  function_call												  {type_check($1->data_type,$3,1); $$ = MEM_ALLOC; $$->data_type = $3;rhs=0;}
	  |lhs assign_op  unary_expr                            {type_check($1->data_type,$3->data_type,1); $$ = MEM_ALLOC; $$->data_type = $3->data_type;rhs=0;}
		|unary_expr assign_op  unary_expr										  {type_check($1->data_type,$3->data_type,1); $$ = MEM_ALLOC; $$->data_type = $3->data_type;rhs=0;}
    ;

unary_expr:	identifier INCREMENT												{$$ = MEM_ALLOC; $$->data_type = $1->data_type;}
					| identifier DECREMENT												{$$ = MEM_ALLOC; $$->data_type = $1->data_type;}
					| DECREMENT identifier												{$$ = MEM_ALLOC; $$->data_type = $2->data_type;}
					| INCREMENT identifier												{$$ = MEM_ALLOC; $$->data_type = $2->data_type;}

lhs: identifier																					{ $$ = MEM_ALLOC; $$->data_type = $1->data_type;
																												 $$->code = (char *)malloc(strlen($1->lexeme)+1);$$->code = $1->lexeme; }
   | array_access																				{$$ = MEM_ALLOC; $$->data_type = $1->data_type; }
	 ;

identifier:IDENTIFIER                                    {
                                                                    if(is_declaration
                                                                    && !rhs)
                                                                    {
                                                                        $1 = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                                                                        if($1 == NULL) yyerror("Redeclaration of variable");
                                                                    }
                                                                    else
                                                                    {
                                                                        $1 = search_recursive(yytext);
                                                                        if($1 == NULL) yyerror("Variable not declared");
                                                                    }
                                                                    $$ = $1;
                                                            }
    			 ;

assign_op:'=' {rhs=1;   $$ = MEM_ALLOC; $$->code = strdup(" = ");}
    |ADD_ASSIGN {rhs=1; $$ = MEM_ALLOC; $$->code = strdup(" += ");}
    |SUB_ASSIGN {rhs=1; $$ = MEM_ALLOC; $$->code = strdup(" -= ");}
    |MUL_ASSIGN {rhs=1; $$ = MEM_ALLOC; $$->code = strdup(" *= ");}
    |DIV_ASSIGN {rhs=1; $$ = MEM_ALLOC; $$->code = strdup(" /= ");}
    |MOD_ASSIGN {rhs=1; $$ = MEM_ALLOC; $$->code = strdup(" %= ");}
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr				{$$ = do_whats_necessary( $1, '+', $3);	}
    |arithmetic_expr '-' arithmetic_expr							      {$$ = do_whats_necessary( $1, '-', $3);	}
    |arithmetic_expr '*' arithmetic_expr							      {$$ = do_whats_necessary( $1, '*', $3);	}
		|arithmetic_expr '/' arithmetic_expr							      {$$ = do_whats_necessary( $1, '/', $3);	}
		|arithmetic_expr '%' arithmetic_expr							      {$$ = do_whats_necessary( $1, '%', $3);	}
    |'-' arithmetic_expr %prec UMINUS												{$$ = MEM_ALLOC; $$->data_type = $2->data_type;}
    |identifier																							{
																								$$ = MEM_ALLOC; $$->data_type = $1->data_type;
																								$$->addr = (char*) malloc(sizeof(char)*(strlen($1->lexeme)+1));
																							  $$->addr = $1->lexeme;
																							  $$->code = (char *) malloc(20);
																								$$->code[0] = 0;

																							}
    |constant																								{
																								$$ = MEM_ALLOC; $$->data_type = $1->data_type;
																								$$->addr = (char*) malloc(sizeof(char)*(strlen($1->lexeme)+1));
																							  $$->addr = $1->lexeme;
																								$$->code = (char *) malloc(20);
																								$$->code[0] = 0;}
    ;

constant: DEC_CONSTANT 												{$1->is_constant=1; $$ = $1;}
    | HEX_CONSTANT														{$1->is_constant=1; $$ = $1;}
		| CHAR_CONSTANT														{$1->is_constant=1; $$ = $1;}
		| FLOAT_CONSTANT													{$1->is_constant=1; $$ = $1;}
    ;

array_access: identifier '[' array_index ']'								{
																															if(is_declaration)
																															{
																																if($3->value <= 0)
																																	yyerror("size of array is not positive");

																																else
                                                                                                                                if($3->is_constant && !rhs)
																																	$1->array_dimension = $3->value;
																																	else if(rhs){
																																	{
																																if($3->value > $1->array_dimension)
																																	yyerror("Array index out of bound");

																																if($3->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															}
																															}

																															else if($3->is_constant)
																															{
																																if($3->value > $1->array_dimension)
																																	yyerror("Array index out of bound");

																																if($3->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															$$ = MEM_ALLOC; $$->data_type = $1->data_type;
																														}

array_index: constant																		{$$ = $1;}
					 | identifier																	{$$ = $1;}
					 ;

function_call: identifier '(' parameter_list ')'				{
																													$$ = $1->data_type;
																													check_parameter_list($1,param_list,p_idx);
																													p_idx = 0;
																												}

             | identifier '(' ')'												{
							 																						 $$ = $1->data_type;
																													 check_parameter_list($1,param_list,p_idx);
																													 p_idx = 0;
																												}
             ;

parameter_list:
              parameter_list ','  parameter
              |parameter
              ;

parameter: sub_expr																			{param_list[p_idx++] = $1->data_type;}
				 | STRING																				{param_list[p_idx++] = STRING;}
				 ;
%%

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
