/*
 * =====================================================================================
 *
 *       Filename:  167_two_sum_ii_input_array_is_sorted.c
 *
 *    Description:  two sum ii input array is sorted
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define ARRAY_SIZE 2

static int bisearch(int *arr, int low, int high, int target) {

    int middle = (high+low)/2;
    int index = -1; 

    if (low <= high) {

        if (arr[middle] == target) {
            index = middle;
        } else if (arr[middle] > target) {
            index = bisearch(arr, low, middle-1, target);
        } else {
            index = bisearch(arr, middle+1, high, target);
        }
    }
    return index;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int difference = 0;
    int second_index = -1;
    int *result = NULL;

    *returnSize = ARRAY_SIZE;
    result = (int *) calloc(ARRAY_SIZE, sizeof(int));

    for (int i = numbersSize-1; i > 0; i--) {

        difference = target-numbers[i];
        second_index = bisearch(numbers, 0, i-1, difference);

        if (second_index != -1) {
            result[0] = second_index+1;
            result[1] = i+1;
            break;
        }
    }
    return result;
}

int main(void) {

    int arr[] = {-1, 0};
    int size = 0, *ptr = NULL; 

    ptr = twoSum(arr, sizeof(arr)/sizeof(*arr), -1, &size);

    printf("index: {%d, %d}\n", ptr[0], ptr[1]);
    free(ptr);

    return EXIT_SUCCESS;
}
