# Compiler Design Project-3

## Semantic Analyser for a subset of the C language
This code is built upon the parser designed in Project-2 with some modifications to the earlier structure.

### Team Members
 - Karthik M (15CO221)
 - Kaushik S Kalmady (15CO222)

### Installation and running
 1. Please make sure you have Lex/Flex and Yacc/Bison installed
 2. Next run `$ chmod +x compile` 
 3. `$ ./compile`
 4. To run the parser `$./semantic_analyser test-file.c`


### FEATURES
 - Type checking in arithmetic expressions
 - Type checking in relational and logical expressions
 - Type checking in assignment expressions
 - Check of array index out of bound
 - Matching type in return statement in function
 - Checking matching function parameter type during function call
 - Checking number of parameters passed during function call
