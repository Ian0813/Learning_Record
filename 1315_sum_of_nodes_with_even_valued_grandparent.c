/*
 * =====================================================================================
 *
 *       Filename:  1315_sum_of_nodes_with_even_valued_grandparent.c
 *
 *    Description:  sum of nodes with even valued grandparent
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

#define TABLE_SIZE 101

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define TABLE_SIZE 101

typedef struct TreeNode *NodePtr;

static void traverse_sum(NodePtr node, NodePtr parent, NodePtr grandpa, int depth, int *sum, int *table) {

    if (node) {

        if (depth == 1) {
            traverse_sum(node->left, node, NULL, depth+1, sum, table);
            traverse_sum(node->right, node, NULL, depth+1, sum, table);
        } else {
            traverse_sum(node->left, node, parent, depth+1, sum, table);
            traverse_sum(node->right, node, parent, depth+1, sum, table);
        }

        if (depth > 2) {
            if (!(grandpa->val%2)) {
                *sum += node->val;
            }
        }
    }
    return;
}

int sumEvenGrandparent(struct TreeNode* root) {

    int grandpa_table[TABLE_SIZE] = {0};
    int sum = 0;

    if (root) {
        traverse_sum(root, NULL, NULL, 1, &sum, grandpa_table);
    }
    return sum;
}
