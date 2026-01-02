/*
 * =====================================================================================
 *
 *       Filename:  908_smallest_range_i.c
 *
 *    Description:  smallest range i
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

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}    

int smallestRangeI(int* nums, int numsSize, int k) {

    int range = numsSize == 1 ? 0 : INT_MAX, diff = 0;

    quick_sort(nums, 0, numsSize-1);

    if (numsSize > 1)
        range = abs(nums[numsSize-1] - nums[0]);

    range = range > (k*2) ? (range - (k*2)) : 0;
    return range;
}
