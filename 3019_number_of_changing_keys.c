/*
 * =====================================================================================
 *
 *       Filename:  3019 number of changing keys.c
 *
 *    Description:  number of changing keys
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
#include <ctype.h>

typedef enum {false, true} bool;

#define IS_CHANGE(letter, new) ((tolower(letter) == tolower(new)) ? false : true)

static int count_process(char *s) {

    char letter = '\0';
    int len = strlen(s), count = 0;

    letter = s[0];

    for (int i = 1; i < len; i++) {
        if (IS_CHANGE(letter, s[i])) {
            letter = s[i];
            count++;
        }    
    }
    return count; 
}

int countKeyChanges(char* s) {
    return count_process(s);
}
