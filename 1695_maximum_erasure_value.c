/*
 * =====================================================================================
 *
 *       Filename:  1695_maximum_erasure_value.c
 *
 *    Description:  maximum erasure value
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

#define TABLE_SIZE 100001

static int get_maximum(int *nums, int numsSize) {

    int temp = 0, max_value = 0;
    bool tracker[TABLE_SIZE] = {0};

    for (int left = 0, right = 0; right < numsSize; right++) {

        if (tracker[nums[right]]) {

            if (temp > max_value) {
                max_value = temp;
            }

            for (left; nums[left] != nums[right]; left++) {
                tracker[nums[left]] = false;
                temp -= nums[left];
            }

            left++;

        } else {
            temp += nums[right];
            tracker[nums[right]] = true;
        }
    }

    if (temp > max_value) {
        max_value = temp;
    }

    return max_value;
}

int maximumUniqueSubarray(int* nums, int numsSize) {

    int result = 0;

    result = get_maximum(nums, numsSize);

    return result;
}
