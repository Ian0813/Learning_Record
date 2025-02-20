/*
 * =====================================================================================
 *
 *       Filename:  1710_maximum_units_on_a_truck.c
 *
 *    Description:  maximum units on a truck
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

#define BOX_INDEX 0
#define UNIT_INDEX 1

static void swap(int **a1, int **a2) {

    int *temp = NULL; 

    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
    return;
}

static void quick_sort(int **boxTypes, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (boxTypes[head][UNIT_INDEX] < boxTypes[tail][UNIT_INDEX]) {
                last++;
                swap(&boxTypes[last], &boxTypes[tail]);
                continue;
            }    
            tail--;
        }

        swap(&boxTypes[head], &boxTypes[last]);
        quick_sort(boxTypes, head, last);
        quick_sort(boxTypes, last+1, end);
    }
    return;
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {

    int result = 0;
    int box_counter = truckSize;

    if (boxTypesSize) {

        quick_sort(boxTypes, 0, boxTypesSize);

        for (int i = 0; i < boxTypesSize && truckSize; i++) {

            if (truckSize > boxTypes[i][BOX_INDEX]) {
                result += (boxTypes[i][BOX_INDEX]*boxTypes[i][UNIT_INDEX]); 
                truckSize -= boxTypes[i][BOX_INDEX];
            } else {
                result += (truckSize*boxTypes[i][UNIT_INDEX]); 
                truckSize = 0;
            }
        }
    }
    return result;
}
