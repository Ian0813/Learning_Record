/*
 * =====================================================================================
 *
 *       Filename:  3095_shortest_subarray_with_or_at_least_k_i.c
 *
 *    Description:  shortest subarray with or at least k i
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

struct range_maximum {
    int count;
    int target;
};

static bool check_target_inrange(int *nums, int start, int end, struct range_maximum *payload) {

    int value = 0;
    bool rc = false;

    if (!payload)
        return rc;

    for (int i = start; i < end; i++) {

        value |= nums[i];

        payload->count++;

        if (value >= payload->target) {
            rc = true;
            break;
        }
    }

    return rc;
}

int minimumSubarrayLength(int* nums, int numsSize, int k) {

    int len = -1;
    struct range_maximum payload = {.target = k, .count = 0};

    for (int i = numsSize-1; i >= 0; i--) {

        if (check_target_inrange(nums, i, numsSize, &payload)) {
            len = ((len == -1) || len > payload.count) ? payload.count : len;
        }

        if (len == 1)
            break;

        payload.count = 0;
    }

    return len;
}
