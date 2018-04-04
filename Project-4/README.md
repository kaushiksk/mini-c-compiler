# Compiler Design Project-4

## Intermediate Code Generation for a subset of the C language
This code is built upon the semantic analyser designed in Project-3 with some modifications to the earlier structure.

### Team Members
 - Karthik M (15CO221)
 - Kaushik S Kalmady (15CO222)

### Installation and running
 1. Please make sure you have Lex/Flex and Yacc/Bison installed
 2. Next run `$ chmod +x compile` 
 3. `$ ./compile`
 4. To run the parser `$./icg test-file.c`


### FEATURES
 - Backward compatibility with Semantic Analyser from Project-3
 - Code generation for arithmetic expressions
 - Backpatching for `if-else` statements and `nested if-else`
 - Backpatching for `while` and `for` loops
 - Array indexing
 - Backpatching for logical amd relational expressions
 - Jumps for `break` and `continue`