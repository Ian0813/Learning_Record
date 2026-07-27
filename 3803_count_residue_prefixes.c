/*
 * =====================================================================================
 *
 *       Filename:  3803_count_residue_prefixes.c
 *
 *    Description:  count residue prefixes
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

#define ALPHABET_LEN 26
#define CH_TO_INDEX(ch) ((ch)-'a')

typedef struct {
    bool table[ALPHABET_LEN];
    int diff_count;
} alphabet_data_t;

static bool get_prefix_len(alphabet_data_t *obj, char ch) {

    if (!obj)
        return false;

    if (!obj->table[CH_TO_INDEX(ch)]) {
        obj->table[CH_TO_INDEX(ch)] = true;
        obj->diff_count++;
        return true;
    }
    return false;
}

int residuePrefixes(char* s) {

    alphabet_data_t tracker = {0};
    int slen = 0, residue_count = 0;

    if (s) {

        slen = strlen(s);

        for (int i = 0; i < slen; i++) {
            get_prefix_len(&tracker, s[i]);

            if (tracker.diff_count == ((i+1)%3)) {
                residue_count++;
            }
        }
    }
    return residue_count;
}
