/*
 * =====================================================================================
 *
 *       Filename:  1248_count_number_of_nice_subarrays.c
 *
 *    Description:  count number of nice subarrays
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

#define IS_ODD(val) (((val)%2) ? true : false)

static int get_count(int *nums, int start, int end, int target) {

    int count = 0;

    while (start <= end) {

        count++;

        if (IS_ODD(nums[start])) {
            break; 
        }
        start++;
    }
    return count;
}

int numberOfSubarrays(int* nums, int numsSize, int k) {

    int odd_count = 0, satisfy_count = 0;
    int start = 0, end = 0;

    while (end < numsSize) {

        if (IS_ODD(nums[end])) {
            odd_count++;
        }

        while (start < end && odd_count > k) {
            if (IS_ODD(nums[start])) {
                odd_count--;
            }
            start++;
        }

        if (odd_count == k)
            satisfy_count += get_count(nums, start, end, k);
        end++;
    }
    return satisfy_count;
}
