/*
 * =====================================================================================
 *
 *       Filename:  2932_maximum_strong_pair_xor_i.c
 *
 *    Description:  maximum strong pair xor i
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

#define MIN(v1, v2) ((v1) < (v2) ? (v1) : (v2))
#define CHECK_STRONG_PAIR(v1, v2) (abs(v1 - v2) <= MIN(v1, v2))

static void get_max_strongpair(int *nums, int numsSize, int index, int cur_index, int *max) {

    int value = 0;

    if (index == numsSize)
        return;

    if (cur_index == index)
        ;
    else if (CHECK_STRONG_PAIR(nums[cur_index], nums[index])) {
        *max = *max < (value = nums[cur_index] ^ nums[index]) ? value : *max;
    }

    get_max_strongpair(nums, numsSize, index+1, cur_index, max);
    return;
}

static void traverse_by_pair(int *nums, int numsSize, int index, int cur_index, int *max) {

    if (index < numsSize) {
        get_max_strongpair(nums, numsSize, index, cur_index, max);
    }

    if (cur_index < (numsSize-1)) {
        traverse_by_pair(nums, numsSize, cur_index+1, index+1, max);
    }
    return;
}

int maximumStrongPairXor(int* nums, int numsSize) {

    int max = 0;

    traverse_by_pair(nums, numsSize, 0, 0, &max);

    return max;
}
