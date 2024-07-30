/*
 * =====================================================================================
 *
 *       Filename:  78_subsets.c
 *
 *    Description:  Subsets  
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

int two_power_of_n(int n) {

    int val = n > 0 ? 1 : 0;

    while (n--) {
        val = 2 * val;
    }
    return val;
}

void find_allsubset(int *nums, int cur_index, int nums_size, int **result, int *rindex, int *returnColumnSizes) {

    int offset = 1, boundary = 0;
    int i = 0, j = 0;

    if (cur_index < nums_size) {

        if (*rindex) {
            boundary = *rindex;
            for (i = 0; i < boundary; i++) {
                result[*rindex] = (int *) calloc(returnColumnSizes[i]+1, sizeof(int));    
                //for (j = 0; j < returnColumnSizes[i]; j++) {
                //    result[*rindex][j] = result[i][j];
                //}
                memcpy(result[*rindex], result[i], sizeof(int)*returnColumnSizes[i]);
                result[*rindex][returnColumnSizes[i]] = nums[cur_index];
                returnColumnSizes[*rindex] = returnColumnSizes[i]+1;
                *rindex += 1;
            }
        }

        result[*rindex] = (int *) calloc(1, sizeof(int));
        returnColumnSizes[*rindex] = 1;
        result[*rindex][0] = nums[cur_index];
        *rindex += 1;

        find_allsubset(nums, cur_index+1, nums_size, result, rindex, returnColumnSizes);
    }
    return;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int arr_len = 0;
    int **result = NULL;
    int rindex = 0;

    result = (int **) calloc(BUFSIZ, sizeof(int *));
    *returnColumnSizes = (int *) calloc(BUFSIZ, sizeof(int)); 

    find_allsubset(nums, 0, numsSize, result, &rindex, *returnColumnSizes);
    result[rindex] = (int *) calloc(0, sizeof(int));
    (*returnColumnSizes)[rindex] = 0;
    rindex += 1;
    *returnSize = rindex;

    return result;
}

int main(void) {

    subsets(NULL, 10, NULL, NULL);

    return EXIT_SUCCESS;
}
