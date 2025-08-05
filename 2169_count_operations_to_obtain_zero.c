/*
 * =====================================================================================
 *
 *       Filename:  2169_count_operations_to_obtain_zero.c
 *
 *    Description:  count operations to obtain zero
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

#define GET_MAXVALUE(val1, val2) ((val1) > (val2) ? (val1) : (val2))
#define GET_MINVALUE(val1, val2) ((val1) <= (val2) ? (val1) : (val2))

static int obtain_zero(int v1, int v2) {

    int count = 0, t1 = 0, t2 = 0, temp = 0;

    if (!v1 || !v2)
        goto EXIT_POINT;

    if (v1 > v2) {
        temp = v1 - v2;
        t1 = GET_MAXVALUE(temp, v2);
        t2 = GET_MINVALUE(temp, v2);
    } else {
        temp = v2 - v1;
        t1 = GET_MAXVALUE(temp, v1);
        t2 = GET_MINVALUE(temp, v1);
    }

    count++;

    if (!t1 || !t2) {
        return count;
    } else {
        count += obtain_zero(t1, t2);
    }

EXIT_POINT:;
    return count;
}

int countOperations(int num1, int num2) {

    int count = 0;

    count = obtain_zero(num1, num2);

    return count;
}
