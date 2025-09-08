/*
 * =====================================================================================
 *
 *       Filename:  1876_substrings_of_size_three_with_distinct_characters.c
 *
 *    Description:  substrings of size three with distinct characters
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

#define GOOD_STRLEN 3
#define IS_DIFF(ch1, ch2) ((ch1) != (ch2))

static int count_good_pattern(char *s) {

    int count = 0, len = 0, boundary = 0;

    len = boundary = strlen(s);

    for (int i = 0; i < len-2; i++) {

        if ((i+2) >= boundary)
            break;

        if (IS_DIFF(s[i], s[i+1]) && IS_DIFF(s[i], s[i+2]) && IS_DIFF(s[i+1], s[i+2])) {
            count++;
        }
    }

    return count;
}

int countGoodSubstrings(char* s) {

    int count = 0;

    count = count_good_pattern(s);

    return count;
}

