/*
 * =====================================================================================
 *
 *       Filename:  1437_check_if_all_1s_are_at_least_length_k_places_away.c
 *
 *    Description:  Check if all 1s are at least length k places away 
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

bool kLengthApart(int* nums, int numsSize, int k) {

    int count = 0;
    int start = -1;
    bool rc = true; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            start = i;
            break;
        }
    }

    for (int i = start + 1; i < numsSize; i++) {

        if (!nums[i]) {
            count++;  
        } else if (nums[i]) {
            if (count < k) {
                rc = false; 
                break;
            }
            count = 0;
        }
    }
    return rc;
}

int main(void) {
    return 0;
}

