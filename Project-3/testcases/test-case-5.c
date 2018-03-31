/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 3

Test Case 5
Check function parameter number and type

*/

int fun(int i, char c){
    return 2;
}

int fun2(int i, char c){
    /*return '2';*/
}

int main()
{
    fun(2); //Number of parameters dont match
    /*fun(2,2); //Parameter types dont match*/
    fun(2,'3'); // Valid
    /*fun(2,'3',4); //Invalid*/

    return 2;
}
