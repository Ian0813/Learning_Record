/*
 * =====================================================================================
 *
 *       Filename:  1984_minimum_difference_between_highest_and_lowest_of_k_scores.c
 *
 *    Description:  minimum difference between highest and lowest of k scores
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
#include <limits.h>

static void merge_process(int *arr, int head, int middle, int end) {

    int a1_size = (middle - head) + 1, a2_size = end - middle;
    int a1[a1_size], a2[a2_size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = 0; i < a1_size; i++) {
        a1[i] = arr[head + i];
    }

    for (int i = 0; i < a2_size; i++) {
        a2[i] = arr[middle + i + 1];
    }

    while (a1_index < a1_size && a2_index < a2_size) {
        if (a1[a1_index] > a2[a2_index]) {
            arr[index++] = a1[a1_index++]; 
        } else {
            arr[index++] = a2[a2_index++]; 
        }
    }

    while (a1_index < a1_size) {
        arr[index++] = a1[a1_index++]; 
    }

    while (a2_index < a2_size) {
        arr[index++] = a2[a2_index++]; 
    }

    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end) / 2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_process(arr, head, middle, end);
    }

    return;
}

int minimumDifference(int* nums, int numsSize, int k) {

    int result = INT_MAX, diff = 0;
    
    if (nums) {

        merge_sort(nums, 0, numsSize-1);

        for (int i = 0; (i + (k-1)) < numsSize; i++) {
            diff = nums[i] - nums[i + (k-1)];
            if (diff < result)
                result = diff;
        }
    }

    return result;
}
