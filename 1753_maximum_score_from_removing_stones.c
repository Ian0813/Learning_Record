/*
 * =====================================================================================
 *
 *       Filename:  1753_maximum_score_from_removing_stones.c
 *
 *    Description:  maximum score from removing stones
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

#define SCORE_LEN 3

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

        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}

int maximumScore(int a, int b, int c) {

    int scores[SCORE_LEN] = {a, b, c};    
    int count = 0, fetch_times = 2;

    quick_sort(scores, 0, SCORE_LEN-1);

    while (scores[0] && scores[1]) {
        for (int i = 0; fetch_times && i < SCORE_LEN; i++) {
            if (scores[i]) {
                scores[i]--;
                fetch_times--;
            }
        }
        fetch_times = 2;
        count++;
        quick_sort(scores, 0, SCORE_LEN-1);
    }
    return count;
}
