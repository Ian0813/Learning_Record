/*
 * =====================================================================================
 *
 *       Filename:  1688 count of matches in tournament.c
 *
 *    Description:  count of matches in tournament
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

#define IS_ODD(val) (((val)%2))
#define GET_MATCH(val) ((IS_ODD(val)) ? ((val)-1)/2 : ((val)/2))
#define GET_ADVANCE(val) ((IS_ODD(val)) ? (((val)-1)/2) + 1 : ((val)/2))

int numberOfMatches(int n){

    int teams = 0, total = 0;

    teams = n;

    while (teams > 1) {
        total += GET_MATCH(teams);
        teams = GET_ADVANCE(teams);
    }

    return total;
}

