/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 3

Test Case 3
LHS and RHS types should match in assignment expressions
Types need to match in arithmetic/relational and logical expressions too
*/


int main()
{
    int x;
    float y;
    char z;

    x = 1; //Valid
    /*y = 'c'; //Invalid*/
    z ='2'; //valid

    int c = 2;
    int d;
    d = x + c; //valid
    /*d = z + c; // Invalid*/

    char a;
    if(x < c){
        /*a = c; //Invalid*/
    }
    return 0;
}
