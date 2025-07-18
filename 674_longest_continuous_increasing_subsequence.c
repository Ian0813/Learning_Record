/*
 * =====================================================================================
 *
 *       Filename:  674_longest_continuous_increasing_subsequence.c
 *
 *    Description:  longest continuous increasing subsequence
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

static bool get_longest_sequence(int *nums, int numsSize, int *cur_max, int possible_max)
{
    int max_length = 1;

    if (possible_max <= *cur_max)
        return false;

    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] < nums[i+1]) {
            max_length++;
            continue;
        }
        break;
    }

    if (max_length > *cur_max)
        *cur_max = max_length;

    return true;
}

int findLengthOfLCIS(int* nums, int numsSize) {

    int max_length = 0, possible_max = numsSize, cur_max = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!get_longest_sequence(&nums[i], numsSize-i, &cur_max, numsSize-i)) {
            break;
        }
    }
    return cur_max;
}
