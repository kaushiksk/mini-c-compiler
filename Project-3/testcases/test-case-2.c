/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 3

Test Case 3
Check for invalid array dimensions
Check for array index out of range
In declaration list with assign statement differentiate lhs and rhs(i.e lhs should be checked for redeclaraion but rhs shouldn't.
In "int a=b, c=d;" a,c have to be checked for redeclarion, b,d have to checked if they have been declared at all.)
*/


int main()
{
    /*int arr[0]; //Invalid*/
    /*int arr1[-1]; //Invalid*/
    int arr2[10];

    int x = arr2[5],  y = arr2[9]; //Valid
    int w = arr2[4.5];
    int z = arr2[11];
    return 0;
}
