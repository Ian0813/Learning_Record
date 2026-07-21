/*
 * =====================================================================================
 *
 *       Filename:  2335_minimum_amount_of_time_to_fill_cups.c
 *
 *    Description:  minimum amount of time to fill cups
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

    if (!v1 || !v2)
        return;

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
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}

int fillCups(int* amount, int amountSize) {

    int count = 0;

    if (amountSize) {

        quick_sort(amount, 0, amountSize-1);

        while (amount[0]) {
            count++;
            for (int i = 0, items = 2; items && i < amountSize; i++) {
                if (amount[i]) {
                    amount[i]--;
                    items--;
                }    
            }
            quick_sort(amount, 0, amountSize-1);
        }
    }
    return count;
}
