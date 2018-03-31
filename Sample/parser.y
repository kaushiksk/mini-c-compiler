%{
	#include <bits/stdc++.h>
	int yyerror(char *msg);

	#include "symboltable.h"
	#include "lex.yy.c"

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

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

	void type_check(int,int,int);

	struct content_s
	{
		vector<int> truelist;
		vector<int> falselist;
		int data_type;
	};
	typedef struct content_s content_t;

	nextinstr = 0;
%}

%union
{
	int data_type;
	entry_t* entry;
	content_t content;
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
%type <data_type> unary_expr
%type <data_type> arithmetic_expr
%type <data_type> assignment_expr
%type <data_type> function_call
%type <data_type> array_access
%type <data_type> lhs

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
			 | declaration
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
    |single_stmt
    ;

 /* The function body is covered in braces and has multiple statements. */
compound_stmt :
							'{' 							{
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}

							statements

							'}' 							{
																	current_scope = exit_scope();
																	$$.nextlist = $3.nextlist;
																}
    ;

statements:statements M stmt		{
																	backpatch($1.nextlist,$2.instr);
																	$$.nextlist = $3.nextlist;
																}
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
																		if(func_type != $2)
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
    ;

for_block:FOR '(' expression_stmt  expression_stmt ')' {is_loop = 1;} stmt {is_loop = 0;}
    		 |FOR '(' expression_stmt expression_stmt expression ')' {is_loop = 1;} stmt {is_loop = 0;}
    		 ;

if_block:IF '(' expression ')' M stmt 	%prec LOWER_THAN_ELSE 		{
																																		backpatch($3.truelist,$5.instr);
																																		$$.nextlist = merge($3.falselist,$6.nextlist);
																																	}

				|IF '(' expression ')' M stmt N ELSE M stmt								{
																																		backpatch($3.truelist,$5.instr);
																																		backpatch($3.falselist,$9.instr);
																																		$$.nextlist = merge(merge($6.nextlist,$7.nextlist),$10.nextlist);
																																	}
    ;

while_block: WHILE M '(' expression	')' M {is_loop = 1;} stmt {is_loop = 0;}		{
																																									backpatch($8.nextlist,$2.instr);
																																									backpatch($4.truelist,$6.instr);
																																									$$.nextlist = $4.falselist;

																																									std::string instruction;
																																									instruction = std::to_string(nextinstr) + ": " + "goto" + $2.instr;
																																									outfile << instruction << endl;
																																									nextinstr++;
																																								}
		;

declaration: type  declaration_list ';'
           {is_declaration = 0; }
					 | declaration_list ';'
					 | unary_expr ';'


declaration_list: declaration_list ',' sub_decl
								|sub_decl
								;

sub_decl: assignment_expr
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

		sub_expr rel sub_expr																{
																													type_check($1,$3,2);
																													$$.data_type = $1.data_type;

																													$$.truelist = {nextinstr};
																													$$.falselist = {nextinstr + 1};

																													std::string instruction;
																													instruction = std::to_string(nextinstr) + ": " + "if" + $1.addr + rel.op + $3.addr + "goto _";
																													outfile << instruction << endl;
																													nextinstr++;
																												}

		|sub_expr LOGICAL_AND M sub_expr										{
																													type_check($1.data_type,$4.data_type,2);
																													$$.data_type = $1.data_type;

																													backpatch($1.truelist,M.instr);
																													$$.truelist = $4.truelist;
																													$$.falselist = merge($1.falselist,$4.falselist);
																												}

		|sub_expr LOGICAL_OR M sub_expr											{
																													type_check($1.data_type,$4.data_type,2);
																													$$.data_type = $1.data_type;

																													backpatch($1.falselist,M.instr);
																													$$.truelist = merge($1.truelist,$4.truelist);
																													$$.falselist = $4.falselist;
																												}

		|'!' sub_expr																				{
																													$$.data_type = $2.data_type;

																													$$.truelist = $2.falselist;
																													$$.falselist = $2.truelist;
																												}
		|arithmetic_expr																		{$$ = $1;}
    |assignment_expr																		{$$ = $1;}
		|unary_expr																					{$$ = $1;}
    ;


rel: '>'																								{rel.op = ">";}
	 | '<'																								{rel.op = "<";}
	 | EQ                                                 {rel.op = "==";}
	 | NOT_EQ                                             {rel.op = "!=";}
	 | LS_EQ																							{rel.op = "<=";}
	 | GR_EQ																							{rel.op = ">=";}
	 ;

assignment_expr :
		lhs assign arithmetic_expr												{
																											 type_check($1->data_type,$3.data_type,1);
																											 $$.data_type = $3.data_type;

																											 $$.code = $1->lexeme + $2.op + $3.addr;

																											 std::string instruction;
																											 instruction = std::to_string(nextinstr) + $$.code;
																											 outfile << instruction << endl;
																											 nextinstr++;
																											}

    |lhs assign array_access													{
																											 type_check($1->data_type,$3.data_type,1);
																											 $$.data_type = $3.data_type;

																											 $$.code = $1->lexeme + $2.op + $3.code;

																											 std::string instruction;
																											 instruction = std::to_string(nextinstr) + $$.code;
																											 outfile << instruction << endl;
																											 nextinstr++;
																											}

    |lhs assign function_call													{type_check($1,$3,1); $$ = $3;}

		|lhs assign unary_expr                            {
																											 type_check($1->data_type,$3.data_type,1);
																											 $$.data_type = $3.data_type;

																											 $$.code = $1->lexeme + $2.op + $3.code;

																											 std::string instruction;
																											 instruction = std::to_string(nextinstr) + $$.code;
																											 outfile << instruction << endl;
																											 nextinstr++;
																										 	}

		|unary_expr assign unary_expr											{
																											 type_check($1.data_type,$3.data_type,1);
																											 $$.data_type = $3.data_type;

																											 $$.code = $1.code + $2.op + $3.code;

																											 std::string instruction;
																											 instruction = std::to_string(nextinstr) + $$.code;
																											 outfile << instruction << endl;
																											 nextinstr++;
																										 	}
    ;

unary_expr:	identifier INCREMENT												{$$.data_type = $1->data_type; $$.code = $1->lexeme + "++";}
					| identifier DECREMENT												{$$.data_type = $1->data_type; $$.code = $1->lexeme + "--";}
					| DECREMENT identifier												{$$.data_type = $2->data_type; $$.code = "--" + $2->lexeme;}
					| INCREMENT identifier												{$$.data_type = $2->data_type; $$.code = "++" + $2->lexeme;}

lhs: identifier																					{$$ = $1;}
   | array_access																				{$$ = $1;}
	 ;

identifier:IDENTIFIER                                    {
                                                          if(is_declaration && !rhs)
                                                          {
                                                            $1 = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                                                            if($1 == NULL) yyerror("Redeclaration of variable");
                                                          }
                                                          else
                                                          {
                                                            $1 = search_recursive(yytext);
                                                            if($1 == NULL) yyerror("Variable not declared");
                                                            if(rhs)
                                                            rhs = 0;
                                                          }

                                                          $$ = $1;
                                                         }
    			 ;

assign:'=' 																{rhs=1; $$.op = "="; }
    |ADD_ASSIGN 													{rhs=1; $$.op = "+=";}
    |SUB_ASSIGN 													{rhs=1; $$.op = "-=";}
    |MUL_ASSIGN 													{rhs=1; $$.op = "*=";}
    |DIV_ASSIGN 													{rhs=1;	$$.op = "/=";}
    |MOD_ASSIGN 													{rhs=1; $$.op = "%=";}
    ;

arithmetic_expr: arithmetic_expr math arithmetic_expr								 {
																																			type_check($1.data_type,$3.data_type,0);

																																			$$.addr = "t" + std::to_string(temp_var_number);
																																			std::string expr = $$.addr + "=" + $1.addr + $2.op + $2.addr;
																																			$$.code = $1.code + $3.code + expr;

																																			temp_var_number++;
																																		 }

							 |'(' arithmetic_expr ')'															 {
								 																											$$.data_type = $2.data_type;

																																			$$.addr = $2.addr;
																																			$$.code = $1.code;
																																		 }

    			 		 |'-' arithmetic_expr %prec UMINUS										 {
								 																											$$.data_type = $2.data_type;

																																			$$.addr = "t" + std::to_string(temp_var_number);
																																			std::string expr = $$.addr + "=" + "-" + $2.addr;
																																			$$.code = $2.code + expr;
																																		 }

    			 		 |identifier																					 {
								 																										  $$.data_type = $1->data_type;

																																		 	$$.addr = $1->lexeme;
																																	   }

    			 		 |constant																						 {
								 																											$$.data_type = $1->data_type;

																																			$$.addr = $1->value;
																																		 }
    			 		 ;

math: '+'										{$$.op = "+";}
		| '-'										{$$.op = "-";}
		| '*'										{$$.op = "*";}
		| '/'										{$$.op = "/";}
		| '%'										{$$.op = "%";}
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

																																else if($3->is_constant)
																																	$1->array_dimension = $3->value;
																															}

																															else if($3->is_constant)
																															{
																																if($3->value > $1->array_dimension)
																																	yyerror("Array index out of bound");

																																if($3->value < 0)
																																	yyerror("Array index cannot be negative");
																															}

																															$$.data_type = $1.data_type;
																															$$.code = $1->lexeme + "[" + $2->value + "]";
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

parameter: sub_expr																			{param_list[p_idx++] = $1;}
				 | STRING																				{param_list[p_idx++] = STRING;}
				 ;

M: 	 		{$$.instr = nextinstr;}
N:			{
					$$.nextlist = {nextinstr};

					std::string instruction;
					instruction = std::to_string(nextinstr)  + ": " + "goto _";
					outfile << instruction << endl;
					nextinstr++;
				}
%%

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
	vector<int> concat;
	concat.reserve(v1.size() + v2.size());
	concat.insert(concat.end(), v1.begin(), v1.end());
	concat.insert(concat.end(), v2.begin(), v2.end());

	return concat;
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
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	ofstream outfile("ICG.code");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}


	printf("SYMBOL TABLES\n\n");
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
