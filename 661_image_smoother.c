/*
 * =====================================================================================
 *
 *       Filename:  661_image_smoother.c
 *
 *    Description:  image smoother
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

#define CHECK_SCOPE(index, limit) ((index)>=0 && (index)<limit)

typedef enum {
    TOP_LEVEL = -1,
    MIDDLE_LEVEL = 0,
    BOTTOM_LEVEL = 1
} smoother_level_t;

static int **allocate(int row_size, int column_size) {

    int **result = NULL;

    result = (int **) calloc(row_size, sizeof(int *));

    for (int i = 0; i < row_size; i++) {
        result[i] = (int *) calloc(column_size, sizeof(int));
    }
    return result;
}

static int smoother_retrival(int **img, int rlimit, int climit, int ri, int ci) {

    int value = -1;

    if (CHECK_SCOPE(ri, rlimit) && CHECK_SCOPE(ci, climit)) {
        return img[ri][ci];
    }
    return value;
}

static int get_level_sum(int **img, int rlimit, int climit, int rindex, int cindex, smoother_level_t level, int *count) {

    int value = 0, sum = 0;

    value = smoother_retrival(img, rlimit, climit, rindex+level, cindex);
    *count += (value == -1 ? 0 : 1);
    sum += (value == -1 ? 0 : value);
    value = smoother_retrival(img, rlimit, climit, rindex+level, cindex+1);
    *count += (value == -1 ? 0 : 1);
    sum += (value == -1 ? 0 : value);
    value = smoother_retrival(img, rlimit, climit, rindex+level, cindex-1);
    *count += (value == -1 ? 0 : 1);
    sum += (value == -1 ? 0 : value);

    return sum;
}

static int get_average(int **img, int rlimit, int climit, int rindex, int cindex) {

    int sum = 0, value = 0;
    int division = 0;

    sum += get_level_sum(img, rlimit, climit, rindex, cindex, TOP_LEVEL, &division);
    sum += get_level_sum(img, rlimit, climit, rindex, cindex, MIDDLE_LEVEL, &division);
    sum += get_level_sum(img, rlimit, climit, rindex, cindex, BOTTOM_LEVEL, &division);

    if (division)
        sum = (sum/division);
    return sum;
}

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    if (img) {

        result = allocate(imgSize, *imgColSize);

        for (int i = 0; i < imgSize; i++) {
            for (int j = 0; j < imgColSize[i]; j++) {
                result[i][j] = get_average(img, imgSize, imgColSize[i], i, j);
            }
        }

        *returnSize = imgSize;
        *returnColumnSizes = imgColSize;
    }
    return result;
}
