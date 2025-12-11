/*
 * =====================================================================================
 *
 *       Filename:  3674_minimum_operations_to_equalize_array.c
 *
 *    Description:  minimum operations to equalize array
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
#include <limits.h>

typedef enum {false, true} bool;

static bool check_is_equal(int *nums, int numsSize) {

    bool rc = true;

    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] != nums[i+1]) {
            rc = false;     
            break;
        }
    }
    return rc;
}

int minOperations(int* nums, int numsSize) {
    return check_is_equal(nums, numsSize) ? 0 : 1; 
}
