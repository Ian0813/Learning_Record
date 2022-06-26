/*
 * =====================================================================================
 *
 *       Filename:  keyword_counter.c
 *
 *    Description:  Read a C program and prints in alphabetic order each group of variable names,
 *                  that are identical in the first 6 characters.    
 *        Version:  1.0
 *        Created:  2022年05月10日 20時25分00秒
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
#include <ctype.h>
#include "common.h"

#define MAXWORD 100
#define YES 1
#define NO  0

/* print in alphabetic order each group of variable name */
/* identical in the first num characters (default 6) */
int main(int argc, char *argv[]) {

	struct tnode *root = NULL;
	char word[MAXWORD];
	int found = NO; /* YES if match was found */
    int num;        /* number of the first identical characters */ 
	// int test_count = 0; /* Feature testing */
	memset(word, 0, MAXWORD);

	num = (--argc && (*++argv)[0] == '-')? atoi(argv[0]+1) : 6; 
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strlen(word) >= num) {
			root = addtreex(root, word, num, &found);
		}
		found = NO;
	}

	treexprint(root);
	tfree(root);

	return 0;
}

/* addtree : add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found) {
	
	int cond = 0;
	if (p == NULL) {    /* a new word has arrived */
		p = talloc();   /* make a new node */
		p->word = strdup(w);
		p->match = *found;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, num, found)) < 0) {
		p->left = addtreex(p->left, w, num, found);
	} else if (cond > 0) {
		p->right = addtreex(p->right, w, num, found);
	}
	return p;
}

/* compare : compare words and update p->match */
int compare(char *s, struct tnode *p, int num, int *found) {
	
	int i;
	char *t = p->word;

	for (i = 0; *s == *t; i++, s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}

	if (i >= num) { /* identical in first num chars ? */
		p->match = *found = YES;	
	}

	return *s - *t;
}


/* make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* treexprint : in-order print of tree p */
void treexprint(struct tnode *p) {

	if (p != NULL) {
		treexprint(p->left);
		if (p->match) {
			printf("[%s] %s\n", __FILE__, p->word);
		}
		treexprint(p->right);
	}
	return;
}	

/* tfree : release all resources in the binary tree */
void tfree(struct tnode *ptr) {

	if (ptr != NULL) {
		tfree(ptr->left);
		tfree(ptr->right);
		free(ptr->word);
		ptr->word = NULL;
		free(ptr);
		ptr = NULL;
	}
	return;
}

/* getword : get next word or character from input. */
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

	for ( ; --lim > - 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
