/*
 * =====================================================================================
 *
 *       Filename:  1372_longest_zigzag_path_in_a_binary_tree.c
 *
 *    Description:  longest zigzag path in a binary tree
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

typedef enum {
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} DIRECTION_TYPE;  

typedef struct TreeNode *NodePtr;

static int count_zigzag_len(NodePtr node, DIRECTION_TYPE direction) {

    int count = 0;

    if (node) {

        count++;

        if (direction == DIRECTION_LEFT) {
            count += count_zigzag_len(node->right, DIRECTION_RIGHT);
        }

        if (direction == DIRECTION_RIGHT) {
            count += count_zigzag_len(node->left, DIRECTION_LEFT);
        }
    }
    return count;
}

int traversal(NodePtr root, int level, int *max) {

    int cur_left = 0, cur_right = 0;
    int lcount = 0, rcount = 0;
    int count = 0;

    if (root) {

        if (*max < level) {

            cur_left = count_zigzag_len(root->left, DIRECTION_LEFT); 
            cur_right = count_zigzag_len(root->right, DIRECTION_RIGHT); 

            count = cur_left > cur_right ? cur_left : cur_right;
            *max = *max > count ? *max : count;

            lcount = traversal(root->left, level-1, max); 
            rcount = traversal(root->right, level-1, max); 
        }
        count = lcount > rcount ? lcount : rcount; 
        *max = *max > count ? *max : count;
    }
    return *max;
}

static int get_height(NodePtr root) {

    int lheight = 0, rheight = 0;

    if (root) {
        lheight = get_height(root->left);
        rheight = get_height(root->right);
        return 1 + (lheight > rheight ? lheight : rheight);
    }
    return 0; 
}

int longestZigZag(struct TreeNode* root) {

    int height = 0;
    int max = 0;

    height = get_height(root);

    traversal(root, height-1, &max);
    return max;
}
