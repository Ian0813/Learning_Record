/*
 * =====================================================================================
 *
 *       Filename:  2185_counting_words_with_a_given_prefix.c
 *
 *    Description:  counting words with a given prefix
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

int prefixCount(char** words, int wordsSize, char* pref) {

    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (!strncmp(words[i], pref, strlen(pref))) {
            count++; 
        }
    }
    return count;
}
