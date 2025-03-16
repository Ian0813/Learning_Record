/*
 * =====================================================================================
 *
 *       Filename:  3174_clear_digits.c
 *
 *    Description:  clear digits
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
#include <ctype.h>

typedef enum {
  false, true 
} bool;

static void clear_process(char *s) {

    int len = strlen(s);
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            if (i && isalpha(s[i-1])) {
                s[i-1] = s[i] = '\n';
            }
         }
    }

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '\n') {
                s[index++] = s[i];
        }
    }
    s[index] = '\0';
    return;
}

static bool check_digit_exist(char *s) {

    bool rc = false;

    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            rc = true;
            break;
        }
    }
    return rc;
}

char* clearDigits(char* s) {

    int index = 0;

    if (check_digit_exist(s)) {
        clear_process(s);
        clearDigits(s);
    }
    return s;
}
