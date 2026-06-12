/*
 * =====================================================================================
 *
 *       Filename:  3945_digit_frequency_score.c
 *
 *    Description:  digit frequency score
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

#define MAX_DIGIT_LEN 10

int digitFrequencyScore(int n) {

    int occurrence[MAX_DIGIT_LEN] = {0}, result = 0;

    while (n) {
        occurrence[(n%10)]++;
        n /= 10;
    }

    for (int i = 1; i < MAX_DIGIT_LEN; i++) {
        result += (i * occurrence[i]);
    }

    return result;
}

