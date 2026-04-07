/*
 * =====================================================================================
 *
 *       Filename:  2075_decode_the_slanted_ciphertext.c
 *
 *    Description:  decode the slanted ciphertext
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>

static char **matrix_allocate(int row, int col) {

    char **ptr = NULL;

    ptr = (char **) calloc(row, sizeof(char *));

    for (int i = 0; i < row; i++) {
        ptr[i] = (char *) calloc(col, sizeof(char));
    }

    return ptr;
}

static void matrix_fillin(char **matrix, int rows, int cols, char *encodedText, int len) {

    int index = 0;

    for (int i = 0; i < rows && index < len; i++) {
        for (int j = 0; j < cols && index < len; j++) {
            matrix[i][j] = encodedText[index++];
        }
    }
    return;
}

static void matrix_retrieve(char **matrix, int rows, int cols, char *result, int *index) {

    for (int i = 0; i < cols; i++) {
        for (int j = i, k = 0; k < rows && j < cols; k++, j++) {
            result[*index] = matrix[k][j];
			*index += 1;
        }
    }

    return;
}

static void matrix_free(char **matrix, int rows) {

    if (rows) {
        matrix_free(matrix, rows-1);
        free(matrix[rows-1]);
    }
    return;
}

char* decodeCiphertext(char* encodedText, int rows) {

    int cols = 0, len = 0, index = 0;
    char **matrix = NULL;

    len = strlen(encodedText);

    if (len) {

        cols = len/rows;
        matrix = matrix_allocate(rows, cols); 

        matrix_fillin(matrix, rows, cols, encodedText, len);
        memset(encodedText, 0, len);

        matrix_retrieve(matrix, rows, cols, encodedText, &index);
        matrix_free(matrix, rows);
        free(matrix);

        while (isspace(encodedText[index-1])) {
            encodedText[index-1] = '\0';
            index--;
        }
    }

    return encodedText;
}

