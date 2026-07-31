/*
 * =====================================================================================
 *
 *       Filename:  3386_button_with_longest_push_time.c
 *
 *    Description:  button with longest push time
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

enum {
    INDEX_EVENT = 0,
    INDEX_INTIME = 1,
};

int buttonWithLongestTime(int** events, int eventsSize, int* eventsColSize) {

    int longest = INT_MIN, e = 0, temp = 0;

    e = events[0][INDEX_EVENT];
    longest = events[0][INDEX_INTIME];

    for (int i = 1; i < eventsSize; i++) {

        temp = events[i][INDEX_INTIME] - events[i-1][INDEX_INTIME];

        if (temp > longest) {
            longest = temp;
            e = events[i][INDEX_EVENT];
        } else if (temp == longest && e > events[i][INDEX_EVENT]) {
            e = events[i][INDEX_EVENT];
        }
    }
    return e;
}
