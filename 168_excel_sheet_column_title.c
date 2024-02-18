/*
 * =====================================================================================
 *
 *       Filename:  168_excel_sheet_column_title.c
 *
 *    Description:  Excel sheet column title  
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

#define BOUND 26
#define CONVERT_TO_UPCASE(num) (num+64)

void reverse(char *s, int len) {

    int head = 0, end = len - 1;
    char ch = '\0';

    for (; head < end; head++, end--) {
        ch = s[head]; 
        s[head] = s[end];
        s[end] = ch;
    }
    s[len] = '\0';
    return;
}

char* convertToTitle(int columnNumber) {

    char *result = (char *) malloc(sizeof(char)*BUFSIZ);
    int index = 0;
    int remain = 0;

    memset(result, 0, sizeof(char) * BUFSIZ);

    while (columnNumber) {

        if (columnNumber > BOUND) {
            remain = columnNumber%BOUND;
            remain = remain == 0 ? 26 : remain;
        } else {
            remain = columnNumber;
        }
        result[index++] = CONVERT_TO_UPCASE(remain);
        columnNumber -= remain;
        columnNumber /= BOUND;
    }
    reverse(result, index);
    return result;
}

int main(void) {

    char *str = NULL;

    str = convertToTitle(701);

    fprintf(stdout, "%s\n", str);

    return EXIT_SUCCESS;
}
