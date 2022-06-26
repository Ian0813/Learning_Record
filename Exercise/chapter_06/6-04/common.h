/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  Declare the prototype of each function to use.
 *
 *        Version:  1.0
 *        Created:  2022年05月29日 22時12分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */


/**
 * @brief the tree node
 */
struct tnode { /*  the tree node */
	char *word;   /* points to the text */	
	struct linklist *lines;  /* line number */
	struct tnode *left;   /* left child */
	struct tnode *right;  /* right child */
};

struct linklist { /* linked list of line numbers */
	int lnum;
	struct linklist *ptr;
};

int getch(void);

void ungetch(int ch);

struct tnode *addtreex(struct tnode *, char *, int);

void treexprint(struct tnode *);

struct tnode *talloc(void);

struct linklist *lalloc(void);

void tfree(struct tnode *ptr); 

int getword(char *, int);

void addln(struct tnode *, int);

int noiseword(char *);

#if 0
struct key *binsearch(char *, struct key *, int);
#endif

