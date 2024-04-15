/*
 * =====================================================================================
 *
 *       Filename:  1367_linked_list_in_binary_tree.c
 *
 *    Description:  Linked list in binary tree  
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct ListNode *NodePtr;
typedef struct TreeNode *TreePtr;

bool is_equal(TreePtr tnode, NodePtr node) {

    bool result = true;

    if (node && tnode) {

        if (tnode->val == node->val) {

            result = is_equal(tnode->left, node->next);

            result = result == true ? result : is_equal(tnode->right, node->next);

        } else {
            result = false;
        }

    } else if (!tnode) {
        result = false;
    }
    return result;
}

bool preorder_compare(TreePtr root, NodePtr head) {

    bool result = false;

    if (root && head) {

        result = is_equal(root, head);

        result = result == true ? result : preorder_compare(root->left, head);

        result = result == true ? result : preorder_compare(root->right, head);
    }
    return result;
}    

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    return preorder_compare(root, head);
}
