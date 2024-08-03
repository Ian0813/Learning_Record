/*
 * =====================================================================================
 *
 *       Filename:  701_insert_into_a_binary_search_tree.c
 *
 *    Description:  Insert into a binary search tree  
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

NodePtr create_node(int val) {

    NodePtr node = NULL;

    node = (NodePtr) malloc(sizeof(struct TreeNode));

    if (node) {
        node->right = node->left = NULL;
        node->val = val;
    }
    return node;
}

void insert(NodePtr root, int val) {

    if (root) {
        if (root->val < val) {
            if (root->right) {
                insert(root->right, val);
            } else {
                root->right = create_node(val);
            }
        } else if (root->val > val) {
            if (root->left) {
                insert(root->left, val);
            } else {
                root->left = create_node(val);
            }
        }
    }
    return;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root)
        insert(root, val);
    else
        root = create_node(val);
    return root;
}

