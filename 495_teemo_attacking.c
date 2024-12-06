/*
 * =====================================================================================
 *
 *       Filename:  495_teemo_attacking.c
 *
 *    Description:  teemo attacking  
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

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {

    int poison_sec = duration;
    int overlap = 0;
    int previous_end = 0;

    for (int i = 1; i < timeSeriesSize; i++) {

        previous_end = ((timeSeries[i-1]+duration)-1);

        if (previous_end >= timeSeries[i]) {
            overlap = (previous_end - timeSeries[i]) + 1;
        }
        poison_sec += duration - overlap; 
        overlap = 0;
    }
    return poison_sec;
}
