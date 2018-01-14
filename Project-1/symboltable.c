/*
 */

#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>

/* struct to hold each entry */
struct entry_s {
	char *key;
	int token;
	struct entry_s *successor;
};

typedef struct entry_s entry_t;

/* Generic hash table */
struct hashtable_s {
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;


/* Create a new hash_table. */
hashtable_t* create_table( int size ) {

	hashtable_t* symbol_table = NULL;
	int i;

	/* Allocate the table */
	if( ( symbol_table = (hashtable_t *) malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( symbol_table->table = malloc( sizeof( entry_t* ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		symbol_table->table[i] = NULL;
	}

	symbol_table->size = size;

	return symbol_table;
}

/* Generate hash from a string. The value is then clamped to < size of table */
uint32_t hash( hashtable_t *symbol_table, char *key ) {

	size_t i;
	uint32_t hash;

	/* Apply jenkin's hash function
	* https://en.wikipedia.org/wiki/Jenkins_hash_function#one-at-a-time
	*/
	for ( hash = i = 0; i < strlen(key); ++i ) {
        hash += key[i];
				hash += ( hash << 10 );
				hash ^= ( hash >> 6 );
    }
	hash += ( hash << 3 );
	hash ^= ( hash >> 11 );
  hash += ( hash << 15 );

	return hash % symbol_table->size;
}

/* Create an entry. This will be called in insert function */
entry_t *create_entry( char *key, int entrytoken ) {
	entry_t *newentry;

	/* Allocate space for newentry */
	if( ( newentry = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}
	/* Copy key to newentry location using strdup. Return NULL if it fails */
	if( ( newentry->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	newentry->token = entrytoken;
	newentry->successor = NULL;

	return newentry;
}

/* Insert an entry into a hash table. */
void insert( hashtable_t *symbol_table, char *key, int entrytoken ) {
	uint32_t idx;
	entry_t *newentry = NULL;
	entry_t *head = NULL;

	idx = hash( symbol_table, key );
	newentry = create_entry( key, entrytoken );

	if(newentry == NULL){
		printf("Insert failed. New entry could not be created.");
		exit(1);
	}

	head = symbol_table->table[ idx ];

	if(head == NULL){
		symbol_table->table[ idx ] = newentry;
	}
	else{
		newentry->successor = symbol_table->table[ idx ];
		symbol_table->table[ idx ] = newentry;
	}
}

/* Retrieve an entry from the hash table. Return -1 if entry does not exist */
int search( hashtable_t *symbol_table, char *key ) {
	uint32_t idx = 0;
	entry_t *myentry;

	idx = hash( symbol_table, key );

	/* Traverse the linked list at this idx and see if key exists */
	myentry = symbol_table->table[ idx ];
	while( myentry != NULL && myentry->key != NULL && strcmp( key, myentry->key ) != 0 ) {
		myentry = myentry->successor;
	}

	/* Check if key was found */
	if( myentry == NULL || myentry->key == NULL ) {
		return -1;
	}
	else {
		return myentry->token;
	}

}
/* TODO
void display(hashtable_t* symbol_table){

}

insert_into_table(hashtable_t* symbol_table, char* key, int mytoken){
	// check if entry exists
	if(){

	}
	else{
		//add entry to table
	}

}
*/
int main( int argc, char **argv ) {

	hashtable_t *symbol_table = create_table( 5 );

	insert( symbol_table, "key1", 10);
	insert( symbol_table, "key2", 12 );
	insert( symbol_table, "key3", 13 );
	insert( symbol_table, "key4", 14 );
	insert( symbol_table, "key5", 15 );
	insert( symbol_table, "key6", 16 );
	insert( symbol_table, "key7", 17 );

	printf("key1 : %d\n", search(symbol_table, "key1"));
	printf("key2 : %d\n", search(symbol_table, "key2"));
	printf("key3 : %d\n", search(symbol_table, "key3"));
	printf("key4 : %d\n", search(symbol_table, "key4"));
	printf("key5 : %d\n", search(symbol_table, "key5"));
	printf("key6 : %d\n", search(symbol_table, "key6"));
	printf("key7 : %d\n", search(symbol_table, "key7"));


	return 0;
}
