/*
 * =====================================================================================
 *
 *       Filename:  654_maximum_binary_tree.c
 *
 *    Description:  Maximum binary tree  
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

#define MAX_NODES 1001
typedef struct TreeNode *NodePtr;

int find_maxindex(int *nums, int start, int end, int *table) {

    int max = -1, index = 0;

    for (int i = start; i <= end; i++) {
        if (nums[i] > max && !table[i]) {
            max = nums[i];
            index = i;
        }
    }
    return index;
}

NodePtr node_append(int val) {

    NodePtr node = NULL;

    node = (NodePtr) malloc(sizeof(struct TreeNode)); 
    node->val = val; 
    node->left = node->right = NULL;
    return node;
}

NodePtr get_maxbst(int *nums, int start, int end, NodePtr root, int *table) {

    int index = 0;

    if (start <= end) {

        index = find_maxindex(nums, start, end, table);

        if (!table[index]) {
            root = node_append(nums[index]);
            table[index] = 1;
            root->left = get_maxbst(nums, 0, index-1, root->left, table);
            root->right = get_maxbst(nums, index+1, end, root->right, table);
        }
    }
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {

    int max_index = 0;
    int table[MAX_NODES] = {0};
    NodePtr root = NULL;

    if (numsSize) {
        root = get_maxbst(nums, 0, numsSize-1, root, table);
    }
    return root;
}
