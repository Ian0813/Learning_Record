/*
 * =====================================================================================
 *
 *       Filename:  98_validate_binary_search_tree.c
 *
 *    Description:  Validate binary tree  
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

typedef struct TreeNode *TreePtr;
typedef unsigned int bool;

#define true 1
#define false 0

#define IS_NULL(node) (node == NULL ? 1 : 0) 

bool rvalidate(TreePtr node, int val) {

    bool rc = true;

    if (!IS_NULL(node)) {
        if (node->val <= val) {
            return false; 
        }
        rc = rc == true ? rvalidate(node->left, val) : rc;
        rc = rc == true ? rvalidate(node->right, val) : rc;
    }
    return rc;
}

bool lvalidate(TreePtr node, int val) {

    bool rc = true;

    if (!IS_NULL(node)) {
        if (node->val >= val) {
            return false;
        }
        rc = rc == true ? lvalidate(node->left, val) : rc;
        rc = rc == true ? lvalidate(node->right, val) : rc;
    }
    return rc;
}

bool traversal(TreePtr node) {

    bool rc = true;

    if (!IS_NULL(node)) {
        rc = rc == true ? lvalidate(node->left, node->val) : rc;
        rc = rc == true ? rvalidate(node->right, node->val) : rc;
        rc = rc == true ? traversal(node->left) : rc;
        rc = rc == true ? traversal(node->right) : rc;
    }
    return rc;
}

bool isValidBST(struct TreeNode* root) {
    return traversal(root);
}

int main(void) {
    return 0;
}
