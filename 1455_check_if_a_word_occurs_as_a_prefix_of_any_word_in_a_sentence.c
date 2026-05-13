/*
 * =====================================================================================
 *
 *       Filename:  1455 check if a word occurs as a prefix of any word in a sentence.c
 *
 *    Description:  check if a word occurs as a prefix of any word in a sentence
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

typedef enum {false, true} bool;

static bool check_prefix(char *s, char *p) {

    bool rc = true;

    while (*p) {
        if (*p++ != *s++) {
            rc = false;    
            break;
        }
    }
    return rc;
}    

int isPrefixOfWord(char* sentence, char* searchWord) {

    char *ptr = NULL;
    int count = 1;

    if (sentence) {
        ptr = strtok(sentence, " ");

        while (ptr) {
            if (check_prefix(ptr, searchWord)) {
                return count;
            }
            count++;
            ptr = strtok(NULL, " ");
        }
    }
    return -1; 
}
