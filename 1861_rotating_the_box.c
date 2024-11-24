/*
 * =====================================================================================
 *
 *       Filename:  1861_rotating_the_box.c
 *
 *    Description:  rotating the box
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

enum {
    STONE = '#',
    OBSTACLE = '*',
    EMPTY = '.'
} TYPES;

static void rearrange(char *arr, int length) {

    int offset = 0, count = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] == STONE) {
            offset = !count ? i : offset;
            count++;
        } else if (arr[i] == EMPTY && count) {
            memmove(arr+offset+1, arr+offset, count);
            arr[offset] = EMPTY;
            offset++;
        } else if (arr[i] == OBSTACLE) {
            count = 0; 
        }
    }
    return;
}

char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){

    char **result = (char **) calloc(*boxColSize, sizeof(char *));
    int column_size = *boxColSize; 
    int rindex = 0, cindex = 0;

    *returnSize = *boxColSize;
    *returnColumnSizes = (int *) calloc(*boxColSize, sizeof(int));

    for (int i = 0; i < boxSize; i++) {
        rearrange(box[i], boxColSize[i]);
    }

    for (int i = 0; i < column_size; i++) {
        result[rindex] = (char *) calloc(boxSize, sizeof(char));
        for (int j = boxSize-1; j >= 0; j--) {
            result[rindex][cindex++] = box[j][i];
        }
        (*returnColumnSizes)[rindex] = cindex;
        rindex++;
        cindex = 0;
    }
    return result;
}
