/*
 * =====================================================================================
 *
 *       Filename:  1848_minimum_distance_to_the_target_element.c
 *
 *    Description:  minimum distance to the target element
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
#include <math.h>
#include <limits.h>

int getMinDistance(int* nums, int numsSize, int target, int start) {

    int minimum = INT_MAX, temp = 0;

    for (int i = 0; minimum && i < numsSize; i++) {
        if (nums[i] == target) {
            temp = abs(i-start);
            minimum = minimum < temp ? minimum : temp; 
        }
    }

    return minimum;
}
