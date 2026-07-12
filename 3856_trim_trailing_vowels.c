/*
 * =====================================================================================
 *
 *       Filename:  3856_trim_trailing_vowels.c
 *
 *    Description:  trim trailing vowels
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
#include <stdbool.h>

#define VOWELS_LEN 5

static bool is_vowel(char ch) {

    if (!isalpha(ch))
        return false;

    char *vowels = "aeiou";

    for (int i = 0; i < VOWELS_LEN; i++)
        if (ch == vowels[i])
            return true; 
    return false;
}

char* trimTrailingVowels(char* s) {

    int slen = 0;

    if (s) {
        slen = strlen(s);

        for (int i = slen-1; i >= 0; i--) {
            if (is_vowel(s[i]))
                s[i] = '\0';
            else
                break;
        }
    }
    return s;
}
