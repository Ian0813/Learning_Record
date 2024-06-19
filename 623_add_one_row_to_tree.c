/*
 * =====================================================================================
 *
 *       Filename:  623_add_one_row_to_tree.c
 *
 *    Description:  Add one row to tree
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
typedef struct queue *Queue;

struct queue {
    NodePtr buffer[BUFSIZ];     
    int windex;
    int rindex;
};

Queue create_queue(void) {

    Queue q = NULL;

    q = (Queue) malloc(sizeof(struct queue));    

    if (q) {
        memset(q->buffer, 0, sizeof(NodePtr)*BUFSIZ);
        q->rindex = q->windex = 0;
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
        if (q->rindex != q->windex) {
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

struct TreeNode *create_node(int val) {

    NodePtr node = NULL;
    node = (NodePtr) malloc(sizeof(struct TreeNode));

    if (node) {
        node->val = val;
        node->left = node->right = NULL;
    }
    return node;
}

void insert_node(NodePtr parent, int val) {

    NodePtr node = NULL;

    node = create_node(val);
    
    node->left = parent->left;
    parent->left = node;
    
    node = create_node(val);
    node->right = parent->right;
    parent->right = node;

    return;
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {

    NodePtr node = NULL, sub = NULL;
    Queue q = NULL;
    int cur_level = 1;

    if (depth > 1) {

        q = create_queue();
        enqueue(q, root);

        while ((sub = peek(q)) != NULL) {

            enqueue(q, NULL);

            while ((sub = peek(q)) != NULL) {

                if (cur_level == (depth-1)) {
                    insert_node(sub, val);
                }
                dequeue(q);

                if (sub->left)
                    enqueue(q, sub->left);

                if (sub->right)
                    enqueue(q, sub->right);
            }
            cur_level++;
            dequeue(q);

            if (cur_level == depth)
                break;
        }
        delete_queue(q);
    } else if (depth) {
        node = create_node(val);
        node->left = root;
        root = node;
    }
    return root;
}
