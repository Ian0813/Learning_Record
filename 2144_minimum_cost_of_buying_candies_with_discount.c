/*
 * =====================================================================================
 *
 *       Filename:  2144_minimum_cost_of_buying_candies_with_discount.c
 *
 *    Description:  minimum cost of buying candies with discount
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
#include <unistd.h>

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
            if (arr[head] < arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last - 1);
        quick_sort(arr, last + 1, end);
    }
    return;
}

int minimumCost(int* cost, int costSize) {

    int min_cost = 0, count = 0;

    if (costSize > 0) 
        quick_sort(cost, 0, costSize-1);

    for (int i = 0; i < costSize; i++) {

        if (count == 2) {
            count = 0;
            continue; 
        }
        count++;
        min_cost += cost[i];
    }

    return min_cost;
}
