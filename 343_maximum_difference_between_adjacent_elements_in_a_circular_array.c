/*
 * =====================================================================================
 *
 *       Filename:  343_maximum_difference_between_adjacent_elements_in_a_circular_array.c
 *
 *    Description:  maximum difference between adjacent elements in a circular array
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

static void get_difference(int *nums, int numsSize, int *diff_array) {

    for (int i = 0; i < numsSize; i++) {
        diff_array[i] = abs(nums[i]-nums[(i+1)%numsSize]);            
    }
    return;
}    

static int get_maximum_diff(int *diff_array, int size) {

    int max = 0;

    for (int i = 0; i < size; i++) {
        if (max < diff_array[i]) {
            max = diff_array[i]; 
        }
    }
    return max;
}

int maxAdjacentDistance(int* nums, int numsSize) {

    int *diff_array = (int *) calloc(numsSize, sizeof(int));  
    int max_diff = 0; 

    get_difference(nums, numsSize, diff_array);     

    max_diff = get_maximum_diff(diff_array, numsSize);
    free(diff_array);
    
    return max_diff;
}
