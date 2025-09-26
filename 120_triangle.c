/*
 * =====================================================================================
 *
 *       Filename:  120 triangle.c
 *
 *    Description:  120 triangle
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
#include <stdint.h>
#include <limits.h>

#define MIN(v1, v2) ((v1) > (v2) ? (v2) : (v1))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {

    int rc = triangle[0][0], min = rc;

    if (triangleSize > 1) {

        min = INT_MAX;

        for (int i = 0; i < triangleSize - 1; i++) {
            for (int j = 0; j < triangleColSize[i]; j++) {
                if (!j) {
                    triangle[i+1][j] += triangle[i][j];
                } else {
                    triangle[i+1][j] += MIN(triangle[i][j], triangle[i][j-1]);
                }
            }
            triangle[i+1][triangleColSize[i]] += triangle[i][triangleColSize[i]-1];
        }
    }

    for (int i = 0; i < triangleColSize[triangleSize-1]; i++) {
        if (min > triangle[triangleSize-1][i]) {
            min = triangle[triangleSize-1][i];
        }
    }

    return min;
}
