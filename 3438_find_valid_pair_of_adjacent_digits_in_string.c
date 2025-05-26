/*
 * =====================================================================================
 *
 *       Filename:  3438_find_valid_pair_of_adjacent_digits_in_string.c
 *
 *    Description:  find valid pair of adjacent digits in string
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

#define TABLE_SIZE 10
#define CH_TO_INT(ch) ((ch)-'0')
#define PAIR_SIZE 2

#define IS_VALID(ch, times) (((ch)-'0') == times)

static void count_occurrences(int *table, const char *s) {

    for (int i = 0; i < strlen(s); i++) {
        table[CH_TO_INT(s[i])]++;
    }
    return;
}

static char *get_valid_pairs(int *table, const char *s) {

    char *result = NULL, last = '\0';
    int len = 0;

    result = (char *) calloc(PAIR_SIZE+1, sizeof(char));
    last = s[0];

    for (int i = 1; i < strlen(s); i++) {

        if (last == s[i]) {
            continue;
        }

        if (IS_VALID(s[i], table[CH_TO_INT(s[i])]) && IS_VALID(s[i-1], table[CH_TO_INT(s[i-1])])) {
            result[0] = s[i-1];
            result[1] = s[i];
            break;
        }
        last = s[i];
    }
    return result;
}

char* findValidPair(char* s) {

    int count_table[TABLE_SIZE] = {0};
    char *result = NULL;

    count_occurrences(count_table, s);

    result = get_valid_pairs(count_table, s);
    return result;
}
