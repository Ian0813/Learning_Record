/*
 * =====================================================================================
 *
 *       Filename:  2640_find_the_score_of_all_prefixes_of_an_array.c
 *
 *    Description:  find the score of all prefixes of an array
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
static void get_maximum_array(int *nums, int *max_array, int numsSize) { 

    int max = 0;

    for (int i = 0; i < numsSize; i++) {
        max = max < nums[i] ? nums[i] : max;
        max_array[i] = max;
    } 
    return;
}  

long long* findPrefixScore(int* nums, int numsSize, int* returnSize) { 

    long long *result = NULL; 
    int *max_array = NULL;

    if (numsSize) { 

        result = (long long *) calloc(numsSize, sizeof(long long));
        max_array = (int *) calloc(numsSize, sizeof(int));

        get_maximum_array(nums, max_array, numsSize);

        for (int i = 0; i < numsSize; i++) {
            result[i] = !i ? (nums[i]*2) : (nums[i]+max_array[i]+result[i-1]);
        } 
        *returnSize = numsSize;
        free(max_array);
    } 
    return result;
}
