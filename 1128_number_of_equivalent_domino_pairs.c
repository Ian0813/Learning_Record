/*
 * =====================================================================================
 *
 *       Filename:  1128_number_of_equivalent_domino_pairs.c
 *
 *    Description:  number of equivalent domino pairs
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
#include <stdint.h>

typedef enum {false, true} bool; 

#define TABLE_SIZE 10

enum {
    LEFT_INDEX = 0,
    RIGHT_INDEX = 1
};

static bool is_equal(int *p1, int *p2) {

    bool rc = false;

    if ((p1[LEFT_INDEX] == p2[LEFT_INDEX]) && (p1[RIGHT_INDEX] == p2[RIGHT_INDEX])) {
        rc = true;
    } else if ((p1[LEFT_INDEX] == p2[RIGHT_INDEX]) && (p1[RIGHT_INDEX] == p2[LEFT_INDEX])) {
        rc = true;
    }

    return rc;
}

static int count_equivalent(int **pairs, int size, int *tracker) {

    int total = 0, count = 0, flag = 0;

    for (int i = 0; i < size; i++, flag = 0) {

        total += count;
        count = 0;

        for (int j = i-1; j >= 0; j--) {
            if (tracker[j] && is_equal(pairs[i], pairs[j])) {
                count = tracker[j] - 1;
                flag = 1;
                break;
            }
        }

        if (flag) {
            tracker[i] = count;
            continue;
        }

        for (int j = i+1; j < size; j++) {
            if (is_equal(pairs[i], pairs[j])) {
                count++;
            }
        }
        tracker[i] = count;
    }
    return total;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {

    int *track_usage = NULL;
    int result = 0;

    if (dominoesSize) {

        track_usage = (int *) calloc(dominoesSize, sizeof(int));
        result = count_equivalent(dominoes, dominoesSize, track_usage);
    }
    return result;
}
