/*
 * =====================================================================================
 *
 *       Filename:  1051_height_checker.c
 *
 *    Description:  height checker   
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

static void swap(int *v1, int *v2) {

    int temp = *v1; 
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1; 

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }    
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int diff_counter(int *heights, int *expects, int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (expects[i] != heights[i])
            count++;
    }
    return count;
}

int heightChecker(int* heights, int heightsSize) {

    int *expects = (int *) calloc(heightsSize, sizeof(int));
    int counter = 0;

    memcpy(expects, heights, heightsSize*sizeof(int));
    quick_sort(expects, 0, heightsSize);
    counter = diff_counter(heights, expects, heightsSize);
    free(expects);

    return counter;
}
