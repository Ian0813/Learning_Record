/*
 * =====================================================================================
 *
 *       Filename:  414_third_maximum_number.c
 *
 *    Description:  Third maximum number  
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

#define SWAP_INT(v1, v2) { typeof(v1) temp = v1; v1 = v2; v2 = temp;}

void quick_sort(int *arr, int head, int end) {

    int front = head, tail = end - 1, last = head;

    if (front < tail) {

        while (last < tail) {
            if (arr[front] < arr[tail]) {
                last++; 
                SWAP_INT(arr[last], arr[tail]);
                continue;
            }
            tail--;
        }

        SWAP_INT(arr[front], arr[tail]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

int thirdMax(int* nums, int numsSize) {

    int val = 0;
	int diff_third = 0;
	int count = 0;

    quick_sort(nums, 0, numsSize);
	val = nums[0];

    for (int i = 1; i < numsSize; i++) {

		if (nums[i] != nums[i-1]) {
            count++;
			if (count == 2) {
                val = nums[i];
			}	
		}
    }

    return val;
}
