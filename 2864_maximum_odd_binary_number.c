/*
 * =====================================================================================
 *
 *       Filename:  2864_maximum_odd_binary_number.c
 *
 *    Description:  Maximum odd binary number  
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

char* maximumOddBinaryNumber(char* s){

    int one_counts = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1')
            one_counts++;
    }

    s[strlen(s)-1] = '1';
    one_counts--;

    memset(s, '0', (strlen(s)-1) * sizeof(char));

    for (int i = 0; i < one_counts; i++) {
        s[i] = '1';     
    }
    return s;
}
