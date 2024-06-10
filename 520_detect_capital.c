/*
 * =====================================================================================
 *
 *       Filename:  520_detect_capital.c
 *
 *    Description:  Detect Capital
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

typedef enum {false, true} bool;

enum {
    LOWERCASE,
    UPPERCASE,
};

bool detectCapitalUse(char* word) {

    bool rc = true; 
    int last_type = LOWERCASE;

    if (word) {

        last_type = isupper(word[0]) ? UPPERCASE : LOWERCASE;

        for (int i = 1; i < strlen(word); i++) {

            if (isupper(word[i])) {
                if (last_type != UPPERCASE) {
                    rc = false;                     
                    break;
                }
                last_type = UPPERCASE;
            } else if (islower(word[i])) {
                if (last_type == UPPERCASE && i != 1) {
                    rc = false;
                    break;
                }
                last_type = LOWERCASE;
            } else {
                rc = false;  
                break;
            }
        }
    }
    return rc;
}
