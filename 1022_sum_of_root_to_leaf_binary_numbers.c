/*
 * =====================================================================================
 *
 *       Filename:  1022_sum_of_root_to_leaf_binary_numbers.c
 *
 *    Description:  Sum of root to leaf binary numbers  
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

void traversal_sum(NodePtr root, int sum, int *summary) {

    if (root) {

        sum = (2 * sum + root->val);

        traversal_sum(root->left, sum, summary);
        traversal_sum(root->right, sum, summary);

        if (!root->left && !root->right) {
            *summary += sum;
        }
    }
    return;
}

int sumRootToLeaf(struct TreeNode* root) {
    
    int summary = 0;
    traversal_sum(root, 0, &summary);

    return summary;
}
