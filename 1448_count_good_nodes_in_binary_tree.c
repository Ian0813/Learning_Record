/*
 * =====================================================================================
 *
 *       Filename:  1448_count_good_nodes_in_binary_tree.c
 *
 *    Description:  Count good nodes in binary tree  
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
#include <limits.h>

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

void count_gnode(NodePtr node, int *count, int max) {

    if (node) {

        if (node->val >= max) {
            *count += 1;
            max = node->val;
        }
        count_gnode(node->left, count, max);
        count_gnode(node->right, count, max);
    }
    return;
}


int goodNodes(struct TreeNode* root){

    int count = 0;

    if (root) {
        count_gnode(root, &count, INT_MIN);
    }
    return count;
}
