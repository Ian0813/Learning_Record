/*
 * =====================================================================================
 *
 *       Filename:  2427_number_of_common_factors.c
 *
 *    Description:  number_of_common_factors
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

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int find_gcd(int max, int min) {

    int remain = 0;

    if (!(remain = (max % min))) {
        return min;
    }

    remain = find_gcd(min, remain);
    return remain;
}

int commonFactors(int a, int b) {

    int gcd = 0, count = 1, boundary = 0; 

    gcd = find_gcd(MAX(a, b), MIN(a, b));

    boundary = (gcd / 2);

    for (int i = 2; i < boundary; i++) {
        if (!(gcd%i))
            count++; 
    }

    count = gcd == 1 ? count : (count+1);
    return count;
}

