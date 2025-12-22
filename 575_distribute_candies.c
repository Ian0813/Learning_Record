/*
 * =====================================================================================
 *
 *       Filename:  575_distribute_candies.c
 *
 *    Description:  distribute candies
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

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }    

        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}

int distributeCandies(int* candyType, int candyTypeSize) {

    int quantum = 0, last_type = 0, types_len = 0;

    if (candyTypeSize) {

        quick_sort(candyType, 0, candyTypeSize-1);
        quantum = candyTypeSize/2;      
        last_type = candyType[0];
        types_len++;

        for (int i = 1; i < candyTypeSize && types_len < quantum; i++) {
            if (last_type != candyType[i]) {
                last_type = candyType[i];
                types_len++;
            }    
        }
    }

    return types_len; 
}
