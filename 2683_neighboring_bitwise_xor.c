/*
 * =====================================================================================
 *
 *       Filename:  2683_neighboring_bitwise_xor.c
 *
 *    Description:  neighboring bitwise xor
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

typedef enum {
    INIT_ZERO = 0,
    INIT_ONE = 1
} init_value_t;

static bool guessing(init_value_t first, int *derived, int derivedSize) {

    int *array = (int *) calloc(derivedSize, sizeof(int));    
    bool rc = true;

    array[0] = first;

    for (int i = 1; i < derivedSize; i++) {
        if (derived[i-1]) {
            array[i] = !array[i-1] ? 1 : 0; 
        } else {
            array[i] = array[i-1];
        }
    }

    if (derived[derivedSize-1]) {
        rc = array[0] == array[derivedSize-1] ? false : true;
    } else {
        rc = array[0] != array[derivedSize-1] ? false : true;
    }

    free(array);

    return rc;
}

bool doesValidArrayExist(int* derived, int derivedSize) {

    bool rc = true;

    rc = guessing(INIT_ZERO, derived, derivedSize) ? true : 
         guessing(INIT_ONE, derived, derivedSize);
     
    return rc;
}
