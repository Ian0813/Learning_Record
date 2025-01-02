/*
 * =====================================================================================
 *
 *       Filename:  162_find_peak_element.c
 *
 *    Description:  Find peak element  
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

#define CHECK_BOUNDARY(index, size) (!(index) || (index) == size)
#define CHECK_PEAK(nums, middle) (nums[middle] > nums[middle-1] && nums[middle] > nums[middle+1])

static int get_peak(int *nums, int head, int tail, int size) {

    int middle = (head+tail)/2;
    int peak = 0;

    if (size < 1)
        goto RETURN_POINT;

    if (CHECK_BOUNDARY(middle, size)) {
        if (!middle && nums[middle] > nums[middle+1]) {
            peak = middle;
        } else if (!middle) {
            peak = get_peak(nums, middle+1, tail, size);   
        }

        if (middle == size && nums[middle] > nums[middle-1]) {
            peak = middle;
        } else if (middle == size) {
            peak = get_peak(nums, head, middle, size);
        }
    } else {

        if (CHECK_PEAK(nums, middle)) {
            peak = middle; 
        } else if (nums[middle] < nums[middle+1]) {
            peak = get_peak(nums, middle+1, tail, size);
        } else {
            peak = get_peak(nums, head, middle, size);
        }
    }
RETURN_POINT:;
    return peak; 
}

int findPeakElement(int* nums, int numsSize) {

    int peak = 0;

    if (numsSize) {
        peak = get_peak(nums, 0, numsSize-1, numsSize-1);
    }
    return peak;
}
