/*
 * =====================================================================================
 *
 *       Filename:  1305_all_elements_in_two_binary_search_trees.c
 *
 *    Description:  All elements in two binary search trees  
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
#include <unistd.h>

#define MAX_NUMS 5001

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

struct data_set {
    int arr[MAX_NUMS];
    int index;
} rset1 = {.arr = {0}, .index = 0}, rset2 = {.arr = {0}, .index = 0};

void get_elements(struct TreeNode *root, struct data_set *set) {

    if (root != NULL) {
        get_elements(root->left, set);
        set->arr[set->index++] = root->val;
        get_elements(root->right, set);
    }
    return;
}

void merge_sort(int *arr, int head, int middle, int tail) {

    //printf("head: %d, middle: %d, tail: %d\n", head, middle, tail);

    int pi1 = 0, pi2 = 0, index = head;
    int p1max = (middle-head+1), p2max = (tail-middle);

    int part1[p1max];
    int part2[p2max];

    memset(part1, 0, sizeof(int) * p1max);
    memset(part2, 0, sizeof(int) * p2max);

    for (int i = head; i < (middle+1); i++) {
        part1[i-head] = arr[i];
    }

    for (int i = middle+1; i <= tail; i++) {
        part2[i-(middle+1)] = arr[i];
    }

    while (pi1 != (p1max) && pi2 != (p2max)) {
        if (part1[pi1] > part2[pi2]) {
            arr[index++] = part2[pi2++];    
        } else {
            arr[index++] = part1[pi1++];
        }
    }

    while (pi1 != p1max) {
        arr[index++] = part1[pi1++];
    }

    while (pi2 != p2max) {
        arr[index++] = part2[pi2++];
    }

    return;
}

void merge_part(int *arr, int head, int tail) {

    int middle = (head+tail)/2;

    if (head < tail) {
        merge_part(arr, head, middle);
        merge_part(arr, middle+1, tail);
        merge_sort(arr, head, middle, tail);
    }
    return;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {

    int *arr = NULL;

    memset(&rset1, 0, sizeof(struct data_set));
    memset(&rset2, 0, sizeof(struct data_set));

    get_elements(root1, &rset1);
    get_elements(root2, &rset2);

    arr = (int *) calloc(rset1.index+rset2.index, sizeof(int));

    memcpy(arr, &rset1.arr, rset1.index * sizeof(int));
    memcpy(arr + rset1.index, &rset2.arr, rset2.index * sizeof(int));

    merge_part(arr, 0, (rset1.index + rset2.index)-1);

    *returnSize = rset1.index + rset2.index;

    return arr;
}
