/*
 * =====================================================================================
 *
 *       Filename:  2126 destroying asteroids.c
 *
 *    Description:  destroying asteroids
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
#include <limits.h>

typedef enum {false, true} bool;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static bool comparison_sort(int *arr, int head, int end, int *mass) {

    int flag = 0, tail = end-1;
    long long value = 0LL + *mass;

    do {
        flag = 0;

        if (head < end) {
            while (head <= tail) {
                if (*mass >= arr[tail]) {
                    swap(&arr[head], &arr[tail]);
                    value += arr[head];
                    *mass = (int) (value >= INT_MAX ? INT_MAX : value);
                    head++;
                    flag = 1;
                    continue;
                }
                tail--;
            }
        }

        if (!flag)
            break;
        tail = end-1;
    } while (flag);

    return *mass >= arr[end-1];
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    return comparison_sort(asteroids, 0, asteroidsSize, &mass);
}
