/*
 * =====================================================================================
 *
 *       Filename:  1893_check_if_all_the_integers_in_a_range_are_covered.c
 *
 *    Description:  check if all the integers in a range are covered
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
#include <sys/param.h>

typedef enum {false, true} bool;

typedef struct {
    bool *table;
    int tsize;
    int remain;
} range_marker;

static void marker_allocate(range_marker *m, int left, int right) {

    if (!m)
        return;

    m->tsize = (MAX(left, right) - MIN(left, right)) + 1;
    m->table = calloc(MIN(left, right) + (m->tsize), sizeof(bool));
    m->remain = m->tsize;

    return;
}

bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right) {

    int min = 0, max = 0;
    range_marker tracker = {0};

    marker_allocate(&tracker, left, right);

    for (int i = 0; i < rangesSize; i++) {
        min = MIN(ranges[i][0], ranges[i][1]);
        max = MAX(ranges[i][0], ranges[i][1]);
        for (int s = min; s <= max; s++) {
            if ((s >= MIN(left, right) && s <= MAX(left, right)) && !tracker.table[s]) {
                tracker.table[s] = true;
                tracker.remain--;
            }
        }
        if (!tracker.remain)
            break;
    }

    if (tracker.table)
        free(tracker.table);
    return tracker.remain ? false : true;
}
