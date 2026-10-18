/*
 * =====================================================================================
 *
 *       Filename:  3194_minimum_average_of_smallest_and_largest_elements.c
 *
 *    Description:  minimum average of smallest and largest elements
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
#include <sys/param.h>
#include <limits.h>

static void swap_int(void *v1, void *v2) {

    int t = 0;

    t = *(int *) v1; 
    *(int *) v1 = *(int *) v2;
    *(int *) v2 = t;
    return;
}

static void swap_double(void *v1, void *v2) {

    double t = 0.0;

    t = *(double *) v1; 
    *(double *) v1 = *(double *) v2;
    *(double *) v2 = t;
    return;
}

static void quick_sort(int *nums, int head, int end, void (*swap)(void *v1, void *v2)) {

    int last = head, tail = end;

    if (head < end) {

        while (tail > last) {
            if (nums[head] > nums[tail]) {
                last++;
                swap(&nums[tail], &nums[last]);
                continue;
            }
            tail--;
        }

        swap(&nums[head], &nums[last]);
        quick_sort(nums, head, last-1, swap);
        quick_sort(nums, last+1, end, swap);
    }
    return;
}

double minimumAverage(int* nums, int numsSize) {

    double smallest = INT_MAX * 1.0;

    if (nums) {
        quick_sort(nums, 0, numsSize-1, swap_int);
    }

    for (int i = 0, j = numsSize-1; i < j; i++, j--) {
        smallest = MIN(smallest, ((double) (((nums[i]) * 1.0) + (nums[j] * 1.0))) / 2.0);
    }
    return smallest;
}
