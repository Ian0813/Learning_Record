/*
 * =====================================================================================
 *
 *       Filename:  508_most_frequent_subtree_sum.c
 *
 *    Description:  Most frequent subtree sum  
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define NODE_NUMS  10001
typedef struct TreeNode *NodePtr;

int sum_allnode(NodePtr node) {

    int left = 0, right = 0;

    if (node) {
        if (node->left) {
            left = sum_allnode(node->left);
        }

        if (node->right) {
            right = sum_allnode(node->right);
        }
        node->val = node->val + left + right;
        return node->val;
    }
    return 0;
}

void post_order(NodePtr node, int *arr, int *index) {


    if (node) {
        post_order(node->left, arr, index);
        post_order(node->right, arr, index);
        arr[*index] = node->val;
        *index += 1;
    }
    return;
}

void swap(int *i1, int *i2) {

    int value = *i1;

    *i1 = *i2;
    *i2 = value;
    return;
}

void quick_sort(int *arr, int head, int end) {

    int last = head, front = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {

    int flag = 0, index = 0;
    int freqs = 0, value = 0, count = 0, rindex = 0;
    int *arr = (int *) calloc(NODE_NUMS, sizeof(int));
    int *result = (int *) calloc(NODE_NUMS, sizeof(int));

    if (root) {

        sum_allnode(root);
        post_order(root, arr, &index);
        quick_sort(arr, 0, index);

        for (int i = 0; i < index; i++) {
            if (value == arr[i]) {
                count++;
            } else {
                value = arr[i];
                count = 1;
            }

            if (count > freqs) {
                freqs = count;
            }
        }

        value = 0;
        count = 0;

        for (int i = 0; i < index; i++) {
            if (value == arr[i]) {
                count++;
            } else {
                value = arr[i];
                count = 1;
            }

            if (count == freqs) {
                if (rindex == index) {
                    memcpy(result, arr, sizeof(int) * index);
                    *returnSize = index;
                    break;
                } else {
                    result[rindex++] = value;
                    *returnSize = rindex;
                }
            }
        }
    }
    return result; 
}
