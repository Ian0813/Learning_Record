/*
 * =====================================================================================
 *
 *       Filename:  107_binary_tree_level_order_traversal_ii.c
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
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_NODENUMS 2001

typedef struct TreeNode *NodePtr;

struct queue {
    NodePtr buffer[BUFSIZ];
    int windex;
    int rindex;
};
typedef struct queue *Queue;

typedef enum {false, true} bool;
Queue create_queue(void) {

    Queue q = NULL; 

    q = (Queue) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(NodePtr) * BUFSIZ);
        q->windex = 0;
        q->rindex = 0;
    }
    return q;
}

bool enqueue(Queue q, NodePtr node) {

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

bool dequeue(Queue q) {

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

NodePtr peek(Queue q) {

    if (q) {

        if (q->windex != q->rindex) {
            return q->buffer[q->rindex];
        }
    }
    return NULL;
}

void delete_queue(Queue q) {

    if (q)
        free(q);
    return;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    int **result = (int **) calloc(MAX_NODENUMS, sizeof(int *));
    int rindex = 0, index = 0, *ptr = NULL, temp_value = 0;
    int temp[BUFSIZ] = {0};
    Queue q = create_queue();
    NodePtr node = NULL;

    *returnColumnSizes = (int *) calloc(MAX_NODENUMS, sizeof(int));

    enqueue(q, root);        

    while ((node = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((node = peek(q)) != NULL) {

            dequeue(q);
            temp[index++] = node->val;

            if (node->left)
                enqueue(q, node->left);

            if (node->right)
                enqueue(q, node->right); 
        }

        result[rindex] = (int *) calloc(index, sizeof(int));
        memcpy(result[rindex], temp, sizeof(int) * index);
        (*returnColumnSizes)[rindex] = index;
        rindex++;
        index = 0;
    }

    for (int i = 0, j = rindex - 1; i < j; i++, j--) {
        ptr = result[i];
        result[i] = result[j];
        result[j] = ptr;
    }

    for (int i = 0, j = rindex - 1; i < j; i++, j--) {
        temp_value = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[j];
        (*returnColumnSizes)[j] = temp_value;
    }
    *returnSize = rindex;
    dequeue(q);
    return result; 
}
