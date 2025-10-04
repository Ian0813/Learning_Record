/*
 * =====================================================================================
 *
 *       Filename:  3467 transform array by parity.c
 *
 *    Description:  transform array by parity
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
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

typedef struct parity_recorder {
    int one_count; 
    int zero_count; 
} parity_recorder;

static void fill_parity_array(int *nums, int numsSize, parity_recorder *recorder) {

    if (!recorder)
        return;

    for (int i = 0; i < numsSize; i++) {
        (nums[i]%2) ? (recorder->one_count++) : (recorder->zero_count++);
    }

    return;
}

int* transformArray(int* nums, int numsSize, int* returnSize) {

    int *result = NULL;
    parity_recorder recorder = {.one_count = 0, .zero_count = 0};

    if (nums) {

        result = (int *) calloc(numsSize, sizeof(int));
        fill_parity_array(nums, numsSize, &recorder);

        for (int i = 0; i < numsSize; i++) {
            result[i] = (i < recorder.zero_count) ? 0 : 1; 
        }
    }    

    *returnSize = numsSize; 

    return result;
}
