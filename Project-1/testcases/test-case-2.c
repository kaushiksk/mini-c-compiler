/*
Karthik M - 15CO221
Kaushik S Kalmady - 15CO222
Compiler Design Project 1

Test Case 2
 - Test for multi-line comment that doesn't end till EOF

The output in lex should print as error message when the comment does not terminate
It should remove the comments that terminate
*/

#include<stdio.h>

void main(){

	// This is fine
	/* This as well
	like we know */

	/* This is not fine since
	this comment has to end somewhere

	return 0;
}
