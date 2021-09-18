/*
 * =====================================================================================
 *
 *       Filename:  559_maximum_depth_of_n_ary_tree.c
 *
 *    Description:  Maximum depth of n ary tree  
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

#define MAX 10001

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

typedef struct Node *NodePtr;

NodePtr node_array[MAX] = {NULL};
static int read_index = 0, write_index = 0;  

int enqueue(NodePtr node) {
    if ((write_index+1) != read_index) {
        node_array[write_index++] = node; 
        write_index %= MAX;
		return write_index;
	}
	return -1;
}

int dequeue(void) {
    if ((read_index) != write_index) {
		read_index++;
        read_index %= MAX;
		return read_index;
	}
	return -1;
}

NodePtr peek(void) {
    if (read_index == write_index) {
        return NULL;
	}
    return node_array[read_index];
}

int maxDepth(struct Node* root) {

    int height = 0, number = 0; 
	NodePtr node;

    if (root == NULL)
        return 0;

    enqueue(root); 

	while (peek() != NULL) {

        height += 1;
		enqueue(NULL);

		while ((node = peek()) != NULL) {
            number = node->numChildren;    
            while (number--) {
                enqueue(node->children[number]);  
			}
            dequeue();
		}
		dequeue();
	}
    return height;
}

int main(void) {
    return 0;
}
