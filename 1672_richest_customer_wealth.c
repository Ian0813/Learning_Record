/*
 * =====================================================================================
 *
 *       Filename:  1672 richest customer wealth.c
 *
 *    Description:  richest customer wealth
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

static int get_sum(int *arr, int len) {

    int value = 0;

    for (int i = 0; i < len; i++)
        value += arr[i];
    return value;
}

static void quick_sort(int *sums, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (sums[head] < sums[tail]) {
                last++;
                swap(&sums[last], &sums[tail]);
                continue;
            }
            tail--;
        }

        swap(&sums[head], &sums[last]);
        quick_sort(sums, head, last-1);
        quick_sort(sums, last+1, end);
    }

    return;
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {

    int *sums = NULL, max = 0;

    sums = (int *) calloc(accountsSize, sizeof(int));

    if (sums) {

        for (int i = 0; i < accountsSize; i++) {
            sums[i] = get_sum(accounts[i], accountsColSize[i]);
        }

        quick_sort(sums, 0, accountsSize-1);
        max = sums[0]; 
        free(sums);
    }

    return max;
}
