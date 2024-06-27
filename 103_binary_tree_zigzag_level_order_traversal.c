/*
 * =====================================================================================
 *
 *       Filename:  103_binary_tree_zigzag_level_order_traversal.c
 *
 *    Description:  Binary tree zigzag level order traversal   
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
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

typedef struct TreeNode *NodePtr;
typedef struct queue *Queue;
typedef enum {false, true} bool; 

struct queue {
    NodePtr buffer[BUFSIZ];
    int windex;
    int rindex;
};

Queue create_queue(void) {

    Queue q = NULL;   

    q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(NodePtr) * BUFSIZ);
        q->windex = q->rindex = 0;
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
        if (q->rindex != q->windex)
            return q->buffer[q->rindex];
    }
    return NULL;
}

void delete_queue(Queue q) {
    if (q)
        free(q);
    return;
}

int get_tree_height(NodePtr root) {

    int lh = 0, rh = 0;

    if (root) {
        lh = get_tree_height(root->left);
        rh = get_tree_height(root->right);
        return 1 + (lh > rh ? lh : rh); 
    }
    return 0;
}

void reverse(int *arr, int len) {

    int val = 0;

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        val = arr[i];
        arr[i] = arr[j];
        arr[j] = val;
    }
    return;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    int height = 0, cindex = 0, index = 0, rindex = 0;
    int **result = NULL, level = 0;
    int temp[BUFSIZ] = {0}; 
    Queue q = NULL;
    NodePtr node = NULL;
    *returnSize = 0;

    if (root) {

        q = create_queue();
        height = get_tree_height(root);
        *returnSize = height;
        *returnColumnSizes = (int *) calloc(height, sizeof(int));
        result = (int **) calloc(height, sizeof(int *));
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

            dequeue(q);

            result[rindex] = (int *) calloc(index, sizeof(int));

            if ((level++)%2)
                reverse(temp, index);

            memcpy(result[rindex], temp, sizeof(int)*index);
            (*returnColumnSizes)[cindex++] = index;
            index = 0;
            memset(temp, 0, sizeof(temp));
            rindex++;
        }
        delete_queue(q);
    }
    return result;
}
