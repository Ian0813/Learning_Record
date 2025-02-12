/*
 * =====================================================================================
 *
 *       Filename:  3274_check_if_two_chessboard_squares_have_the_same_color.c
 *
 *    Description:  check if two chessboard squares have the same color
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

typedef enum {false, true} bool; 

#define FIELD_NUMBER 8
#define CLASSIFY_ALPHA(col) (((col+1)%2) ? ODD : EVEN)
#define ODD_COLOR(num) ((num+1)%2) ? BLACK : WHITE
#define EVEN_COLOR(num) ((num+1)%2) ? WHITE : BLACK
#define ALPHA_TO_NUM(ch) ((ch)-'a')
#define NUMERICAL_CH_TO_NUM(ch) ((ch)-'1')
#define TRANSLATE_COLOR(fields, alpha, num) (fields[alpha][num])

enum {
    WHITE = 0,
    BLACK = 1
};

enum {
    ODD = 0,
    EVEN = 1
};

enum COLS {
    a = 0,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
};

static void fill_colors(int fields[][FIELD_NUMBER]) {

    for (int i = a; i <= h; i++) {
        for (int j = 0; j < FIELD_NUMBER; j++) {
            if (CLASSIFY_ALPHA(i) == ODD) {
                fields[j][i] = ODD_COLOR(j);
            } else if (CLASSIFY_ALPHA(i) == EVEN) {
                fields[j][i] = EVEN_COLOR(j);
            }
        }
    }
    return;
}

static void print_fields(int fields[][FIELD_NUMBER]) {

    for (int i = FIELD_NUMBER-1; i >= 0; i--) {
        for (int j = 0; j < FIELD_NUMBER; j++) {
            printf("%d ", fields[i][j]);
        }
        putchar('\n');
    }
    return;
}

bool checkTwoChessboards(char* coordinate1, char* coordinate2) {

    int fields[FIELD_NUMBER][FIELD_NUMBER];
    int alpha_num = 0, numerical_num = 0;
    int c1_color = BLACK, c2_color = BLACK;

    fill_colors(fields);

    alpha_num = ALPHA_TO_NUM(coordinate1[0]);
    numerical_num = NUMERICAL_CH_TO_NUM(coordinate1[1]);
    c1_color = TRANSLATE_COLOR(fields, alpha_num, numerical_num);

    alpha_num = ALPHA_TO_NUM(coordinate2[0]);
    numerical_num = NUMERICAL_CH_TO_NUM(coordinate2[1]);
    c2_color = TRANSLATE_COLOR(fields, alpha_num, numerical_num);

    return c1_color == c2_color ? true : false;
}
