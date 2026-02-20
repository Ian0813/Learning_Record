/*
 * =====================================================================================
 *
 *       Filename:  1578_minimum_time_to_make_rope_colorful.c
 *
 *    Description:  minimum time to make rope colorful
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

#define MIN(a, b) ((a) < (b) ? (a) : (b))

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
        quick_sort(arr, last + 1, end);
    }

    return;
}

static int get_minimum(char *colors, int start, int end, int *neededTime, int remove_count) {

    int minimum = 0;

    quick_sort(neededTime, start, end-1);

    for (int i = start; i < (remove_count + start); i++) {
        minimum += neededTime[i]; 
    }

    return minimum;
}

int minCost(char* colors, int* neededTime, int neededTimeSize) {

    int color_len = 0, start = 0, end = 0;
    int cost = 0;

    if (colors) {

        color_len = strlen(colors);

        for (start, end; end < color_len; end++) {
            if (colors[start] != colors[end]) {
                if ((end-start) > 1)
                    cost += get_minimum(colors, start, end, neededTime, (end - start) - 1);
                start = end;
            }
        }

        if (start != (end-1)) {
            cost += get_minimum(colors, start, end, neededTime, (end - start) - 1);
        }
    }
    return cost;
}
