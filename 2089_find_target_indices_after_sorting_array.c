/*
 * =====================================================================================
 *
 *       Filename:  2089_find_target_indices_after_sorting_array.c
 *
 *    Description:  find target indices after sorting array
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

void merge_process(int *arr, int head, int middle, int end) {

    int a1size = (middle-head)+1, a2size = (end-middle);
    int a1[a1size], a2[a2size]; 
    int a1index = 0, a2index = 0, index = head;

    while (a1index < a1size) {
        a1[a1index++] = arr[head+a1index];
    }

    while (a2index < a2size) {
        a2[a2index++] = arr[middle+a2index+1];
    }

    a1index = a2index = 0;

    while (a1index < a1size && a2index < a2size) {
        if (a1[a1index] < a2[a2index]) {
            arr[index++] = a1[a1index++];
        } else {
            arr[index++] = a2[a2index++];
        }
    }

    while (a1index < a1size) {
        arr[index++] = a1[a1index++];
    }

    while (a2index < a2size) {
        arr[index++] = a2[a2index++];
    }
    return;
}

void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);             
        merge_sort(arr, middle+1, end);             
        merge_process(arr, head, middle, end);
    }
    return;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {

    int *result = NULL;
    int *index = returnSize;

    *returnSize = 0;

    if (numsSize) {
        result = (int *) calloc(numsSize, sizeof(int));
        merge_sort(nums, 0, numsSize-1);

        for (int i = 0; i < numsSize; i++) {
            if (target == nums[i]) {
                result[*index] = i;    
                *index += 1;
            }
        }
    }
    return result;
}
