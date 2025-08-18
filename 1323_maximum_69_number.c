/*
 * =====================================================================================
 *
 *       Filename:  1323_maximum_69_number.c
 *
 *    Description:  Maximum 69 number
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

typedef enum {
    DIGIT_THREE = 3,
    DIGIT_SIX = 6,
    DIGIT_NINE = 9
} DIGIT_TYPE;

DIGIT_TYPE get_digit(int num, int divider) {

    int digit = 0;

    if (divider > 10) {
       num /= 10;
       divider /= 10;
       digit = get_digit(num, divider); 
    } else {
       digit = (num % divider);
    }
    return digit; 
}

int maximum69Number (int num) {

    int max_divider = -1, temp = 0, divider = 10;

    temp = num; 

    while (temp) {
        if (get_digit(num, divider) == DIGIT_SIX) {
            max_divider = divider; 
        }
        temp /= 10;
        divider *= 10;
    }

    if (max_divider != -1)
        num =  num + ((max_divider * 3) / 10);
        
    return num;
}
