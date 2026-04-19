/*
 * =====================================================================================
 *
 *       Filename:  3663_find_the_least_frequent_digit.c
 *
 *    Description:  find the least frequent digit
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
#include <limits.h>

#define DIGIT_SIZE 10 

int getLeastFrequentDigit(int n) {

    int digit_count[DIGIT_SIZE] = {0}, frequent_value = INT_MAX, value = 0;

    while (n) {
        digit_count[n%10]++;
        n /= 10;
    }

    for (int i = 0; i < DIGIT_SIZE; i++) {
        if (digit_count[i] && digit_count[i] < frequent_value) {
            frequent_value = digit_count[i];
            value = i;
        }
    }
    return value;
}
