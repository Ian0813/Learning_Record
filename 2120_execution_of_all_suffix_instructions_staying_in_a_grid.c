/*
 * =====================================================================================
 *
 *       Filename:  2120_execution_of_all_suffix_instructions_staying_in_a_grid.c
 *
 *    Description:  execution of all suffix instructions staying in a grid
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

enum {
    R_INDEX = 0,
    C_INDEX = 1,
};

enum {
    GO_LEFT = 'L',
    GO_RIGHT = 'R',
    GO_UP = 'U',
    GO_DOWN = 'D'
};

static void movement(int *pos, char direction) {

    switch (direction) {
        case GO_LEFT: {
            pos[C_INDEX] -= 1; 
        }
        break;
        case GO_RIGHT: {
            pos[C_INDEX] += 1; 
        }
        break;
        case GO_UP: {
            pos[R_INDEX] -= 1; 
        }
        break;
        case GO_DOWN: {
            pos[R_INDEX] += 1; 
        }
        break;
    }    
    return;
}

static int get_steps(int *pos, int boundary, const char *ins) {

    int count = 0;

    for (int i = 0; i < strlen(ins); i++) {

        movement(pos, ins[i]);

        if ((pos[R_INDEX] < boundary && pos[C_INDEX] < boundary) && 
             (pos[R_INDEX] >= 0 && pos[C_INDEX] >= 0)) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int* executeInstructions(int n, int* startPos, int startPosSize, char* s, int* returnSize) {

    int *result = NULL;    
    int *pos = (int *) calloc(startPosSize, sizeof(int)); 

    if (startPosSize) {

        result = (int *) calloc(strlen(s), sizeof(int));

        for (int i = 0; i < strlen(s); i++) {
            memcpy(pos, startPos, sizeof(int) * startPosSize);
            result[i] = get_steps(pos, n, &s[i]);
        }
        *returnSize = strlen(s);
    }
    free(pos);
    return result;
}
