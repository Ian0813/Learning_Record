/*
 * =====================================================================================
 *
 *       Filename:  2391_minimum_amount_of_time_to_collect_garbage.c
 *
 *    Description:  minimum amount of time to collect garbage
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

#define GARBAGE_TOTAL 3

typedef enum {
    PAPER = 'P',
    GLASS = 'G',
    METAL = 'M'
} garbage_type_t;

enum GARBAGE_INDEX {
    PAPER_INDEX = 0,
    GLASS_INDEX = 1,
    METAL_INDEX = 2,
};

struct garbage_collect {
    char garr[GARBAGE_TOTAL];
    int travel_time;
    int process_time;
    int total_time[GARBAGE_TOTAL]; 
};

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {

    struct garbage_collect ginfo = {.garr = {PAPER, GLASS, METAL}};

    for (int i = 0; i < GARBAGE_TOTAL; i++) {
        for (int j = 0; j < garbageSize; j++) {
            ginfo.travel_time = !ginfo.process_time ? ginfo.travel_time : 0;
            ginfo.process_time = 0;
            for (int k = 0; k < strlen(garbage[j]); k++) {
                ginfo.process_time += (garbage[j][k] == ginfo.garr[i] ? 1 : 0);
            }
            ginfo.travel_time += (j ? travel[j-1] : 0);
            ginfo.total_time[i] += (ginfo.process_time ? (ginfo.process_time+ginfo.travel_time) : 0); 
        }
        ginfo.travel_time = 0;
    }
    return ginfo.total_time[PAPER_INDEX] + ginfo.total_time[GLASS_INDEX] + ginfo.total_time[METAL_INDEX];
}
