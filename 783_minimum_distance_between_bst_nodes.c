/*
 * =====================================================================================
 *
 *       Filename:  783_minimum_distance_between_bst_nodes.c
 *
 *    Description:  Minimum distance between bst nodes  
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

#define MAX 100001

void in_order(struct TreeNode *root, int *arr, int *index) {

    if (root != NULL) {
        in_order(root->left, arr, index);
        arr[(*index)++] = root->val;
        in_order(root->right, arr, index);
    }
    return;
}

int minDiffInBST(struct TreeNode* root) {

    int arr[MAX] = {0};    
    int index = 0;
    int diff = MAX;

    in_order(root, arr, &index);

    for (int i = 1; i < index; i++) {
        if (arr[i] - arr[i-1] < diff) {
            diff = arr[i] - arr[i-1]; 
        }    
    }
    return diff;
}
