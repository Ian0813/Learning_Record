/*
 * =====================================================================================
 *
 *       Filename:  153_find_minimum_in_rotated_sorted_array.c
 *
 *    Description:  find minumum in rotated sorted array  
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

int findMin(int* nums, int numsSize) {

    int left = 0, right = numsSize - 1;
	int mid = 0, value = 0;

    while (left < right) {

	    mid = (left+right)/2;
        value = nums[mid];

        if (value > nums[right]) {
            left = mid+1;
		} else {
            right = mid;
		}
    }

    if (nums[right] > nums[left]) {
        value = nums[left];
	} else {
        value = nums[right];
	}
	return value;
}

int main(void) {

    int arr[] = {3, 4, 1, 2};

    printf("minimum: %d\n", findMin(arr, sizeof(arr)/sizeof(int)));

    return EXIT_SUCCESS;
}

