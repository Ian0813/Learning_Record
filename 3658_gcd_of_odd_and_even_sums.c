/*
 * =====================================================================================
 *
 *       Filename:  3658_gcd_of_odd_and_even_sums.c
 *
 *    Description:  gcd of odd and even sums
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

#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))
#define MIN(v1, v2) ((v1) < (v2) ? (v1) : (v2))

static int get_great_common_divisor(int v1, int v2) {

    int t1 = MAX(v1, v2), t2 = MIN(v1, v2), value = 0;

    if ((t1%t2)) {
        value = get_great_common_divisor(t2, t1%t2);
    }
    return !value ? t2 : value;
}

int gcdOfOddEvenSums(int n) {

    int even_sum = 0, odd_sum = 0, gcd = 0;

    for (int count = 0, val = 1; count < n; count++, val += 2) {
        odd_sum += val;
    }

    for (int count = 0, val = 2; count < n; count++, val += 2) {
        even_sum += val;
    }

    gcd = get_great_common_divisor(even_sum, odd_sum);
    return gcd;
}
