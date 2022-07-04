/*
 * =====================================================================================
 *
 *       Filename:  table_lookup.c
 *
 *    Description:  a hash table for searching a specific word. 
 *     				Add a undef() function to remove a name and definition from the hash
 *     				table. 
 *
 *        Version:  1.0
 *        Created:  2022年07月01日 00時14分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h" 
#include <time.h>

static struct nlist *hashtab[HASHSIZE]; /* pointer table */


void main(int argc, char *argv[]) {
	
	if (argc > 1) {

		srand(time(NULL));

	    /* The index points to the first argument passing from outside. */ 
	    int start_index = 1, random_num;
	    struct nlist *np = NULL;

	    for(; start_index < argc; start_index++) {
	    	np = install(argv[start_index], reverse(argv[start_index]));					
	    }
		show_hashtab();
		random_num = rand() % (start_index - 1) + 1;
		printf("Remove %s in the hash table.\n", argv[random_num]);
		undef(argv[random_num]);
		show_hashtab();
		tfree();

	} else {
		printf("[%s] Please enter the correct arguments.\n", __FILE__);
		exit(EXIT_FAILURE);
	}
		
	return;    
}

/* show the hash table content  */
void show_hashtab(void) {
	
	struct nlist *temp = NULL;
	for (int i = 0; i < HASHSIZE; i++) {
		if ((temp = hashtab[i]) != NULL) {
			do {
				printf("hashtab[%d] name : %s\n", i, temp->name);			
				printf("hashtab[%d] defn : %s\n", i, temp->defn);
				temp = temp->next;	
			} while (temp != NULL);
		}
	}	
}	

/* hash: form hash value for string s */
unsigned hash(char *s) {
	
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval%HASHSIZE;
}

/* lookup : look for s in hashtab */
struct nlist *lookup(char *s) {
	
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
}

/* install : put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {

	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {  /* Not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);	
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np; 
	} else { /* already there */
		free((void *) np->defn);  /* free previous defn */	
	}

	if ((np->defn = strdup(defn)) == NULL) {
		return NULL;
	}
	free(defn);

	return np;
}

/* Traverse a linked list to release the memory space allocated by the memory manager. */
void nfree(struct nlist *np) {
	
	struct nlist *temp = NULL;

	while ((temp = np) != NULL) {
		np = np->next;
		free(temp->defn);
		free(temp->name);
		free(temp);
		temp = np;
	}
	return;
}

/* Release all resources allocatrd ny the memory manager. */
void tfree(void) {
	
	for (int i = 0; i < HASHSIZE; i++) {
		nfree(hashtab[i]);
	}
	bzero(hashtab, sizeof(struct nlist *) * HASHSIZE);
	
	return;

}

char *reverse(char *s) {

	int tail = strlen(s) - 1;
	char *temp = strdup(s);
	bzero(temp, strlen(s));

	for (int index = 0; tail >= 0; tail--, index++) {
		temp[index] = s[tail];
	}

	return temp;
}


/* undef : remove a name and definition from the table */
void undef(char *s) {
	
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash(s);               /* hash value of string */
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			break;
		}
		prev = np;           /* remeber previous entry */
	}

	if (np != NULL) {       /* found name */
		if (prev == NULL) { /* first in the hash list */
			hashtab[h] = np->next;
		} else {
			prev->next = np->next; /* eleswhere in the hash list */
		}
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);   /* free allocated structure */
	}
	return;
}
