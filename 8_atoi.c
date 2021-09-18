/*
 * =====================================================================================
 *
 *       Filename:  8_atoi.c
 *
 *    Description:  String to Integer  
 *
 *         Author:  Ian
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int myAtoi(char* s) {

    int digit = 0, value = 0, sign = 1; 

	while (*s) {
        if (isdigit(*s)) {
            digit = *s - 48;    
			value = value * 10 + digit;
		} else if (*s == '-') {
            sign = -sign; 
		}
		s++;
	}
	return value * sign;
}

int main(void) {

    return 0;
}

