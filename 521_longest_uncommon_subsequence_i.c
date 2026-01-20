/*
 * =====================================================================================
 *
 *       Filename:  521_longest_uncommon_subsequence_i.c
 *
 *    Description:  longest uncommon subsequence i
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
#include <ctype.h>
#include <unistd.h>

typedef enum {false, true} bool;

int findLUSlength(char* a, char* b) {

    int len_a = strlen(a), len_b = strlen(b), llen = 0, slen = 0, temp = 0;
    char *lptr = NULL, *sptr = NULL;
    int result = -1;
    bool flag = false;

    lptr = len_a > len_b ? a : b;
    sptr = lptr == a ? b : a;

    llen = lptr == a ? len_a : len_b;
    slen = lptr == a ? len_b : len_a;

    for (int i = 0; llen == slen && i < slen; i++) {

        temp = slen - i;

        for (int j = llen - temp; j >= 0; j--) {
            if (strncmp(&sptr[i], &lptr[j], temp)) {
                result = temp;
                flag = true;
            } else {
                flag = false;   
                break;
            }
        }

        if (flag)
            break;
    }

    if (slen != llen)
        result = slen;

    return result == slen ? llen : result;
}
