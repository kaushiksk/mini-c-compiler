/* 
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 1

Test Case 1
 - Test for single line comments
 - Test for multi-line comments
 - Test for single line nested comments
 - Test for multiline nested comments 

The output in lex should remove all the comments including this one 
*/

#include<stdio.h>

void main(){
    // Single line comment
    
    /* Multi-line comment
       Like this */
    
    /* here */ int a; /* "int a" should be untouched */
    
	// This nested comment // This comment should be removed should be removed


	
	/* To make things /*  nested multi-line comment */ interesting */

	return 0;
}
