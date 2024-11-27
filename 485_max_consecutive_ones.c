/*
 * =====================================================================================
 *
 *       Filename:  485_max_consecutive_ones.c
 *
 *    Description:  max consecutive ones
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

#define BUFFER_SIZE 100000

int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int zero_pos[BUFFER_SIZE] = {0};
    int index = 0;
    int one_length = 0, max = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!nums[i]) {
            zero_pos[index++] = i;
            one_length = 0;
        } else {
            one_length++;
        }
        if (one_length > max) {
            max = one_length;
        }
    }
    return max;
}
