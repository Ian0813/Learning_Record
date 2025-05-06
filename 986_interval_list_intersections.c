/*
 * =====================================================================================
 *
 *       Filename:  986_interval_list_intersections.c
 *
 *    Description:  interval list intersections
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define UNIT_SIZE 2

#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))
#define MIN(v1, v2) ((v1) <= (v2) ? (v1) : (v2))

enum {
    F_INDEX = 0,
    S_INDEX = 1
};

struct s_result {
    int **list;
    int len;
};

static void mark_digits(int **list, int listSize, char *table) {

    for (int i = 0; i < listSize; i++) {
        for (int j = list[i][F_INDEX]; j <= list[i][S_INDEX]; j++) {
            table[j] = 0x1;
        }
    }
    return;
}

static void find_inter_section(int **list1, int list1Size, int **list2, int list2Size, struct s_result *result) {

    int l1_index = 0, l2_index = 0;
    int start = 0, end = 0;

    while (l1_index < list1Size && l2_index < list2Size) {

        start = MAX(list1[l1_index][F_INDEX], list2[l2_index][F_INDEX]);
        end = MIN(list1[l1_index][S_INDEX], list2[l2_index][S_INDEX]);

        if (start <= end) {
            result->len++;
            result->list = (int **) reallocarray(result->list, result->len, sizeof(int *));
            result->list[result->len-1] = (int *) calloc(UNIT_SIZE, sizeof(int));

            result->list[result->len-1][F_INDEX] = start;
            result->list[result->len-1][S_INDEX] = end;
        }

        if (MIN(list1[l1_index][S_INDEX], list2[l2_index][S_INDEX]) == list1[l1_index][S_INDEX]) {
            l1_index++;
        } else {
            l2_index++;
        }
    }

    return;
}

int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {

    struct s_result result = {NULL};

    if (firstListSize && secondListSize) {
        find_inter_section(firstList, firstListSize, secondList, secondListSize, &result);
        *returnSize = result.len;
        *returnColumnSizes = (int *) calloc(result.len, sizeof(int));
        for (int i = 0; i < result.len; i++) {
            (*returnColumnSizes)[i] = UNIT_SIZE;
        }
    } else {
        *returnSize = 0;
    }
    return result.list;
}
