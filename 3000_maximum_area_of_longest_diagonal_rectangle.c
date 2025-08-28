/*
 * =====================================================================================
 *
 *       Filename:  3000_maximum_area_of_longest_diagonal_rectangle.c
 *
 *    Description:  maximum area of longest diagonal rectangle
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define GET_POWER(val) ((val) * (val))
#define GET_AREA(length, width) ((length) * (width))

struct diagonal_info {
    double diagonal_size;
    int area;
};

enum {
    WIDTH_INDEX = 1,
    LENGTH_INDEX = 0
};

static void find_maxarea(int **dimensions, int row, struct diagonal_info *info) {

    double value = 0.0F;
    int area = 0;

    for (int i = 0; i < row; i++) {

        value = sqrt((GET_POWER(dimensions[i][LENGTH_INDEX]) + GET_POWER(dimensions[i][WIDTH_INDEX])));
        area = GET_AREA(dimensions[i][WIDTH_INDEX], dimensions[i][LENGTH_INDEX]);

        if (value > info->diagonal_size || (value == info->diagonal_size && area > info->area)) {
            info->diagonal_size = value;
            info->area = GET_AREA(dimensions[i][LENGTH_INDEX], dimensions[i][WIDTH_INDEX]); 
        }
    }

    return;  
}

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {

    struct diagonal_info info = {0};

    find_maxarea(dimensions, dimensionsSize, &info);

    return info.area;
}
