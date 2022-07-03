#include <stdio.h>
#include <stdlib.h>


struct nlist {  /* table entry */
	struct nlist *next;  /* next entry in chain */
	char *name;          /* defined name  */
    char *defn;          /* replacement text */
};

#define HASHSIZE 101

/* hash: form hash value for string s */
unsigned hash(char *);

/* lookup : look for s in hashtab */
struct nlist *lookup(char *s); 

/* install : put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn);

/* reverse : reverse string */
char *reverse(char *s);

/* Show the hash table content */
void show_hashtab(void);

/* nfree :Traverse a linked list to release memory space allocated by the memory manager. */
void nfree(struct nlist *np);

/* tfree : Release all resources allocated by the memory manager. */
void tfree(void);
