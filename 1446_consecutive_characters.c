/*
 * =====================================================================================
 *
 *       Filename:  1446_consecutive_characters.c
 *
 *    Description:  Consecutive characters  
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

#define INIT_LENGTH 1

int maxPower(char* s) {

    int cur = INIT_LENGTH, max = INIT_LENGTH;

    for (int i = 0; i < strlen(s)-1; i++) {
        if (s[i] == s[i+1]) {
            cur++;
        } else {
            if (max < cur) {
                max = cur;
            }
            cur = INIT_LENGTH;
        }    
    }

    if (max < cur) {
        max = cur;
    }
    return max;
}

