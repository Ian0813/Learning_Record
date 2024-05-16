/*
 * =====================================================================================
 *
 *       Filename:  173_binary_search_tree_iterator.c
 *
 *    Description:  Binary search tree iterator  
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

struct stack {
    bool (*push)(struct stack *s, NodePtr node);
    bool (*pop)(struct stack *s);
    bool (*isempty)(struct stack *s);
    bool (*isfull)(struct stack *s);
    NodePtr (*peek)(struct stack *s);
    NodePtr *buffer;
    int top;
    int max;
};

bool push(struct stack *s, NodePtr node) {

    bool rc = true;

    if (s->top < s->max) {
        s->buffer[s->top++] = node;         
    } else {
        rc = false;
    }
    return rc;
}

bool pop(struct stack *s) {

    bool rc = true;

    if (s->top > 0) {
        s->top--;
    } else {
        rc = false;
    }
    return rc;
}

bool isempty(struct stack *s) {

    bool rc = true;

    if (s->top) {
        rc = false;
    }
    return rc;
}

bool isfull(struct stack *s) {

    bool rc = true;

    if (s->top < s->max) {
        rc = false;
    }
    return rc;
}

NodePtr peek(struct stack *s) {

    if (!isempty(s)) {
        return s->buffer[s->top-1];
    }
    return NULL;
}    

struct stack *stack_create(int amount) {

    struct stack *s = NULL;

    s = (struct stack *) malloc(sizeof(struct stack));

    if (s) {
        s->buffer = (NodePtr *) calloc(amount, sizeof(NodePtr));
        s->max = amount;
        s->push = push;
        s->pop = pop;
        s->isempty = isempty;
        s->isfull = isfull;
		s->peek = peek;
        s->top = 0;
    }
    return s;
}    

static void get_nodeamount(NodePtr root, int *amount) {

    if (root) {
        *amount += 1;        
        get_nodeamount(root->left, amount);
        get_nodeamount(root->right, amount);
    } 
    return; 
}

typedef struct {
    struct stack *s;
    NodePtr root;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {

    BSTIterator *bst_iter = NULL; 
    int amount = 0;

    bst_iter = (BSTIterator *) malloc(sizeof(BSTIterator)); 
    get_nodeamount(root, &amount);

    if (bst_iter) {
        bst_iter->root = root;
        bst_iter->s = stack_create(amount);
    }
    return bst_iter;
}

int bSTIteratorNext(BSTIterator* obj) {

    NodePtr node = NULL;

    if (obj) {

        if (obj->root) {
            do {

                obj->s->push(obj->s, obj->root);

                if (obj->root->left) {
                    obj->root = obj->root->left;
                } else {
                    obj->root = NULL;    
                }
            } while (obj->root);
        }

        node = obj->s->peek(obj->s); 
        if (node && node->right)
            obj->root = node->right;
        obj->s->pop(obj->s);
    }
    return node->val; 
}

bool bSTIteratorHasNext(BSTIterator* obj) {

    bool rc = true;

    if (obj->s->isempty(obj->s) &&!obj->root) {
        rc = false;
    }
    return rc;
}

void bSTIteratorFree(BSTIterator* obj) {

    if (obj) {
        free(obj->s->buffer);
        free(obj->s);
        free(obj);
    }
    return;
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/

