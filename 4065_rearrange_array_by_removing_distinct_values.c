/*
 * =====================================================================================
 *
 *       Filename:  4065_rearrange_array_by_removing_distinct_values.c
 *
 *    Description:  rearrange array by removing distinct values
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *nums, int head, int end) {

    int last = head, tail = end;      

    if (head < end) {

        while (last < tail) {
            if (nums[head] > nums[tail]) {
                last++;
                swap(&nums[last], &nums[tail]); 
                continue;
            }
            tail--;
        }
        swap(&nums[head], &nums[last]);
        quick_sort(nums, head, last-1);
        quick_sort(nums, last+1, end);
    }
    return;
}

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {

    bool *nums_flag = NULL; 
    int *result = NULL, rindex = 0, index = 0;

    if (nums) {

        nums_flag = calloc(numsSize, sizeof(bool)); 
        result = calloc(numsSize, sizeof(int)); 

        quick_sort(nums, 0, numsSize-1);

        for (int amount = numsSize, last = -1; amount; last = -1) {
            for (int i = 0; i < numsSize; i++) {
                if (nums[i] != last && !nums_flag[i]) {
                    result[rindex++] = nums[i];
                    last = nums[i];
                    nums_flag[i] = true;
                    amount--;
                }
            }
        }
        free(nums_flag);
        *returnSize = numsSize;
    }
    return result;
}
