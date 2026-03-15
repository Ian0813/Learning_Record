/*
 * =====================================================================================
 *
 *       Filename:  3090_maximum_length_substring_with_two_occurrences.c
 *
 *    Description:  maximum length substring with two occurrences
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
#define LIMIT_LEN 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void update_start(char *s, int slen, int *start, int *count, int target) {

    int cindex = 0;

    while (*start < slen) {

        cindex = CH_TO_INDEX(s[*start]);
        count[cindex]--;

        if (cindex == target) {
            *start += 1; 
            break;
        }

        *start += 1;
    }

    return;
}

int maximumLengthSubstring(char* s) {

    int count[ALPHABET_LEN] = {0};
    int  index = 0, slen = 0, start = 0, curlen = 0, max = 0, cindex = 0;

    slen = strlen(s);

    while (index < slen) {

        cindex = CH_TO_INDEX(s[index]); 
        count[cindex]++;

        if (count[cindex] > LIMIT_LEN) {
            update_start(s, slen, &start, count, cindex);
        } else {
            curlen = (index - start) + 1;
        }

        max = MAX(max, curlen);
        index++;
    }

    return max;
}

