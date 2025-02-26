/*
 * =====================================================================================
 *
 *       Filename:  1720_decode_xored_array.c
 *
 *    Description:  decode xored array
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
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {

    int *result = (int *) calloc(encodedSize+1, sizeof(int));
    int index = 0;
    
    result[index++] = first;

    for (int i = 0; i < encodedSize; i++) {
        result[index] = first ^ encoded[i];

        if (index <= encodedSize)
            first = result[index++];
    } 

    *returnSize = encodedSize + 1;
    return result;
}
