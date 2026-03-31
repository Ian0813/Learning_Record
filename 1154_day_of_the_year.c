/*
 * =====================================================================================
 *
 *       Filename:  1154.c
 *
 *    Description:  day of the year
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

typedef enum {false, true} bool;

#define DECIMAL 10

typedef enum {
    MONTH_JAN = 31,
    MONTH_FEB = 28,
    MONTH_MAR = 31,
    MONTH_ARP = 30,
    MONTH_MAY = 31,
    MONTH_JUN = 30,
    MONTH_JUL = 31,
    MONTH_AUG = 31,
    MONTH_SEP = 30,
    MONTH_OCT = 31,
    MONTH_NOV = 30,
    MONTH_DEC = 31,
    MONTH_SIZE = 12,
} month_t;

static bool is_leapyear(unsigned int year) {

    if (!(year%4) && ((year%100) || !(year%400))) {
        return true;
    }

    return false;
}

int dayOfYear(char* date) {

    int year = 0, month = 0, day = 0, result = 0;
    char *yptr = NULL, *mptr = NULL, *dptr = NULL;
    month_t months[MONTH_SIZE] = {MONTH_JAN, MONTH_FEB, MONTH_MAR, MONTH_ARP, MONTH_MAY, MONTH_JUN, MONTH_JUL, MONTH_AUG, MONTH_SEP, MONTH_OCT, MONTH_NOV, MONTH_DEC};

    if (date) {

        yptr = strtok_r(date, "-", &mptr);
        mptr = strtok_r(mptr, "-", &dptr);

        year = (int) strtol(yptr, NULL, DECIMAL); 
        month = (int) strtol(mptr, NULL, DECIMAL); 
        day = (int) strtol(dptr, NULL, DECIMAL);

        for (int i = 0; i < (month-1); i++) {

            if (i == 1 && is_leapyear(year)) {
                result += (months[i]+1);
                continue;
            }
            result += months[i];
        }

        result += day;

        printf("year : %d, month : %d, day : %d\n", year, month, day);
    }

    return result;
}

