/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 1

Test Case 4

Following errors must be detected
 - Invalid identifiers: 9y, total$
 - Invalid operator: @
 - Invalid escape characters \q \d should be detected
 - Invalid hexadecimal character g for int
 - Invalid character constant 'aa'
 - Stray characters: `, @, -


The output should display appropriate errors
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  `
  int a=0x0g, 54;
  @ -
  char='x','aa';
  int x, 9y, total$;
  x = 10, y = 20;
  x=x*3/2;
  total = x @ y;
  printf ("Total = %d \n \" ", total);
}

// Errors:
//
