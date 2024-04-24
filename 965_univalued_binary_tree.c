/*
 * =====================================================================================
 *
 *       Filename:  965_univalued_binary_tree.c
 *
 *    Description:  Univalued binary tree  
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

bool inorder(struct TreeNode *root, int value) {

    bool rc = true;

    if (root) {
        rc = rc == true ? inorder(root->left, value) : rc;
        if (root->value != value) {
            return false;        
        }
        rc = rc == true ? inorder(root->right, value) : rc;
    }

    return rc;
}

bool isUnivalTree(struct TreeNode* root) {

    int value = 0;
    bool rc = true;

    if (root) {
        rc = inorder(root, root->val);
    }

    return rc;
}
