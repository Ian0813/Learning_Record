/*
 * =====================================================================================
 *
 *       Filename:  563_binary_tree_tilt.c
 *
 *    Description:  Binary tree tilt  
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

int get_node_amount(NodePtr root) {

    int count = 0;

    if (root) {
        count++;
        count += get_node_amount(root->left);
        count += get_node_amount(root->right);
    }
    return count;
}

int get_tree_sum(NodePtr node) {

    int sum = 0;
    int lsum = 0, rsum = 0;

    if (node) {

        sum = node->val;
        sum += get_tree_sum(node->left);
        sum += get_tree_sum(node->right);

        return sum;
    }
    return sum;
}

void get_tiltval(NodePtr root, int *arr, int *index) {

    int lsum = 0, rsum = 0;
    
    if (root) {

        if (root->left)
            lsum = get_tree_sum(root->left); 

        if (root->right)
            rsum = get_tree_sum(root->right);

        arr[*index] = (lsum-rsum) < 0 ? -(lsum-rsum) : (lsum-rsum);   
        *index += 1;
    }
    return;
}

void traverse_nodes(NodePtr root, int *arr, int *index) {

    if (root) {
        traverse_nodes(root->left, arr, index);
        traverse_nodes(root->right, arr, index);
        get_tiltval(root, arr, index);
    }
    return;
}

int findTilt(struct TreeNode* root) {

    int *arr = NULL, index = 0;
    int tilt = 0;

    if (root) {
        
        arr = (int *) calloc(get_node_amount(root), sizeof(int));
        
        traverse_nodes(root, arr, &index);

        for (int i = 0; i < index; i++) {
            tilt += arr[i];
        }

    }
    return tilt;
}
