/*
 * =====================================================================================
 *
 *       Filename:  1313_decompress_run_length_encoded_list.c
 *
 *    Description:  decompress run length encoded list
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

#define BASIC_SIZE 100

static int *get_array(int r, int c, int *size) {

    int *arr = (int *) calloc(r, sizeof(int)), index = 0;

    for (int i = 0; i < r; i++)
        arr[i] = c;

    *size = r;

    return arr;
}

int* decompressRLElist(int* nums, int numsSize, int* returnSize) {

    int *result = (int *) calloc(BASIC_SIZE, sizeof(int)), *arr = NULL;
    int rindex = 0, size = 0, rsize = BASIC_SIZE;

    for (int i = 0; i < numsSize; i += 2) {

        arr = get_array(nums[i], nums[i+1], &size);

        if ((rindex + size) > rsize) {
            rsize += BASIC_SIZE; 
            result = (int *) reallocarray(result, rsize, sizeof(int));
        }

        memcpy(result + rindex, arr, sizeof(int) * size);
        rindex += size;
        free(arr);
    }

    *returnSize = rindex;

    return result;
}

