/*
 * =====================================================================================
 *
 *       Filename:  3010_divide_an_array_into_subarrays_with_minimum_cost_i.c
 *
 *    Description:  divide an array into subarrays with minimum cost i
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

        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last - 1);
        quick_sort(arr, last + 1, end);
    }

    return;
}

int minimumCost(int* nums, int numsSize) {

    int cost = 0;

    cost += nums[0];

    quick_sort(&nums[1], 0, numsSize-2);
    cost += (nums[1] + nums[2]);

    return cost;
}
