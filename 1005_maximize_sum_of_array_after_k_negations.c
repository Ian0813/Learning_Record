/*
 * =====================================================================================
 *
 *       Filename:  1005_maximize_sum_of_array_after_k_negations.c
 *
 *    Description:  maximize sum of array after k negations
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

static void merge_process(int *nums, int head, int middle, int end) {

    int a1_size = (middle - head) + 1, a2_size = (end - middle);
    int a1[a1_size], a2[a2_size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = 0; i < a1_size; i++) {
        a1[i] = nums[i + head];
    }

    for (int i = 0; i < a2_size; i++) {
        a2[i] = nums[i + middle + 1];
    }

    while (a1_index < a1_size && a2_index < a2_size) {
        if (a1[a1_index] < a2[a2_index]) {
            nums[index++] = a1[a1_index++];
        } else {
            nums[index++] = a2[a2_index++];
        }
    }

    while (a1_index < a1_size) {
        nums[index++] = a1[a1_index++];
    }

    while (a2_index < a2_size) {
        nums[index++] = a2[a2_index++];
    }
    return;
}

static void merge_sort(int *nums, int head, int end) {

    int middle = (head + end)/2;

    if (head < end) {
        merge_sort(nums, head, middle);
        merge_sort(nums, middle+1, end);
        merge_process(nums, head, middle, end);
    }
    return;
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {

    int sum = 0, index = 0;

    merge_sort(nums, 0, numsSize - 1);

    while (k) {
        nums[index] = -nums[index];
        k--;
        index = nums[((index+1) % numsSize)] > nums[index] ? index : ((index+1) % numsSize);
    }

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum;
}
