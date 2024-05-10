/*
 * =====================================================================================
 *
 *       Filename:  102_binary_tree_level_order_traversal.c
 *
 *    Description:  Binary tree level order traversal  
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_NODE 2001

typedef struct TreeNode *NodePtr;
typedef enum {false, true} bool;

struct queue {
    NodePtr nodes[MAX_NODE];
    int windex;
    int rindex;
};

struct queue *create(void) {

    struct queue *q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->nodes, 0, sizeof(NodePtr) * MAX_NODE);
        q->windex = 0; 
        q->rindex = 0;
    }
    return q;
}

bool enqueue(struct queue *q, NodePtr node) {

    bool rc = true;
    if (q) {
        if ((q->windex+1)%MAX_NODE != q->rindex) {
            q->nodes[q->windex++] = node;        
            q->windex %= MAX_NODE;
        } else {
            rc = false;
        }
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

    if (q->rindex != q->windex) {
        q->rindex = (q->rindex+1)%MAX_NODE;
    } else {
        rc = false;
    }
    return rc;
}

NodePtr peek(struct queue *q) {

    if (q->rindex != q->windex) {
        return q->nodes[q->rindex];
    }
    return NULL;
}

void destroy(struct queue *q) {

    if (q) {
        free(q);        
    }
    return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    int **result = (int **) calloc(MAX_NODE, sizeof(int *));
    int index = 0, count = 0, tindex = 0;
    int arr[MAX_NODE] = {0};
    struct queue *q = NULL;
    NodePtr temp = root;

    *returnColumnSizes = (int *) calloc(MAX_NODE, sizeof(int));
    *returnSize = index;

    q = create();
    enqueue(q, temp);  

    while ((temp = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((temp = peek(q)) != NULL) {
            dequeue(q);
            arr[tindex++] = temp->val;

            if (temp->left)
                enqueue(q, temp->left);
            if (temp->right)
                enqueue(q, temp->right);
        }

        dequeue(q);
        (*returnColumnSizes)[index] = tindex; 
        result[index] = (int *) calloc(tindex, sizeof(int));
        memcpy(result[index], arr, sizeof(int) * tindex);
        index++;
        memset(arr, 0, MAX_NODE * sizeof(int));
        tindex = 0;
    }

    destroy(q);

    *returnSize = index;
    return result;
}

