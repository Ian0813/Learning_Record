/*
 * =====================================================================================
 *
 *       Filename:  3285_find_indices_of_stable_mountains.c
 *
 *    Description:  find indices of stable mountains
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {

    int *result = NULL;

    *returnSize = 0;

    result = (int *) calloc(heightSize, sizeof(int));

    for (int i = 1; i < heightSize; i++) {
        if (height[i-1] > threshold) {
            result[*returnSize] = i;
            *returnSize += 1;
        }
    }

    return result;
}
