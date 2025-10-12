/*
 * =====================================================================================
 *
 *       Filename:  2652 sum multiples.c
 *
 *    Description:  sum multiples
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

#define IS_NEEDED_NUMBER(val) (!((val) % 3) || !((val) % 5) || !((val) % 7))

int sumOfMultiples(int n) {

    int val = 0;

    for (int i = 3; i <= n; i++) {
        val += (IS_NEEDED_NUMBER(i) ? i : 0);
    }

    return val;
}
