/*
 * =====================================================================================
 *
 *       Filename:  1640_check_array_formation_through_concatenation.c
 *
 *    Description:  check array formation through concatenation
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
#include <limits.h>
#include <stdbool.h>

static int get_first_matched(int *arr, int arrSize, int val) {

    int index = -1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == val) {
            index = i;     
            break;
        }
    }
    return index;
}

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize) {

    int fit_count = arrSize, index = 0;

    for (int i = 0; i < piecesSize; i++) {
        if ((index = get_first_matched(arr, arrSize, pieces[i][0])) != -1) {

            if ((arrSize - index) < piecesColSize[i])
                continue; 

            if (!memcmp(&arr[index], pieces[i], sizeof(int) * piecesColSize[i])) {
                if (fit_count >= piecesColSize[i]) 
                    fit_count -= piecesColSize[i];
            }
        }

        if (!fit_count) {
            break; 
        }
    }
    return fit_count == 0 ? true : false;
}
