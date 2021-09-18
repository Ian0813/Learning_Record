/*
 * =====================================================================================
 *
 *       Filename:  205_isomorphic_strings.c
 *
 *    Description:  Isomorphic strings 
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

typedef unsigned int bool;
enum BOOL {false, true};

bool isIsomorphic(char* s, char* t) {

    char table[128] = {0};
    char mark[128] = {0};

    for (int i = 0; i < strlen(s); i++) {
        if (!table[(int)s[i]] && !mark[(int)t[i]]) {
            table[(int)s[i]] = t[i];
            mark[(int)t[i]] = 1;
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        if (table[(int)s[i]] != t[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    return 0;
}
