/*
 * =====================================================================================
 *
 *       Filename:  733_flood_fill.c
 *
 *    Description:  flood fill
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

#define CHECK_ROW(sr, boundary) ((sr) >= boundary->lrb && (sr) < boundary->urb) 
#define CHECK_COL(sc, boundary) ((sc) >= boundary->lcb && (sc) < boundary->ucb) 

struct boundaries {
    int lrb;
    int urb;
    int lcb;
    int ucb;
};

static void field_check(int **image, int sr, int sc, struct boundaries *boundary, int source, int color) {

    if (CHECK_ROW(sr, boundary) && CHECK_COL(sc, boundary)) {
        if (image[sr][sc] == source) {
            image[sr][sc] = color;
            field_check(image, sr-1, sc, boundary, source, color);
            field_check(image, sr+1, sc, boundary, source, color);
            field_check(image, sr, sc-1, boundary, source, color);
            field_check(image, sr, sc+1, boundary, source, color);
        }
    }
    return;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {

    if (image[sr][sc] != color) {
        struct boundaries boundary = {.urb = imageSize, .ucb = *imageColSize};
        int source = image[sr][sc];

        field_check(image, sr, sc, &boundary, source, color);
    }

    *returnSize = imageSize;  
    *returnColumnSizes = imageColSize;  

    return image;
}
