/*
 * =====================================================================================
 *
 *       Filename:  2833_furthest_point_from_origin.c
 *
 *    Description:  2833 furthest point from origin
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
#include <limits.h>

enum {
    LEFT = 'L',
    RIGHT = 'R',
    LINE = '_'
};

static void replace(char *moves, char target) {

    for (int i = 0; i < strlen(moves); i++) {
        if (moves[i] == LINE) {
            moves[i] = target;
        }
    }
    return;
}

static int get_max_distance(char *moves) {

    int count = 0;

    for (int i = 0; i < strlen(moves); i++) {
        count = moves[i] == LEFT ? (count-1) : (count+1);
    }
    return count;
}

int furthestDistanceFromOrigin(char* moves) {

    char *dup = NULL;
    int lmax = 0, rmax = 0;

    dup = strdup(moves);
    replace(dup, RIGHT);
    rmax = get_max_distance(dup);

    free(dup);

    dup = strdup(moves);
    replace(dup, LEFT);
    lmax = get_max_distance(dup);

    free(dup);

    return abs(rmax) > abs(lmax) ? abs(rmax) : abs(lmax);
}
