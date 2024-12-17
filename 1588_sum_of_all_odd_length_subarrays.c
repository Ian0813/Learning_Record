/*
 * =====================================================================================
 *
 *       Filename:  1588_sum_of_all_odd_length_subarrays.c
 *
 *    Description:  sum of all odd length subarrays

 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

static int sum_range(int *arr, int start, int len) {

    int sum = 0;

    for (int i = start; i < start+len; i++) {
        sum += arr[i];
    }
    return sum;
}

int sumOddLengthSubarrays(int* arr, int arrSize) {

    int length = 1;
    int result = 0;

    while (length <= arrSize) {
        for (int i = 0; i < (arrSize-length)+1; i++) {
            result += sum_range(arr, i, length);
        }
        length += 2;
    }
    return result;
}
