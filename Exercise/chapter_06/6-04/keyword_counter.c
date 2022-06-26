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
#define NDISTINCT 1000

struct tnode *list[NDISTINCT];  /* pointer to tree nodes */
int ntn = 0;                     /* number of tree nodes */

/* print distince words sorted in decreasing order of freq */ 
int main(int argc, char *argv[]) {

	struct tnode *root = NULL;
	char word[MAXWORD];
	int i; 
	memset(word, 0, MAXWORD);

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}

	treestore(root);
	sortlist();
	for (i = 0; i < ntn; i++) {
		printf("%2d:%20s\n", list[i]->count, list[i]->word);
	}

	tfree(root);

	return 0;
}

/* addtree : add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
	int cond = 0;
	if (p == NULL) {    /* a new word has arrived */
		p = talloc();   /* make a new node */
		p->word = strdup(w);
		p->count++;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
	} else if (cond > 0) {
		p->right = addtree(p->right, w);
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	}

	return p;
}

/* make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) calloc(sizeof(struct tnode), 1);
}

/* treestore : store in list[] pointer to tree nodes */ 
void treestore(struct tnode *p) {
	
	if (p != NULL) {
		treestore(p->left);
		if (ntn < NDISTINCT) {
			list[ntn++] = p;
		}
		treestore(p->right);
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

/* sortlist : sort list of pointers to tree nodes */
void sortlist(void) {

    int gap, i, j; 
	struct tnode *temp; 

	for (gap = ntn/2; gap > 0; gap/=2) {
		for (i = gap; i < ntn; i++) {
			for (j = i-gap; j >= 0; j -= gap) {
				if (list[j]->count >= list[j+gap]->count) {
					break;	
				}
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
		}
		printf("hello\n");
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

	for ( ; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';

	return word[0];
}
