/*
 * =====================================================================================
 *
 *       Filename:  2824_count_pairs_whose_sum_is_less_than_target.c
 *
 *    Description:  count pairs whose sum is less than target
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

typedef enum {false, true} bool;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end;

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int count_less_pairs(int *nums, int numsSize, int target) {

    int counter = 0, base = *nums;

    for (int i = 1; i < numsSize; i++) {
        if ((base+nums[i]) < target)
            counter++;
        else
            break;
    }
    return counter;
}

int countPairs(int* nums, int numsSize, int target) {

    int result = 0, count = 0;

    if (numsSize) {

        quick_sort(nums, 0, numsSize-1);

        for (int i = 0; i < numsSize-1; i++) {
            count = count_less_pairs(&nums[i], numsSize-i, target);
            result += count;
        }
    }
    return result;
}
