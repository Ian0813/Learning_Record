/*
 * =====================================================================================
 *
 *       Filename:  1925_count_square_sum_triples.c
 *
 *    Description:  count square sum triples
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

#define SQUARE_TABLE_SIZE ((250 * 250) + 1)
#define MAXIMUM_VAL 250

static void square_table_generate(int *table, int value) {

    for (int i = 1; i <= value; i++) {
        table[i * i] = true;
    }
    return;
}    

int countTriples(int n) {

    int table[SQUARE_TABLE_SIZE] = {0};    
    int count = 0, boundary = (n * n), csquare = 0;

    square_table_generate(table, MAXIMUM_VAL);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;

            csquare = (i * i) + (j * j);

            if (csquare > boundary)
                break;

            if (table[csquare])
                count++;
        }
    }
    return count;
}
