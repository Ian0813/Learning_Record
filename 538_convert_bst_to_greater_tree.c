/*
 * =====================================================================================
 *
 *       Filename:  538_convert_bst_to_greater_tree.c
 *
 *    Description:  Convert bst to greater tree  
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

int get_nodeamount(struct TreeNode *root) {

    int lcount = 0, rcount = 0;

    if (root) {
        lcount = get_nodeamount(root->left);
        rcount = get_nodeamount(root->right);
        return 1 + lcount + rcount;
    }
    return 0;
}

void traversal(NodePtr root, NodePtr *ptrs, int *index) {

    if (root) {

        traversal(root->left, ptrs, index);

        ptrs[*index] = root;
        *index += 1;

        traversal(root->right, ptrs, index);
    }
    return;
}

struct TreeNode* convertBST(struct TreeNode* root) {

    int amount = 0, index = 0, sum = 0, aindex = 0;
    int *arr = NULL; 
    NodePtr *ptrs = NULL;

    amount = get_nodeamount(root);

    if (amount) {
        ptrs = (NodePtr *) calloc(amount, sizeof(NodePtr));
        arr = (int *) calloc(amount, sizeof(int));
    }

    if (ptrs) {

        traversal(root, ptrs, &index);

        for (int i = 0; i < index; i++) {
            arr[i] = ptrs[i]->val; 
        }

        for (int i = index - 2; i >= 0; i--) {

            sum += arr[i+1];

            if (ptrs[i]->val < arr[i+1]) {
                ptrs[i]->val += sum;
            }
        }
    }
    return root;
}

