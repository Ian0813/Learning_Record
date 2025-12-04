/*
 * =====================================================================================
 *
 *       Filename:  46_permutations.c
 *
 *    Description:  permutations
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXIMUM_SIZE 1024 

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void recur_print(int *nums, int index, int numsSize, int **result, int *result_len) {

    if (index == numsSize) {
        for (int i = 0; i < numsSize; i++) {
            result[*result_len][i] = nums[i];
        }
        *result_len += 1;
    }
    
    for (int i = index; i < numsSize; i++) {
        swap(&nums[index], &nums[i]);
        recur_print(nums, index + 1, numsSize, result, result_len);
        swap(&nums[index], &nums[i]);
    }
    return;
}

static void **allocate_dimensional_space(int row, int column) {

    void **result = NULL;

    result = (void **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        result[i] = (int *) calloc(column, sizeof(int));
    }

    return result;
}    

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    *returnSize = 0;

    result = (int **) allocate_dimensional_space(MAXIMUM_SIZE, numsSize);
    recur_print(nums, 0, numsSize, result, returnSize);

    if (*returnSize) {
        *returnColumnSizes = (int *) calloc(*returnSize, sizeof(int)); 
        for (int i = 0; i < *returnSize; i++) {
            (*returnColumnSizes)[i] = numsSize;
        }
    }

    return result;
}
