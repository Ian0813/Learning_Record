/*
 * =====================================================================================
 *
 *       Filename:  109_sum_root_to_leaf_numbers.c
 *
 *    Description:  Sum root to leaf numbers
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

void get_height_of_node(TreePtr root, TreePtr node, int deep, int *height) {

    if (root != NULL && root != node) {

        deep += 1;
        if (root->left != NULL) {
            get_height_of_node(root->left, node, deep, height);
        }

        if (root->right != NULL) {
            get_height_of_node(root->right, node, deep, height);
        }

    } else if (root != NULL && root == node) {
        *height = deep + 1;
    }
    return;
}

int ten_to_power(int times) {

    int val = 1;

    while (times) {
        val *= 10;
        times--;
    }
    return val;
}

int check_val_in_range(TreePtr node, int val, TreePtr topmost) {

    int height = 0;
    int range = 0;

    get_height_of_node(topmost, node, 0, &height);

    if (!topmost->val)
        range = ten_to_power(height-1);
    else
        range = ten_to_power(height);

    while (val >= range) {
        val /= 10;
    }
    return val;
}

void sum_traversal(TreePtr root, int *sum, int *val, TreePtr topmost) {

    if (root != NULL) {
        if (root->left != NULL || root->right != NULL) {
            *val = (*val * 10) + root->val;
            sum_traversal(root->left, sum, val, topmost);
            val = check_val_in_range(root, *val, topmost); 
            sum_traversal(root->right, sum, val, topmost);
        } else {
            *sum = *sum + ((*val * 10) + root->val);
        }
    }    
    return;
}

int sumNumbers(struct TreeNode* root) {

    int sum = 0, val = 0;

    if (root != NULL) {

        val = root->val;
        if (root->left != NULL) {
            sum_traversal(root->left, &sum, &val, root);
        }

        val = root->val;
        if (root->right != NULL) {
            sum_traversal(root->right, &sum, &val, root);
        }

        if (!sum)
            sum = root->val;
    }
    return sum;
}

TreePtr create_bt(TreePtr root, int val) {

    if (root == NULL) {
        root = (TreePtr) malloc(sizeof(struct TreeNode));
        root->val = val;
        root->right = NULL;
        root->left = NULL;
    } else if (root->val >= val) {
        root->left = create_bt(root->left, val);
    } else if (root->val < val) {
        root->right = create_bt(root->right, val);
    }
    return root;
}

void in_order(TreePtr root) {

    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->val);
        in_order(root->right);
    }
    return;
}

void release(TreePtr root) {

    if (root != NULL) {
        release(root->left);
        release(root->right);
        free(root);
    }
    return;
}

int main(void) {

    int arr[10] = {35, 15, 14, 13, 12, 11, 77, 86, 83, 93};
    TreePtr root = NULL;
    int height = 0;

    //for (int i = 0; i < 6; i++) {
    //    arr[i] = rand()%100;
    //}

    for (int i = 0; i < 10; i++) {
        root = create_bt(root, arr[i]);    
    }

    in_order(root);
    putchar('\n');

    get_height_of_node(root, root->left->left->left->left->left, 0, &height);
    printf("height: %d\n", height);

    release(root);

    return EXIT_SUCCESS;
}
