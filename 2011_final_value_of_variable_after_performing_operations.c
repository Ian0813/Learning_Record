/*
 * =====================================================================================
 *
 *       Filename:  2011_final_value_of_variable_after_performing_operations.c
 *
 *    Description:  final value of variable after performing operations
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

int finalValueAfterOperations(char** operations, int operationsSize) {

    int value = 0;

    for (int i = 0; i < operationsSize; i++) {
        value = (operations[i][0] == '+' || operations[i][2] == '+') ? (value + 1) : value;
        value = (operations[i][0] == '-' || operations[i][2] == '-') ? (value - 1) : value;
    }

    return value;
}
