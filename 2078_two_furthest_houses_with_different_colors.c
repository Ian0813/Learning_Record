/*
 * =====================================================================================
 *
 *       Filename:  2078_two_furthest_houses_with_different_colors.c
 *
 *    Description:  Two furthest houses with different colors   
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

int maxDistance(int* colors, int colorsSize) {

    int base = 0, end = colorsSize - 1;
    int max = 0, diff = 0;

    for (int i = end; i >= 0; i--) {
        if (colors[base] != colors[i]) {
            max = i - base;
            break;
        }
    }

    for (int i = 0; i < end; i++) {
        if (colors[i] != colors[end]) {
            if ((diff = end - i) > max) {
                max = diff;
            }
            break;
        }        
    }
    return max;
}
