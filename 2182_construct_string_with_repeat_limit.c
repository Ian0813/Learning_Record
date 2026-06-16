/*
 * =====================================================================================
 *
 *       Filename:  2182_construct_string_with_repeat_limit.c
 *
 *    Description:  construct string with repeat limit
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

#define ALPHABET_SIZE 26
#define ALPHABET_TO_INDEX(ch) ((ch)-'a')
#define INDEX_TO_ALPHABET(index) ((index)+'a')

struct letter_info {
    int table[ALPHABET_SIZE];
    int total;
};

static void count_alphabet(char *s, struct letter_info *recorder) {

    int len = 0;

    if (!recorder || !s)
        return;

    len = strlen(s);
    recorder->total = len;

    for (int i = 0; i < strlen(s); i++) {
        recorder->table[ALPHABET_TO_INDEX(s[i])]++;
    }
    return;
}

static void reform_string(struct letter_info *recorder, char *s, int limit) {

    int count = 0, index = 0, breaker = 0;

    while (recorder->total) {
       for (int i = ALPHABET_SIZE-1; i >= 0; i--) {

            count = recorder->table[i] > limit ? limit : recorder->table[i];

            if (count) {

                count = breaker ? 1 : count;

                memset(&s[index], INDEX_TO_ALPHABET(i), sizeof(char) * count);
                recorder->total -= count;
                recorder->table[i] -= count;
                index += count;

                if (breaker) {
                    break;
                }

                if (count == limit && recorder->table[i])
                    breaker = 1;
            }

            if (!recorder->total)
                break;
        }
        breaker = 0;
    }
    return;
}

static void check_legal(char *s, int len, int limit) {

    char cur = '\0';
    int curlen = 0, index = 1;

    cur = s[0];
    curlen += 1;

    for (int i = 1; i < len; i++) {

        if (cur == s[i]) {
            curlen++;
        } else {
            cur = s[i]; 
            curlen = 1;
        }

        if (curlen <= limit) {
            s[index++] = s[i];             
        }
    }

    s[index] = '\0';
    return;
}

char* repeatLimitedString(char* s, int repeatLimit) {

    int table[ALPHABET_SIZE] = {0}, len = 0;
    struct letter_info recorder = {0};

    len = strlen(s);

    if (len) {
        count_alphabet(s, &recorder);
        reform_string(&recorder, s, repeatLimit);         
        check_legal(s, len, repeatLimit);
    }
    return s;
}
