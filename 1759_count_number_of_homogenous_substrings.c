/*
 * =====================================================================================
 *
 *       Filename:  1759_count_number_of_homogenous_substrings.c
 *
 *    Description:  count number of homogenous substrings
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

#define GET_TOTAL_COUNT(count) (((count)*(count+1))/2)
#define BOUNDARY_LIMITATION 1000000007

static int count_process(char *s, int slen) {

    long long count = 1LL, result = 0LL;
    char ch = '\0';

    ch = s[0];

    for (int i = 1; i < slen; i++) {
        if (ch != s[i]) {
            result = (result + GET_TOTAL_COUNT(count)) % BOUNDARY_LIMITATION; 
            count = 1LL; 
            ch = s[i];
        } else {
            count++; 
        }
    }
    result = (result + GET_TOTAL_COUNT(count)) % BOUNDARY_LIMITATION; 
    return (int) result;
}

int countHomogenous(char* s) {
    return count_process(s, strlen(s));
}
