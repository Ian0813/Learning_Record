/*
 * =====================================================================================
 *
 *       Filename:  515_find_largest_value_in_each_tree_row.c
 *
 *    Description:  Find largest value in each tree (Breadth First Search)
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
#include <stdint.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef enum {false, true} bool;

#define NODE_MAXNUM 10001

typedef struct TreeNode *NodePtr;

struct queue {
    NodePtr buffer[BUFSIZ];
    int windex;
    int rindex;
};

struct queue *create_queue(void) {

    struct queue *q = NULL;              

    q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(BUFSIZ) * sizeof(NodePtr));
        q->windex = q->rindex = 0;
    }
    return q;
}

bool enqueue(struct queue *q, NodePtr node) {

    bool rc = true;

	if (!q) {
        return false;
	}
      
    if ((q->windex+1)%BUFSIZ != q->rindex) {
       q->buffer[q->windex++] = node;     
       q->windex %= BUFSIZ;
    } else {
        rc = false;  
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

	if (!q)
        return false; 

    if (q->windex != q->rindex) {
        q->rindex++;     
        q->rindex %= BUFSIZ;
    } else {
        rc = false;  
    }
    return rc;
}

NodePtr peek(struct queue *q) {

    if (q->windex != q->rindex) {
        return q->buffer[q->rindex];
    }
    return NULL;
}

void delete_queue(struct queue *q) {
    if (q)
        free(q);
    return;
}

int* largestValues(struct TreeNode* root, int* returnSize) {

    struct queue *q = NULL;
    NodePtr node = NULL;
    int *result = calloc(NODE_MAXNUM, sizeof(int)), index = 0;
    int flag = 0;

    q = create_queue();

    enqueue(q, root);

    while ((node = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((node = peek(q)) != NULL) {

            dequeue(q);

            if (!flag) {
                result[index] = node->val;
                flag = 1;
            } else if (node->val > result[index]) {
                result[index] = node->val;
            }

            if (node->left)
                enqueue(q, node->left);

            if (node->right)
                enqueue(q, node->right);
        }
        flag = 0;
        index++;
        dequeue(q);
    }

    delete_queue(q);

    *returnSize = index;
    return result;
}
