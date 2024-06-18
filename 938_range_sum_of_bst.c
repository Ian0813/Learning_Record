/*
 * =====================================================================================
 *
 *       Filename:  938_range_sum_of_bst.c
 *
 *    Description:  Range sum of bst  
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

void get_range_sum(NodePtr node, int low, int high, int *result) {

    if (node) {

        if (node->val >= low && node->val <= high) {
            (*result) += node->val; 
        }
        get_range_sum(node->left, low, high, result);
        get_range_sum(node->right, low, high, result);
    }
    return;
}

int rangeSumBST(struct TreeNode* root, int low, int high) {

    int result = 0;
    get_range_sum(root, low, high, &result);
    return result;
}

