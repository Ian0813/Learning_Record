/*
 * =====================================================================================
 *
 *       Filename:  819_most_common_word.c
 *
 *    Description:  819 most common word
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

typedef enum {false, true} bool;

#define MAX_SUBSTR_LEN 1000

typedef struct {
    char *strs[MAX_SUBSTR_LEN];
    int count[MAX_SUBSTR_LEN];
    int len;
} substr;

static void to_lowercase(char *s) {

    int len = 0;

    if (!s)
        return;

    len = strlen(s);

    if (!s)
        return;

    for (int i = 0; i < len; i++) {
        s[i] = isalpha(s[i]) ? tolower(s[i]) : s[i];
    }
    return;
}

static bool is_banned(char *str, char **banned, int bannedSize) {

    bool rc = false;

    for (int i = 0; i < bannedSize; i++) {
        if (!strcmp(str, banned[i])) {
            rc = true;   
            break;
        }
    }
    return rc;
}

static void substr_append(substr *sstr, char *str) {

    int index = 0;

    if (!sstr)
        return;

    for (int i = 0; i < sstr->len; i++) {
        if (!strcmp(sstr->strs[i], str)) {
            break;
        }
        index = i+1; 
    }

    if (!sstr->strs[index]) {
        sstr->strs[index] = strdup(str);
    }

    sstr->count[index]++;
    sstr->len = sstr->len > (index+1) ? sstr->len : index + 1;
    return;
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {

    substr sstr = {0};
    char temp[BUFSIZ] = {0}, *ptr = NULL;
    int max = 0;

    to_lowercase(paragraph);

    ptr = strtok(paragraph, " !?',;.");

    while (ptr) {

        sscanf(ptr, "%[a-z]s", temp);

        if (!is_banned(temp, banned, bannedSize)) {
            substr_append(&sstr, temp); 
        }
        ptr = strtok(NULL, " !?',;.");
    }

    for (int i = 0; i < sstr.len; i++) {

        if (sstr.count[i] > max) {
            ptr = strdup(sstr.strs[i]);
            max = sstr.count[i]; 
        }
        free(sstr.strs[i]);
    }
    return ptr;
}
