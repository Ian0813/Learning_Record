/*
 * =====================================================================================
 *
 *       Filename:  2433 find the original array of prefix xor.c
 *
 *    Description:  find the original array of prefix xor
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
int* findArray(int* pref, int prefSize, int* returnSize) {

    int *result = NULL;

    result = (int *) calloc(prefSize, sizeof(int));

    result[0] = pref[0];

    for (int i = 1; i < prefSize; i++) {
        result[i] = pref[i-1] ^ pref[i];
    }

    *returnSize = prefSize;
    return result;
}

