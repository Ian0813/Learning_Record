/*
 * =====================================================================================
 *
 *       Filename:  696_count_binary_substrings.c
 *
 *    Description:  Count binary substrings  
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

#define MINIMUM(a, b) ((a) < (b) ? (a) : (b))

int countBinarySubstrings(char* s) {

    int substrings = 0, count = 1;
    int *count_consecutive = (int *) calloc(strlen(s), sizeof(int));
    int index = 0;

    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i-1]) {
            count++; 
        } else {
            count_consecutive[index++] = count;
            count = 1;
        }
    }
    count_consecutive[index++] = count;

    for (int i = 0; i < (index-1); i++) {
        substrings += MINIMUM(count_consecutive[i], count_consecutive[i+1]);        
    }
    return substrings;
}
