/*
 * =====================================================================================
 *
 *       Filename:  896_monotonic_array.c
 *
 *    Description:  Monotonic array    
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

static bool check_sorted(int *arr, int size) {

    bool rc = true;

    for (int i = 0; i < (size-1); i++) {
        if (arr[i] > arr[i+1]) {
            rc = false;
            break;
        }
    }

    if (!rc) {
        rc = true;
        for (int i = 0; i < (size-1); i++) {
            if (arr[i] < arr[i+1]) {
                rc = false;
                break;
            }
        }
    }
    return rc;
}

bool isMonotonic(int* nums, int numsSize) {
    return check_sorted(nums, numsSize);
}

