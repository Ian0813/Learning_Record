/*
 * =====================================================================================
 *
 *       Filename:  1582_special_positions_in_a_binary_matrix.c
 *
 *    Description:  special positions in a binary matrix
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

#define MAX_LENGTH (100 * 100)
#define PAIR_SIZE 2
#define SKIP_SELFPOINT(row1, row2, col1, col2) ((row1) == (row2) && (col1) == (col2))

typedef enum {
    POS_FIRST = 0,
    POS_SECOND = 1
} position_index_t;

typedef enum {
    CONFLICT_NONE = -1,
    CONFLICT_ROW = 0,
    CONFLICT_COLUMN = 1
} conflict_type;

struct one_recorder {
    int location[MAX_LENGTH][PAIR_SIZE];
    int length;
};

static void collect_one_location(int **mat, int matSize, int matColSize, struct one_recorder *recorder) {

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize; j++) {
            if (mat[i][j]) {
                recorder->location[recorder->length][POS_FIRST] = i;
                recorder->location[recorder->length][POS_SECOND] = j;
                recorder->length++;
            }
        }    
    }
    return;
}

static conflict_type check_special(struct one_recorder *recorder, int row, int column) {

    conflict_type rc = CONFLICT_NONE;

    for (int i = 0; i < recorder->length; i++) {
        if (recorder->location[i][POS_FIRST] == row || recorder->location[i][POS_SECOND] == column) {

            if (SKIP_SELFPOINT(recorder->location[i][POS_FIRST], row, recorder->location[i][POS_SECOND], column))
                continue;   

            if (recorder->location[i][POS_FIRST] == row) {
                rc = CONFLICT_ROW;    
            } else if (recorder->location[i][POS_SECOND] == column) {
                rc = CONFLICT_COLUMN;
            }
            break;
        }
    }

    return rc; 
}

int numSpecial(int** mat, int matSize, int* matColSize) {

    struct one_recorder recorder = {0};
    int count = 0;
    conflict_type conflict = CONFLICT_NONE;

    collect_one_location(mat, matSize, *matColSize, &recorder);

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] && ((conflict = check_special(&recorder, i, j)) == CONFLICT_NONE)) {
                count++; 
            }

            if (conflict == CONFLICT_ROW)
                break;
        }
        conflict = CONFLICT_NONE;
    }
    
    return count;
}
