/*
 * =====================================================================================
 *
 *       Filename:  4097_minimum_value_of_merged_integers.c
 *
 *    Description:  minimum value of merged integers
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
#include <sys/param.h>
#include <limits.h>

#define PAIR_LEN 2

int minMergedInteger(int* nums, int numsSize) {

    int value = 0, min = INT_MAX;
    char digit_str[CHAR_BIT * sizeof(int)]; 

    memset(digit_str, 0, sizeof(digit_str));

    for (int i = 0; i < numsSize; i += PAIR_LEN) {
        sprintf(digit_str, "%d%d", nums[i], nums[i+1]);
        value = strtol(digit_str, NULL, 10);
        min = MIN(value, min); 
        memset(digit_str, 0, sizeof(digit_str));
    }
    return min;
}
