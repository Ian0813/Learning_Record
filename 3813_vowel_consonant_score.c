/*
 * =====================================================================================
 *
 *       Filename:  3813_vowel_consonant_score.c
 *
 *    Description:  vowel consonant score
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
#include <ctype.h>
#include <math.h>

#define VOWEL_LEN 5

typedef enum {
    LETTER_NONE = -1,
    LETTER_VOWEL = 0,
    LETTER_CONSONANT = 1
} letter_t;

static letter_t get_letter_type(char ch) {

    const char vowels[VOWEL_LEN] = "aeiou";

    if (!isalpha(ch)) {
        return LETTER_NONE;
    }

    for (int i = 0; i < VOWEL_LEN; i++)
        if (ch == vowels[i])
            return LETTER_VOWEL;   
    return LETTER_CONSONANT;
}

int vowelConsonantScore(char* s) {

    double vowel_count = 0.0, consonant_count = 0.0;
    int len = 0;

    if (s) {

        len = strlen(s);

        for (int i = 0; i < len; i++) {
            if (get_letter_type(s[i]) == LETTER_VOWEL)
                vowel_count += 1.0;
            else if (get_letter_type(s[i]) == LETTER_CONSONANT)
                consonant_count += 1.0;
        }
    }
    return (int) (consonant_count ? (floor(vowel_count/consonant_count)) : 0);
}
