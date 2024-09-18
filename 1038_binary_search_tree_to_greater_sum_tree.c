/*
 * =====================================================================================
 *
 *       Filename:  1038_binary_search_tree_to_greater_sum_tree.c
 *
 *    Description:  binary search tree to greater sum tree.c
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

#define BUFFER_SIZE 101

static void inorder_collect(NodePtr root, int *values, int *index) {

    if (root) {
        inorder_collect(root->left, values, index);
        values[*index] = root->val;
        *index += 1;
        inorder_collect(root->right, values, index);
    }
    return;
}

static void inorder_sums(NodePtr root, int *values, int *index) {

    if (root) {
        inorder_sums(root->left, values, index);
        root->val = values[*index];
        *index += 1;
        inorder_sums(root->right, values, index);
    }
    return;
}

struct TreeNode* bstToGst(struct TreeNode* root) {

    int values[BUFFER_SIZE] = {0};
    int index = 0;

    if (root) {

        inorder_collect(root, values, &index);                 

        for (int i = index-1; i > 0; i--) {
            values[i-1] += values[i]; 
        }
        index = 0;

        inorder_sums(root, values, &index);
    }
    return root;
}
