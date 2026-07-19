/*
 * =====================================================================================
 *
 *       Filename:  2496_maximum_value_of_a_string_in_an_array.c
 *
 *    Description:  maximum value of a string in an array
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
#include <ctype.h>
#include <limits.h>
#include <sys/param.h>

static int get_value(char *ptr, int len) {

    int value = 0, is_numeric = 1;

    for (int i = 0; i < len; i++) {
        if (isalpha(ptr[i])) {
            is_numeric = 0;
            break;
        }
    }

    if (is_numeric) 
        sscanf(ptr, "%d", &value);
    else 
        value = strlen(ptr);
    return value;
}    

int maximumValue(char** strs, int strsSize) {

    int max = INT_MIN, val = 0;    

    for (int i = 0; i < strsSize; i++) {
        val = get_value(strs[i], strlen(strs[i])); 
        max = MAX(max, val);
    }
    return max;
}
