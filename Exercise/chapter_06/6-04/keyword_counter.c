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

/* cross-referencer */
int main(int argc, char *argv[]) {

	struct tnode *root = NULL;
	char word[MAXWORD];
	int linenum = 1;
	memset(word, 0, MAXWORD);

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && noiseword(word) == -1 && word[0] != 'a') {
			root = addtreex(root, word, linenum);
		} else if (word[0] == 'a') {
			linenum++;
		}
		printf("linenum : %d\n", linenum);
	}

	treexprint(root);
	tfree(root);

	return 0;
}

/* addtree : add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum) {
	int cond = 0;
	if (p == NULL) {    /* a new word has arrived */
		p = talloc();   /* make a new node */
		p->word = strdup(w);
		p->lines = lalloc();
		p->lines->lnum = linenum;
		p->lines->ptr = NULL;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		addln(p, linenum);
	} else if (cond > 0) {
		p->right = addtreex(p->right, w, linenum);
	} else if (cond < 0) {
		p->left = addtreex(p->left, w, linenum);
	}

	return p;
}

/*  addln : add a line number to the linker list */
void addln(struct tnode *p, int linenum) {

	struct linklist *temp;

	temp = p->lines;

	while (temp->ptr != NULL && temp->lnum != linenum) {
		temp = temp->ptr; 
	}

	if (temp->lnum != linenum) {
		temp->ptr = lalloc();
		temp->ptr->lnum = linenum;
		temp->ptr->ptr = NULL;	
	}
	return;
}

/* make a linklist */
struct linklist *lalloc(void) {
	return (struct linklist *) malloc(sizeof(struct linklist)); 
}


/* make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* treexprint : in-order print of tree p */
void treexprint(struct tnode *p) {
	
	struct linklist *temp = NULL;

	if (p != NULL) {
		treexprint(p->left);
		printf("%10s:", p->word);
		for (temp = p->lines; temp != NULL; temp = temp->ptr) {
			printf("%4d ", temp->lnum);
		}	
		treexprint(p->right);
	}
	return;
}

/* lfree : release the link list inside the tnode. */
void lfree(struct linklist *ptr) {

	struct linklist *temp = ptr;

	while (temp != NULL) {
		ptr = ptr->ptr;
		free(temp);
		temp = ptr;
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
		lfree(ptr->lines);
		free(ptr);
		ptr = NULL;
	}
	return;
}

/* noiseword : identify word as a noise word */
int noiseword(char *w) {
	static char *nw[] = {
		"a",
		"and",
		"are",
		"in",
		"is",
		"of",
		"or",
		"that",
		"the",
		"this",
		"to"
	};

	int cond, mid;
	int low = 0;
	int high = sizeof(nw) / sizeof(char *) - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(w, nw[mid])) < 0) {
			high = mid - 1;
		} else if (cond > 0) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
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
