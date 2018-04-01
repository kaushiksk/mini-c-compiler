%{
	#include <bits/stdc++.h>
	#include "symboltable.h"
	#include "lex.yy.c"

	using namespace std;

	int yyerror(char *msg);

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
	vector<int> merge(vector<int>& v1, vector<int>& v2);
	void backpatch(vector<int>&, int);
	void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);
	void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op);


	int nextinstr = 0;
	int temp_var_number = 0;

	vector<string> ICG;

%}

%union
{
	int data_type;
	entry_t* entry;
	content_t* content;
	string* op;
	vector<int>* nextlist;
	int instr;
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

%type <op> assign;
%type <data_type> function_call

%type <content> lhs
%type <content> sub_expr
%type <content> expression
%type <content> unary_expr
%type <content> arithmetic_expr
%type <content> assignment_expr
%type <content> array_access

%type <content> if_block
%type <content> while_block
%type <content> compound_stmt

%type <content> statements
%type <content> single_stmt
%type <content> stmt


%type <instr> M
%type <nextlist> N

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
stmt:compound_stmt										{$$ = new content_t(); $$->nextlist = $1->nextlist;}
    |single_stmt											{$$ = new content_t(); $$->nextlist = $1->nextlist;}
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

																	$$ = new content_t();
																	$$->nextlist = $3->nextlist;

																}
    ;

statements:statements M stmt		{
																	backpatch($1->nextlist,$2);

																	$$ = new content_t();
																	$$->nextlist = $3->nextlist;
																}

    |														{
																	$$ = new content_t();
																}
    ;

 /* Grammar for what constitutes every individual statement */
single_stmt :if_block						{$$ = new content_t(); $$->nextlist = $1->nextlist;}
    |for_block									{$$ = new content_t();}
    |while_block								{$$ = new content_t(); $$->nextlist = $1->nextlist;}
    |declaration								{$$ = new content_t();}
    |function_call ';'					{$$ = new content_t();}
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

if_block:IF '(' expression ')' M stmt 	%prec LOWER_THAN_ELSE 		{
																																		backpatch($3->truelist,$5);

																																		$$ = new content_t();
																																		$$->nextlist = merge($3->falselist,$6->nextlist);
																																	}

				|IF '(' expression ')' M stmt ELSE N M stmt								{
																																		backpatch($3->truelist,$5);
																																		backpatch($3->falselist,$9);

																																		$$ = new content_t();
																																		vector<int> temp = merge($6->nextlist,*$8);
																																		$$->nextlist = merge(temp,$10->nextlist);
																																	}
    ;

while_block: WHILE M '(' expression	')' M {is_loop = 1;} stmt {is_loop = 0;}		{
																																									backpatch($8->nextlist,$2);
																																									backpatch($4->truelist,$6);

																																									$$ = new content_t();
																																									$$->nextlist = $4->falselist;

																																									std::string instruction;
																																									instruction = to_string(nextinstr) + string(": ") + string("goto") + to_string($2);
																																									ICG.push_back(instruction);
																																									nextinstr++;
																																								}
		;

declaration: type  declaration_list ';'					{is_declaration = 0; rhs = 0;}
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

expression: expression ',' sub_expr									{$$ = new content_t(); $$->truelist = $3->truelist; $$->falselist = $3->falselist;}
    			| sub_expr																{$$ = new content_t(); $$->truelist = $1->truelist; $$->falselist = $1->falselist;}
					;

sub_expr:

		sub_expr '>' sub_expr																{
																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string(">"));
																												}

		| sub_expr '<' sub_expr															{
																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string("<"));
																												}

		| sub_expr EQ sub_expr															{
																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string("=="));
																												}

		| sub_expr NOT_EQ sub_expr													{
																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string("!="));
																												}

		| sub_expr GR_EQ sub_expr														{
																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string(">="));
																												}

		| sub_expr LS_EQ sub_expr														{

																													type_check($1->data_type,$3->data_type,2);

																													$$ = new content_t();
																													gencode_rel($$, $1, $3, string("<="));
																												}

		|sub_expr LOGICAL_AND M sub_expr										{
																													type_check($1->data_type,$4->data_type,2);

																													$$ = new content_t();
																													$$->data_type = $1->data_type;

																													backpatch($1->truelist,$3);
																													$$->truelist = $4->truelist;
																													$$->falselist = merge($1->falselist,$4->falselist);
																												}

		|sub_expr LOGICAL_OR M sub_expr											{
																													type_check($1->data_type,$4->data_type,2);

																													$$ = new content_t();
																													$$->data_type = $1->data_type;

																													backpatch($1->falselist,$3);
																													$$->truelist = merge($1->truelist,$4->truelist);
																													$$->falselist = $4->falselist;
																												}

		|'!' sub_expr																				{
																													$$ = new content_t();
																													$$->data_type = $2->data_type;

																													$$->truelist = $2->falselist;
																													$$->falselist = $2->truelist;
																												}

		|arithmetic_expr																		{$$ = new content_t(); $$->data_type = $1->data_type; $$->addr = $1->addr;}
    |assignment_expr																		{$$ = new content_t(); $$->data_type = $1->data_type;}
		|unary_expr																					{$$ = new content_t(); $$->data_type = $1->data_type;}
    ;

assignment_expr :
		lhs assign arithmetic_expr												{
																											 type_check($1->entry->data_type,$3->data_type,1);

																											 $$ = new content_t();
																											 $$->data_type = $3->data_type;

																											 $$->code = $1->entry->lexeme + *$2 + $3->addr;

																											 std::string instruction;

																											 instruction = to_string(nextinstr) + string(": ") + $$->code;
																											 ICG.push_back(instruction);
																											 nextinstr++;

																											}

    |lhs assign array_access													{
																											 type_check($1->entry->data_type,$3->data_type,1);

																											 $$ = new content_t();
																											 $$->data_type = $3->data_type;

																											 $$->code = $1->entry->lexeme + *$2 + $3->code;

																											 std::string instruction;
																											 instruction = to_string(nextinstr) + string(": ") + $$->code;
																											 ICG.push_back(instruction);
																											 nextinstr++;
																											}

    |lhs assign function_call													{type_check($1->entry->data_type,$3,1); $$ = new content_t(); $$->data_type = $3;}

		|lhs assign unary_expr                            {
																											 type_check($1->entry->data_type,$3->data_type,1);

																											 $$ = new content_t();
																											 $$->data_type = $3->data_type;

																											 $$->code = $1->entry->lexeme + *$2 + $3->code;

																											 std::string instruction;
																											 instruction = to_string(nextinstr) + string(": ") + $$->code;
																											 ICG.push_back(instruction);
																											 nextinstr++;
																										 	}

		|unary_expr assign unary_expr											{
																											 type_check($1->data_type,$3->data_type,1);

																											 $$ = new content_t();
																											 $$->data_type = $3->data_type;

																											 $$->code = $1->code + *$2 + $3->code;

																											 std::string instruction;
																											 instruction = to_string(nextinstr) + string(": ") + $$->code;
																											 ICG.push_back(instruction);
																											 nextinstr++;
																										 	}
    ;

unary_expr:	identifier INCREMENT												{$$ = new content_t(); $$->data_type = $1->data_type; $$->code = string($1->lexeme) + string("++");}
					| identifier DECREMENT												{$$ = new content_t(); $$->data_type = $1->data_type; $$->code = string($1->lexeme) + string("--");}
					| DECREMENT identifier												{$$ = new content_t(); $$->data_type = $2->data_type; $$->code = string("--") + string($2->lexeme);}
					| INCREMENT identifier												{$$ = new content_t(); $$->data_type = $2->data_type; $$->code = string("++") + string($2->lexeme);}

lhs: identifier																					{$$ = new content_t(); $$->entry = $1;}
   | array_access																				{$$ = new content_t(); $$->code = $1->code;}
	 ;

identifier:IDENTIFIER                                    {
                                                          /* if(is_declaration && !rhs)
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

                                                          $$ = $1; */

																													if(is_declaration && !rhs)
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

assign:'=' 																{rhs=1; $$ = new string("=");}
    |ADD_ASSIGN 													{rhs=1; $$ = new string("+=");}
    |SUB_ASSIGN 													{rhs=1; $$ = new string("-=");}
    |MUL_ASSIGN 													{rhs=1; $$ = new string("*=");}
    |DIV_ASSIGN 													{rhs=1;	$$ = new string("/=");}
    |MOD_ASSIGN 													{rhs=1; $$ = new string("%=");}
    ;

arithmetic_expr: arithmetic_expr '+' arithmetic_expr								 {
																																			type_check($1->data_type,$3->data_type,0);
																																			$$ = new content_t();

																																			$$->data_type = $1->data_type;
																																			gencode_math($$, $1, $3, string("+"));
																																		 }

							  | arithmetic_expr '-' arithmetic_expr								 {
																																			 type_check($1->data_type,$3->data_type,0);
																																			 $$ = new content_t();

																																			 $$->data_type = $1->data_type;
																																			 gencode_math($$, $1, $3, string("-"));
								 																										 }

								| arithmetic_expr '*' arithmetic_expr								 {
																																			 type_check($1->data_type,$3->data_type,0);
																																			 $$ = new content_t();

																																			 $$->data_type = $1->data_type;
																																			 gencode_math($$, $1, $3, string("*"));
								 																										 }


							| arithmetic_expr '/' arithmetic_expr									 {
																																			type_check($1->data_type,$3->data_type,0);
																																			$$ = new content_t();

																																			$$->data_type = $1->data_type;
																																			gencode_math($$, $1, $3, string("/"));
																																		 }

							 | arithmetic_expr '%' arithmetic_expr									 {
																																				type_check($1->data_type,$3->data_type,0);
																																				$$ = new content_t();

																																				$$->data_type = $1->data_type;
																																				gencode_math($$, $1, $3, string("%"));
																																		 }

							 |'(' arithmetic_expr ')'															 {
								 																											$$ = new content_t();
								 																											$$->data_type = $2->data_type;

																																			$$->addr = $2->addr;
																																			$$->code = $2->code;
																																		 }

    			 		 |'-' arithmetic_expr %prec UMINUS										 {
								 																											$$ = new content_t();
								 																											$$->data_type = $2->data_type;

																																			$$->addr = "t" + to_string(temp_var_number);
																																			std::string expr = $$->addr + "=" + "-" + $2->addr;
																																			$$->code = $2->code + expr;

																																			temp_var_number++;
																																		 }

    			 		 |identifier																					 {
								 																											$$ = new content_t();
								 																										  $$->data_type = $1->data_type;

																																		 	$$->addr = $1->lexeme;
																																	   }

    			 		 |constant																						 {
								 																											$$ = new content_t();
								 																											$$->data_type = $1->data_type;

																																			$$->addr = to_string($1->value);
																																		 }
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

																															$$ = new content_t();
																															$$->data_type = $1->data_type;

																															if($3->is_constant)
																																$$->code = string($1->lexeme) + string("[") + to_string($3->value) + string("]");
																															else
																																$$->code = string($1->lexeme) + string("[") + string($3->lexeme) + string("]");

																															$$->entry = $1;
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

M: 	 		{$$ = nextinstr;}
 ;

N:			{
					$$ = new vector<int>(nextinstr);

					std::string instruction;
					instruction = to_string(nextinstr)  + ": " + "goto _";
					ICG.push_back(instruction);
					nextinstr++;
				}
	;

%%

void gencode_rel(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->data_type = arg1->data_type;

	lhs->truelist = {nextinstr};
	lhs->falselist = {nextinstr + 1};

	std::string instruction;

	instruction = to_string(nextinstr) + string(": ") + string("if") + arg1->addr + op + arg2->addr + string("goto _");
	ICG.push_back(instruction);
	nextinstr++;

	instruction = to_string(nextinstr) + string(": ") + string("goto _");
	ICG.push_back(instruction);
	nextinstr++;
}

void gencode_math(content_t* & lhs, content_t* arg1, content_t* arg2, const string& op)
{
	lhs->addr = "t" + to_string(temp_var_number);
	std::string expr = lhs->addr + string("=") + arg1->addr + op + arg2->addr;
	lhs->code = arg1->code + arg2->code + expr;

	temp_var_number++;

	string instruction = to_string(nextinstr) + string(": ") + expr;
	nextinstr++;
	ICG.push_back(instruction);
}

void backpatch(vector<int>& v1, int number)
{
	for(int i = 0; i<v1.size(); i++)
	{
		string instruction = ICG[v1[i]];

		if(instruction.find("_") < instruction.size())
		{
			instruction.replace(instruction.find("_"),1,to_string(number));
			ICG[v1[i]] = instruction;
		}
		else
		{
			printf("Error while backpatching!\n");
			cout << instruction << endl;
		}
	}
}

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

void displayICG()
{
	ofstream outfile("ICG.code");

	for(int i=0; i<ICG.size();i++){
		outfile << ICG[i] <<endl;
		cout<<ICG[i] <<endl;
	}


	outfile.close();
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
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);
*/
	displayICG();


	fclose(yyin);
	return 0;
}

int yyerror(const char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
