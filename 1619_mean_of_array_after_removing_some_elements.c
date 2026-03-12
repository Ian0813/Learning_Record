/*
 * =====================================================================================
 *
 *       Filename:  1619_mean_of_array_after_removing_some_elements.c
 *
 *    Description:  mean of array after removing some elements
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

double trimMean(int* arr, int arrSize) {

    double result = 0.0;
    int count = 0;

    quick_sort(arr, 0, arrSize-1);

    for (int i = 0; i < arrSize; i++) {
        if (((i+1) * 100) <= (5 * arrSize) || ((i+1)*100) > (95 * arrSize)) {
            count++;
            arr[i] = 0;
        }
    }

    for (int i = 0; i < arrSize; i++) {
        result += arr[i];
    }

    return result / ((arrSize-count) * 1.0);
}
