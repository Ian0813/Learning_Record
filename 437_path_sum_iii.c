/*
 * =====================================================================================
 *
 *       Filename:  437_path_sum_iii.c
 *
 *    Description:  Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 *                  The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
static bool isequal(long long v1, long long v2) {
    return v1 == v2;
}

void count_target(struct TreeNode *root, int targetSum, int *counter, long long carryin) {

    if (root) {

        if (isequal(root->val+carryin, targetSum)) {
            *counter += 1;    
        }

        carryin += root->val;

        if (root->left)
            count_target(root->left, targetSum, counter, carryin);

        if (root->right)
            count_target(root->right, targetSum, counter, carryin);
    }
    return;
}

void traverse(struct TreeNode *root, int targetSum, int *counter) {

    if (root) {
        count_target(root, targetSum, counter, 0);

        if (root->left)
            traverse(root->left, targetSum, counter);

        if (root->right) 
            traverse(root->right, targetSum, counter);
    }
    return; 
}

int pathSum(struct TreeNode* root, int targetSum) {

    int counter = 0;

    traverse(root, targetSum, &counter);
    return counter;
}
