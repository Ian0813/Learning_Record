/*
 * =====================================================================================
 *
 *       Filename:  2196_create_binary_tree_from_descriptions.c
 *
 *    Description:  Create binary tree from descriptions  
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
#include <limits.h>

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

#define TABLE_SIZE 100001
enum {
    PARENT_INDEX = 0,
    CHILD_INDEX,
    DIRECTION_INDEX,
};

typedef enum {
    RIGHT = 0,
    LEFT = 1,
} NODE_DIRECTION;

typedef struct TreeNode *NodePtr;

NodePtr create_node(int val) {

    NodePtr node = NULL;

    node = (NodePtr) malloc(sizeof(struct TreeNode));

    if (node) {
        node->left = node->right = NULL;
        node->val = val;
    }
    return node;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {

    NodePtr root = NULL, parent_node = NULL, child_node = NULL;
    NodePtr buffer[TABLE_SIZE] = {NULL};
    NODE_DIRECTION dir = RIGHT;
    int node_numbers = 0;
    int count = 0, parent_val = 0, child_val = 0, index = 0, flag = 1;

    if (descriptionsSize) {

        for (int i = 0; i < descriptionsSize; i++) {
            buffer[descriptions[i][CHILD_INDEX]] = create_node(descriptions[i][CHILD_INDEX]);
        }

        for (int i = 0; i < descriptionsSize; i++) {

            parent_node = buffer[descriptions[i][PARENT_INDEX]];
            if (!parent_node) {
                root = parent_node = create_node(descriptions[i][PARENT_INDEX]);
                buffer[descriptions[i][PARENT_INDEX]] = root;
            }
            child_node = buffer[descriptions[i][CHILD_INDEX]];

            if (descriptions[i][DIRECTION_INDEX] == RIGHT) {
                parent_node->right = child_node; 
            } else if (descriptions[i][DIRECTION_INDEX] == LEFT) {
                parent_node->left = child_node;
            }
        }
    }
    return root;
}
