/*
 * =====================================================================================
 *
 *       Filename:  1763_longest_nice_substring.c
 *
 *    Description:  longest nice substring
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
#include <stdbool.h>

#define TABLE_SIZE 26

typedef struct {
    int utable[TABLE_SIZE];
    int ltable[TABLE_SIZE];
} table_node;

static void node_counter(char *s, int slen, table_node *node) {

    if (!s || !node)
        return;

    for (int i = 0; i < slen; i++) {
        if (isupper(s[i])) {
            node->utable[s[i] - 'A']++;
        } else if (islower(s[i])) {
            node->ltable[s[i] - 'a']++;
        }
    }
    return;
}

static bool check_valid(char *s, int len) {

    table_node node = {0};

    for (int i = 0; i < len; i++) {
        if (isupper(s[i])) {
            node.utable[s[i] - 'A']++;
        } else if (islower(s[i])) {
            node.ltable[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < len; i++) {
        if (!node.utable[toupper(s[i]) - 'A'] || !node.ltable[tolower(s[i]) - 'a']) {
            return false; 
        }
    }
    return true;
}

static void get_nice_string(char *s, int slen, char *result, int *rlen) {

    table_node node = {0};
    char *ptr = NULL;
    int len = 0;

    node_counter(s, slen, &node);

    for (int i = 0; i < slen; i++) {
        if (node.utable[toupper(s[i]) - 'A'] && node.ltable[tolower(s[i]) - 'a']) {
            len++;
            ptr = &s[i];
        } else {
            if (*rlen < len) {

                if (check_valid(ptr - (len-1), len)) {
                    memcpy(result, ptr - (len-1), len);
                    *rlen = len;
                    result[len] = '\0';
                } else {
                    get_nice_string(ptr - (len-1), len, result, rlen);
                }

                for (int j = i - len; j < i; j++) {
                    if (isupper(s[j])) {
                        node.utable[toupper(s[j]) - 'A']--;
                    } else if (islower(s[j])) {
                        node.ltable[tolower(s[j]) - 'a']--;
                    }
                }
            }
            len = 0;
        }
    }

    if (*rlen < len) {
        if (check_valid(ptr - (len-1), len)) {
            memcpy(result, ptr - (len-1), len);
            *rlen = len;
            result[len] = '\0';
        } else {
            get_nice_string(ptr - (len-1), len, result, rlen);
        }
    }
    return;
}

char* longestNiceSubstring(char* s) {

    int slen = 0, len = 0, rlen = 0, record = 0;
    char *result = NULL;
    table_node node = {0};

    if (s) {
        slen = strlen(s);
        result = calloc(slen + 1, sizeof(char));
        node_counter(s, slen, &node);

        for (int i = 0; i < slen; i++) {
            if (node.utable[toupper(s[i]) - 'A'] && node.ltable[tolower(s[i]) - 'a']) {
                len++;
            } else {
                get_nice_string(s + record, (i+1) - record, result, &rlen);
                record = i+1;
                len = 0;
            }
        }
        get_nice_string(s + record, slen - record, result, &rlen);
    }
    return result;
}
