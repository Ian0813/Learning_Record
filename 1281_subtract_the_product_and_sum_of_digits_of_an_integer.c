/*
 * =====================================================================================
 *
 *       Filename:  1281 subtract the product and sum of digits of an integer.c
 *
 *    Description:  subtract the product and sum of digits of an integer
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

typedef enum {
    OP_MULTIPLY = 0,
    OP_ADDITIVE = 1
} operation_type;

static int digit_operation(int value, operation_type op) {

    int digit = 0, rc = 0;

    digit = value % 10;
    value /= 10;

    switch (op) {
        case OP_MULTIPLY:
           if (!value)
               rc = !digit ? 1 : digit;
           else
               rc = 1;
        break;
        case OP_ADDITIVE:
           rc = digit;
        break;
        default:
            ;
    }

    if (!digit && !value)
        return rc;

    return op == OP_MULTIPLY ? (digit * digit_operation(value, op)) : (digit + digit_operation(value, op));
}

int subtractProductAndSum(int n) {

    int digit_sum = 0, digit_product = 0;

    digit_sum = digit_operation(n, OP_ADDITIVE);
    digit_product = digit_operation(n, OP_MULTIPLY);

    return digit_product - digit_sum;
}
