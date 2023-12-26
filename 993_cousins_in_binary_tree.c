/*
 * =====================================================================================
 *
 *       Filename:  993_cousins_in_binary_tree.c
 *
 *    Description:  Cousins in binary tree
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

typedef unsigned int bool;
enum BOOL {false, true};
typedef struct TreeNode *NodePtr;

bool check_node(NodePtr root, int val) {

    bool rc = false;

    if (root != NULL) {
        if (root->val == val) {
            rc = true;
        }
        rc = rc == true ? rc : check_node(root->left, val);
        rc = rc == true ? rc : check_node(root->right, val);
    }
    return rc;
}

int get_height(NodePtr node, int val) {

    int lh = 0, rh = 0;

    if (node != NULL) {
        if (node->val != val) {
            if (check_node(node->left, val)) {
                lh = get_height(node->left, val);
                rh = get_height(node->right, val);
            } else if (check_node(node->right, val)) {
                lh = get_height(node->left, val);
                rh = get_height(node->right, val);
            } else {
                return 0;
            }
        }
        return 1 + (lh > rh ? lh : rh);
    }
    return 0;
}

NodePtr find_parent(NodePtr node, int val) {

    NodePtr temp = NULL;

    if (node != NULL) {
        if (node->left != NULL && node->left->val == val) {
            temp = node;
        } else if (node->right != NULL && node->right->val == val) {
            temp = node;
        }
        temp = temp == NULL ? find_parent(node->left, val) : temp;
        temp = temp == NULL ? find_parent(node->right, val) : temp;
    }
    return temp;
}

bool isCousins(struct TreeNode* root, int x, int y) {

    NodePtr xparent = NULL, yparent = NULL;
    int xheight = 0, yheight = 0;
    bool rc = false;

    if (root != NULL) {
        if ((root->val == x && x == y) || x == y) {
            rc = false;
        } else {
            if (root->left != NULL) {
                if (check_node(root->left, x)) {
                    xheight = get_height(root, x);
                    xparent = find_parent(root->left, x);
                }
                if (check_node(root->left, y)) {
                    yheight = get_height(root, y);
                    yparent = find_parent(root->left, y);
                }
            }

            if (root->right != NULL) {
                if (check_node(root->right, x)) {
                    xheight = get_height(root, x);
                    xparent = find_parent(root->right, x);
                }
                if (check_node(root->right, y)) {
                    yheight = get_height(root, y);
                    yparent = find_parent(root->right, y);
                }
            }
        }
    }

    if (xheight == yheight && yparent != xparent) {
        rc = true;
    }

    return rc;
}

int main(void) {
    return 0;
}
