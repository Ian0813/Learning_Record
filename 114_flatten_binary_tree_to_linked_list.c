/*
 * =====================================================================================
 *
 *       Filename:  114_flatten_binary_tree_to_linked_list.c
 *
 *    Description:  Flatten binary tree to linked list  
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

enum NODE_TYPE {
    LEFT,
    MIDDLE,
    RIGHT
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *bt_merge_after(struct TreeNode *left, struct TreeNode *right) {

    struct TreeNode *temp = left;

    if (left) {
        while (temp->right)
            temp = temp->right;
        temp->right = right;
    } else {
        left = right;
    }
    return left;
}

void bt_toright(struct TreeNode *root) {

    if (root) {

        if (root->left)
            bt_toright(root->left);
        
        if (root->right) 
            bt_toright(root->right);

        root->right = bt_merge_after(root->left, root->right);
        root->left = NULL;
    }
    return;
}

void flatten(struct TreeNode* root) {

    if (root) {
        bt_toright(root);
    }
    return;
}
