/*
 * =====================================================================================
 *
 *       Filename:  1837_sum_of_digits_in_base_k.c
 *
 *    Description:  sum of digits in base k
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

static int get_digits_sum(int n, int base) {

    int value = 0;

    while (n) {
        value += (n%base);
        n /= base;
    }
    return value;
}

int sumBase(int n, int k) {
    return get_digits_sum(n, k);
}
