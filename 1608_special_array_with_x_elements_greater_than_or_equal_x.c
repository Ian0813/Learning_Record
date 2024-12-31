/*
 * =====================================================================================
 *
 *       Filename:  1608_special_array_with_x_elements_greater_than_or_equal_x.c
 *
 *    Description:  special array with x elements greater than or equal x
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

static bool check_special(int *nums, int numsSize, int special) {

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= special) {
            count++;  
        }
    }
    return special == count ? true : false;
}

int specialArray(int* nums, int numsSize) {

    int special = -1;

    for (int i = 0; i <= numsSize; i++) {
        if (check_special(nums, numsSize, i)) {
            special = i;   
            break;
        }
    }
    return special;
}
