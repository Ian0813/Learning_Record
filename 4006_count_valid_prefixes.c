/*
 * =====================================================================================
 *
 *       Filename:  4006_count_valid_prefixes.c
 *
 *    Description:  count valid prefixes
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

#define COUNTER_LEN 2
#define CH_TO_INDEX(ch) ((ch)-'0')

typedef enum {
    DIGIT_ZERO_INDEX = 0,
    DIGIT_ONE_INDEX = 1,
} digit_index_t;

int countValidPrefixes(char* s) {

    int counter[COUNTER_LEN] = {0};        
    int slen = 0, count = 0;

    if (s) {
        slen = strlen(s);

        for (int i = 0; i < slen; i++) {
            counter[CH_TO_INDEX(s[i])]++; 
            if (abs(counter[DIGIT_ZERO_INDEX]-counter[DIGIT_ONE_INDEX]) <= 1)
                count++;
        }
    }
    return count;
}
