# Compiler Design Project-2

## Parser for a subset of the C language

### Team Members
 - Karthik M (15CO221)
 - Kaushik S Kalmady (15CO222)

### Installation and running
 1. Please make sure you have Lex/Flex and Yacc/Bison installed
 2. Next run `$ chmod +x compile` 
 3. `$ ./compile`
 4. To run the parser `$./parser test-file.c`


### FEATURES
 - Nested code blocks
 - +=, -= supported
 - for loops and nested for loops
 - integer assignment and declaration
 - if-else handled
 - array assignment, array declaration
 - comma separated initialization/declaration e.g int a=10,b;
 - support for short, long , long long , signed and unsigned
 - while statements supported
 - unary expressions supported in both lhs, rhs and standalone statements
 - display specific errors with line numbers
 - additionally evaluates expressions and adds to symbol table(implemented as a fun exercise - this is not the job of the parser)
