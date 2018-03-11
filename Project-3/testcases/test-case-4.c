/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 2

Test Case 4

Following errors must be detected
 - Invalid identifiers: 9y, total$
 - Invalid operator: @
 - Escaped quoted should be part of the string that is identified
 - Stray characters: `, @, -

The output should display appropriate errors
*/


int main()
{
  int x, y;
  long long int total, diff;
  int *ptr;
  int a = 86;

  if (a > 90)
  {
	  printf ("Grade is AA");
  }
  else if (a > 80)
  {
	  printf ("Grade is AB");
  }
  else
  {
	  printf ("Grade is BB");
  }

  x = -10, y = 20;
  x=x*3/2;
  total = x + y;
}

// Errors:
//
