/*
 * =====================================================================================
 *
 *       Filename:  404_sum_of_left_leaves.c
 *
 *    Description:  Sum of left leaves  
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

enum {LEFT, RIGHT, MIDDLE};
typedef struct TreeNode *TreePtr;

void dfs_sumleft(TreePtr root, int type, int *sum) {

    if (root != NULL) {

        dfs_sumleft(root->left, LEFT, sum);

        if (!root->left && !root->right)
            if (type == LEFT) {
                *sum = *sum + root->val;
            }

        dfs_sumleft(root->right, RIGHT, sum);
    }
    return;
}

int sumOfLeftLeaves(struct TreeNode* root) {

    int sum = 0; 
    dfs_sumleft(root, MIDDLE, &sum);

    return sum;
}

