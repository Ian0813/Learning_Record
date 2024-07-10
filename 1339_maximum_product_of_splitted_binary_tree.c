/*
 * =====================================================================================
 *
 *       Filename:  1339_maximum_product_of_splitted_binary_tree.c
 *
 *    Description:  Maximum product of splitted binary tree  
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

#define TEST_NODES 5 

typedef enum {false, true} bool;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode *NodePtr;

NodePtr append_node(NodePtr node, int value) {
    if (!node) {
        node = (NodePtr) malloc(sizeof(struct TreeNode));
        node->val = value;
        node->left = node->right = NULL;
    } else {
        if (node->val >= value) {
            node->left = append_node(node->left, value); 
        } else {
            node->right = append_node(node->right, value); 
        }
    }
    return node;
}

void release_node(NodePtr node) {

    if (node) {
        release_node(node->left);
        release_node(node->right);
        free(node);
    }
    return;
}

void post_order(NodePtr root, int *arr, int *index) {

    if (root) {
        post_order(root->left, arr, index);
        post_order(root->right, arr, index);

        if (root->left)
            root->val += root->left->val;
        if (root->right)
            root->val += root->right->val;
        arr[*index] = root->val;
        *index += 1;
    }
    return;
}

bool handle_largeval(unsigned long long a, unsigned long long b, unsigned long long *last, int *product) {

    if ((a*b) > INT_MAX || *last) {
        if ((a*b) > *last) {
            *last = (a*b);
            *product = (int) ((*last)%(1000000000+7));
        }
        return true;
    }
    return false;
}

int maxProduct(struct TreeNode* root) {

    int arr[100000] = {0};
    int index = 0;
    int root_sum = 0, product = 0;
    int maximum_product = 0;
    unsigned long long last = 0LLU;

    post_order(root, arr, &index);

    root_sum = arr[index-1];
    index -= 1;

    for (int i = 0; i < index; i++) {
        if (handle_largeval((root_sum-arr[i]), arr[i], &last, &product) || (product = (root_sum - arr[i]) * arr[i]) > maximum_product) {
            maximum_product = product;
        }
    }
    return maximum_product;
}

int main(void) {

    NodePtr root = NULL;
    srand(time(NULL));

    for (int i = 0; i < TEST_NODES; i++) {
        root = append_node(root, rand()%100);
    }

    maxProduct(root);

    release_node(root);
    return EXIT_SUCCESS;
}
