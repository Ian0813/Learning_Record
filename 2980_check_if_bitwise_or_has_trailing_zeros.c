/*
 * =====================================================================================
 *
 *       Filename:  2980_check_if_bitwise_or_has_trailing_zeros.c
 *
 *    Description:  check if bitwise or has trailing zeros
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

bool hasTrailingZeros(int* nums, int numsSize) {

    int count_even = 0;

    for (int i = 0; i < numsSize; i++) {

        if (!(nums[i]%2))
            count_even++;

        if (count_even > 1)
            break;
    }

    return count_even > 1 ? true : false;
}
