/*
 * =====================================================================================
 *
 *       Filename:  3151_special_array_i.c
 *
 *    Description:  special array i
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

#define CHECK_ODD(value) ((value)%2)
#define CHECK_EVEN(value) (!((value)%2))

bool check_special(int *nums, int numsSize, int odd_index, int even_index) {

    bool result = true;

    while (odd_index < numsSize && even_index < numsSize) {

        if (!CHECK_ODD(nums[odd_index])) {
            result = false;
            break;
        }

        if (!CHECK_EVEN(nums[even_index])) {
            result = false;
            break;
        }
        odd_index > even_index ? (even_index+=2) : (odd_index+=2);
    }
    return result;
}

bool isArraySpecial(int* nums, int numsSize) {

    bool result = true;

    if (numsSize > 1) {
        if (nums[0]%2) {
            result = check_special(nums, numsSize, 0, 1);
        } else {
            result = check_special(nums, numsSize, 1, 0);
        }
    }
    return result;
}
