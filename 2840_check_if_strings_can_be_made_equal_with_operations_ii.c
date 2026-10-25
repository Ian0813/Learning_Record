/*
 * =====================================================================================
 *
 *       Filename:  2840_check_if_strings_can_be_made_equal_with_operations_ii.c
 *
 *    Description:  check if strings can be made equal with operations ii
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

#define ALPHA_TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')

typedef struct {
    int odd_table[ALPHA_TABLE_SIZE];
    int even_table[ALPHA_TABLE_SIZE];
} alpha_index_table; 

static void alpha_counter(char *s, alpha_index_table *t) {

    int slen = 0; 

    if (!s || !t)
        return; 

    slen = strlen(s);

    for (int i = 0; i < slen; i += 2) {
        t->even_table[CH_TO_INDEX(s[i])]++;
    }

    for (int i = 1; i < slen; i += 2) {
        t->odd_table[CH_TO_INDEX(s[i])]++;
    }
    return;
}

static bool alpha_table_comparison(alpha_index_table *t1, alpha_index_table *t2) {

    if (!t1 || !t2)
        return false;

    for (int i = 0; i < ALPHA_TABLE_SIZE; i++) {
        if (t1->even_table[i] != t2->even_table[i])
            return false;

        if (t1->odd_table[i] != t2->odd_table[i])
            return false;
    }    
    return true;
}

bool checkStrings(char* s1, char* s2) {

    alpha_index_table s1_table = {0}, s2_table = {0}; 

    alpha_counter(s1, &s1_table);
    alpha_counter(s2, &s2_table);

    return alpha_table_comparison(&s1_table, &s2_table);
}
