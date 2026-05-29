/*
 * =====================================================================================
 *
 *       Filename:  540 single element in a sorted array.c
 *
 *    Description:  single element in a sorted array
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

static int binary_check_dup(int *nums, int head, int end, int numsSize) {

    int middle = (head+end)/2, index = -1;

    if (head < end) {

        if ((middle && middle < (numsSize-1)) && (nums[middle] != nums[middle-1]) && (nums[middle+1] != nums[middle])) {
            return middle;
        }

        if (!middle && nums[middle] != nums[middle+1]) {
            return middle;
        } if (middle == (numsSize-1) && nums[middle-1] != nums[middle]) {
            return middle;
        }

        index = binary_check_dup(nums, head, middle, numsSize);

        if (index == -1)
            index = binary_check_dup(nums, middle+1, end, numsSize);
    }
    return index;

}

int singleNonDuplicate(int* nums, int numsSize) {

    int index = 0;

    if (numsSize > 1)
        index = binary_check_dup(nums, 0, numsSize, numsSize);

    return nums[index];
}
