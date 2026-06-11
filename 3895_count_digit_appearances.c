/*
 * =====================================================================================
 *
 *       Filename:  3895_count_digit_appearances.c
 *
 *    Description:  count digit appearances
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

static int get_digit_count(int value, int digit) {

    int count = 0;

    while (value) {

        if ((value%10) == digit)
            count++;  
        value /= 10;
    }
    return count;
}

int countDigitOccurrences(int* nums, int numsSize, int digit) {

    int total_count = 0; 

    for (int i = 0; i < numsSize; i++) {
        total_count += get_digit_count(nums[i], digit);
    }
    return total_count;
}
