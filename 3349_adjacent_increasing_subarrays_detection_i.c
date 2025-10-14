/*
 * =====================================================================================
 *
 *       Filename:  3349 adjacent increasing subarrays detection i.c
 *
 *    Description:  adjacent increasing subarrays detection i
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

typedef struct increase_arr {
    int findex;
    int endindex;
    int len;
} inc_array;

static bool get_incarray(int *nums, int numsSize, inc_array *arr, int k) {

    int index = 0;
    bool rc = true;

    if (!arr)
        return rc;

    for (int index = arr->findex; index < (arr->findex + k) - 1; index++) {
        if (nums[index] >= nums[index+1]) {
            rc = false;
            break;
        }
        arr->endindex = index+1;
    }

    rc = arr->endindex == (arr->findex + (k-1)) ? true : false;

    return rc;
}

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {

    inc_array arr = {0};
    bool rc = false;

    if (k > 1) {
        for (int i = 0; i < (numsSize - k) - 1; i++) {

            arr.findex = i;

            if (get_incarray(nums, numsSize, &arr, k)) {

                arr.findex = arr.findex + k;

                if ((arr.findex + (k-1)) >= numsSize)
                     break;

                if (get_incarray(nums, numsSize, &arr, k)) {
                    rc = true;
                    break;
                }
            }
        }
    }

    rc = k == 1 ? true : rc;

    return rc;
}
