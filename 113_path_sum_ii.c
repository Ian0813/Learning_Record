/*
 * =====================================================================================
 *
 *       Filename:  113_path_sum_ii.c
 *
 *    Description:  path sum ii  
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

/* 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_NODES 1000

struct list_node {
    struct TreeNode *leaf;
    struct list_node *next;
};

typedef struct list_node *NodePtr;

bool is_leaf(struct TreeNode *node) {

    if (!node->left && !node->right) {
        return true;
    }
    return false;
}

struct list_node *add_node(NodePtr head, struct TreeNode *leaf) {

    if (head == NULL) {
        head = (NodePtr) malloc(sizeof(struct list_node));
        head->leaf = leaf;
        head->next = NULL;
    } else {
        head->next = add_node(head->next, leaf);
    }
    return head;
}

int get_listlen(struct list_node *head) {

    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct list_node *traversal(struct TreeNode *root, int targetSum, int summarize, struct list_node *head) {

    if (root) {

        summarize += root->val;

        if (is_leaf(root)) {
            if (root->val == targetSum) {
                head = add_node(head, root);
            }
        }

        if (root->left) {
            if (!is_leaf(root->left)) {
                head = traversal(root->left, targetSum, summarize, head);
            } else {
                if ((summarize + root->left->val) == targetSum) {
                    head = add_node(head, root->left);
                }
            }
        }

        if (root->right) {
            if (!is_leaf(root->right)) {
                head = traversal(root->right, targetSum, summarize, head);
            } else {
                if ((summarize + root->right->val) == targetSum) {
                    head = add_node(head, root->right);
                }
            }
        }
    }
    return head;
}

bool path_recorder(struct TreeNode *root, int *arr, int *index, struct TreeNode *leaf) {

    bool rc = false;

    if (root) {

        if (root->left)
            rc = rc == false ? path_recorder(root->left, arr, index, leaf) : rc;

        if (root->right)
            rc = rc == false ? path_recorder(root->right, arr, index, leaf) : rc;

        if (root == leaf) {
            rc = true;
        }

        if (rc) {
            arr[*index] = root->val;
            *index = *index + 1;
        }
    }
    return rc;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {

    struct list_node *head = NULL;
    int len = 0;
    int **result = NULL;
    int temp_arr[BUFSIZ] = {0}, index = 0, result_index = 0;

    *returnColumnSizes = (int *) calloc(MAX_NODES, sizeof(int));

    if (root) {

        head = traversal(root, targetSum, 0, head);

        *returnSize = len = get_listlen(head);
        result = (int **) calloc(len, sizeof(int *));

        while (head) {
            path_recorder(root, temp_arr, &index, head->leaf);
            for (int i = 0; i < index; i++) {
            }
            (*returnColumnSizes)[result_index] = index;
            result[result_index] = (int *) calloc(index, sizeof(int));
            for (int i = index-1, j = 0; i >= 0; i--, j++) {
                result[result_index][j] = temp_arr[i];
            }
            result_index++;
            index = 0;
            memset(temp_arr, 0, sizeof(int) * BUFSIZ);
            head = head->next;
        }
    }
    return result;
}
