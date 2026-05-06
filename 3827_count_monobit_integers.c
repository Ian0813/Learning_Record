/*
 * =====================================================================================
 *
 *       Filename:  3827 count monobit integers.c
 *
 *    Description:  count monobit integers
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

#define MAX_VALUE 1000

static void power_two_arr_init(int *arr, int *arrSize, int max) {

    int val = 1; 

    arr[*arrSize] = 0;
    *arrSize += 1;

    while (val < max) {
        arr[*arrSize] = val;    
        *arrSize += 1;
        val *= 2;
    }
    return;
}

static int binary_search(int *arr, int head, int end, int target) {

    int middle = (head + end)/2;

    if (head < end) {
        if (arr[middle] == target) {
            ;
        } else if (arr[middle] > target) {
            middle = binary_search(arr, head, middle, target);
        } else if (arr[middle] < target) {
            middle = binary_search(arr, middle+1, end, target);
        }
    }

    return middle;
}

int countMonobit(int n) {

    int power_two_arr[BUFSIZ] = {0};
    int count = 0, size = 0, index = 0;

    power_two_arr_init(power_two_arr, &size, MAX_VALUE);
    
    for (int i = 0; i <= n; i++) {
        if (i > 1) {
            index = binary_search(power_two_arr, 0, size, i);
            count = index < size ? power_two_arr[index] == (i+1) ? (count + 1) : count : count;
        } else {
            count++; 
        }
    }

    return count;
}
