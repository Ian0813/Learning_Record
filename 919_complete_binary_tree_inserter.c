/*
 * =====================================================================================
 *
 *       Filename:  919_complete_binary_tree_inserter.c
 *
 *    Description:  Complete binary tree inserter  
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
    NodePtr *buffer;
    int windex;
    int rindex;
    int size;
};

Queue create_queue(int size) {

    Queue q = NULL;

    if (size) {
        q = (Queue) malloc(sizeof(struct queue));

        if (q) {
            q->buffer = (NodePtr *) calloc(size, sizeof(NodePtr));
            q->windex = q->rindex = 0;
            q->size = size;
        }
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

void deep_dequeue(Queue q) {
    while (q->rindex != q->windex) {
        q->rindex++;
        q->rindex %= q->size;
    }
    return;
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

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}

typedef struct {
    NodePtr root;
    Queue q;
} CBTInserter;

CBTInserter* cBTInserterCreate(struct TreeNode* root) {

    CBTInserter *obj = NULL;

    obj = (CBTInserter *) malloc(sizeof(CBTInserter));

    if (obj) {
        obj->root = root;
        obj->q = create_queue(BUFSIZ);
    }
    return obj;
}

int cBTInserterInsert(CBTInserter* obj, int val) {

    NodePtr new_node = NULL, temp = NULL;
    int flag = 0;
    int inode_parent = 0;

    new_node = (NodePtr) malloc(sizeof(struct TreeNode));

    if (new_node) {
        new_node->val = val;
        new_node->left = new_node->right = NULL; 
    }

    if (obj->root) {

        enqueue(obj->q, obj->root);

        while ((temp = peek(obj->q)) != NULL) {

            enqueue(obj->q, NULL);

            while ((temp = peek(obj->q)) != NULL) {

                dequeue(obj->q);

                if (!temp->left) {
                    inode_parent = temp->val;
                    temp->left = new_node;
                    flag = 1;
                    break;
                } else if (!temp->right) {
                    inode_parent = temp->val;
                    temp->right = new_node; 
                    flag = 1;
                    break;
                }                    

                enqueue(obj->q, temp->left);
                enqueue(obj->q, temp->right);
            }
            if (flag)
                break;
            dequeue(obj->q);
        }
    } else {
        obj->root = new_node;
        inode_parent = obj->root->val;
    }

    deep_dequeue(obj->q);

    return inode_parent; 
}

struct TreeNode* cBTInserterGet_root(CBTInserter* obj) {
    if (obj) {
        return obj->root;
    }
    return NULL;
}

void cBTInserterFree(CBTInserter* obj) {

    if (obj) {
        delete_queue(obj->q);        
        free(obj);
    }
    return;
}

/**
 * Your CBTInserter struct will be instantiated and called as such:
 * CBTInserter* obj = cBTInserterCreate(root);
 * int param_1 = cBTInserterInsert(obj, val);

 * struct TreeNode* param_2 = cBTInserterGet_root(obj);

 * cBTInserterFree(obj);
*/

