/*
 * =====================================================================================
 *
 *       Filename:  3708_longest_fibonacci_subarray.c
 *
 *    Description:  longest fibonacci subarray
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

int longestSubarray(int* nums, int numsSize) {

    int cumulate = 0, len = 0, maxlen = 0;

    cumulate = nums[0] + nums[1];
    maxlen = len = 2;

    for (int i = 2; i < numsSize; i++) {
        if (cumulate == nums[i]) {
            len++;
            maxlen = MAX(maxlen, len); 
        } else {
            len = 2; 
        }
        cumulate = nums[i] + nums[i-1];
    }
    return maxlen;
}
