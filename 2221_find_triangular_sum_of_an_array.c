/*
 * =====================================================================================
 *
 *       Filename:  2221_find_triangular_sum_of_an_array.c
 *
 *    Description:  find triangular sum of an array
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

#define MAX_LENGTH 1000
#define GET_UPDATE_VALUE(v1, v2) (((v1)+(v2))%10)

int triangularSum(int* nums, int numsSize) {

    int arr[MAX_LENGTH] = {0}; 
    int update_arr[MAX_LENGTH] = {0}; 
    int index = 0, arr_size = numsSize;

    memcpy(arr, nums, sizeof(int)*numsSize);

    do {
        for (int i = 0; i < (arr_size-1); i++) {
            update_arr[index++] = GET_UPDATE_VALUE(arr[i], arr[i+1]); 
        }        

        if (index) {
            arr_size = index; 
            memcpy(arr, update_arr, sizeof(int)*index);
            memset(update_arr, 0, sizeof(int)*index);
            index = 0;
        }
    } while (arr_size > 1); 

    return arr[0];
}
