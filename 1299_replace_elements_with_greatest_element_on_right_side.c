/*
 * =====================================================================================
 *
 *       Filename:  1299_replace_elements_with_greatest_element_on_right_side.c
 *
 *    Description:  Replace elements with greatest element on right side  
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {

    int *result = (int *) malloc(sizeof(int) * arrSize); 
    int max = 0, index = 0;

    memset(result, 0, sizeof(int) * arrSize);

    for (int i = arrSize - 1; i >= 0; i--) {

        if (i == (arrSize-1)) {
           result[i] = -1; 
        } else {
           result[i] = max;
        }    
        
        if (arr[i] > max) {
           max = arr[i];
        }
    }

    *returnSize = arrSize;

    return result;
}
