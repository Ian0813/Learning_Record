/*
 * =====================================================================================
 *
 *       Filename:  875 koko eating bananas.c
 *
 *    Description:  koko eating bananas
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

static int get_max(int *piles, int pilesSize) {

    int max = 0;

    for (int i = 0; i < pilesSize; i++) {
        max = max < piles[i] ? piles[i] : max;
    }
    return max;
}

static int get_hours(int *piles, int pilesSize, int speed) {

    int hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += (!(piles[i]%speed) ? (piles[i]/speed) : (piles[i]/speed)+1);
    }

    return hours;
}

static int binary_search(int left, int right, int *piles, int pilesSize, int *spent, int expected) {

    int middle = (left+right)/2, hours = 0;

    if (left < right) {

        hours = get_hours(piles, pilesSize, middle);

        if (hours == expected) {
            ; 
        } else if (hours > expected) {
            middle = binary_search(middle+1, right, piles, pilesSize, spent, expected);
        } else if (hours < expected) {
            middle = binary_search(left, middle, piles, pilesSize, spent, expected);
        }
    }

    *spent = expected == hours ? hours : *spent;

    return middle;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {

    int rc = 0, left = 1, right = 1, spent = 0;

    right = get_max(piles, pilesSize);

    do {
        spent = -1;
        rc = binary_search(left, right+1, piles, pilesSize, &spent, h);
        right = rc - 1;
    } while (spent != -1);

    return rc;
}
