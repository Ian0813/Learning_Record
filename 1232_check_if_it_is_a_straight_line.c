/*
 * =====================================================================================
 *
 *       Filename:  1232_check_if_it_is_a_straight_line.c
 *
 *    Description:  check if it is a straight line
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

typedef enum {false, true} bool;

#define POINT_LEN 2 

enum {
    INDEX_X = 0,
    INDEX_Y = 1
};

typedef enum {
    GAP_NONE = -1, 
    GAP_VERTICAL = 0,
    GAP_HORIZONTAL = 1,
    GAP_DIAGONAL = 2,
    GAP_RANDOM = 3
} gap_type;

static gap_type get_gap_type(int *p1, int *p2, double *random_distance) {

    gap_type gtype = GAP_NONE;
    double divisor = 0.0, dividend = 0.0; 

    if (p1[INDEX_X] == p2[INDEX_X]) {
        gtype = GAP_VERTICAL;    
    } else if (p1[INDEX_Y] == p2[INDEX_Y]) {
        gtype = GAP_HORIZONTAL;    
    } else if (p1[INDEX_X] == p1[INDEX_Y] && p2[INDEX_X] == p2[INDEX_Y]) {
        gtype = GAP_DIAGONAL;
    } else {

        dividend = abs(p1[INDEX_X]-p2[INDEX_X]);
        divisor = abs(p1[INDEX_Y]-p2[INDEX_Y]);

        if (!(*random_distance)) {
            *random_distance = dividend/divisor; 
            gtype = GAP_RANDOM;
        } else {
            gtype = (*random_distance) == (dividend/divisor) ? GAP_RANDOM : GAP_NONE;
        }
    }
    return gtype;
}

static void swap_ptr(int **p1, int **p2) {

    int *ptr = *p1;

    *p1 = *p2;
    *p2 = ptr;
    return;
}

static void quick_sort(int **coordinates, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {

            if (coordinates[head][INDEX_X] > coordinates[tail][INDEX_X]) {
                last++;  
                swap_ptr(&coordinates[last], &coordinates[tail]);
                continue;
            }
            tail--;
        }

        swap_ptr(&coordinates[head], &coordinates[last]);
        quick_sort(coordinates, head, last-1);
        quick_sort(coordinates, last + 1, end);
    }

    return;
}

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {

    gap_type gtype = GAP_NONE;
    double random_distance = 0; 

    gtype = get_gap_type(coordinates[0], coordinates[1], &random_distance);

    if (gtype == GAP_RANDOM)
        quick_sort(coordinates, 0, coordinatesSize - 1);

    for (int i = 0; i < (coordinatesSize-1); i++) {
        if (get_gap_type(coordinates[i], coordinates[i+1], &random_distance) != gtype) {
            gtype = GAP_NONE;
            break;
        }
    }

    return gtype ==GAP_NONE ? false : true;
}
