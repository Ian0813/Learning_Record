/*
 * =====================================================================================
 *
 *       Filename:  889_construct_binary_tree_from_preorder_and_postorder_traversal.c
 *
 *    Description:  construct binary tree from preorder and postorder traversal
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <sys/param.h>

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

#define MAXIMUM_BOUNDARY 10000000
#define GET_LEFT_INDEX(index) (((index) * 2) + 1)
#define GET_RIGHT_INDEX(index) (((index) * 2) + 2)

typedef enum {
    NODE_LEFT = 0, 
    NODE_RIGHT = 1, 
} node_type;

typedef struct TreeNode *NodePtr;

static NodePtr btree_allocate(unsigned int size) {

    if (!size)
        return NULL;

    NodePtr nodes = NULL; 

    nodes = calloc(size, sizeof(struct TreeNode));

    return nodes;
}

static int get_child_node(int *arr, int arrlen, int pvalue, node_type type) {

    int value = -1, index = -1;

    for (int i = 0; i < arrlen; i++) {
        if (pvalue == arr[i]) {
            index = i; 
            break;
        } }

    if (index != -1) {
        if (type == NODE_LEFT && (index+1) < arrlen) {
            value = arr[index+1]; 
        } else if (type == NODE_RIGHT && (index)) {
            value = arr[index-1]; 
        }
    }
    return value;
}

static void btree_construct(int *preorder, int *postorder, int pvalue, NodePtr nodes, int *vtable, int val_size, int total_len, int nindex) {

    int lindex = 0, rindex = 0, lvalue = 0, rvalue = 0, lflag = 0, rflag = 0;

    lindex = GET_LEFT_INDEX(nindex);
    rindex = GET_RIGHT_INDEX(nindex);

    if (lindex < total_len) {

        lvalue = get_child_node(preorder, val_size, pvalue, NODE_LEFT);

        if (lvalue != -1 && vtable[lvalue]) {
            vtable[lvalue] = 0;     
            lflag = 1;
        }
    }

    if (rindex < total_len) {

        rvalue = get_child_node(postorder, val_size, pvalue, NODE_RIGHT);

        if (rvalue != -1 && vtable[rvalue]) {
            vtable[rvalue] = 0;     
            rflag = 1;
        }
    }

    if (lflag) {
        nodes[nindex].left = &nodes[lindex]; 
        nodes[lindex].val = lvalue; 
        nodes[lindex].left = nodes[lindex].right = NULL; 
        btree_construct(preorder, postorder, lvalue, nodes, vtable, val_size, total_len, lindex);
    }

    if (rflag) {
        nodes[nindex].right = &nodes[rindex];
        nodes[rindex].val = rvalue;
        nodes[rindex].left = nodes[rindex].right = NULL; 
        btree_construct(preorder, postorder, rvalue, nodes, vtable, val_size, total_len, rindex);
    }
    return;
}

static void traversal_preorder(NodePtr node) {
    if (node) {
        printf("%d ", node->val);
        traversal_preorder(node->left);
        traversal_preorder(node->right);
    }
    return;
}

static void vtable_marker(int *table, int *arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        table[arr[i]] = 1; 
    }
    return;
}

static int power_of_2(int exp) {

    int val = 1;

    if (!exp) {
        return 1;
    }
    return 2 * power_of_2(exp-1);
}

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {

    NodePtr nodes = NULL;    
    int vtable[MAXIMUM_BOUNDARY] = {0};
    unsigned int maximum_space = 0;

    if (preorderSize) {
        maximum_space = power_of_2(preorderSize); 
        maximum_space = MIN(MAXIMUM_BOUNDARY, maximum_space);
        vtable_marker(vtable, preorder, preorderSize);
        nodes = btree_allocate((uint32_t) maximum_space);
        nodes[0].val = preorder[0];
        nodes[0].left = nodes[0].right = NULL;
        btree_construct(preorder, postorder, preorder[0], nodes, vtable, preorderSize, maximum_space, 0);
    }
    return nodes;
}
