/*
 * =====================================================================================
 *
 *       Filename:  1184_distance_between_bus_stops.c
 *
 *    Description:  distance between bus stops
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

#define MIN(a, b) ((a) < (b) ? (a) : (b)) 
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

static int forward_distance(int *distance, int distanceSize, int p1, int p2) {

    int count = 0, start = 0, destination = 0;

    start = MIN(p1, p2);
    destination = MAX(p1, p2);

    for (int i = start; i < destination; i = (i+1) % distanceSize) {
        count += distance[i];
    }
    return count;
}    

static int backward_distance(int *distance, int distanceSize, int p1, int p2) {

    int count = 0, start = 0, destination = 0;

    start = MIN(p1, p2);
    destination = MAX(p1, p2);

    for (int i = destination; i != start; i = (i+1) % distanceSize) {
        count += distance[i];     
    }

    return count;
}    

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){

    int forward = 0, backward = 0;    

    forward = forward_distance(distance, distanceSize, start, destination);
    backward = backward_distance(distance, distanceSize, start, destination);

    return MIN(forward, backward); 
}
