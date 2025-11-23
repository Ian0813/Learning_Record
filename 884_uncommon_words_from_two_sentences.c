/*
 * =====================================================================================
 *
 *       Filename:  884_uncommon_words_from_two_sentences.c
 *
 *    Description:  uncommon words from two sentences
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

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STR_LIST 201

static void split_to_list(char *s1, char **list, int *len) {

    char *ptr = NULL;

    ptr = strtok(s1, " ");

    while (ptr) {
        list[*len] = ptr;
        *len += 1;
        ptr = strtok(NULL, " ");
    }

    return;
}

static bool is_duplicate(char **list, int len, char *word, bool is_checkself) {

    bool rc = false;
    int occur_time = is_checkself ? -1 : 0;

    for (int i = 0; i < len; i++) {
        if (!strcmp(list[i], word)) {

            if (occur_time == -1) {
                occur_time = 0;
                continue;
            }

            if (!occur_time) {
                rc = true;
                break;
            }
        }
    }
    return rc;
}

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {

    char *list1[MAX_STR_LIST] = {NULL}, *list2[MAX_STR_LIST] = {NULL};
    char **ptr = NULL;
    char **uncommon_list = NULL;
    int len1 = 0, len2 = 0, ulen = 0;

    if (strlen(s1) || strlen(s2)) {

        uncommon_list = (char **) calloc(MAX_STR_LIST, sizeof(char *));

        split_to_list(s1, list1, &len1);
        split_to_list(s2, list2, &len2);

        ptr = list1;

        for (int i = 0; i < len1; i++) {
            if (!is_duplicate(list1, len1, ptr[i], ptr == list1) && !is_duplicate(list2, len2, ptr[i], ptr == list2)) {
                uncommon_list[ulen] = ptr[i];
                ulen++;
            }
        }

        ptr = list2;

        for (int i = 0; i < len2; i++) {
            if (!is_duplicate(list1, len1, ptr[i], ptr == list1) && !is_duplicate(list2, len2, ptr[i], ptr == list2)) {
                uncommon_list[ulen] = ptr[i];
                ulen++;
            }
        }

        *returnSize = ulen;
    }
    return uncommon_list;
}
