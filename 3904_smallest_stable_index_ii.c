/*
 * =====================================================================================
 *
 *       Filename:  3904_smallest_stable_index_ii.c
 *
 *    Description:  smallest stable index ii
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

    int max = INT_MIN, min = INT_MAX, last_min = 0, sindex = -1;

    for (int i = 0; i < numsSize; i++) {

        max = MAX(nums[i], max);

        if ((i && min == nums[i-1]) || min == INT_MAX) {
            min = INT_MAX;
            for (int j = i; j < numsSize; j++) {
                min = MIN(nums[j], min);
                if (last_min == min)
                    break;
            }
            last_min = min;
        }

        if ((max-min) <= k) {
            sindex = i;
            break;
        }
    }
    return sindex;
}
