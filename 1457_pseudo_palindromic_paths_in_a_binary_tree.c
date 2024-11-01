/*
 * =====================================================================================
 *
 *       Filename:  1457_pseudo_palindromic_paths_in_a_binary_tree.c
 *
 *    Description:  pseudo palindromic paths in a binary tree
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

#define TABLE_SIZE 10 

typedef struct TreeNode *NodePtr; 

static void check_palindromic(NodePtr node, int bit_vector, int *counter) {

    if (node) {

        check_palindromic(node->left, (bit_vector ^ (1 << node->val)), counter);    
        check_palindromic(node->right, (bit_vector ^ (1 << node->val)), counter);    

        if (!node->left && !node->right) {
            bit_vector ^= (1 << node->val); 
            if (!(bit_vector & (bit_vector-1))) {
                *counter += 1;
            }
        }
    }
    return;
}

int pseudoPalindromicPaths (struct TreeNode* root) {

    int bit_vector = 0;
    int counter = 0;

    if (root) {
        check_palindromic(root, bit_vector, &counter);
    }
    return counter;
}
