/*
 * =====================================================================================
 *
 *       Filename:  74_search_a_2d_matrix.c
 *
 *    Description:  search a 2d matrix
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

typedef enum {false, true} bool;

static int binary_search(int *arr, int head, int end, int target) {
    
    int middle = (head+end)/2, index = 0;

    printf("middle: %d\n", middle);

    if (head < end) {
        if (arr[middle] == target) {
            index = middle;        
        } else if (arr[middle] > target) {
            index = binary_search(arr, head, middle, target);
        } else if (arr[middle] < target) {
            index = binary_search(arr, middle+1, end, target);
        }
    } else {
        index = head;
    }
    return index;
}

static bool check_exist(int **matrix, int length, int row_index, int target) {

   int column_index = 0;
   bool result = false;

   column_index = binary_search(matrix[row_index], 0, length-1, target);

   if (column_index < length)
       result = target == matrix[row_index][column_index] ? true : false;

   return result;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) { 

    int *row_front = NULL;
    bool result = true;
    int row_index = 0, column_index = 0, index = 0;

    if (matrixSize) {
#if 0
        row_front = (int *) calloc(matrixSize, sizeof(int));

        for (int i = 0; i < matrixSize; i++) row_front[i] = *matrix[i];
 
        row_index = binary_search(row_front, 0, matrixSize-1, target);

        if (target != *matrix[row_index]) {

            result = false;

            row_index = row_index > 0 ? row_index - 1 : row_index;

            result = check_exist(matrix, row_index, matrixColSize[row_index], target);

            if (!result && row_index < matrixSize-1) {
                row_index += 1;
                result = check_exist(matrix, row_index, matrixColSize[row_index], target);
            }
        }
        free(row_front);
#endif
        for (int i = 0; i < matrixSize; i++) {
            index = binary_search(matrix[i], 0, matrixColSize[i], target);
            if (index < matrixColSize[i] && matrix[i][index] == target) {
                result = true;
                break;
            }
        }
    }
    return result;
}
