/*
 * =====================================================================================
 *
 *       Filename:  3159_find_occurrences_of_an_element_in_an_array.c
 *
 *    Description:  find occurrences of an element in an array
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define EMPTY -1

static void tracker_init(int *tracker, int *nums, int numsSize, int *index, int x) {

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] == x) {
            tracker[*index] = i;
            *index += 1;
        }
    }

    return;
}

static void get_query_result(int *queries, int queriesSize, int *result, int *tracker, int tlen) {

    for (int i = 0; i < queriesSize; i++) {

        if (queries[i] <= tlen) {
            result[i] = tracker[queries[i]-1];
        } else {
            result[i] = EMPTY;
        }
    }

}

int* occurrencesOfElement(int* nums, int numsSize, int* queries, int queriesSize, int x, int* returnSize) {

    int *result = NULL, *tracker = NULL, tindex = 0;

    result = (int *) calloc(queriesSize, sizeof(int));
    tracker = (int *) calloc(numsSize, sizeof(int));

    tracker_init(tracker, nums, numsSize, &tindex, x);
    get_query_result(queries, queriesSize, result, tracker, tindex);

    *returnSize = queriesSize;
    free(tracker);

    return result;
}
