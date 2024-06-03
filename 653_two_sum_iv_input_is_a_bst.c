/*
 * =====================================================================================
 *
 *       Filename:  653_two_sum_iv_input_is_a_bst.c
 *
 *    Description:  Two sum iv input is a bst  
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

int count_nodes(struct TreeNode *root) {

    int lcount = 0, rcount = 0;

    if (root) {
        lcount = count_nodes(root->left);
        rcount = count_nodes(root->right);
        return 1 + lcount + rcount;
    }
    return 0; 
}

void get_treenodes(struct TreeNode *root, int *tree_nodes, int *index) {

    if (root) {

        tree_nodes[*index] = root->val;
        *index += 1;

        get_treenodes(root->left, tree_nodes, index);
        get_treenodes(root->right, tree_nodes, index);
    }
    return;
}

bool findTarget(struct TreeNode* root, int k) {

    int *tree_nodes = NULL, *difference = 0;
    int node_number = 0, index = 0;
    bool rc= false;

    if (root) {

        node_number = count_nodes(root);

        if (node_number < 1)
            return rc;

        tree_nodes = (int *) calloc(node_number, sizeof(int));
        difference = (int *) calloc(node_number, sizeof(int));
        get_treenodes(root, tree_nodes, &index);

        for (int i = 0; i < index; i++) {
            difference[i] = k - tree_nodes[i];
        }

        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                if (difference[i] == tree_nodes[j] && i != j) {
                    rc = true;
                    break;
                }
            }
            if (rc)
                break; 
        }
        free(tree_nodes);
        free(difference);
    }
    return rc;
}
