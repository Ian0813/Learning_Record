/*
 * =====================================================================================
 *
 *       Filename:  3354 make array elements equal to zero.c
 *
 *    Description:  make array elements equal to zero
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

#define TWO_SIDE 2

typedef struct {
    int left_sum;
    int right_sum;
} two_side_sum;

static int get_total(int *nums, int len) {

    int total = 0;

    for (int i = 0; i < len; i++) {
        total += nums[i];
    }

    return total;
}

int countValidSelections(int* nums, int numsSize) {

     int total = 0, valid = 0;
     two_side_sum sums = {0};

     sums.right_sum = total = get_total(nums, numsSize);

     for (int i = 0; i < numsSize; i++) {

        if (!nums[i]) {

            if (sums.left_sum == sums.right_sum)
                valid += TWO_SIDE;
            else if (abs(sums.left_sum - sums.right_sum) == 1)
                valid += 1;
        }

        sums.left_sum += nums[i];
        sums.right_sum = total - sums.left_sum;
     }

     return valid; 
}
