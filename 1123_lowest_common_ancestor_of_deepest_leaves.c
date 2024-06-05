/*
 * =====================================================================================
 *
 *       Filename:  1123_lowest_common_ancestor_of_deepest_leaves.c
 *
 *    Description:  Lowest common ancestor of deepest leaves  
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

#define MAX(a, b) (a > b ? a : b)
typedef struct TreeNode *NodePtr;

int get_height(NodePtr root) {

    int lh = 0, rh = 0;

    if (root) {

        lh = get_height(root->left);
        rh = get_height(root->right);
        return 1 + MAX(lh, rh);
    }
    return 0;
}

void get_lcanode(NodePtr root, NodePtr *lca_node, int count, int height) {

    int lh = 0, rh = 0;

    if (root) {

        get_lcanode(root->left, lca_node, count+1, height);
        get_lcanode(root->right, lca_node, count+1, height);

		if (root->left)
            lh = get_height(root->left);

		if (root->right)
            rh = get_height(root->right);

        if (count == height) {
            *lca_node = root;
        }

		if ((lh+count) == height && (rh+count) == height) {
            *lca_node = root; 
		}
    }
    return;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {

    int height = 0;
    NodePtr lca_node = NULL; 

    if (root) {
        height = get_height(root);
        get_lcanode(root, &lca_node, 0, height);
    }
    return lca_node;
}
