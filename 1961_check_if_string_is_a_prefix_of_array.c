/*
 * =====================================================================================
 *
 *       Filename:  1961_check_if_string_is_a_prefix_of_array.c
 *
 *    Description:  check if string is a prefix of array
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

static bool is_belongto(char *s, char *prefix) {
    return !strncmp(s, prefix, strlen(prefix));
}

bool isPrefixString(char* s, char** words, int wordsSize) {

    bool rc = true;

    for (int i = 0; i < wordsSize; i++) {
        if (is_belongto(s, words[i])) {
            s += strlen(words[i]);
        } else if (strlen(s)) {
            break;
        }
    }
    rc = !strlen(s) ? true : false;
    return rc;
}
