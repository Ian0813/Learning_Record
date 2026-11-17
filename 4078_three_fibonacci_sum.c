/*
 * =====================================================================================
 *
 *       Filename:  4078_three_fibonacci_sum.c
 *
 *    Description:  4078 three fibonacci sum
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
#include <stdbool.h>

static bool form_fibon_array(int *arr, int arr_size, int boundary) {

    int value = 0;
    unsigned int sum = 0U;

    if (arr_size < 3)
        return false;

    for (int i = 2; value < boundary; i++) {
        arr[i] = arr[i-1] + arr[i-2];
        value = arr[i];

        sum = value; 
        sum += arr[i-1] + arr[i-2];

        if (sum == boundary)
            return true;
    }
    return false;
}

bool threeFibonacciSum(int n) {

    int arr[BUFSIZ] = {0};        

    arr[0] = 0, arr[1] = 1;
    return form_fibon_array(arr, BUFSIZ, n);
}
