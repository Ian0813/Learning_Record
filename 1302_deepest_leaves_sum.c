/*
 * =====================================================================================
 *
 *       Filename:  1302_deepest_leaves_sum.c
 *
 *    Description:  Deepest leaves sum
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
#include <unistd.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_NODE_NUMS 10001

struct queue {

    struct TreeNode **buffer; 
    int windex;
    int rindex;
};

struct queue * create_queue(void) {

    struct queue *q = NULL;

    q = (struct queue *) malloc(sizeof(struct queue));

    if (!q) {
        perror("malloc ");
    } else {
        q->buffer = (struct TreeNode **) calloc(MAX_NODE_NUMS, sizeof(struct TreeNode *));  
        q->windex = 0;
        q->rindex = 0;
    }
    return q;
}

bool enqueue(struct queue *q, struct TreeNode *node) {

    bool rc = true;

    if (q) {
        q->buffer[q->windex] = node;
		q->windex %= MAX_NODES_NUMS;
    } else {
        rc = false;
    }
    return rc;
}

bool dequeue(struct queue *q) {

    bool rc = true;

    if (q && q->rindex != q->windex) {
        q->rindex++;
        q->rindex %= MAX_NODE_NUMS;
    } else {
        rc = false;
    }
    return rc;
}

struct TreeNode *peeking(struct queue *q) {

    if (q && q->rindex != q->windex) {
        return q->buffer[q->rindex];
    }
    return NULL;
}    

void delete_queue(struct queue *q) {

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}

int get_hight(struct TreeNode *root) {

    int lhigh = 0, rhigh = 0;

    if (root) {

        lhigh = get_hight(root->left);
        rhigh = get_hight(root->right);
        return 1 + (lhigh > rhigh ? lhigh : rhigh); 
    }
    return 0;
}

int deepestLeavesSum(struct TreeNode* root) {

    int sum = 0;
    struct queue *q = create_queue();
    struct TreeNode *temp = NULL;
    int high = 0;

    enqueue(q, root);

    while ((temp = peeking(q)) != NULL) {

        enqueue(q, NULL);
        sum = 0;
        high++;

        while ((temp = peeking(q)) != NULL) {

            dequeue(q);

            sum += temp->val; 

            if (temp->left) {
                enqueue(q, temp->left); 
            }

            if (temp->right) {
                enqueue(q, temp->right); 
            }
        }
        dequeue(q);
    }

    delete_queue(q);
    return sum;
}
