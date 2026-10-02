/*
 * =====================================================================================
 *
 *       Filename:  2828_check_if_a_string_is_an_acronym_of_words.c
 *
 *    Description:  check if a string is an acronym of words
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
#include <stdbool.h>

bool isAcronym(char** words, int wordsSize, char* s) {

    int slen = 0;
    bool rc = false;

    if (words && s) {

        slen = strlen(s);

        if (slen == wordsSize) {
            rc = true;
            for (int i = 0; i < slen; i++) {
                if (s[i] != words[i][0]) {
                    rc = false;
                    break;
                }
            }
        }
    }
    return rc;
}
