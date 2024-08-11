/*
 * =====================================================================================
 *
 *       Filename:  1508_range_sum_of_sorted_subarray_sums.c
 *
 *    Description:  Range sum of sorted subarray sums  
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

#define MODULO_VALUE 1000000007

void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[tail]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

long long get_result(int *arr, int left, int right) {

    int start = left - 1;
    int end = right;
    long long int result = 0LL;

    for (; start < end; start++) {
        result += arr[start];        
    }

    if (result >= MODULO_VALUE) {
        result %= MODULO_VALUE;
    }
    return result;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {

    int *sum_array = NULL;
    int index = 0, temp = 0;
    long long int result = 0LL;

    if (numsSize) {

        sum_array = (int *) calloc((numsSize*(numsSize+1))/2, sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            if (index) {
                sum_array[index++] = sum_array[index-1] + nums[i];  
            } else {
                sum_array[index++] = nums[i]; 
            }
        }

        for (int i = 1; i < numsSize; i++) {
            temp = index;
            for (int j = temp - (numsSize-i); j < temp; j++) {
                sum_array[index++] = sum_array[j] - nums[i-1];
            }
        }
        quick_sort(sum_array, 0, index);
        result = get_result(sum_array, left, right);
    }
    free(sum_array);
    return result;
}

int main(void) {

    int arr[] = {1, 2, 3, 4};

    rangeSum(arr, sizeof(arr)/sizeof(int), 0, 0 ,0);
    return EXIT_SUCCESS;
}
