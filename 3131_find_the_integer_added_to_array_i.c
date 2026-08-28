/*
 * =====================================================================================
 *
 *       Filename:  3131_find_the_integer_added_to_array_i.c
 *
 *    Description:  find_the_integer_added_to_array_i
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
#include <limits.h>
#include <sys/param.h>

static int get_minimum(int *nums, int numsSize) {

    int min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        min = MIN(nums[i], min);
    }

    return min;
}

int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int min1 = INT_MAX, min2 = INT_MAX;

    min1 = get_minimum(nums1, nums1Size);
    min2 = get_minimum(nums2, nums2Size);

    return min2 - min1;
}
