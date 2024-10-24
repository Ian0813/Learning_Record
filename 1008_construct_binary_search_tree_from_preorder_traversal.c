/*
 * =====================================================================================
 *
 *       Filename:  1008_construct_binary_search_tree_from_preorder_traversal.c
 *
 *    Description:  construct binary search tree from preorder traversal
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

typedef struct TreeNode *NodePtr;

NodePtr bt_create(NodePtr root, int val) {

    if (!root) {
        root = (NodePtr) malloc(sizeof(*root));
        root->right = root->left = NULL;
        root->val = val;
    } else if (root->val < val) {
        root->right = bt_create(root->right, val);
    } else if (root->val > val) {
        root->left = bt_create(root->left, val);
    }
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {

    NodePtr root = NULL;

    if (preorderSize) {
        for (int i = 0; i < preorderSize; i++) {
            root = bt_create(root, preorder[i]);
        }
    }
    return root;
}
