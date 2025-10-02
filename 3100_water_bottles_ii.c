/*
 * =====================================================================================
 *
 *       Filename:  3100 water bottles ii.c
 *
 *    Description:  water bottles ii
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

typedef struct bottle_info {
    int bottles;
    int total;
    int empty;
} bottle_info;

static bool bottle_exchange(bottle_info *obj, int numExchange) {

    bool rc = false;

    if (!obj)
        return rc;

    obj->total += obj->bottles;
    obj->empty += obj->bottles;
    obj->bottles = 0;

    if (obj->empty >= numExchange) {
        obj->empty -= numExchange;
        obj->bottles++;
        rc = true;
    }

    return rc;
}

int maxBottlesDrunk(int numBottles, int numExchange) {

    struct bottle_info bottle_redeem = {.bottles = numBottles};

    for (int i = 0; bottle_exchange(&bottle_redeem, numExchange+i); i++)
        ;

    return bottle_redeem.total;
}
