/*
 * =====================================================================================
 *
 *       Filename:  3783_mirror_distance_of_an_integer.c
 *
 *    Description:  mirror distance of an integer
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

static int reverse_value(int n) {

    int value = 0;

    while (n) {
        value *= 10;
        value += (n%10);
        n /= 10;
    }
    return value;
}

int mirrorDistance(int n) {
    return abs(n - reverse_value(n));    
}
