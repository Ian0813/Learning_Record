/*
 * =====================================================================================
 *
 *       Filename:  88_merge_sorted_array.c
 *
 *    Description:  Merge sorted array  
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

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

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    memcpy(nums1 + m, nums2, sizeof(int) * n);

	quick_sort(nums1, 0, m + n);

	for (int i = 0; i < (m + n); i++) {
        printf("%d ", nums1[i]);
	}


    return;
}

int main(void) {
#if 0
    int arr1[6] = {1, 2, 3, 0, 0, 0}, arr2[3] = {2, 5, 6};

	merge(arr1, 3, 6, arr2, 3, 3);

    //memcpy(arr1 + 3, arr2, sizeof(int) * 3);
    //quick_sort(arr1, 0, 6);
	printf("\n");
#else
    printf("long long: %ld\n", sizeof(long long));
    printf("long: %ld\n", sizeof(long));
    printf("long double: %ld\n", sizeof(long double));
    printf("double: %ld\n", sizeof(double));
    printf("float: %ld\n", sizeof(float));
#endif

	return 0;
}

