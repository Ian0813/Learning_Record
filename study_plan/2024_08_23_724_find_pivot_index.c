/*
 * =====================================================================================
 *
 *       Filename:  2024_08_23_724_find_pivot_index.c
 *
 *    Description:  Find Pivot Index  
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

#define SUM(arr, s, e, value) for (int k = s; k < e; k++) {value += arr[k];}

int find_pivot(int *nums, int size) {

    int *sumLeft = NULL, *sumRight = NULL; 
    int pivot = -1;

    sumLeft = (int *) calloc(size, sizeof(int));
    sumRight = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        if (!i)
            sumLeft[i] = 0;
        else {
            sumLeft[i] = sumLeft[i-1] + nums[i-1]; 
        }
    }

    for (int i = size-1; i >= 0; i--) {

        if (i == size-1) {
            sumRight[i] = 0;
        } else {
            sumRight[i] = sumRight[i+1] + nums[i+1]; 
        }
    }

    for (int i = 0; i < size; i++) {
        if (sumLeft[i] == sumRight[i]) {
            pivot = i; 
            break;
        }
    }
    free(sumLeft);
    free(sumRight);
    return pivot;
}

int pivotIndex(int* nums, int numsSize) {

    int pivot = 0;

    if (numsSize > 1)
        pivot = find_pivot(nums, numsSize);
    return pivot;  
}

int main(void) {

    int arr[] = {1,7,3,6,5,6};

    printf("pivot: %d\n", pivotIndex(arr, sizeof(arr)/sizeof(*arr)));

    return EXIT_SUCCESS;
}
