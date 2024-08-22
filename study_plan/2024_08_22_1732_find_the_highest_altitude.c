/*
 * =====================================================================================
 *
 *       Filename:  2024_08_22_1732_find_the_highest_altitude.c
 *
 *    Description:  Find the highest altitude   
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

int largestAltitude(int* gain, int gainSize) {

    int *net_gains = (int *) calloc(gainSize+1, sizeof(int));
    int highest = 0;

    for (int i = 0, index = 1; i < gainSize; i++, index++) {
        net_gains[index] = net_gains[index-1] + gain[i];    
        if (net_gains[index] > highest) {
            highest = net_gains[index];  
        }
    }
    free(net_gains);
    return highest;
}
