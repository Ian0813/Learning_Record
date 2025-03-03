/*
 * =====================================================================================
 *
 *       Filename:  2079_watering_plants.c
 *
 *    Description:  watering plants
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

int wateringPlants(int* plants, int plantsSize, int capacity) {

    int steps = 0, waters = capacity, record = 0;

    for (int i = 0; i < plantsSize; i++) {

        if (waters >= plants[i]) {
            waters -= plants[i];  
        } else {
            steps += (record*2); 
            waters = capacity-plants[i]; 
        }
        steps += 1;
        record += 1;
    }
    return steps;
}
