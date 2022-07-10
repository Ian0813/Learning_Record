/*
 * =====================================================================================
 *
 *       Filename:  table_lookup.
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
#include <ctype.h>

#define MAXWORD 100

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

void main(int argc, char *argv[]) {
		
	char w[MAXWORD];
	struct nlist *p = NULL;

	while (getword(w, MAXWORD) != EOF) {
		if (strcmp(w, "#") == 0) {   /*beginning of direct  */
			getdef();	
		} else if (!isalpha(w[0])) {
			printf("[%s] %s, @%d\n", __func__, w, __LINE__);         /* cannot be defined */		
		} else if ((p = lookup(w)) == NULL) {
			printf("[%s] %s, @%d\n", __func__, w, __LINE__);         /* not defined  */				
		} else {
			printf("[%s] %s, @%d\n", __func__, p->defn, __LINE__);         /* not defined  */				
			ungets(p->defn);         /* push definition */
		}
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
	//free(defn);

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

/* getdef : get definition and install it  */
void getdef(void) {
	
	int c, i;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD]; 

	skipblanks();
	if (!isalpha(getword(dir, MAXWORD))) {
		error(dir[0], "getdef : expecting a directive after #");	
	} else if (strcmp(dir, "define") == 0) {
		skipblanks();		
		if (!isalpha(getword(name, MAXWORD))) {
			error(name[0], "getdef : non-alpha - name expected.");
		} else {
			skipblanks();
			for (i = 0; i < MAXWORD; i++) {
				if ((def[i] = getch()) == EOF || def[i] == '\n') {
					break;   /* enf of definition */
				} 
			}
			def[i] = '\0';
			if (i <= 0) { /* no definition ? */
				error('\n', "getdef : incomplete define.");
			} else {    /* install */
				printf("[%s] name : %s, def : %s\n", __func__, name, def);
				install(name, def);
			}
		}
	} else if (strcmp(dir, "undef") == 0) {
		skipblanks();	
		if (!isalpha(getword(name, MAXWORD))) {
			error(name[0], "getdef : non-alpha in undef.");
		} else {
			undef(name);
		} 
	} else {
		error(dir[0], "getdef : expecting a directive after #.");	
	}
	return;
}

/* error : print error message and skip the rest of the line */
void error(int c, char *s) {
	printf("error : %s\n", s);
	while (c != EOF && c != '\n') {
		c = getch();
	}
}

/* skipblanks :  skip blank and tab characters */ 
void skipblanks(void) {
	int c;
	
	while ((c = getch()) == ' ' || c == '\t') 
			;
	ungetch(c);
	
	return;
}

/* getword : get next word or character from input */
int getword(char *word, int lim) {

	int c;
	char *w = word;

	while (isspace(c = getch())) 
		;

	if (c != EOF) {
		*w++ = c;
	}

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}

	*w = '\0';
	return word[0];
}

void ungets(char *c) {

	int flag = 0;
	int len = strlen(c) - 1;
	c += len;

	while (len >= 0) {
		flag = 1;
		ungetch(*c--);
		len--;
	}

	if (flag == 0) {
		printf("No remains character.\n");
	}

	return;
}
