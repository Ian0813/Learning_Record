/*
 * =====================================================================================
 *
 *       Filename:  3637_trionic_array_i.c
 *
 *    Description:  trionic array i
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

#define COND_LEN 3

typedef enum {
    SEQ_INCREASE = 0,
    SEQ_DECREASE = 1
} seq_type;

static bool check_seq_is_type(int *arr, int s, int e, seq_type type) {

    bool rc = true;

    if (type == SEQ_INCREASE) {
        for (s; s < (e); s++) {
            if (arr[s-1] <= arr[s]) {
                rc = false; 
                break;
            }
        }
    } else if (type == SEQ_DECREASE) {
        for (s; s < e; s++) {
            if (arr[s-1] >= arr[s]) {
                rc = false; 
                break;
            }
        }
    }
    return rc;
}

bool isTrionic(int* nums, int numsSize) {

    bool rc = true;
    int  start = 0, last = 0;

    do {
        for (start; start < (numsSize-1); start++) {
            if (nums[start] >= nums[start+1]) {
                break;
            }
        }

        if (start == last || start == (numsSize-1)) {
            rc = false;
            break;
        }

        last = start;

        for (start; start < (numsSize-1); start++) {
            if (nums[start] <= nums[start+1]) {
                break;
            }
        }

        if (start == last || start == (numsSize-1)) {
            rc = false;
            break;
        }

        for (start; start < (numsSize-1); start++) {
            if (nums[start] >= nums[start+1]) {
                break;
            }
        }

        if (start != (numsSize-1)) {
            rc = false;
        }
    } while (0);

    return rc;
}

