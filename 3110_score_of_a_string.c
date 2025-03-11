/*
 * =====================================================================================
 *
 *       Filename:  3110_score_of_a_string.c
 *
 *    Description:  score_of_a_string
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

#define GET_ABS(val) (val) > 0 ? (val) : -(val)

int scoreOfString(char* s) {

    int score = 0;

    for (int i = 0; i < strlen(s)-1; i++) {
        score += GET_ABS(s[i]-s[i+1]);     
    }
    return score;
}
