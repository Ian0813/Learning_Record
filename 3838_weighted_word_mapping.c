/*
 * =====================================================================================
 *
 *       Filename:  3838 weighted word mapping.c
 *
 *    Description:  weighted word mapping
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

#define ALPHABET_LEN 26
#define CH_TO_INDEX(ch) ((ch)-'a')
#define CONVERT_TO_CH(val) ('z'-(val))

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {

    char *result = NULL;
    int value = 0, len = 0, rindex = 0;

    if (wordsSize) {

        result = (char *) calloc(wordsSize+1, sizeof(char)); 

        for (int i = 0; i < wordsSize; i++) {

            len = strlen(words[i]);

            for (int j = 0; j < len; j++) {
                value += weights[CH_TO_INDEX(words[i][j])]; 
            }

            value %= ALPHABET_LEN;
            result[rindex++] = CONVERT_TO_CH(value);
            value = 0;
        }
    }
    return result;
}
