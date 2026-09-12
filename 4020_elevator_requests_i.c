/*
 * =====================================================================================
 *
 *       Filename:  4020_elevator_requests_i.c
 *
 *    Description:  elevator requests i
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
#include <math.h>

int elevatorRequests(int n, int* requests, int requestsSize) {

    int count = 0, start = 0;

    for (int i = 0; i < requestsSize; i++) {
        count += abs(start-requests[i]);
        start = requests[i];
    }
    return count;
}
