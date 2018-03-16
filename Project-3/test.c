/*
 */


/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 2

Test Case 1
- Missing semicolon
- Single quotes for characters and double quotes for strings

The output in lex/yacc should identify statements without a terminating semiclon and unmatched single and double quotes
*/

int fun(int a, int b, int c)
{
  return 2 ;
}

int main()
{

  // int arr[-1];
  // int arr1[0];
  // int arr2[-1];
  // break;
  // arr[0] = 4;
  // arr[-1] = 10;
  // arr[11] = 2;

  int x = 1;

  int y;
  int z;

  if(x<0)
  {
    int y;

    int z=1;

    {
      int w =1;
    }
    //w=3;
  }
  char c='a';
  for(x=2;x<y;x++)
  {
    break;
  }
  return 3;

  // fun();

}
