/*
 * =====================================================================================
 *
 *       Filename:  1021 remove outermost parentheses.c
 *
 *    Description:  remove outermost parentheses *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PAIR_LEN 2

typedef struct collect_parentheses {
    int start;
    int end;
    int lcount; 
    int rcount;
} parentheses_collector;

static void locator(char *s, parentheses_collector *collector) {

    if (!collector)
        return;

    collector->start = collector->end;

    do {
        s[collector->end++] == '(' ? collector->lcount++ : collector->rcount++; 
    } while (collector->lcount != collector->rcount);

    return;
}

char* removeOuterParentheses(char* s) {

    char *parsed_str = NULL;
    int len = strlen(s), plen = 0;
    parentheses_collector collector = {0};

    if (len) {

        parsed_str = (char *) calloc(len, sizeof(char));

        while (len) {
            locator(s, &collector);   
            len -= (collector.lcount + collector.rcount);
            memcpy(&parsed_str[plen], &s[collector.start+1], (collector.lcount + collector.rcount) - PAIR_LEN);
            plen += (collector.rcount + collector.lcount) - PAIR_LEN;
            collector.rcount = collector.lcount = 0;
        }
    }

    return parsed_str;
}
