/*
 * =====================================================================================
 *
 *       Filename:  1829_maximum_xor_for_each_query.c
 *
 *    Description:  maximum xor for each query
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

static int get_power_of_2(int exp) {

    if (!exp) {
        return 1;
    }
    return get_power_of_2(exp-1)*2;
}    

static void get_xor_values(int *nums, int numsSize, int *xor_values, int *xindex) {

    int temp = 0;

    xor_values[*xindex] = nums[0]; 
    *xindex += 1; 

    for (int i = 1; i < numsSize; i++, *xindex += 1) {
        xor_values[i] = nums[i] ^ xor_values[i-1];
    }

    for (int i = *xindex-1, j = 0; i > j; i--, j++) {
        temp = xor_values[i];
        xor_values[i] = xor_values[j];
        xor_values[j] = temp;
    }
    return;
}

int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {

    int *xor_values = NULL, *result = NULL;
    int xindex = 0, rindex = 0, maximum = 0; 

    if (numsSize) {

        result = (int *) calloc(numsSize, sizeof(int));               
        xor_values = (int *) calloc(numsSize, sizeof(int));               
        get_xor_values(nums, numsSize, xor_values, &xindex);
        maximum = get_power_of_2(maximumBit)-1;

        for (int i = 0; i < xindex; i++) {
            result[i] = maximum ^ xor_values[i];
        }
        *returnSize = numsSize;              
        free(xor_values);
    }        
    return result;
}
