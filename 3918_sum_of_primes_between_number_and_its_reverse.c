/*
 * =====================================================================================
 *
 *       Filename:  3918_sum_of_primes_between_number_and_its_reverse.c
 *
 *    Description:  sum of primes between number and its reverse
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
#include <sys/param.h>
#include <stdbool.h>
#include <math.h>

static bool isprime(int val) {

    int check_point = (int) sqrt(val * 1.0);

    for (int i = 2; i <= check_point; i++) {
        if (!(val%i))
            return false; 
    }
    return true;
}

static int num_reverse(int n) {

    int value = 0, temp = 0;

    do {
        value *= 10;
        value += (n%10);
        n /= 10;
    } while (n);

    return value;
}

int sumOfPrimesInRange(int n) {

    int start = 0, end = 0, rev_n = 0, sum = 0;

    rev_n = num_reverse(n);
    start = MIN(n, rev_n);
    end = MAX(n, rev_n);

    start = start < 2 ? 2 : start;

    while (start <= end) {
        if (isprime(start))    
            sum += start;
        start++;
    }
    return sum;
}
