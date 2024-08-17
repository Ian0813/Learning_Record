/*
 * =====================================================================================
 *
 *       Filename:  2024_08_17_leaf_similar_trees.c
 *
 *    Description:  leat similar trees  
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

void collect_leafs(NodePtr node, NodePtr *leafs, int *index) {

    if (node) {
        collect_leafs(node->left, leafs, index);
        collect_leafs(node->right, leafs, index);

        if (!node->left && !node->right) {
            leafs[*index] = node;
            *index += 1;
        }
    }
    return;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {

    NodePtr leafs1[BUFSIZ] = {NULL}, leafs2[BUFSIZ] = {NULL};
    int index = 0, leafs1_size = 0, leafs2_size = 0;
    bool rc = true;

    collect_leafs(root1, leafs1, &index);
    leafs1_size = index;
    index = 0;

    collect_leafs(root2, leafs2, &index);
    leafs2_size = index ;

    if (leafs2_size == leafs1_size) {
        for (int i = 0; i < leafs1_size; i++) {
            if (leafs1[i]->val != leafs2[i]->val) {
                rc = false;
                break;
            }
        }
    } else {
        rc = false;
    }
    return rc;
}
