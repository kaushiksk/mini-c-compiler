/*
* Compiler Design Project 3 : Semantic Analyser
*
* File        : symboltable.h
*
* Authors     : Karthik M - 15CO22, Kaushik S Kalmady - 15CO222
* Date        : 11-3-2018
*/


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define HASH_TABLE_SIZE 100
#define NUM_TABLES 10

int table_index = 0;
int current_scope = 0;

/* struct to hold each entry */
struct entry_s
{
	char* lexeme;
	double value;
	int data_type;
	int* parameter_list; // for functions
	int array_dimension;
	int is_constant;
	int num_params;
	struct entry_s* successor;
};

typedef struct entry_s entry_t;

/* Wrapper for symbol table with pointer to symbol table of parent scope */
struct table_s
{
	entry_t** symbol_table;
	int parent;
};

typedef struct table_s table_t;

extern table_t symbol_table_list[NUM_TABLES];

/* Create a new hash_table. */
entry_t** create_table()
{
	entry_t** hash_table_ptr = NULL; // declare a pointer

	/* Allocate memory for a hashtable array of size HASH_TABLE_SIZE */
	if( ( hash_table_ptr = malloc( sizeof( entry_t* ) * HASH_TABLE_SIZE ) ) == NULL )
    	return NULL;

	int i;

	// Intitialise all entries as NUscopeLL
    for( i = 0; i < HASH_TABLE_SIZE; i++ )
	{
		hash_table_ptr[i] = NULL;
	}

	return hash_table_ptr;
}

int create_new_scope()
{
	table_index++;

	symbol_table_list[table_index].symbol_table = create_table();
	symbol_table_list[table_index].parent = current_scope;

	return table_index;
}

int exit_scope()
{
	return symbol_table_list[current_scope].parent;
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
entry_t *create_entry( char *lexeme, int value, int data_type )
{
	entry_t *new_entry;

	/* Allocate space for new_entry */
	if( ( new_entry = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}
	/* Copy lexeme to new_entry location using strdup (string-duplicate). Return NULL if it fails */
	if( ( new_entry->lexeme = strdup( lexeme ) ) == NULL ) {
		return NULL;
	}

	new_entry->value = value;
	new_entry->successor = NULL;
	new_entry->parameter_list = NULL;
	new_entry->array_dimension = -1;
	new_entry->is_constant = 0;
	new_entry->num_params = 0;
	new_entry->data_type = data_type;

	return new_entry;
}

/* Search for an entry given a lexeme. Return a pointer to the entry of the lexeme exists, else return NULL */
entry_t* search(entry_t** hash_table_ptr, char* lexeme)
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

// Search recursively in every parent scope for lexeme
entry_t* search_recursive(char* lexeme)
{
	int idx = current_scope;
	entry_t* finder = NULL;

	while(idx != -1)
	{
		finder = search(symbol_table_list[idx].symbol_table, lexeme);

		if(finder != NULL)
			return finder;

		idx = symbol_table_list[idx].parent;
	}

	return finder;
}
/* Insert an entry into a hash table. */
entry_t* insert( entry_t** hash_table_ptr, char* lexeme, int value, int data_type)
{
	// Make sure you pass the current scope symbol table here
	entry_t* finder = search( hash_table_ptr, lexeme );
	if( finder != NULL) // If lexeme already exists, don't insert, return NULL
	{
		if(finder->is_constant)
			return finder;
		return NULL; //capture this is callee code and do necessary error handling
	}

	uint32_t idx;
	entry_t* new_entry = NULL;
	entry_t* head = NULL;

	idx = hash( lexeme ); // Get the index for this lexeme based on the hash function
	new_entry = create_entry( lexeme, value, data_type ); // Create an entry using the <lexeme, token> pair

	if(new_entry == NULL) // In case there was some error while executing create_entry()
	{
		printf("Insert failed. New entry could not be created.");
		exit(1);
	}

	head = hash_table_ptr[idx]; // get the head entry at this index

	if(head == NULL) // This is the first lexeme that matches this hash index
	{
		hash_table_ptr[idx] = new_entry;
	}
	else // if not, add this entry to the head
	{
		new_entry->successor = hash_table_ptr[idx];
		hash_table_ptr[idx] = new_entry;
	}
	return hash_table_ptr[idx];
}

// This is called after a function call to check if param list match
int check_parameter_list(entry_t* entry, int* list, int m)
{
	int* parameter_list = entry->parameter_list;

	if(m != entry->num_params)
	{
		yyerror("Number of parameters and arguments do not match");
	}

	int i;
	for(i=0; i<m; i++)
	{
		if(list[i] != parameter_list[i])
		yyerror("Parameter and argument types do not match");
	}

	return 1;
}

void fill_parameter_list(entry_t* entry, int* list, int n)
{
	entry->parameter_list = (int *)malloc(n*sizeof(int));

	int i;
	for(i=0; i<n; i++)
	{
		entry->parameter_list[i] = list[i];
	}
	entry->num_params = n;
}


void print_dashes(int n)
{
  printf("\n");

	int i;
	for(i=0; i< n; i++)
	printf("=");
	printf("\n");
}

// Traverse the hash table and print all the entries
void display_symbol_table(entry_t** hash_table_ptr)
{
	int i;
	entry_t* traverser;

	print_dashes(100);

  printf(" %-20s %-20s %-20s %-20s %-20s\n","lexeme","data-type","array_dimension","num_params","param_list");

	print_dashes(100);

	for( i=0; i < HASH_TABLE_SIZE; i++)
	{
		traverser = hash_table_ptr[i];
		while( traverser != NULL)
		{
			printf(" %-20s %-20d %-20d ", traverser->lexeme, traverser->data_type, traverser->array_dimension);

			printf(" %-20d", traverser->num_params);

			int j;
			for(j=0; j < traverser->num_params; j++)
			printf(" %d",traverser->parameter_list[j]);
			printf("\n");

			traverser = traverser->successor;
		}
	}

	print_dashes(100);

}

void display_constant_table(entry_t** hash_table_ptr)
{
	int i;
	entry_t* traverser;

	print_dashes(25);

	printf(" %-10s %-10s \n","lexeme","data-type");

	print_dashes(25);

	for( i=0; i < HASH_TABLE_SIZE; i++)
	{
		traverser = hash_table_ptr[i];
		while( traverser != NULL)
		{
			printf(" %-10s %-10d \n", traverser->lexeme, traverser->data_type);
			traverser = traverser->successor;
		}
	}

	print_dashes(25);
}

void display_all()
{
		int i;
		for(i=0; i<=table_index; i++)
		{
			printf("Scope: %d\n",i);
			display_symbol_table(symbol_table_list[i].symbol_table);
			printf("\n\n");
		}
}
