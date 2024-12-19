/*
 * =====================================================================================
 *
 *       Filename:  2778_sum_of_squares_of_special_elements.c
 *
 *    Description:  sum of squares of special elements
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

#define SQUARE_NUM(num) ((num)*(num))

static inline bool is_special(int index, int boundary) {
    return !(boundary%index); 
}    

int sumOfSquares(int* nums, int numsSize) {

    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        if (is_special(i+1, numsSize))
            result += SQUARE_NUM(nums[i]);
    }
    return result;
}
