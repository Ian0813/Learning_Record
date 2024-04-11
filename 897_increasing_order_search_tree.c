/*
 * =====================================================================================
 *
 *       Filename:  897_increasing_order_search_tree.c
 *
 *    Description:  Increasing order search tree  
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

typedef struct TreeNode *NodePtr;

NodePtr create_skew_bst(NodePtr sroot, int value) {

    if (sroot == NULL) {
        sroot = (NodePtr) malloc(sizeof(struct TreeNode));
        sroot->left = sroot->right = NULL;
        sroot->val = value;
    } else if (sroot->val < value) {
        sroot->right = create_skew_bst(sroot->right, value);
    } else if (sroot->val >= value) {
        sroot->left = create_skew_bst(sroot->left, value);
    }

    return sroot;
}

NodePtr traversal(NodePtr root, NodePtr sroot) {

    if (root) {
        sroot = traversal(root->left, sroot);
        sroot = create_skew_bst(sroot, root->val);
        sroot = traversal(root->right, sroot);
    }
    return sroot;
}

struct TreeNode* increasingBST(struct TreeNode* root) {

    NodePtr sroot = NULL;
    sroot = traversal(root, sroot);

    return sroot;
}
