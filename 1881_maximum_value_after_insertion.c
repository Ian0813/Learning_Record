/*
 * =====================================================================================
 *
 *       Filename:  1881_maximum_value_after_insertion.c
 *
 *    Description:  maximum value after insertion
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
#include <inttypes.h>

typedef enum {false, true} bool;

#define INT_TO_CH(x) ((x)+'0')
#define EXTRA_SPACE 2 // For an appended digit and null-terminated byte.  

char* maxValue(char* n, int x) {

    int positive = true;
    int len = strlen(n);
    char *result = (char *) calloc(strlen(n)+EXTRA_SPACE, sizeof(char));

    memcpy(result, n, strlen(n));

    for (int i = 0; i < strlen(n); i++) {
        if (isalnum(n[i])) {
            if (positive && n[i] < INT_TO_CH(x) || !positive && n[i] > INT_TO_CH(x)) {
                memcpy(&result[i+1], &n[i], (len-i));                         
                result[i] = INT_TO_CH(x);
                break;
            }    
        } else {
            positive = false; 
        }
    }

    if (len == strlen(result)) {
        result[len] = INT_TO_CH(x);
    }
    return result;
}
