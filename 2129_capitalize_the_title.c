/*
 * =====================================================================================
 *
 *       Filename:  2129_capitalize_the_title.c
 *
 *    Description:  Capitalize the title  
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

void capitalized(char *str, int len) {

    if (len > 2) {
        for (int i = 0; i < len; i++) {
            if (!i) {
                str[i] = toupper(str[i]);  
            } else {
                str[i] = tolower(str[i]);  
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            str[i] = tolower(str[i]);  
        }
    }
    return; 
}

char* capitalizeTitle(char* title) {

    int i = 0, j = 0;

    for (i = 0, j = 0; title[j]; j++) {
        if (title[j] == ' ') {
            capitalized(&title[i], (j-i));
            i = j+1; 
        }
    }
    capitalized(&title[i], (j-i));
    return title;
}

