/*
 * =====================================================================================
 *
 *       Filename:  1807_evaluate_the_bracket_pairs_of_a_string.c
 *
 *    Description:  evaluate the bracket pairs of a string
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
#include <regex.h>
#include <uthash.h>

#define MAXLEN 100001
#define KEYLEN 256
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(*arr))

typedef enum {
    INDEX_KEY = 0,
    INDEX_VAL = 1,
} pair_index_t;

typedef struct {
    char data[KEYLEN];
    char *rdata;
    UT_hash_handle hh;
} hnode_t;

static char *convert_matched(char *matched, int mlen, char ***knowledge, int knowledgeSize, int *knowledgeColSize, char *result, int *rlen) {

    int index = -1;

    for (int i = 0, j = 0; i < knowledgeSize; i++, j = 0) {
        for (j = 0; j < mlen; j++) {
            if (matched[j] != knowledge[i][INDEX_KEY][j] || knowledge[i][INDEX_KEY][j] == '\0') {
                break;
            }
        }

        if (mlen == j && knowledge[i][INDEX_KEY][j] == '\0') {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = 0; knowledge[index][INDEX_VAL][i] != '\0'; i++) {
            result[*rlen] = knowledge[index][INDEX_VAL][i];
            *rlen += 1;
        }
    } else {
        result[*rlen] = '?'; 
        *rlen += 1;
    }
    return NULL;
}

static void hash_register(hnode_t **hlist, hnode_t *hkeys, int *hkey_len, char ***knowledge, int knowledgeSize, int *knowledgeColSize) {

    hnode_t *hdata = NULL;
    char *key = NULL;
    int keylen = 0;

    for (int i = 0; i < knowledgeSize; i++) {

        key = knowledge[i][INDEX_KEY];
        keylen = strlen(knowledge[i][INDEX_KEY]);
        HASH_FIND(hh, *hlist, key, keylen, hdata); 

        if (!hdata) {
            hkeys[*hkey_len].rdata = knowledge[i][INDEX_VAL]; 
            HASH_ADD_KEYPTR(hh, *hlist, key, keylen, &hkeys[*hkey_len]);
            *hkey_len += 1;
        }
    }
    return;
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {

    const char *filter_pattern = "([a-z]*)";
    char *result = NULL, *str = NULL, *trans_str = NULL, *last_end = NULL, key[BUFSIZ] = {0}, temp = '\0';
    int result_len = 0, len = 0, tran_len = 0, hkey_len = 0;
    regex_t regex_obj;
    regmatch_t pmatch[1] = {0};
    hnode_t hkeys[MAXLEN] = {0}, *hdata = NULL, *hlist = NULL;

    result = calloc(MAXLEN, sizeof(char));
    //regcomp(&regex_obj, filter_pattern, REG_NEWLINE);
    str = s;

    hash_register(&hlist, hkeys, &hkey_len, knowledge, knowledgeSize, knowledgeColSize);

    for (int i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {

            for (j = i+1; s[j] != ')'; j++)
                ;
            len = j - (i+1);

            HASH_FIND(hh, hlist, &s[i+1], len, hdata);

            if (hdata) {
                for (int k = 0; hdata->rdata[k] != '\0'; k++)
                    result[result_len++] = hdata->rdata[k]; 
            } else {
                result[result_len++] = '?';
            }
            i = j;
        } else {
            result[result_len++] = s[i];
        }
    }

#if 0
    while (!regexec(&regex_obj, str, ARRAY_SIZE(pmatch), pmatch, 0)) {

        if (last_end) {
            memcpy(&result[result_len], last_end, (&str[pmatch[0].rm_so]) - last_end);
            result_len += ((&str[pmatch[0].rm_so]) - last_end);
        }

        len = (pmatch[0].rm_eo - pmatch[0].rm_so) - 2;
        // memcpy(key, &str[pmatch[0].rm_so] + 1, len);

        // HASH_FIND_STR(hlist, key, hdata);

        // if (!hdata) {
            trans_str = convert_matched(&str[pmatch[0].rm_so] + 1, len, knowledge, knowledgeSize, knowledgeColSize, result, &result_len);
            // memcpy(hkey.data, key, len);
            // hkey.rdata = trans_str;
            // HASH_ADD_STR(hlist, data, &hkey);
        // } else if (hdata) {
        //     trans_str = hdata->rdata;
        // }

        //tran_len = strlen(trans_str);
        last_end = &str[pmatch[0].rm_eo];
        //memcpy(&result[result_len], trans_str, tran_len);
        //result_len += tran_len;
        str += pmatch[0].rm_eo;
        // memset(key, 0, len);
    }

    if (last_end) {
        len = (s + strlen(s)) - last_end;

        for (int i = 0; i < len; i++) {
            result[result_len++] = *(last_end+i);
        }
    }
    regfree(&regex_obj);
#endif
    return result;
}
