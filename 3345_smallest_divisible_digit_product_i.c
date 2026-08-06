/*
 * =====================================================================================
 *
 *       Filename:  3345_smallest_divisible_digit_product_i.c
 *
 *    Description:  smallest divisible digit product i
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

static int get_digit_product(int val) {

    int d = val ? 1 : 0;

    do {
        d *= (val%10);
        val /= 10;
    } while (val);
    return d;
}

int smallestNumber(int n, int t) {
    while ((get_digit_product(n)%t))
        n++;
    return n;
}
