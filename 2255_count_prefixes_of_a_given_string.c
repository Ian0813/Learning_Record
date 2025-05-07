/*
 * =====================================================================================
 *
 *       Filename:  2255_count_prefixes_of_a_given_string.c
 *
 *    Description:  count prefixes of a given string
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

typedef enum {false, true} bool;

static bool is_prefix(char *prefix, char *str) {

    bool rc = false;

    if (strlen(prefix) <= strlen(str)) {
        rc = !strncmp(prefix, str, strlen(prefix)) ? true : false;  
    }
    return rc;
}

int countPrefixes(char** words, int wordsSize, char* s) {

    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        count = is_prefix(words[i], s) ? count+1 : count;
    }
    return count;
}
