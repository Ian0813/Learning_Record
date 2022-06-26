/*
 * =====================================================================================
 *
 *       Filename:  keyword_counter.c
 *
 *    Description:  Count C keywords - binary tree version
 *
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

/*  word frequency count */
int main(void) {

	struct tnode *root = NULL;
	char word[MAXWORD];
	// int test_count = 0; /* Feature testing */
	memset(word, 0, MAXWORD);

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}

	treeprint(root);
	tfree(root);

	return 0;
}

/* addtree : add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
	
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
	    p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(p->word, w)) == 0) {
		p->count++;	
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	} else {
		p->right = addtree(p->right, w);
	}
	
	return p;
}

/* make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* treeprint : in-order print of tree p */
void treeprint(struct tnode *p) {

	if (p != NULL) {
		treeprint(p->left);
		printf("count : %d, word : %s\n", p->count, p->word);
		treeprint(p->right);
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
