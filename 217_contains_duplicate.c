/*
 * =====================================================================================
 *
 *       Filename:  217_contains_duplicate.c
 *
 *    Description:  Contains duplicate  
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef _STDBOOL_H
typedef unsigned int bool;
enum BOOL {false, true};
#endif

void swap(int *i1, int *i2) {

    int temp = *i1; 
    *i1 = *i2;
	*i2 = temp;
    return;
}

void quick_sort(int *arr, int front, int tail) {

    int head = front, end = tail, last = front;

	while (head < end) {
        while (last < end) {
            if (arr[head] > arr[end]) {
                last++;  
				swap(&arr[last], &arr[end]);
				continue;
			}
			end--;
		}
		swap(&arr[head], &arr[last]);
		quick_sort(arr, front, last);
		quick_sort(arr, last+1, tail);
	}
    return;
}

void merge(int *arr, int left, int middle, int right) {

    int lindex = 0, rindex = 0, aindex = left;   
	int lim_left = middle-left+1, lim_right = right - middle;    

	int sub1[lim_left], sub2[lim_right];

	memset(sub1, 0, sizeof(sub1));
	memset(sub2, 0, sizeof(sub2));


	for (lindex = 0; lindex < middle; lindex++) {
        sub1[lindex] = arr[left+lindex];        
	}

	for (rindex = 0; rindex < right; rindex++) {
        sub2[rindex] = arr[middle+rindex+1];
	}

    lindex = 0;
	rindex = 0;

    while (lindex < lim_left && rindex < lim_right) {
        if (sub1[lindex] <= sub2[rindex]) {
            arr[aindex++] = sub1[lindex++]; 
		} else {
            arr[aindex++] = sub2[rindex++]; 
		}
	}

    while (lindex < lim_left) {
        arr[aindex++] = sub1[lindex++];
    }

    while (rindex < lim_right) {
        arr[aindex++] = sub2[rindex++];
    }
	return;
}

void merge_sort(int *arr, int left, int right) {

    int middle = (left+right)/2;

    if (left < right) {

        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

		merge(arr, left, middle, right);
    }
	return;
}

bool containsDuplicate(int* nums, int numsSize) {

    //quick_sort(nums, 0, numsSize);
    merge_sort(nums, 0, numsSize - 1);
	for (int i = 0; i < (numsSize - 1); i++) {
        if (nums[i] == nums[i+1]) {
            return true;
		}
	}
	return false;
}

int main(void) {
    return 0;
}

