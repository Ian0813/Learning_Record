/*
 * =====================================================================================
 *
 *       Filename:  1325_delete_leaves_with_a_given_value.c
 *
 *    Description:  Delete leaves with a given value  
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

NodePtr target_delete(struct TreeNode *node, int target) {

    if (node != NULL) {

        node->left = target_delete(node->left, target);
        node->right = target_delete(node->right, target);

        if (!node->left && !node->right) {
            if (node->val == target) {
                free(node);
                node = NULL;
            }
        }

    }
    return node;
}

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    return target_delete(root, target);
}

