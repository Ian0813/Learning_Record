/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  The common info (data type, function, etc.) for the program compile
 *
 *        Version:  1.0
 *        Created:  2022年07月31日 03時52分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct tnode * Treeptr; 

typedef struct tnode {  /*  the tree node */
	
	//char *word;    /* points to the text */
	//int  count;    /* number of occurrences */ 
	int value;     /* a value by a node hold. */	
	Treeptr left;  /* left child */
	Treeptr right; /* right child */
} Treenode;

Treeptr talloc(void); 

Treeptr new_node(Treeptr node, int value);

void show_nodes(Treeptr node);

void release_nodes(Treeptr node);
