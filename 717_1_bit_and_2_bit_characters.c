/*
 * =====================================================================================
 *
 *       Filename:  717_1_bit_and_2_bit_characters.c
 *
 *    Description:  1 bit and 2 bit characters
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

enum {
    PAIR_TOKEN = -1,
};

static bool is_pair(int b1, int b2) {
    return ((b1 == 1 && b2 == 1) || (b1 == 1 && !b2));
}

bool isOneBitCharacter(int* bits, int bitsSize) {

    bool rc = true;

    if (bitsSize != 1) {

        for (int i = 0; i < bitsSize-1;) {
            if (is_pair(bits[i], bits[i+1])) {
                bits[i+1] = bits[i] = PAIR_TOKEN; 
                i += 2;
            } else {
                i++;
            }
        }
        rc = ((bits[bitsSize-2] == PAIR_TOKEN || !bits[bitsSize-2]) && !bits[bitsSize-1]) ? true : false;
    }

    return rc;
}
