/*
 * =====================================================================================
 *
 *       Filename:  3184_count_pairs_that_form_a_complete_day_i.c
 *
 *    Description:  count pairs that form a complete day i
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

#define CHECK_COMPLETE_DAY(time1, time2) (!((time1+time2)%24))

int countCompleteDayPairs(int* hours, int hoursSize) {

    int count = 0;

    for (int i = 0; i < hoursSize-1; i++) {
        for (int j = i+1; j < hoursSize; j++) {
            if (CHECK_COMPLETE_DAY(hours[i], hours[j]))
                count++;
        }
    }
    return count;
}
