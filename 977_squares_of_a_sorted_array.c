/*
 * =====================================================================================
 *
 *       Filename:  977_squares_of_a_sorted_array.c
 *
 *    Description:  Squares of a sorted array  
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
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void square_ranges(int *arr, int size, int *result) {

    int val = 0;    

    for (int i = 0; i < size; i++) {
        result[i] = (int) (arr[i] * arr[i]);
    }
    return;
}

void swap(int *a, int *b) {

    int temp = *a;

    *a = *b;
    *b = temp;
    return;
}

void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
        while (last < tail) {
            if (arr[front] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);                 
                continue;
            }
            tail--;
        }
        swap(&arr[front], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    int *result = (int *) calloc(numsSize, sizeof(int));

    square_ranges(nums, numsSize, result);
    quick_sort(result, 0, numsSize);

    *returnSize = numsSize;
    return result;
}

#if 1
int main(void) {

    int num[] = {-4, -1, 0, 3, 10};
    int *result = (int *) calloc(sizeof(num)/sizeof(int), sizeof(int));
    int size = sizeof(num)/sizeof(int);

    square_ranges(num, size, result);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    quick_sort(result, 0, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    free(result);
    return EXIT_SUCCESS;
}
#endif
