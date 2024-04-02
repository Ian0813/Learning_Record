/*
 * =====================================================================================
 *
 *       Filename:  374_guess_number_higher_or_lower.c
 *
 *    Description:  Guess number higher or lower  
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
#include <limits.h>

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return          -1 if num is higher than the picked number
 *                  1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num) {

    static int answer = 2;

    if (num == answer) {
        return 0;
    } else if (num > answer) {
        return -1;
    }
    return 1;
}

int guessNumber(int n) {

    unsigned int lower = 1, higher = UINT_MAX;
    unsigned int rc = 0, value = n;

    while ((rc = guess(value)) != 0) {

        if (rc == 1) {
            lower = value; 
            value = (lower+higher)/2;
        } else {
            higher = value;
            value = (lower+higher)/2;
        }
    }
    return value;
}

int main(void) {

    printf("%d\n", guessNumber(3));
    return EXIT_SUCCESS;
}
