/* 
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 1

Test Case 5

Identifying tokens and displaying symbol and constants table

Following tokens must be detected
 - Keywords   (int, long int, long long int, main include)
 - Identifiers (main,total,x,y,printf),
 - Constants  (-10, 20, 0x0f, 123456l)
 - Strings ("Total = %d \n")
 - Special symbols and Brackets ( (), {}, ;, ,)
 - Operators (+,-,=,*,/,%,--,++)

The output should display appropriate tokens with their type and also the symbol and constants table
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int x, y;
  long long int total, diff;
  int *ptr;
  unsigned int a = 0x0f;
  long int mylong = 123456l;
  long int i, j;
  for(i=0; i < 10; i++){
    for(j=10; j > 0; j--){
    printf("%d",i);
    }
  }
  x = -10, y = 20;
  x=x*3/2;
  total = x + y;
  diff = x - y;
  int rem = x % y;
  printf ("Total = %d \n", total);
}

