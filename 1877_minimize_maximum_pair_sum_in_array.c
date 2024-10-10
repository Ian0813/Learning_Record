/*
 * =====================================================================================
 *
 *       Filename:  1877_minimize_maximum_pair_sum_in_array.c
 *
 *    Description:  minimize maximum pair sum in array
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
#include <limits.h>

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;  

    if (front < tail) {

        while (last < tail) {
            if (arr[front] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[front], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}    

int minPairSum(int* nums, int numsSize) {

    int maximum = INT_MIN;
    int pair = 0;

    if (numsSize) {

        quick_sort(nums, 0, numsSize);

        for (int i = 0, j = numsSize-1; i < j; i++, j--) {
            if (maximum < (pair = nums[i]+nums[j])) {
                maximum = pair;
            }
        }
    }
    return maximum;
}
