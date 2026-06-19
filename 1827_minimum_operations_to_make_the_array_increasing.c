/*
 * =====================================================================================
 *
 *       Filename:  1827_minimum_operations_to_make_the_array_increasing.c
 *
 *    Description:  minimum operations to make the array increasing
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int minOperations(int* nums, int numsSize){

    int total = 0, temp = 0; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i-1]) {
            temp = (nums[i] == nums[i-1] ? 1 : (nums[i-1]-nums[i]+1));
            total += temp;
            nums[i] += temp;
        }
    }
    return total;
}
