/*
 * =====================================================================================
 *
 *       Filename:  2946_matrix_similarity_after_cyclic_shifts.c
 *
 *    Description:  matrix similarity after cyclic shifts
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

#define CONVERT_INDEX(index, size) (((index) >= 0) ? ((index) == (size)) ? 0 : index : (size-1))
#define GET_ROWTYPE(number) ((number) % 2 ? ROW_ODD : ROW_EVEN)

typedef enum {
    ROW_ODD = 0,
    ROW_EVEN = 1
} row_type;

static void row_move(int *data, int size, int count, row_type rtype) {

    int next = 0, dest = 0, cur = 0;

    if (count) {
        if (rtype == ROW_EVEN) {
            next = data[size-1];
            for (int i = size-1; i; i--) {
                cur = next;
                dest = CONVERT_INDEX((i-1), size); 
                next = data[dest]; 
                data[dest] = cur; 
            }
            data[size-1] = next;
        } else if (rtype == ROW_ODD) {
            next = data[0];
            for (int i = 0; i < (size-1); i++) {
                cur = next;
                dest = CONVERT_INDEX((i+1), size);
                next = data[dest];
                data[dest] = cur;
            }
            data[0] = next;
        }
        row_move(data, size, count-1, rtype); 
    }
    return;
}

static int ** matrix_duplicate(int **matrix, int row, int col) {

    int **ptr = NULL;

    ptr = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        ptr[i] = (int *) calloc(col, sizeof(int));

        for (int j = 0; j < col; j++) {
            ptr[i][j] = matrix[i][j];   
        }
    }

    return ptr;
}

static void matrix_free(int **data, int row_size) {

    if (row_size) {
        free(data[row_size-1]);
        matrix_free(data, row_size-1);
    } else {
        free(data);
    }

    return;
}    

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {

    int **data = NULL;
    bool rc = true;

    data = matrix_duplicate(mat, matSize, *matColSize);

    for (int i = 0; i < matSize; i++) {
        row_move(data[i], *matColSize, k % (*matColSize), GET_ROWTYPE(i));
    }

    for (int i = 0; rc && i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] != data[i][j]) {
                rc = false;  
                break;
            }    
        }
    }

    matrix_free(data, matSize);
    return rc;
}
