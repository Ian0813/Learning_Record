/*
 * =====================================================================================
 *
 *       Filename:  2194_cells_in_a_range_on_an_excel_sheet.c
 *
 *    Description:  cells in a range on an excel sheet
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define INFO_SIZE 2
#define UNIT_SIZE 2

enum {
    START_INDEX = 0,
    END_INDEX = 1
};

static void convert_info(char *s, char *rows, char *columns) {

    while (*s != ':') {
        if (isalpha(*s)) {
            columns[START_INDEX] = *s;
        }

        if (isdigit(*s)) {
            rows[START_INDEX] = *s;
        }
        s++;
    }

    while (*s) {
        if (isalpha(*s)) {
            columns[END_INDEX] = *s;
        }

        if (isdigit(*s)) {
            rows[END_INDEX] = *s;
        }
        s++;
    }
    return;
}

static char **allocate_result(char *rows, char *columns) {

    char **result = NULL;
    int amount = 0;

    amount = ((rows[END_INDEX]-rows[START_INDEX])+1) * ((columns[END_INDEX]-columns[START_INDEX])+1);

    result = (char **) calloc(amount, sizeof(char *));

    for (int i = 0; i < amount; i++) {
        result[i] = (char *) calloc(UNIT_SIZE+1, sizeof(char));
    }
    return result;
}

char** cellsInRange(char* s, int* returnSize) {

    char rows[INFO_SIZE] = {0};
    char columns[INFO_SIZE] = {0}, unit[UNIT_SIZE+1] = {0};
    char **result = NULL;
    int len = 0;

    convert_info(s, rows, columns);
    result = allocate_result(rows, columns);

    for (char i = columns[START_INDEX]; i <= columns[END_INDEX]; i++) {
        for (char j = rows[START_INDEX]; j <= rows[END_INDEX]; j++) {
            sprintf(unit, "%c%c", i, j);
            memcpy(result[len], unit, UNIT_SIZE);
            len++;
            memset(unit, 0, UNIT_SIZE+1);
        }
    }
    *returnSize = len;
    return result;
}
