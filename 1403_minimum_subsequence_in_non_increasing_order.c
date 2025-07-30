/*
 * =====================================================================================
 *
 *       Filename:  1403_minimum_subsequence_in_non_increasing_order.c
 *
 *    Description:  minimum subsequence in non increasing order
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

struct range {
    int left;
    int right;
};

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *nums, int head, int end) {

    int last = head, tail = end;

    if (head < tail) {

        while (tail > last) {
            if (nums[head] < nums[tail]) {
                last++;
                swap(&nums[last], &nums[tail]);
                continue;
            }
            tail--;              
        }

        swap(&nums[last], &nums[head]);
        quick_sort(nums, head, last-1);
        quick_sort(nums, last+1, end);
    }
    return;
}

static int get_min_subsequence(int *nums, int numsSize) {

    int number = 0, sum = 0, sub_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];    
    }

    for (int i = 0; i < numsSize; i++) {

       if (sub_sum > sum) {
           break;
       } 

       sub_sum += nums[i];
       sum -= nums[i];
       number++;
    }

    return number;
}

static void get_range(int *nums, int numsSize, int *dupnums, int number, struct range *range) {

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == dupnums[0]) {
            range->left = i;  
            break;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == dupnums[number-1]) {
            range->right = i;
            break;
        }
    }

    if (range->left > range->right) {
        swap(&range->left, &range->right);
    }

    return;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) {

    int *result = NULL, number = 0;

    quick_sort(nums, 0, numsSize-1);
    number = get_min_subsequence(nums, numsSize);

    if (number) {
        result = (int *) calloc(number, sizeof(int));
        memcpy(result, nums, sizeof(int) * number);
        *returnSize = number; 
    }
    return result;
}
