/*
 * =====================================================================================
 *
 *       Filename:  2894_divisible_and_non_divisible_sums_difference.c
 *
 *    Description:  divisible and non divisible sums difference
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

static int sum_of_range(int num) {
    return (num*(num+1))/2;
}

static int get_divisible_sum(int n, int m) {

    int value = 0;

    for (int i = m; i <= n; i++) {
        value = (!(i%m)) ? (value+i) : value;
    }
    return value;
}

int differenceOfSums(int n, int m) {

    int num1 = 0, num2 = 0; 

    num2 = get_divisible_sum(n, m);
    num1 = sum_of_range(n)-num2;
    return num1-num2;
}

