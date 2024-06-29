/*
 * =====================================================================================
 *
 *       Filename:  700_search_in_a_binary_search_tree.c
 *
 *    Description:  Search in a binary tree  
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

NodePtr find_node(NodePtr root, int *find, int target) {

    NodePtr node = NULL;

    if (root) {

        if (root->val == target) {
            *find = 1;
            node = root;
        }

        if (!(*find))
            node = find_node(root->left, find, target);

        if (!(*find))
            node = find_node(root->right, find, target);
    }
    return node;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    int find = 0;
    return find_node(root, &find, val);
}

