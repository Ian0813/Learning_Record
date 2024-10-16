/*
 * =====================================================================================
 *
 *       Filename:  1382_balance_a_binary_search_tree.c
 *
 *    Description:  balance a binary search tree.c
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

static int get_amount(NodePtr root) {

    int amount = 0;

    if (root) {
        amount += get_amount(root->left);
        amount += get_amount(root->right);
        return 1 + amount;
    }
    return amount;
}

static void bt_to_arr(NodePtr root, int *arr, int *index) {

    if (root) {
        bt_to_arr(root->left, arr, index);
        arr[*index] = root->val;
        *index += 1;
        bt_to_arr(root->right, arr, index);
    }
    return;
}

static void get_balance_seq(int *arr, int low, int high, int *seq, int *sindex) {

    int middle = (low+high)/2;

    if (low <= high) {

        seq[*sindex] = arr[middle];
        *sindex += 1;
        get_balance_seq(arr, low, middle-1, seq, sindex);
        get_balance_seq(arr, middle+1, high, seq, sindex); 
    }
    return;
}

NodePtr create_binary_tree(NodePtr root, int val) {

    if (!root) {
        root = (NodePtr) malloc(sizeof(*root));
        root->left = root->right = NULL;
		root->val = val;
    } else if (root->val >= val) {
        root->left = create_binary_tree(root->left, val);
    } else {
        root->right = create_binary_tree(root->right, val);
    }
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {

    int amount = 0;
    int *arr = NULL, *seq = NULL;
    int index = 0, sindex = 0;
    NodePtr result = NULL;

    if (root) {

        amount = get_amount(root);
        arr = (int *) calloc(amount, sizeof(int));
        seq = (int *) calloc(amount, sizeof(int));

        bt_to_arr(root, arr, &index);
        get_balance_seq(arr, 0, amount-1, seq, &sindex);

        for (int i = 0; i < sindex; i++) {
            result = create_binary_tree(result, seq[i]);
            //printf("%d ", seq[i]);
        }
        //putchar('\n');
        free(arr);
        free(seq);
    }
    return result;
}
