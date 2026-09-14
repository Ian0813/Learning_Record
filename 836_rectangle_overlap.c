/*
 * =====================================================================================
 *
 *       Filename:  836_rectangle_overlap.c
 *
 *    Description:  rectangle_overlap.c

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
#define DOT_LEN 2

enum {
    INDEX_X = 0,
    INDEX_Y = 1,
};

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {

    int diff_p1[DOT_LEN] = {0};

    diff_p1[INDEX_X] = abs(rec1[0]-rec2[0]); 
    diff_p1[INDEX_Y] = abs(rec1[1]-rec2[1]);

    if ((MIN(rec1[0], rec2[0]) + diff_p1[INDEX_X]) < MIN(rec1[2], rec2[2]) && 
        (MIN(rec1[1], rec2[1]) + diff_p1[INDEX_Y]) < MIN(rec1[3], rec2[3])) {
        return true;
    }
    return false;
}
