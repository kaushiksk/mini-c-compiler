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


int main(){

  int x = 1;

  int y;
  int z;
  if(x<0)
  {
    int y;
    z=1;
    {
      int w =1;
    }
    w=3;
  }

}
