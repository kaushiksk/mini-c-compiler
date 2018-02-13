/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 2

Test Case 3
 - Left hand side of an assignment statement should be an lvalue

The output in lex/yacc should identify those assignment statements whose left habd side is not an lvalue and stray characters must be detected as an error
*/


int main()
{

  `
  @ -
  total = x @ y;

	int a = 4;

	if(a > 0 )
	{
		printf("a is positive");
		a * 2 = a;
	}
	else
	{
		printf("a is negative");
		a = a * 2;
	}

}
