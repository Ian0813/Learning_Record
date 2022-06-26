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
	int count;    /*  number of occurences */
	struct tnode *left;   /* left child */
	struct tnode *right;  /* right child */
};

int getch(void);

void ungetch(int ch);

struct tnode *addtree(struct tnode *, char *);

struct tnode *talloc(void);

void tfree(struct tnode *ptr); 

int getword(char *, int);

void sortlist(void);

void treestore(struct tnode *);
#if 0
struct key *binsearch(char *, struct key *, int);
#endif

