/*
 * =====================================================================================
 *
 *       Filename:  2259_remove_digit_from_number_to_maximize_result.c
 *
 *    Description:  remove digit from number to maximize result
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
#include <limits.h>

#define MAX_LENGTH 100

static void comparison(char *buffer_max, char *buffer_temp) {

    int length = strlen(buffer_max), tindex = 0, mindex = 0;

    for (int i = 0; i < length; i++) {
        if (buffer_temp[i] > buffer_max[i]) {
            tindex = i;    
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        if (buffer_max[i] > buffer_temp[i]) {
            mindex = i;    
            break;
        }
    }
    if (tindex < mindex)
        memcpy(buffer_max, buffer_temp, length);
    return;
}

char* removeDigit(char* number, char digit) {

    int index = 0, length = strlen(number), firstless = 0;
    char buffer_temp[MAX_LENGTH] = {0}, buffer_max[MAX_LENGTH] = {0};

    for (int i = 0; i < length; i++) {
        if (number[i] == digit) {
            index = i; 
            break;
        }
    }

    memcpy(buffer_max, number, index);
    memcpy(buffer_max+index, number+(index+1), length-(index+1));
    buffer_max[length-1] = '\0';

    for (int i = index+1; i < length; i++) {
        if (number[i] == digit) {
            memcpy(buffer_temp, number, i);
            memcpy(buffer_temp+i, number+(i+1), length-(i+1));
            buffer_temp[length-1] = '\0';
            comparison(buffer_max, buffer_temp); 
            memset(buffer_temp, 0, MAX_LENGTH);
        }
    }
    memcpy(number, buffer_max, length-1);
    number[length-1] = '\0';
    return number;
}

int main(void) {

    char numbers[BUFSIZ] = "123", digit = '3';
    char *ptr = NULL;

    ptr = removeDigit(numbers, digit);

    printf("ptr: %s\n", ptr);

    return EXIT_SUCCESS;
}
