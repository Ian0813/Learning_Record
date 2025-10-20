/*
 * =====================================================================================
 *
 *       Filename:  2114 maximum number of words found in sentences.c
 *
 *    Description:  maximum number of words found in sentences
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

#define SEPARATE_WORD " "

static int count_words(char *str) {

    int count = 0;
    char *ptr = NULL;

    if (str) {

        ptr = strtok(str, SEPARATE_WORD);

        do {
            count++;
        } while ((ptr = strtok(NULL, SEPARATE_WORD)));
    }

    return count;
}

int mostWordsFound(char** sentences, int sentencesSize) {

    int max_occurrences = 0, rc = 0;

    for (int i = 0; i < sentencesSize; i++) {

        rc = count_words(sentences[i]);
        max_occurrences = rc > max_occurrences ? rc : max_occurrences;
    }
    return max_occurrences;
}
