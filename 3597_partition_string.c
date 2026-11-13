/*
 * =====================================================================================
 *
 *       Filename:  3597_partition_string.c
 *
 *    Description:  partition string
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
#include <stdint.h>
#include <uthash.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    char *str;
    UT_hash_handle hh;
} str_record;

static void record_add_str(str_record **list, char *pattern, str_record **ptr) {

    str_record *record = NULL; 

    record = calloc(1, sizeof(str_record));
    record->str = strdup(pattern);
    HASH_ADD_STR(*list, str, record);

    if (ptr)
        *ptr = record;
    return;
}

char** partitionString(char* s, int* returnSize) {

    int slen = 0, pindex = 0, rindex = 0;
    char pattern[BUFSIZ] = {0}, **result = NULL;
    str_record *record_list = NULL, *record = NULL; 

    if (s) {

        slen = strlen(s);
        result = calloc(slen, sizeof(char *));

        for (int i = 0; i < slen; i++) {

            pattern[pindex++] = s[i];
            HASH_FIND_STR(record_list, pattern, record);

            if (!record) {
                record_add_str(&record_list, pattern, &record);
                result[rindex++] = record->str;
                memset(pattern, 0, pindex);
                pindex = 0;
            }
        }
        *returnSize = rindex;
    }
    return result;
}
