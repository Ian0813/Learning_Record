/*
 * =====================================================================================
 *
 *       Filename:  704_binary_search.c
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int divide(int *nums, int head, int end, int target) {

    int middle = (head+end)/2;
    int rc = -1;

    if (head <= end) {
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            rc = divide(nums, head, middle-1, target);
        } else {
            rc = divide(nums, middle+1, end, target);
        }
    }
    return rc;
}

int search(int* nums, int numsSize, int target) {
    return divide(nums, 0, numsSize-1, target);
}
