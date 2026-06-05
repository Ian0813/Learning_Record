/*
 * =====================================================================================
 *
 *       Filename:  3633_earliest_finish_time_for_land_and_water_rides_i.c
 *
 *    Description:  earliest finish time for land and water rides i
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
#include <limits.h>

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {

    int value1 = 0, value2 = 0, total = 0, result = INT_MAX, t1 = 0, t2 = 0;

    for (int i = 0; i < landStartTimeSize; i++) {

        value1 = landStartTime[i] + landDuration[i];

        for (int j = 0; j < waterStartTimeSize; j++) {

            value2 = waterStartTime[j] + waterDuration[j];

            if (value1 <= waterStartTime[j]) {
                total = value2;
            } else {

                if (value2 <= landStartTime[i]) {
                    total = value1;
                } else {
                    t1 = value2 + landDuration[i];
                    t2 = value1 + waterDuration[j];
                    total = t1 > t2 ? t2 : t1;
                }
            }
            result = result < total ? result : total;
        }
    }
    return result;
}
