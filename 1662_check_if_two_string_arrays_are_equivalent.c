/*
 * =====================================================================================
 *
 *       Filename:  1662_check_if_two_string_arrays_are_equivalent.c
 *
 *    Description:  check if two string arrays are equivalent
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

static char *concatenate(char **word, int wordSize) {

    char *ptr = NULL;

    for (int i = 0; i < wordSize; i++) {

        if (!ptr) {
            ptr = (char *) malloc(strlen(word[i])+1);
            memset(ptr, 0, strlen(word[i])+1);
            memcpy(ptr, word[i], strlen(word[i]));
        } else {
            ptr = (char *) realloc(ptr, strlen(ptr)+strlen(word[i])+1);
            strcat(ptr, word[i]);
        }    
    }
    return ptr;
}

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {

    char *s1 = NULL, *s2 = NULL;     
    bool rc = true; 

    s1 = concatenate(word1, word1Size);
    s2 = concatenate(word2, word2Size);

    rc = !strcmp(s1, s2) ? true : false;
    free(s1);
    free(s2);

    return rc;
}

