/*
 * =====================================================================================
 *
 *       Filename:  47_permutations_ii.c
 *
 *    Description:  permutations ii
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 * *         Author:  Ian * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static inline int GET_LIST_LEN(int size) {
    int value = 1;

    for (int i = 2; i <= size; i++) {
        value *= i;
    }
    return value;
}

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static bool check_unique(int *nums, int numsSize) {
    for (int i = 0; i < numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] == nums[j]) 
                return false; 
        }
    }
    return true;
}

static bool check_is_set(int *nums, int numsSize, int **nums_list, int *nllen) {

    bool rc = false;

    for (int i = 0; i < *nllen; i++) {
        rc = true;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] != nums_list[i][j]) {
                rc = false;
                break;
            }
        }
        if (rc)
            break;
    }
    return rc;
}

static void printPermutation(int *nums, int numsSize, int index, int **nums_list, int *nllen, bool unique) {

    if (index < numsSize) {
        for (int i = index; i < numsSize; i++) {
            swap(&nums[i], &nums[index]);
            printPermutation(nums, numsSize, index + 1, nums_list, nllen, unique);
            swap(&nums[i], &nums[index]);
        }
    } else {
        if (unique || !check_is_set(nums, numsSize, nums_list, nllen)) {
            nums_list[*nllen] = calloc(numsSize, sizeof(int));
            memcpy(nums_list[*nllen], nums, sizeof(int) * numsSize);
            *nllen += 1;
        }
    }
    return;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int **nums_list = NULL, nllen = 0, *nl_colsize = 0;
    bool unique = false;

    unique = check_unique(nums, numsSize);
    nums_list = (int **) calloc(GET_LIST_LEN(numsSize), sizeof(int *));
    nl_colsize = (int *) calloc(GET_LIST_LEN(numsSize), sizeof(int));

    printPermutation(nums, numsSize, 0, nums_list, &nllen, unique);

    for (int i = 0; i < nllen; i++)
        nl_colsize[i] = numsSize;

    *returnSize = nllen;
    *returnColumnSizes = nl_colsize;

    return nums_list;
}
