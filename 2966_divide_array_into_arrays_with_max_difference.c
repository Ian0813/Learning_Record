/*
 * =====================================================================================
 *
 *       Filename:  2966_divide_array_into_arrays_with_max_difference.c
 *
 *    Description:  divide array into arrays with max difference
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

typedef enum {false, true} bool;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define UNIT_SIZE 3

static void merge_operation(int *nums, int head, int middle, int end) {

    int arr1Size = (middle-head)+1, arr2Size = end-middle;
    int arr1[arr1Size], arr2[arr2Size];
    int a1Index = 0, a2Index = 0, index = head;

    for (int i = a1Index; i < arr1Size; i++) {
        arr1[i] = nums[head+i];
    }

    for (int i = a2Index; i < arr2Size; i++) {
        arr2[i] = nums[middle+i+1];
    }

    while (a1Index < arr1Size && a2Index < arr2Size) {
        if (arr1[a1Index] < arr2[a2Index]) {
            nums[index++] = arr1[a1Index++];
        } else {
            nums[index++] = arr2[a2Index++];
        }
    }

    while (a1Index < arr1Size) {
        nums[index++] = arr1[a1Index++]; 
    }

    while (a2Index < arr2Size) {
        nums[index++] = arr2[a2Index++]; 
    }
    return;
}

static void merge_sort(int *nums, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(nums, head, middle);
        merge_sort(nums, middle+1, end);
        merge_operation(nums, head, middle, end);
    }
    return;
}

static bool dispatch(int **result, int *nums, int numsSize, int *rsize, int boundary) {

    bool rc = true;

    for (int i = 0; i < numsSize; i += UNIT_SIZE) {
        memcpy(result[*rsize], &nums[i], sizeof(int) * UNIT_SIZE);
        
        if ((result[*rsize][2]-result[*rsize][0]) > boundary) {
            rc = false;
            *rsize = 0;
            break;
        }
        *rsize += 1;
    }
    return rc; 
}

static int **allocate(int length) {

    int **ptr = NULL;

    ptr = (int **) calloc(length, sizeof(int *)); 

    for (int i = 0; i < length; i++) {
        ptr[i] = (int *) calloc(UNIT_SIZE, sizeof(int));
    }

    return ptr; 
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    if (numsSize) {

        *returnSize = 0; 
        merge_sort(nums, 0, numsSize-1);
        result = allocate(numsSize/3);

        if (dispatch(result, nums, numsSize, returnSize, k)) {
            *returnColumnSizes = (int *) calloc(*returnSize, sizeof(int)); 
            for (int i = 0; i < *returnSize; i++)
                (*returnColumnSizes)[i] = UNIT_SIZE;
        }
    }
    return result;
}

