/*
 * =====================================================================================
 *
 *       Filename:  2395_find_subarrays_with_equal_sum.c
 *
 *    Description:  find subarrays with equal sum
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

typedef enum {false, true} bool;


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

bool findSubarrays(int* nums, int numsSize) {

    bool result = false;
    int *sum_arr = (int *) malloc(numsSize * sizeof(int));
    int sindex = 0;

    if (numsSize) {
        memset(sum_arr, 0, numsSize * sizeof(int));

        for (int i = 0; i < (numsSize-1); i++) {
            sum_arr[sindex++] = nums[i] + nums[i+1];
        }

        quick_sort(sum_arr, 0, sindex);

        for (int i = 0; i < (sindex-1); i++) {
            if (sum_arr[i] == sum_arr[i+1]) {
                result = true;
                break;
            }
        }
        free(sum_arr);
    }
    return result;
}
