/*
 * =====================================================================================
 *
 *       Filename:  814_binary_tree_pruning.c
 *
 *    Description:  Binary Tree Pruning  
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

/* depth first search */
NodePtr dfs(NodePtr root) {

    if (root != NULL) {

        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if (!root->left && !root->right) {
            if (!root->val) {
                free(root);
                root = NULL;
            }
        }
    }
    return root;
}

struct TreeNode* pruneTree(struct TreeNode* root) {
    return dfs(root);
}
