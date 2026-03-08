/*
 * =====================================================================================
 *
 *       Filename:  3701_compute_alternating_sum.c
 *
 *    Description:  compute alternating sum
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

#define GET_VALUE(arr, index, size) ((index) < (size) ? arr[(index)] : 0)

int alternatingSum(int* nums, int numsSize) {

    int sum = 0; 

    for (int i = 0, j = 1; (i < numsSize) || (j < numsSize); i += 2, j += 2) {
        sum += (GET_VALUE(nums, i, numsSize) - GET_VALUE(nums, j, numsSize));
    }

    return sum; 
}
