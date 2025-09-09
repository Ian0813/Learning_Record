/*
 * =====================================================================================
 *
 *       Filename:  1880_check_if_word_equals_summation_of_two_words.c
 *
 *    Description:  check if word equals summation of two words
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef enum {false, true} bool;

#define CH_TO_INT(ch) ((ch) - 'a')

static int strtoint(char *str) {

    int base = 0, len = strlen(str), val = 0;

    for (int i = 0; i < len; i++) {
        if (islower(str[i]) && str[i] != '0') {
            val *= base;
            val += (CH_TO_INT(str[i]));
            base = val ? 10 : 0;
        }
    }

    return val;
}

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
    return (strtoint(firstWord) + strtoint(secondWord)) == strtoint(targetWord);    
}

