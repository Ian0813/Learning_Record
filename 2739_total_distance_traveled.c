/*
 * =====================================================================================
 *
 *       Filename:  2739_total_distance_traveled.c
 *
 *    Description:  Total distance traveled  
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

#define UNIT_MILES (10)
#define SATISFY_COND (5)

int distanceTraveled(int mainTank, int additionalTank){

    int accumulation = 0;
    int total_distance = 0; 

    while (mainTank) {

        total_distance += UNIT_MILES;
        accumulation++;
        mainTank--;

        if (accumulation == SATISFY_COND) {
            if (additionalTank) {
                additionalTank--;
                mainTank++;
            }
            accumulation = 0;
        }
    }
    return total_distance;
}

int main(void) {

    printf("%d\n", distanceTraveled(9, 2));
    return EXIT_SUCCESS;
}
