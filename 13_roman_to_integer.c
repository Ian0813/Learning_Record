/*
 * =====================================================================================
 *
 *       Filename:  13_roman_to_integer.c
 *
 *    Description:  Roman to integer  
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

int symbol_to_int(char symbol) {

    int value = 0;

    switch (symbol) {
        case 'I':     
            value = 1;
        break;
        case 'V':
            value = 5;
        break;
        case 'X':
            value = 10;
        break;
        case 'L':
            value = 50;
        break;
        case 'C':
            value = 100;
        break;
        case 'D':
            value = 500;
        break;
        case 'M':
            value = 1000;
        break;
        default:
    }
    return value;
}

int romanToInt(char* s) {

    int last = 0, value = 0, sum = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        value = symbol_to_int(s[i]);            

        if (value > last) {
            value -= last; 
			sum -= last;
        }
        sum += value;
        last = value;
    }

    return sum;
}
