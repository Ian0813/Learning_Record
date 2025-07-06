/*
 * =====================================================================================
 *
 *       Filename:  1394_find_lucky_integer_in_an_array.c
 *
 *    Description:  find lucky integer in an array
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

#define TABLE_SIZE 501 

static void count_frequency(int *table, int *arr, int arrSize, int *max) {

    for (int i = 0; i < arrSize; i++) {
        table[arr[i]]++;
        *max = *max < arr[i] ? arr[i] : *max;
    }

    return;
}

static int get_lucky(int *table, int max) {

    int lucky = -1;

    for (int i = max; i >= 1; i--) {
        if (table[i] == i) {
            lucky = i;
            break;
        }
    }
    return lucky;
}

int findLucky(int* arr, int arrSize) {

    int counting[TABLE_SIZE] = {0}, lucky = 0, max = 0;
    
    count_frequency(counting, arr, arrSize, &max);
    lucky = get_lucky(counting, max);

    return lucky;
}
