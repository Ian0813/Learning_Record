/*
 * =====================================================================================
 *
 *       Filename:  2710_remove_trailing_zeros_from_a_string.c
 *
 *    Description:  remove trailing zeros from a string
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

char* removeTrailingZeros(char* num) {

    int len = strlen(num);

    for (int i = len - 1; i >= 0 && num[i] == '0'; i--) {
        num[i] = num[i] == '0' ? '\0' : num[i];
    }

    return num;
}
