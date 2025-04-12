/*
 * =====================================================================================
 *
 *       Filename:  1828_queries_on_number_of_points_inside_a_circle.c
 *
 *    Description:  queries on number of points inside a circle
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

typedef enum {
    false,
    true
} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define POWER(value) ((value)*(value))

enum {
    X_POINT = 0,
    Y_POINT = 1,
    R_POINT = 2
};

static int get_euclidean(int *point, int *center) {

    int distance = 0;

    distance = POWER(abs(point[X_POINT]-center[X_POINT])) + POWER(abs(point[Y_POINT]-center[Y_POINT]));

    return distance;
}

static bool check_range(int *center, int *point) {

    bool rc = false;
    int distance = 0;

    distance = get_euclidean(center, point);

    if (distance <= POWER(center[R_POINT])) {
        rc = true;
    }
    return rc;
}

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {

    int *result = NULL;

    if (queriesSize) {

        result = (int *) calloc(queriesSize, sizeof(int));

        for (int i = 0; i < queriesSize; i++) {
            for (int j = 0; j < pointsSize; j++) {
                if (check_range(queries[i], points[j])) {
                    result[i]++;
                }
            }
        }
        *returnSize = queriesSize;
    }
    return result;
}
