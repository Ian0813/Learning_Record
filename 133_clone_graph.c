/*
 * =====================================================================================
 *
 *       Filename:  133_clone_graph.c
 *
 *    Description:  Clone graph   
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
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

typedef enum {false, true} bool;

#define TABLE_SIZE 101

typedef struct Node *NodePtr;

void traverse_copy(NodePtr *dup, struct Node *s, bool *table_record) {

    if (s) {

        if (!table_record[s->val]) {

            if (*dup == NULL) {

                table_record[s->val] = true; 

                dup[s->val] = (struct Node *) malloc(sizeof(struct Node));  
                memset(dup[s->val], 0, sizeof(struct Node));
                dup[s->val]->val = s->val; 

                if (s->numNeighbors > 0) {

                    dup[s->val]->numNeighbors = s->numNeighbors;

                    if (s->numNeighbors) {
                        dup[s->val]->neighbors = (NodePtr *) calloc(s->numNeighbors, sizeof(NodePtr)); 
                    }

                    for (int i = 0; i < s->numNeighbors; i++) {
                        traverse_copy(dup, s->neighbors[i], table_record);
                        dup[s->val]->neighbors[i] = dup[s->neighbors[i]->val];
                    }    
                }
            }
        }
    }
    return;
}

void print_graph(NodePtr node, bool *table_record) {

    if (node && !table_record[node->val]) {

        table_record[node->val] = true;

        printf("val: %d\n", node->val);
        printf("numNeighbors: %d\n", node->numNeighbors);

        if (node->numNeighbors) {
            for (int i = 0; i < node->numNeighbors; i++) {
                print_graph(node->neighbors[i], table_record);
            }
        }
    }
    return;
}

struct Node *cloneGraph(struct Node *s) {

    bool table_record[TABLE_SIZE] = {false};
    NodePtr dup[TABLE_SIZE] = {NULL};
	NodePtr result = NULL;

    if (s) {
        traverse_copy(dup, s, table_record);
        result = dup[s->val];
	}

	return result;
}
