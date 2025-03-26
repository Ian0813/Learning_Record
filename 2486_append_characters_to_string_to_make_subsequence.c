/*
 * =====================================================================================
 *
 *       Filename:  2486_append_characters_to_string_to_make_subsequence.c
 *
 *    Description:  append characters to string to make subsequence
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

int appendCharacters(char* s, char* t) {

    char *mptr = s, *subptr = t;
    int count = 0;

    while (*mptr != '\0') {
        if (*mptr == *subptr) {
            subptr++;
            count++;
        }
        mptr++;
    }    
    return strlen(t)-count; 
}

int main(void) {

    char *s = "coaching", *t = "coding";

    printf("%d\n", appendCharacters(s, t)); 

    return EXIT_SUCCESS;
}
