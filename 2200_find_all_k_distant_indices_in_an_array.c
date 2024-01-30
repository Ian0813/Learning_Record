/*
 * =====================================================================================
 *
 *       Filename:  2200_find_all_k_distant_indices_in_an_array.c
 *
 *    Description:  Find all k distant indices in an array  
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

#define ABS(val) ((val) < 0 ? (val) * -1 : (val))

#define MAX 1001

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {

    int indices[MAX] = {0}, index = 0, result_index = 0;
    int *result = (int *) malloc(sizeof(int) * MAX);

    memset(result, 0, sizeof(int) * MAX);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            indices[index++] = i;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < index; j++) {
            if (ABS(i-indices[j]) <= k) {
                result[result_index++] = i;
                break;
            }
        }    
    }
    *returnSize = result_index;

    return result;
}

int main(void) {
   return EXIT_SUCCESS;     
}
