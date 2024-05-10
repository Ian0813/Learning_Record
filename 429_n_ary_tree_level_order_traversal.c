/*
 * =====================================================================================
 *
 *       Filename:  429_n_ary_tree_level_order_traversal.c
 *
 *    Description:  N-ary tree level order traversal  
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef enum {false, true} bool; 

#define MAX_NODENUM 10001

typedef struct Node *NodePtr;

struct queue {
    NodePtr buffer[MAX_NODENUM];
    int windex;
    int rindex;
};

struct queue *create(void) {

    struct queue *q = NULL;

    q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(NodePtr) * MAX_NODENUM);
        q->windex = q->rindex = 0; 
    }
    return q;
}

bool enqueue(struct queue *q, NodePtr node) {

    bool rc = true;

    if ((q->windex+1)%MAX_NODENUM != q->rindex) {
        q->buffer[q->windex++] = node;
        q->windex %= MAX_NODENUM;
    } else {
        rc = false;
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

    if (q->windex != q->rindex) {
        q->rindex++;
        q->rindex %= MAX_NODENUM;
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

void destroy(struct queue *q) {
    if (q) {
        free(q);
    }
    return;
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;
    struct queue *q = NULL; 
    NodePtr temp = NULL;
    int index = 0, tindex = 0;
    int arr[BUFSIZ] = {0}; 

    result = (int **) calloc(MAX_NODENUM, sizeof(int *));
    *returnColumnSizes = (int *) calloc(MAX_NODENUM, sizeof(int));
    q = create();

    enqueue(q, root);

    while ((temp = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((temp = peek(q)) != NULL) {
            dequeue(q);
            for (int i = 0; i < temp->numChildren; i++) {
                enqueue(q, temp->children[i]);
            }
            arr[tindex++] = temp->val;
        }

        dequeue(q);
        result[index] = (int *) calloc(tindex, sizeof(int));
        memcpy(result[index], arr, sizeof(int) * tindex);
        (*returnColumnSizes)[index] = tindex; 

        memset(arr, 0, sizeof(int) * BUFSIZ);
        tindex = 0;
        index++;
    }

    *returnSize = index;
    destroy(q);
    return result;
}
