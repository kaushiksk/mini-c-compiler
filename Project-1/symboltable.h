/* 
* Compiler Design Project 1 : Lexical Analyser
*
* File        : symboltable.h
* Description : This file contains functions related to a hash organised symbol table. 
*               The functions implemented are:
*               create_table(), insert(), search, display() 
*                  
* Authors     : Karthik M - 15CO22, Kaushik S Kalmady - 15CO222
* Date        : 17-1-2018
*/



#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

/* struct to hold each entry */
struct entry_s
{
	char* lexeme; 
	int token_name;
	struct entry_s* successor;
};

typedef struct entry_s entry_t;

/* Create a new hash_table. */
entry_t** create_table()
{
	entry_t** hash_table_ptr = NULL; // declare a pointer

	/* Allocate memroy for a hashtable array of size HASH_TABLE_SIZE */
	if( ( hash_table_ptr = malloc( sizeof( entry_t* ) * HASH_TABLE_SIZE ) ) == NULL )
    	return NULL;

	int i;
	
	// Intitialise all entries as NULL
    for( i = 0; i < HASH_TABLE_SIZE; i++ )
	{
		hash_table_ptr[i] = NULL;
	}

	return hash_table_ptr;
}

/* Generate hash from a string. Then generate an index in [0, HASH_TABLE_SIZE) */
uint32_t hash( char *lexeme )
{
	size_t i;
	uint32_t hash;

	/* Apply jenkin's hash function
	* https://en.wikipedia.org/wiki/Jenkins_hash_function#one-at-a-time
	*/
	for ( hash = i = 0; i < strlen(lexeme); ++i ) {
        hash += lexeme[i];
        hash += ( hash << 10 );
        hash ^= ( hash >> 6 );
    }
	hash += ( hash << 3 );
	hash ^= ( hash >> 11 );
    hash += ( hash << 15 );

	return hash % HASH_TABLE_SIZE; // return an index in [0, HASH_TABLE_SIZE)
}

/* Create an entry for a lexeme, token pair. This will be called from the insert function */
entry_t *create_entry( char *lexeme, int token_name )
{
	entry_t *newentry;

	/* Allocate space for newentry */
	if( ( newentry = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}
	/* Copy lexeme to newentry location using strdup (string-duplicate). Return NULL if it fails */
	if( ( newentry->lexeme = strdup( lexeme ) ) == NULL ) {
		return NULL;
	}

	newentry->token_name = token_name;
	newentry->successor = NULL;

	return newentry;
}

/* Search for an entry given a lexeme. Return a pointer to the entry of the lexeme exists, else return NULL */
entry_t* search( entry_t** hash_table_ptr, char* lexeme )
{
	uint32_t idx = 0;
	entry_t* myentry;
    
    // get the index of this lexeme as per the hash function
	idx = hash( lexeme );

	/* Traverse the linked list at this idx and see if lexeme exists */
	myentry = hash_table_ptr[idx];
	
	while( myentry != NULL && strcmp( lexeme, myentry->lexeme ) != 0 )
	{
		myentry = myentry->successor;
	}

	if(myentry == NULL) // lexeme is not found
		return NULL;
	
	else // lexeme found
		return myentry;

}

/* Insert an entry into a hash table. */
void insert( entry_t** hash_table_ptr, char* lexeme, int token_name )
{
	if( search( hash_table_ptr, lexeme ) != NULL) // If lexeme already exists, don't insert, return
	    return;

	uint32_t idx;
	entry_t* newentry = NULL;
	entry_t* head = NULL;

	idx = hash( lexeme ); // Get the index for this lexeme based on the hash function
	newentry = create_entry( lexeme, token_name ); // Create an entry using the <lexeme, token> pair

	if(newentry == NULL) // In case there was some error while executing create_entry()
	{
		printf("Insert failed. New entry could not be created.");
		exit(1);
	}

	head = hash_table_ptr[idx]; // get the head entry at this index

	if(head == NULL) // This is the first lexeme that matches this hash index 
	{
		hash_table_ptr[idx] = newentry;
	}
	else // if not, add this entry to the head
	{
		newentry->successor = hash_table_ptr[idx];
		hash_table_ptr[idx] = newentry;
	}
}

// Traverse the hash table and print all the entries
void display(entry_t** hash_table_ptr)
{
	int i;
	entry_t* traverser;
    printf("\n==========================================\n");
    printf("\t < lexeme , token >\n");
    printf("==========================================\n");

	for( i=0; i < HASH_TABLE_SIZE; i++)
	{
		traverser = hash_table_ptr[i];

		while( traverser != NULL)
		{
			printf("< %-30s, %3d >\n", traverser->lexeme, traverser->token_name);
			traverser = traverser->successor;
		}
	}
    printf("==========================================\n");
   
}
