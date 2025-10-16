/*
 * =====================================================================================
 *
 *       Filename:  1822 sign of the product of an array.c
 *
 *    Description:  sign of the product of an array
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

typedef enum {
    ARR_POSITIVE = 0,
    ARR_NEGATIVE = 1,
    ARR_ZERO = 2,
} array_sign_t;

static array_sign_t get_arr_signtype(int *nums, int numsSize) {

    int negative_count = 0; 

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] < 0) {
            negative_count++; 
        } else if (!nums[i]) {
            return ARR_ZERO;
        }
    }

    return !(negative_count%2) ? ARR_POSITIVE : ARR_NEGATIVE;
}

static int get_sign_value(array_sign_t sign_type) {

    switch (sign_type) {
        case ARR_POSITIVE:
            return 1;
        case ARR_NEGATIVE:
            return -1;
        case ARR_ZERO:
            return 0;
    }
    return 2;
}

int arraySign(int* nums, int numsSize) {

    array_sign_t sign_type = 0; 

    sign_type = get_arr_signtype(nums, numsSize);

    return get_sign_value(sign_type);
}
