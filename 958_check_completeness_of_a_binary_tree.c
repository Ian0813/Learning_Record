/*
 * =====================================================================================
 *
 *       Filename:  958_check_completeness_of_a_binary_tree.c
 *
 *    Description:  Check completeness of a binary tree 
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
typedef struct TreeNode *NodePtr;

struct queue {
    NodePtr *buffer;
    int windex;
    int rindex;
    int size; 
};

typedef struct queue *Queue;

Queue create_queue(int size) {

    Queue q = NULL;

    if (size) {
        q = (Queue) malloc(sizeof(struct queue)); 
        q->buffer = (NodePtr *) calloc(size, sizeof(NodePtr)); 
        q->windex = q->rindex = 0;
        q->size = size;
    }
    return q;
}

bool enqueue(Queue q, NodePtr node) {

    bool rc = true;

    if (q) {
        if ((q->windex+1)%q->size != q->rindex) {
            q->buffer[q->windex++] = node;             
            q->windex %= q->size; 
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
            q->rindex %= q->size; 
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
            q->buffer[q->rindex];
        }
    }
    return NULL; 
}

void delete_queue(Queue q) {

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}

int getheight(NodePtr root) {

    int lh = 0, rh = 0;

    if (root) {
        lh = getheight(root->left); 
        rh = getheight(root->right); 
        return 1 + (lh > rh ? lh : rh);
    }
    return 0;
}

int count_nodes(NodePtr root) {

    int lcount = 0, rcount = 0;

    if (root) {
        lcount = count_nodes(root->left);    
        rcount = count_nodes(root->right);    
        return 1 + lcount + rcount; 
    }
    return 0;
}

bool isCompleteTree(struct TreeNode* root) {

    NodePtr node = NULL, last = NULL;
    NodePtr arrptr[BUFSIZ] = {NULL}; 
    Queue q = NULL;
    int index = 0, count = 0, flag = 0;
    bool rc = true;

    if (root) {

        q = create_queue(BUFSIZ); 

        count = count_nodes(root);

        enqueue(q, root);

        while (count) {

            node = peek(q);
            dequeue(q);
            arrptr[index++] = node;

            if (node)
                count--;
            if (node)
                enqueue(q, node->left);
            if (node)
                enqueue(q, node->right);
        }

        for (int i = 0; i < index; i++) {
            if (!arrptr[i] && i != index-1) {
                rc = false;
            }
        }
        delete_queue(q);
    }
    return rc;
}
