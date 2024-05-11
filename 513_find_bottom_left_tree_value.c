/*
 * =====================================================================================
 *
 *       Filename:  513_find_bottom_left_tree_value.c
 *
 *    Description:  Find bottom left tree value  
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef enum {false, true} bool;

#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ 10001
#endif

typedef struct TreeNode *NodePtr;

struct queue {
    NodePtr buffer[BUFSIZ];
    int windex;
    int rindex;
};

struct queue *create(void) {

    struct queue *q = NULL; 

    q = (struct queue *) malloc(sizeof(struct queue));

    if (q) {
        memset(q->buffer, 0, sizeof(int) * BUFSIZ);
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
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true; 

    if (q) {
        if (q->rindex != q->windex) {
            q->rindex = q->rindex+1 % BUFSIZ;
        } else {
            rc = false;
        }
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

void destroy(struct queue *q) {
    if (q) {
        free(q);
    }
    return;
}

int findBottomLeftValue(struct TreeNode* root) {

    int result = 0, flag = 0;
    struct queue *q = NULL;  
    NodePtr temp = root;

    q = create();
    enqueue(q, root);

    while ((temp = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((temp = peek(q)) != NULL) {
            dequeue(q); 
            if (!flag) {
                result = temp->val; 
                flag = 1;
            }

            if (temp->left) {
                enqueue(q, temp->left);
            }

            if (temp->right) {
                enqueue(q, temp->right);
            }
        }
        flag = 0;
        dequeue(q);
    }
    destroy(q);
    return result;
}
