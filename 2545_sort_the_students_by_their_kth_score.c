/*
 * =====================================================================================
 *
 *       Filename:  2545 sort the students by their kth score.c
 *
 *    Description:  sort the students by their kth score
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

static void swap(int **score, int pos1, int pos2, int size) {

    int temp[size];

    for (int i = 0; i < size; i++) {
        temp[i] = score[pos1][i];
    }
    for (int i = 0; i < size; i++) {
        score[pos1][i] = score[pos2][i];
    }
    for (int i = 0; i < size; i++) {
        score[pos2][i] = temp[i];
    }
    //memcpy(temp, &score[pos1], sizeof(int)*size);
    //memcpy(&score[pos1], &score[pos2], sizeof(int)*size);
    //memcpy(&score[pos2], temp, sizeof(int)*size);
    return;
}

void quick_sort(int **score, int head, int column, int end, int size) {


    int front = head, last = head, tail = end-1;    

    if (front < end) {
        while (last < tail) {
            if (score[head][column] < score[tail][column]) {
                last++;
                swap(score, last, tail, size); 
                continue;
            }
            tail--;
        }
        swap(score, head, last, size);
        quick_sort(score, head, column, last, size);
        quick_sort(score, last+1, column, end, size);
    }

    return;
}

int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    quick_sort(score, 0, k, scoreSize, *scoreColSize);
    *returnSize = scoreSize;
    *returnColumnSizes = (int *) calloc(scoreSize, sizeof(int));

    result = (int **) calloc(scoreSize, sizeof(int *));

    for (int i = 0; i < scoreSize; i++) {
        (*returnColumnSizes)[i] = scoreColSize[i];
        result[i] = (int *) calloc(scoreColSize[i], sizeof(int));
    }

    for (int i = 0; i < scoreSize; i++) {
        for (int j = 0; j < scoreColSize[i]; j++) {
            result[i][j] = score[i][j];
        }
    }
    return result;
}
