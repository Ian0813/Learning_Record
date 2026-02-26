/*
 * =====================================================================================
 *
 *       Filename:  1886_determine_whether_matrix_can_be_obtained_by_rotation.c
 *
 *    Description:  determine whether matrix can be obtained by rotation
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

typedef enum {false, true} bool;

typedef enum {
    DEGREE_90 = 0,
    DEGREE_180 = 1,
    DEGREE_270 = 2,
    DEGREE_360 = 3,
    DEGREE_LEN
} degree_t;

static void rotate_90(int **mat, int len, int **result) {

    int col_index = len-1; 

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            result[j][col_index-i] = mat[i][j];
        }
    }

    return;
}

static void mat_refresh(int **mat, int len, int **result) {

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            mat[i][j] =result[i][j];  
        }
    }

    return;
}

static bool mat_is_match(int **target, int **result, int len) {

    bool rc = true;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (result[i][j] != target[i][j]) {
                rc = false;      
                break;
            }
        }
    }

    return rc;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {

    bool rc = false;
    int **result = 0;

    result = (int **) calloc(matSize, sizeof(int *));

    for (int i = 0; i < matSize; i++) {
        result[i] = (int *) calloc(matSize, sizeof(int));
    }

    for (int i = DEGREE_90; i < DEGREE_LEN; i++) {
        rotate_90(mat, matSize, result);

        if (mat_is_match(target, result, matSize)) {
            rc = true; 
            break;
        }    
        mat_refresh(mat, matSize, result);
    }

    for (int i = 0; i < matSize; i++) {
        free(result[i]);
    }
    free(result);

    return rc;
}
