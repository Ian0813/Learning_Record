/*
 * =====================================================================================
 *
 *       Filename:  201_bitwise_and_of_numbers_range.c
 *
 *    Description:  bitwise and of numbers range
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
#include <stdbool.h>

#define INT_BITS (sizeof(int) * CHAR_BIT)

static int get_mask(int val) {

    int mask = 0, msb_pos = 0;

    for (int i = INT_BITS; i > 0; i--) {
        if ((val >> (i-1)) & 1) {
            msb_pos = i;
            break;
        }
    }

    for (int i = msb_pos; i > 0; i--) {
        mask |= (1 << (i-1));
    }
    return ~mask;
}

int rangeBitwiseAnd(int left, int right) {

    int result = 0, mask = 0;
    int diff = right - left;

    mask = get_mask(diff);
    result = right & (mask & left);

    return result;
}
