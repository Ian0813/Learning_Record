/*
 * =====================================================================================
 *
 *       Filename:  171_excel_sheet_column_number.c
 *
 *    Description:  excel sheet column number
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

#define CH_TO_INT(ch) ((ch)-'A'+1)

static int calculate_multiply(char *columnTitle) {

    int value = 0, unit = 1;

    for (int i = strlen(columnTitle)-1; i >= 0; i--) {
        value += CH_TO_INT(columnTitle[i])*unit;
        unit = i > 0 ? unit*26 : unit;
    }

RETURN_POINT:;
    return value;
}

int titleToNumber(char* columnTitle) {

    int len = 0, result = 0;

    len = strlen(columnTitle);

    result += calculate_multiply(columnTitle);

    return result;
}
