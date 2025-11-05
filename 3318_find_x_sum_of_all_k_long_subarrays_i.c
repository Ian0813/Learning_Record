/*
 * =====================================================================================
 *
 *       Filename:  3318_find_x_sum_of_all_k_long_subarrays_i.c
 *
 *    Description:  find x sum of all k long subarrays i
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 51

static int get_xsum(int *nums, int k, int x, int matrix_table[][MAX_SIZE], int level) {

    int value = 0, max_occur = 0, count = 0;

    for (int i = 0; i < k; i++) {

         matrix_table[level][nums[i]]++;

         if (matrix_table[level][nums[i]] > max_occur) {
             max_occur = matrix_table[level][nums[i]];
         }
    }

    for (int i = max_occur; i > 0; i--) {
        for (int j = MAX_SIZE-1; j > 0; j--) {
            if (matrix_table[level][j] == i) {
                value += (j * i);
                count++;
            }

            if (count == x) {
                goto RETURN_POINT;
            }
        }
    }

RETURN_POINT:;
    return value;;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {

    int matrix_table[MAX_SIZE][MAX_SIZE] = {0};
    int *result = NULL, index = 0; 

    result = (int *) calloc((numsSize - k) + 1, sizeof(int));

    if (numsSize >= x) {
        for (int i = 0; i <= (numsSize - k); i++) {
            result[index++] = get_xsum(&nums[i], k, x, matrix_table, i);
        }
        *returnSize = (numsSize - k) + 1; 
    } else {
        for (int i = 0; i < numsSize; i++) 
            result[0] += nums[i];
        *returnSize = 1; 
    }

    return result;
}
