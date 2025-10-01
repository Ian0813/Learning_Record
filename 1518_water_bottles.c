/*
 * =====================================================================================
 *
 *       Filename:  1518 water bottles.c
 *
 *    Description:  water bottles
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
    int empty;
    int total;
} bottle_info;

static bool bottle_exchange(bottle_info *binfo, int redeem_cond) {

    bool rc = false;

    if (!binfo)
        return rc;

    binfo->total += binfo->bottles;
    binfo->empty += binfo->bottles;
    binfo->bottles = 0;

    if (binfo->empty >= redeem_cond) {
        binfo->bottles = (binfo->empty/redeem_cond);
        binfo->empty = binfo->empty % redeem_cond;
        rc = true;
    }

    return rc;
}

int numWaterBottles(int numBottles, int numExchange) {

    bottle_info binfo = {0};

    binfo.bottles = numBottles;

    while (bottle_exchange(&binfo, numExchange))
        ;

    return binfo.total;
}
