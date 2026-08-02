/*
 * =====================================================================================
 *
 *       Filename:  2679_sum_in_a_matrix.c
 *
 *    Description:  sum in a matrix
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/param.h>

static void merge_process(int *arr, int head, int middle, int end) {

    int a1Size = middle - head + 1, a2Size = end - middle;
    int a1[a1Size], a2[a2Size];
    int a1Index = 0, a2Index = 0, index = head;

    for (int i = 0; i < a1Size; i++) {
        a1[i] = arr[head + i];
    }

    for (int i = 0; i < a2Size; i++) {
        a2[i] = arr[middle + i + 1];
    }

    while (a1Index < a1Size && a2Index < a2Size) {
        if (a1[a1Index] > a2[a2Index]) {
            arr[index++] = a1[a1Index++];  
        } else {
            arr[index++] = a2[a2Index++];  
        }
    }

    while (a1Index < a1Size) {
        arr[index++] = a1[a1Index++];  
    }

    while (a2Index < a2Size) {
        arr[index++] = a2[a2Index++];  
    }
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head + end) / 2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_process(arr, head, middle, end);
    }
    return;
}

int matrixSum(int** nums, int numsSize, int* numsColSize) {

    int max = 0, cumulate = 0;

    for (int i = 0; i < numsSize; i++)            
        merge_sort(nums[i], 0, numsColSize[i]-1);

    for (int i = 0; i < numsColSize[0]; i++, max = 0) {
        for (int j = 0; j < numsSize; j++) {
            max = MAX(nums[j][i], max);        
        }
        cumulate += max;
    }    
    return cumulate;
}
