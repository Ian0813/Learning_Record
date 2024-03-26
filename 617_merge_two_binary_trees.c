/*
 * =====================================================================================
 *
 *       Filename:  617_merge_two_binary_trees.c
 *
 *    Description:  Merge two binary trees  
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

typedef struct TreeNode *TreePtr;

TreePtr merge(TreePtr root1, TreePtr root2) {

    int both_status = (root1 && root2);

    if (both_status) {
        root1->val += root2->val;
    }

    if (both_status && root1->left && root2->left) {
        root1->left = merge(root1->left, root2->left);
    } else if (root1 && root1->left) {
        root1->left = merge(root1->left, NULL);
    } else if (root2 && root2->left) {
        root1->left = root2->left;
    }

    if (both_status && root1->right && root2->right) {
        root1->right = merge(root1->right, root2->right);
    } else if (root1 && root1->right) {
        root1->right = merge(root1->right, NULL);
    } else if (root2 && root2->right) {
        root1->right = root2->right;
    }

    return root1;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {

    TreePtr result = NULL;

    if (root1 && root2) {
        result = merge(root1, root2);
    } else if (root1) {
        result = root1; 
    } else {
        result = root2;   
    }

    return root1;
}
