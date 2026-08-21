/*
 * =====================================================================================
 *
 *       Filename:  3903_smallest_stable_index_i.c
 *
 *    Description:  smallest stable index i
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

int firstStableIndex(int* nums, int numsSize, int k) {

    int max = INT_MIN, min = INT_MAX, sindex = -1;

    for (int i = 0; i < numsSize; i++) {

        for (int j = 0; j < (i+1); j++) {
            max = MAX(nums[j], max);
        }

        for (int j = i; j < numsSize; j++) {
            min = MIN(nums[j], min);
        }

        if ((max-min) <= k) {
            sindex = i; 
            break;
        }
        max = INT_MIN;
        min = INT_MAX;
    }
    return sindex;
}
