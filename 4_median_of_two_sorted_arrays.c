/*
 * =====================================================================================
 *
 *       Filename:  4_median_of_two_sorted_arrays.c
 *
 *    Description:  Median of two sorted arrays  
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 2000

void swap(int *i1, int *i2) {

    int temp = *i1;

    *i1 = *i2;
    *i2 = temp;

    return;
}

void quick_sort(int *arr, int front, int tail) {

    int head = front, end = tail - 1, last = front;

    if (head < end) {
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
        quick_sort(arr, last + 1, tail);
    }
    return;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int *combo = (int *) calloc(MAX, sizeof(int));
    int pos = 0; 
    double median = 0.0, sec_median = 0.0; 

    memcpy(combo, nums1, sizeof(int) * nums1Size);
    memcpy(combo + nums1Size, nums2, sizeof(int) * nums2Size);

	quick_sort(combo, 0, nums1Size + nums2Size);

	for (int i = 0; i < (nums1Size + nums2Size); i++) {
        printf("%d ", combo[i]);
	}

	putchar('\n');
    pos = (nums1Size + nums2Size)/2;    
    median = combo[pos];

	if (!((nums1Size + nums2Size)%2)) {
		sec_median = combo[pos-1];
	    free(combo);
	    return (median + sec_median)/2.0;
	}
    free(combo);
    return (median + sec_median);
}

int main(void) {

    int arr1[] = {1, 2}, arr2[] = {3, 4};

	printf("%lf \n", findMedianSortedArrays(arr1, 2, arr2, 2));
	return 0;
}
