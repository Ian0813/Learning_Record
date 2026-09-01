/*
 * =====================================================================================
 *
 *       Filename:  2027_minimum_moves_to_convert_string.c
 *
 *    Description:  minimum moves to convert string
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

#define PATTERN_LEN 3
#define GOLDEN__PATTERN "OOO"

int minimumMoves(char* s) {

    int slen = strlen(s), index = 0;
    int move_count = 0;

    while (index < slen) {

        if (s[index] == 'O') {
            index++; 
            continue;
        }

        for (int i = 0; i < PATTERN_LEN; i++) {
            if ((index+i) < slen)
                s[index+i] = 'O';
        }

        index += PATTERN_LEN;
        move_count++;
    }    
    return move_count;
}
