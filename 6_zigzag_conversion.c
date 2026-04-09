/*
 * =====================================================================================
 *
 *       Filename:  6_zigzag_conversion.c
 *
 *    Description:  zigzag conversion
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
#include <ctype.h>

static char **matrix_allocate(int rows, int cols) {

    char **matrix = NULL;

    matrix = (char **) calloc(rows, sizeof(char *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *) calloc(cols, sizeof(char));
    }

    return matrix;
}

static void matrix_fillin(char *s, char **matrix, int rows, int cols) {

    int slen = 0, index = 0; 

    slen = strlen(s);

    for (int i = 0; i < cols && index < slen; i++) {

        for (int j = 0; j < rows && index < slen; j++) {
            matrix[j][i] = s[index++];
        }

        for (int j = rows-2; j > 0 && index < slen && i < (cols-1); j--) {
            matrix[j][++i] = s[index++];  
        }
    }
    return;
}

static void matrix_free(char **matrix, int rows, int cols) {

    if (!matrix)
        return;

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return;
}

char* convert(char* s, int numRows) {

    char **matrix = NULL;
    int len = 0, index = 0;

    if (s) {

        len = strlen(s);
        matrix = matrix_allocate(numRows, len);
        matrix_fillin(s, matrix, numRows, len);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < len; j++) {
                if (isprint(matrix[i][j])) {
                    s[index++] = matrix[i][j];
                }
            }
        }

        matrix_free(matrix, numRows, len);
    }
    return s;
}
