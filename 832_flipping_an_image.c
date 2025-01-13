/*
 * =====================================================================================
 *
 *       Filename:  832_flipping_an_image.c
 *
 *    Description:  Flipping an image  
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

#define INVERT_BINARY(b) (!(b) ? 1 : 0)

int ** allocate_result(int imageSize, int *imageColSize) {

    int **ptr = NULL;    

    ptr = (int **) calloc(imageSize, sizeof(int *));

    for (int i = 0; i < imageSize; i++) {
        ptr[i] = (int *) calloc(imageColSize[i], sizeof(int));
    }
    return ptr;
}    

static void invert_image(int **image, int imageSize, int *imageColSize, int **result) {

    if (imageSize) {

        for (int i = 0; i < imageSize; i++) {
            for (int origin = imageColSize[i]-1, rindex = 0; rindex < imageColSize[i]; rindex++, origin--) {
                result[i][rindex] = INVERT_BINARY(image[i][origin]);
            }
        }
    }
    return;
}

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL; 

    if (imageSize) {

        result = allocate_result(imageSize, imageColSize);

        invert_image(image, imageSize, imageColSize, result);

        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
    }
    return result;
}
