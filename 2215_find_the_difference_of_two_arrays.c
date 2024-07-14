/*
 * =====================================================================================
 *
 *       Filename:  2215_find_the_difference_of_two_arrays.c
 *
 *    Description:  Find the difference of two arrays  
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

#define MAX_SIZE 1000 
#define RESULT_FIELDS 2

void check_difference(int *n1, int n1Size, int *n2, int n2Size, int **result, int *r_index, int index) {

    int exist = 0;

    for (int i = 0; i < n1Size; i++) {
        for (int j = 0; j < n2Size; j++) {
            if (n1[i] == n2[j]) {
                exist = 1;                            
                break;
            }
        }
        if (!exist) {
            for (int k = 0; k < *r_index; k++) {
                if (result[index][k] == n1[i]) {
                    exist = 1;
                }
            }
            if (!exist)
                result[index][(*r_index)++] = n1[i];
        }
        exist = 0;
    }
    return;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {

    int **result = {NULL};
    int r1_index = 0, r2_index = 0;

    result = (int **) calloc(RESULT_FIELDS, sizeof(int *));
    *returnColumnSizes = (int *) calloc(RESULT_FIELDS, sizeof(int));

    for (int i = 0; i < RESULT_FIELDS; i++) {
        result[i] = (int *) calloc(MAX_SIZE, sizeof(int));
    }

    check_difference(nums1, nums1Size, nums2, nums2Size, result, &r1_index, 0);
    check_difference(nums2, nums2Size, nums1, nums1Size, result, &r2_index, 1);

    (*returnColumnSizes)[0] = r1_index;   
    (*returnColumnSizes)[1] = r2_index;   

    *returnSize = RESULT_FIELDS;
    return result;
}
