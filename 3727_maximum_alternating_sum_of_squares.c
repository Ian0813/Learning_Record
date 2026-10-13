/*
 * =====================================================================================
 *
 *       Filename:  3727_maximum_alternating_sum_of_squares.c
 *
 *    Description:  maximum alternating sum of squares
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

#define GET_SQUARE(num) ((num) * (num))

static void merge_process(int *nums, int head, int middle, int end) {

    int n1_size = (middle - head) + 1, n2_size = end - middle;
    int n1_arr[n1_size], n2_arr[n2_size];
    int n1_index = 0, n2_index = 0, index = head;

    for (int i = 0; i < n1_size; i++) {
        n1_arr[i] = nums[head + i];
    }

    for (int i = 0; i < n2_size; i++) {
        n2_arr[i] = nums[middle + i + 1];
    }

    while (n1_index < n1_size && n2_index < n2_size) {
        if (n1_arr[n1_index] > n2_arr[n2_index]) {
            nums[index++] = n2_arr[n2_index++];
        } else {
            nums[index++] = n1_arr[n1_index++];
        }
    }

    while (n1_index < n1_size) {
         nums[index++] = n1_arr[n1_index++];
    }

    while (n2_index < n2_size) {
         nums[index++] = n2_arr[n2_index++];
    }
    return;
}

static void merge_sort(int *nums, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(nums, head, middle);
        merge_sort(nums, middle+1, end);
        merge_process(nums, head, middle, end);
    }
    return;
}

long long maxAlternatingSum(int* nums, int numsSize) {

    long long result = 0LL; 
    int rindex = 0, lindex = 0;

    if (nums) {

        for (int i = 0; i < numsSize; i++) {
            nums[i] = nums[i] < 0 ? -nums[i] : nums[i];         
        }

        merge_sort(nums, 0, numsSize-1);

        rindex = numsSize-1;
        lindex = 0;

        while (lindex < rindex) {
            result += ((GET_SQUARE(nums[rindex])) - (GET_SQUARE(nums[lindex])));
            lindex++;
            rindex--;
        }

        if (lindex == rindex) {
            result += (GET_SQUARE(nums[rindex]));
        }
    }
    return result;
}
