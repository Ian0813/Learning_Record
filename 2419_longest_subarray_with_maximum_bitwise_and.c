/*
 * =====================================================================================
 *
 *       Filename:  2419_longest_subarray_with_maximum_bitwise_and.c
 *
 *    Description:  longest subarray with maximum bitwise and
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

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestSubarray(int* nums, int numsSize) {

    int longest = 0, count = 0, cur_val = 0, maximum = 0;

    if (numsSize) {

        longest = count = 1;
        maximum = cur_val = nums[0];

        for (int i = 1; i < numsSize; i++) {

            if (maximum > nums[i]) {
                longest = MAX(longest, count);
                count = 0;
                continue;
            }

            if (maximum < nums[i]) {
                longest = count = 1;
                maximum = cur_val = nums[i];
            } else {
                count++;
            }
        }
    }
    return MAX(longest, count);
}
