/*
 * =====================================================================================
 *
 *       Filename:  1422_maximum_score_after_splitting_a_string.c
 *
 *    Description:  maximum score after splitting a string
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

/*  
 *
 * Example 1:
 *   Input: s = "011101"
 *   Output: 5 
 *   Explanation: 
 *   All possible ways of splitting s into two non-empty substrings are:
 *   left = "0" and right = "11101", score = 1 + 4 = 5 
 *   left = "01" and right = "1101", score = 1 + 3 = 4 
 *   left = "011" and right = "101", score = 1 + 2 = 3 
 *   left = "0111" and right = "01", score = 1 + 1 = 2 
 *   left = "01110" and right = "1", score = 2 + 1 = 3
 **/

#define COUNT_SIZE 2

#define CH_TO_INT(ch) ((ch)-'0')

enum {
    ZERO_INDEX = 0,
    ONE_INDEX = 1
};

static void count_digits(int *count, char *s) {

    for (int i = 0; i < strlen(s); i++) {
        count[CH_TO_INT(s[i])]++;
    }
    return;
}

int maxScore(char* s) {

    int lcount[COUNT_SIZE] = {0}, rcount[COUNT_SIZE] = {0};
    int lvalue = 0, rvalue = 0, value = 0, max = 0;

    count_digits(rcount, s);

    for (int i = 0; i < strlen(s)-1; i++) {
        lcount[CH_TO_INT(s[i])]++;
        rcount[CH_TO_INT(s[i])]--;
        max = (value = lcount[ZERO_INDEX] + rcount[ONE_INDEX]) > max ? value : max;
    }
    return max;
}
