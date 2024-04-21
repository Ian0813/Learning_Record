/*
 * =====================================================================================
 *
 *       Filename:  199_binary_tree_right_side_view.c
 *
 *    Description:  Binary tree right side view  
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct queue {
    struct TreeNode *arr[BUFSIZ];
    int windex;
    int rindex;
};

struct queue *create_queue(void) {

    struct queue *q = NULL;

    q = (struct queue *) malloc(sizeof(struct queue));
    memset(q, 0, sizeof(struct queue)); 

    return q;
}

bool enqueue(struct queue *q, struct TreeNode *node) {

    bool rc = true;

    if (q->windex < BUFSIZ) {
        q->arr[q->windex++] = node;
    } else {
        rc = false;
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

    if (q->rindex != q->windex) {
        q->rindex++;
    } else {
        rc = false;
    }
    return rc;
}

struct TreeNode *peeking(struct queue *q) {

    if (q->windex != q->rindex) {
        return q->arr[q->rindex]; 
    }
    return NULL;
}

void delete_queue(struct queue *q) {

    if (q != NULL) {
        free(q);
    }
    return;
}

int bfs_getmostright(struct TreeNode *root, int *arr) {

    struct queue *q = create_queue();
    int lastone = 0;
    int index = 0;
    struct TreeNode *node = NULL;

    enqueue(q, root);

    while ((node = peeking(q)) != NULL) {

        enqueue(q, NULL);

        while ((node = peeking(q)) != NULL) {
              
            lastone = node->val;

            if (node->left)
                enqueue(q, node->left);

            if (node->right)
                enqueue(q, node->right);

            dequeue(q);
        }
        arr[index++] = lastone;
        dequeue(q);
    }

    delete_queue(q);

    return index;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {

    int *arr = NULL;

    arr = (int *) calloc(BUFSIZ, sizeof(int));

    *returnSize = bfs_getmostright(root, arr);

    return arr;
}
