/*
 * =====================================================================================
 *
 *       Filename:  2032_two_out_of_three.c
 *
 *    Description:  two out of three
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

#define TABLE_SIZE 101
#define LOWER_BOUND 2

enum {
    T1 = 0,  
    T2 = 1,  
    T3 = 2,  
    TC
};

static inline void count_frequencies(int *table, int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (!table[nums[i]]) {
            table[nums[i]] = 1;
        }
    }
    return;
}

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {

    int table[TC][TABLE_SIZE] = {[T1] = {0}, [T2] = {0}, [T3] = {0}};
    int *result = NULL, index = 0;

    count_frequencies(table[T1], nums1, nums1Size);
    count_frequencies(table[T2], nums2, nums2Size);
    count_frequencies(table[T3], nums3, nums3Size);

    result = (int *) calloc(nums1Size+nums2Size+nums3Size, sizeof(int));

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[T1][i]+table[T2][i]+table[T3][i] >= LOWER_BOUND) {
            result[index++] = i;
        }
    }
    *returnSize = index;
    return result;
}
