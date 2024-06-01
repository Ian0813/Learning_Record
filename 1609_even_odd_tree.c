/*
 * =====================================================================================
 *
 *       Filename:  1609_even_odd_tree.c
 *
 *    Description:  Even-odd tree  
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
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} *NodePtr;

typedef enum {false, true} bool;

struct queue {
    NodePtr buffer[BUFSIZ];
    int windex;
    int rindex;
};

struct queue *create_queue(void) {

    struct queue *q = NULL;

    q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(q->buffer));
        q->windex = q->rindex = 0;
    }
    return q;
}

bool enqueue(struct queue *q, NodePtr node) {

    bool rc = true;

    if (q) {
        if ((q->windex+1)%BUFSIZ != q->rindex) {
            q->buffer[q->windex++] = node;
            q->windex %= BUFSIZ; 
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

    if (q) {
        if (q->rindex != q->windex) {
            q->rindex++;
            q->rindex %= BUFSIZ;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

NodePtr peek(struct queue *q) {

    NodePtr node = NULL;

    if (q) {
        if (q->rindex != q->windex) {
            node = q->buffer[q->rindex];
        }
    }
    return node;
}

void delete_queue(struct queue *q) {
    free(q);
    return;
}

bool check_order(int level, NodePtr node, int last_even, int last_odd) {

    bool rc = true;

    if (level%2) {
        if (!(node->val%2)) {
            if (last_even > node->val) {
                last_even = node->val;                                                        
            } else {
                rc = false;  
            }    
        } else {
            rc = false;   
        }
    } else {
        if (node->val%2) {
            if (last_odd < node->val) {
                last_odd = node->val;
            } else {
                rc = false;
            }
        } else {
            rc = false;
        }
    }
	return rc;
}

bool isEvenOddTree(struct TreeNode* root) {

    struct queue *q = create_queue();
    NodePtr node = root;
    int level = 0, last_odd = 0, last_even = INT_MAX;
    bool rc = true;

    if (root) {

        enqueue(q, node);

        while ((node = peek(q)) != NULL) {

            enqueue(q, NULL);

            while ((node = peek(q)) != NULL) {

                dequeue(q);

                if (!(rc = check_order(level, node, last_even, last_odd))) {
                    break;
                }

                if (node->left)
                    enqueue(q, node->left);

                if (node->right)
                    enqueue(q, node->right);
            }

            last_even = INT_MAX;
            last_odd = 0;
			level++; 

            if (!rc)
                break;

            dequeue(q);
        }
    }
    delete_queue(q);

    return rc;
}
