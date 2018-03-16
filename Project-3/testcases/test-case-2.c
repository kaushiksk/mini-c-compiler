/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 3

Test Case 3
Check for invalid array dimensions
Check for array index out of range
In declaration staments with assignment, check which identifiers to check for redeclaraion(e.g int a=b; a should be checked for redeclaration and not b)
*/


int main()
{
	int arr[0]; //Invalid
    int arr1[-1]; //Invalid
    int arr2[10];

    int x = arr2[5], y = arr2[15]; //Index out of bound
    return 0;
}
