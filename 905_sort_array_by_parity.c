/*
 * =====================================================================================
 *
 *       Filename:  905_sort_array_by_parity.c
 *
 *    Description:  Sort array by parity  
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

void quick_sort(int *nums, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {
        while (last < tail) {
            if (!(nums[tail]%2)) {
                last++;
                swap(&nums[last], &nums[tail]);
                continue;
            }
            tail--;
        }
        swap(&nums[head], &nums[last]);
        quick_sort(nums, head, last);
        quick_sort(nums, last+1, end);
    }
    return;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {

    int *result = NULL;

    result = (int *) calloc(numsSize, sizeof(int));

    memcpy(result, nums, sizeof(int)*numsSize);
    quick_sort(result, 0, numsSize);
    *returnSize = numsSize;

    return result; 
}

