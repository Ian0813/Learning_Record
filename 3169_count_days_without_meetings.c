/*
 * =====================================================================================
 *
 *       Filename:  3169_count_days_without_meetings.c
 *
 *    Description:  count days without meetings
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

#define UNIT_LEN 2

enum {
    S_INDEX = 0,
    E_INDEX = 1
};

struct ptr_array {
    int **ptrs;
    int len;
};

static void swap_point(int **p1, int **p2) {

    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return;
}

static void quick_sort(int **arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {

            if (arr[head][E_INDEX] > arr[tail][E_INDEX]) {
                last++;
                swap_point(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap_point(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int merge_interval(int **meetings, int meetingsSize, struct ptr_array *p) {

    int offset = 0, last = 0;

    for (int i = 0; i < meetingsSize-1; i++) {

        if (meetings[i][E_INDEX] >= meetings[i+1][S_INDEX]) {
            meetings[i+1][S_INDEX] = meetings[i][S_INDEX] < meetings[i+1][S_INDEX] ? meetings[i][S_INDEX] : meetings[i+1][S_INDEX];
            p->ptrs[p->len++] = meetings[i+1];
            last = i+1;
            offset++, i++;
        } else {
            p->ptrs[p->len++] = meetings[i];
            last = i;
        }
    }

    if (last == meetingsSize-2) {
        p->ptrs[p->len++] = meetings[meetingsSize-1];
    }

    return offset;
}

static int count_difference(int **meetings, int size, int days) {

    int count = 0;

    for (int i = 0; i < size-1; i++) {
        count += ((meetings[i+1][S_INDEX]-meetings[i][E_INDEX]) - 1);
    }

    count += (days-meetings[size-1][E_INDEX]);
    count += (meetings[0][S_INDEX]-1);

    return count;
}

static void merge_operation(int **meetings, int head, int middle, int end) {

    int a1Size = (middle-head)+1, a2Size = end-middle;
    int a1[a1Size][UNIT_LEN], a2[a2Size][UNIT_LEN];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        memcpy(a1[i], meetings[head+i], UNIT_LEN*sizeof(int));
    }

    for (int i = a2_index; i < a2Size; i++) {
        memcpy(a2[i], meetings[middle+(i+1)], UNIT_LEN*sizeof(int));
    }

    while (a1_index < a1Size && a2_index < a2Size) {
        if (a1[a1_index][E_INDEX] < a2[a2_index][E_INDEX]) {
            memcpy(meetings[index++], a1[a1_index++], UNIT_LEN*sizeof(int));
        } else {
            memcpy(meetings[index++], a2[a2_index++], UNIT_LEN*sizeof(int));
        }
    }

    while (a1_index < a1Size) {
        memcpy(meetings[index++], a1[a1_index++], sizeof(int)*UNIT_LEN);
    }

    while (a2_index < a2Size) {
        memcpy(meetings[index++], a2[a2_index++], sizeof(int)*UNIT_LEN);
    }
    return;
}

static void merge_sort(int **meetings, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(meetings, head, middle);
        merge_sort(meetings, middle+1, end);
        merge_operation(meetings, head, middle, end);
    }
    return;
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {

    int result = 0, offset = 0;
    struct ptr_array p = {.ptrs = NULL, .len = 0}, temp = {.ptrs = NULL, .len = 0};

    if (meetingsSize) {

        p.ptrs = (int **) calloc(meetingsSize, sizeof(int *));
        merge_sort(meetings, 0, meetingsSize-1);

        temp.ptrs = meetings;
        temp.len = meetingsSize;

        while ((offset = merge_interval(temp.ptrs, temp.len, &p))) {
            temp.ptrs = p.ptrs;
            temp.len = p.len;
            p.len = 0;
        }

        memcpy(&p, &temp, sizeof(struct ptr_array));
        result = count_difference(p.ptrs, p.len, days);
    }
    return result;
}
