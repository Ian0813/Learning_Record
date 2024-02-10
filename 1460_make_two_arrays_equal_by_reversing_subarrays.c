/*
 * =====================================================================================
 *
 *       Filename:  1460_make_two_arrays_equal_by_reversing_subarrays.c
 *
 *    Description:  Make two arrays equal by reversing subarrays   
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

#define MAX 1001 

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {

    int target_count[MAX] = {0}, arr_count[MAX] = {0};     

    for (int i = 0; i < targetSize; i++) {
        target_count[target[i]]++;
    }

    for (int i = 0; i < arrSize; i++) {
        arr_count[arr[i]]++;
    }
    return !memcmp(target_count, arr_count, sizeof(int) * MAX);
}

int main(void) {
    return EXIT_SUCCESS;
}

