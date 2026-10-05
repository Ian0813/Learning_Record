/*
 * =====================================================================================
 *
 *       Filename:  3407_substring_matching_pattern.c
 *
 *    Description:  substring matching pattern
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
#include <stdbool.h>

bool hasMatch(char* s, char* p) {

    char *p1 = NULL, *p2 = NULL;
    char *sp1 = NULL, *sp2 = NULL;
    int p1_len = 0; 

    p1 = strtok_r(p, "*", &p2);

    if (!p1 && *p2 == '\0')
        return true;

    if (p1 && p2) {

        p1_len = strlen(p1);
        sp1 = strstr(s, p1);

        do {
            sp2 = strstr(s, p2);
            s = sp1 + p1_len;
        } while (sp2 && sp2 < (sp1+p1_len));
    }

    return  sp1 && sp2 ? true : false;
}
