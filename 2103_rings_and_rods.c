/*
 * =====================================================================================
 *
 *       Filename:  2103_rings_and_rods.c
 *
 *    Description:  Rings and robs  
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

#define MAX_ROBNUM 10
#define MAX_COLORS 3

enum {
    RED,
    GREEN,
    BLUE,
}; 

int countPoints(char* rings) {

    int combo[MAX_COLORS][MAX_ROBNUM] = {0};
    int counter = 0, num = 0;

    for (int i = 0; i < strlen(rings); i++) {

        switch (rings[i]) {

            case 'R': {
                num = rings[++i] - '0';    
                combo[RED][num] = 1;
            }
            break;
            case 'G': {
                num = rings[++i] - '0';    
                combo[GREEN][num] = 1;
            }
            break;
            case 'B': {
                num = rings[++i] - '0';    
                combo[BLUE][num] = 1;
            }
            break;
        }
    }

    for (int i = 0; i < MAX_ROBNUM; i++) {
        counter = (combo[RED][i] && combo[GREEN][i] && combo[BLUE][i]) ? counter + 1 : counter;
    }
    return counter;
}
