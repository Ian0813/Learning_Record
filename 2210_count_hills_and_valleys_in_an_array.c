/*
 * =====================================================================================
 *
 *       Filename:  2210_count_hills_and_valleys_in_an_array.c
 *
 *    Description:  count_hills_and_valleys_in_an_array.c
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
#include <limits.h>

typedef enum {false, true} bool;

typedef enum {
    TYPE_HILL = 0,
    TYPE_VALLEY = 1
} land_type_t;

static bool search(int *nums, int left, int middle, int right, int end, land_type_t type) {

    bool rc = false;

    switch (type) {

        case TYPE_HILL:

            if (nums[left] < nums[middle]) {
                rc = true;
            }

            if (!rc)
                break;

            rc = false;

            for (right; right <= end && nums[right] == nums[middle]; right++)
                ;

            if (right > end)
                break;

            if (nums[right] < nums[middle]) {
                rc = true;
            }

        break;

        case TYPE_VALLEY:

            if (nums[left] > nums[middle]) {
                rc = true;
            }

            if (!rc)
                break;

            rc = false;

            for (right; right <= end && nums[right] == nums[middle]; right++)
                ;

            if (right > end)
                break;

            if (nums[right] > nums[middle]) {
                rc = true;
            }
        break;
    }

    return rc;
}

int countHillValley(int* nums, int numsSize) {

    int index = 0, count = 0;

    if (numsSize) {

        for (int i = 1; i < numsSize-1; i++) {
            if (nums[i] == nums[i-1])
                continue;

            if (search(nums, i-1, i, i+1, numsSize-1, TYPE_HILL)) {
                count++;
                continue;
            }

            if (search(nums, i-1, i, i+1, numsSize-1, TYPE_VALLEY)) {
                count++;
                continue;
            }
        }
    }
    return count;
}
