/*
 * =====================================================================================
 *
 *       Filename:  2717 semi ordered permutation.c
 *
 *    Description:  semi ordered permutation
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

#define IS_SEMI_ORDERED(nums, numsSize) (nums[0] == 1 && nums[numsSize-1] == numsSize)

typedef enum {
    SWAP_FORWARD = 1,
    SWAP_BACKWARD = 2,
} swap_method_t;

static void swap(int *nums, int expected, int cur_loc, int *count, swap_method_t m) {

    int temp = 0;

    if (cur_loc == expected)
        return;

    temp = nums[cur_loc];

    if (m == SWAP_BACKWARD) {
        nums[cur_loc] = nums[cur_loc-1];
        nums[cur_loc-1] = temp;
        *count += 1;
        swap(nums, expected, cur_loc-1, count, m);
    } else if (m == SWAP_FORWARD) {
        nums[cur_loc] = nums[cur_loc+1];
        nums[cur_loc+1] = temp;
        *count += 1;
        swap(nums, expected, cur_loc+1, count, m);
    }

    return;
}

static int count_swap(int *nums, int numsSize) {

    int head = 1, tail = numsSize, count = 0;

    if (nums[0] != head) {
        for (int j = 1; j < numsSize; j++) {
            if (nums[j] == head) {
                swap(nums, 0, j, &count, SWAP_BACKWARD);
                break;
            }
        }
    }

    if (nums[numsSize-1] != tail) {
        for (int j = 1; j < numsSize; j++) {
            if (nums[j] == tail) {
                swap(nums, numsSize-1, j, &count, SWAP_FORWARD);
                break;
            }
        }
    }
    return count; 
}

int semiOrderedPermutation(int* nums, int numsSize) {
    return IS_SEMI_ORDERED(nums, numsSize) ? 0 : count_swap(nums, numsSize);    
}
