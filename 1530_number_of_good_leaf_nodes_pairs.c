/*
 * =====================================================================================
 *
 *       Filename:  1530_number_of_good_leaf_nodes_pairs.c
 *
 *    Description:  Number of good leaf nodes pairs   *
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

#define IS_LEAF(node) ((!node->left && !node->right) ? true : false)
typedef struct TreeNode *NodePtr;

void collect_leafs(NodePtr node, NodePtr *buffer, int *index) {

    if (node) {

        collect_leafs(node->left, buffer, index);
        collect_leafs(node->right, buffer, index);

        if (IS_LEAF(node)) {
            buffer[*index] = node;
            *index += 1;
        }
    }    
    return;
}

void get_length(NodePtr node, NodePtr leaf, int *find, int *len) {

    if (node) {

        if (!(*find)) {
            get_length(node->left, leaf, find, len); 
        }

        if (!(*find)) {
            get_length(node->right, leaf, find, len); 
        }

        if (*find) {
            *len += 1;
        }

        if (node == leaf) {
            *find = 1;
        }
    }
    return;
}

void check_pairs(NodePtr node, int *count, int distance) {

    NodePtr lleafs[BUFSIZ] = {NULL}, rleafs[BUFSIZ] = {NULL};
    int left_lengths[BUFSIZ] = {0}, right_lengths[BUFSIZ] = {0};
    int lindex = 0, rindex = 0, llen_index = 0, rlen_index = 0, find = 0, len = 0;

    collect_leafs(node->left, lleafs, &lindex);
    collect_leafs(node->right, rleafs, &rindex);

    printf("[%s] node: %d\n", __func__, node->val);

    for (int i = 0; i < lindex; i++) {
        get_length(node, lleafs[i], &find, &len);
        left_lengths[llen_index++] = len;
        find = len = 0;
    }

    for (int i = 0; i < rindex; i++) {
        get_length(node, rleafs[i], &find, &len);
        right_lengths[rlen_index++] = len;
        find = len = 0;
    }

    if (llen_index && rlen_index) {
        for (int i = 0; i < llen_index; i++) {
            for (int j = 0; j < rlen_index; j++) {
                if ((left_lengths[i]+right_lengths[j]) <= distance) {
                    *count += 1;
                }
            }
        }
    }
    return;
}

void traversal(NodePtr root, int *count, int distance) {

    if (root && !IS_LEAF(root)) {
        check_pairs(root, count, distance);
        traversal(root->left, count, distance);
        traversal(root->right, count, distance);
    }
    return;
}

int countPairs(struct TreeNode* root, int distance) {

    int count = 0;

    traversal(root, &count, distance);

    return count;
}
