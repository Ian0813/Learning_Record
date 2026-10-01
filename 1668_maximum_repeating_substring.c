/*
 * =====================================================================================
 *
 *       Filename:  1668_maximum_repeating_substring.c
 *
 *    Description:  maximum repeating substring
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
#include <sys/param.h>

static int get_repeat_len(char *sequence, int slen, char *word, int wlen) {

    int len = 0;

    for (int i = 0; i < slen; i += wlen) {
        if (strncasecmp(&sequence[i], word, wlen)) {
            break;
        }
        len += wlen;
    }
    return len;
}

int maxRepeating(char* sequence, char* word) {

    int maxlen = 0, len = 0, wlen = 0, slen = 0;

    if (sequence && word) {

        slen = strlen(sequence);
        wlen = strlen(word);

        for (int i = 0; i < slen; i++) {

            len = get_repeat_len(&sequence[i], slen - i, word, wlen); 

            maxlen = MAX(maxlen, len);

            if (maxlen >= (slen-i)) {
                break;
            }
        }
    }
    return maxlen ? maxlen/wlen : 0;
}
