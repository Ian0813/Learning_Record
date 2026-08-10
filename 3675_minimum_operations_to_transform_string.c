/*
 * =====================================================================================
 *
 *       Filename:  3675_minimum_operations_to_transform_string.c
 *
 *    Description:  minimum operations to transform string
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

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')

typedef struct {
    int index;
    int counts;
    int steps;
} ch_node;

static void count_occurrence(char *s, int slen, int *table) {

    if (!s || !table) {
        fprintf(stderr, "[%s] Invalid arguments.\n", __func__);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < slen; i++) {
        table[CH_TO_INDEX(s[i])]++;
    }
    return;
}

int minOperations(char* s) {

    int table[TABLE_SIZE] = {0}, slen = 0;
    ch_node node = {0};

    if (s) {

        slen = strlen(s);
        count_occurrence(s, slen, table);

        for (int i = CH_TO_INDEX('b'); i < TABLE_SIZE; i++) {
            if (table[i]) {
                if (node.index) {
                    node.steps += (i - node.index);
                }
                node.index = i;
            }
        }
    }

    node.steps += (TABLE_SIZE - node.index);
    return node.index ? node.steps : 0;
}
