/*
 * =====================================================================================
 *
 *       Filename:  788_rotated_digits.c
 *
 *    Description:  rotated digits
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

typedef enum {
    ROTATE_INVALID = -1,
    ROTATE_UNCHANGE = 0,
    ROTATE_FLIP = 1
} rotate_op;

typedef enum {
    NUM_0_TO_ROTATE = 0, 
    NUM_1_TO_ROTATE = 1,
    NUM_2_TO_ROTATE = 2,
    NUM_3_TO_ROTATE = 3,
    NUM_4_TO_ROTATE = 4,
    NUM_5_TO_ROTATE = 5,
    NUM_6_TO_ROTATE = 6,
    NUM_7_TO_ROTATE = 7,
    NUM_8_TO_ROTATE = 8,
    NUM_9_TO_ROTATE = 9,
    NUM_LENGTH = 10
} num_operation;

static void get_rotate_ops(rotate_op *ops) {

    if (!ops)
        return;

    for (int i = 0; i < NUM_LENGTH; i++) {
        if (i == 0 || i == 1 || i == 8) {
            ops[i] = ROTATE_UNCHANGE; 
        } else if (i == 2 || i == 5 || i == 6 || i == 9) {
            ops[i] = ROTATE_FLIP;  
        } else {
            ops[i] = ROTATE_INVALID;  
        }
    }
    return;
}

static rotate_op get_rotate_type(int value, rotate_op *num_ops) {

    int temp = 0;
    rotate_op op = ROTATE_INVALID;

    while (value) {

        temp = value % 10;
        value /= 10;

        if (num_ops[temp] == ROTATE_INVALID) {
            op = num_ops[temp];  
            break;
        }
        op = ROTATE_FLIP == op ? op : num_ops[temp];   
    }

    return op;
    
}    

int rotatedDigits(int n) {

    int count = 0; 
    rotate_op num_ops[NUM_LENGTH] = {ROTATE_INVALID};

    get_rotate_ops(num_ops);

    for (int i = 1; i <= n; i++) {
        if (get_rotate_type(i, num_ops) == ROTATE_FLIP) {
            count++;  
        }
    }

    return count;
}
