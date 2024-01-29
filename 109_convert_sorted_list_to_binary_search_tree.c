/*
 * =====================================================================================
 *
 *       Filename:  109_convert_sorted_list_to_binary_search_tree.c
 *
 *    Description:  Convert sorted list to binary search tree  
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

#define MAX (2 * 10000)

struct TreeNode *create_tree(struct TreeNode *node, int val) {

    if (node == NULL) {
        node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
    } else if (node->val >= val) {
        node->left = create_tree(node->left, val);
    } else {
        node->right = create_tree(node->right, val);
    }
    return node;
}

void convert(struct ListNode **arr, struct TreeNode **node, int head, int end) {

    int mid = (head+end)/2;

    if (head < end) {

        *node = create_tree(*node, arr[mid]->val);

        convert(arr, node, head, mid);
        convert(arr, node, mid+1, end);
    }
    return;
}

void place_to_arr(struct ListNode *node, struct ListNode **arr, int *index) {

    while (node != NULL) {
        arr[*index] = node;
        ++*index;
        node = node->next; 
    }
    return;
}


struct TreeNode* sortedListToBST(struct ListNode* head) {

    int index = 0;
    struct ListNode *arr[MAX] = {NULL}; 
    struct TreeNode *root = NULL;

    place_to_arr(head, arr, &index);

    if (index > 0) {
        convert(arr, &root, 0, index);
    }

    return root;
}

