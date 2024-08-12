/*
 * =====================================================================================
 *
 *       Filename:  2024_08_12_605_can_place_flowers.c
 *
 *    Description:  Can place flowers  
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

typedef enum {false, true} bool;

enum {
    EMPTY = 0,
    PLANTED = 1,
};

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {

    int count = 0;
    bool rc = false;

    if (flowerbedSize > 1) {

        for (int i = 0; i < flowerbedSize; i++) {

            if (!flowerbed[i]) {
                if (!i) {
                    if (!flowerbed[i+1]) {
                        flowerbed[i] = PLANTED;
                        count++; 
                    }
                } else if (i == flowerbedSize-1) {
                    if (!flowerbed[i-1]) {
                        flowerbed[i] = PLANTED;
                        count++;
                    }                
                } else if (i) {
                    if (!flowerbed[i-1] && !flowerbed[i+1]) {
                        count++;    
                        flowerbed[i] = PLANTED;
                    }
                }
            }
        }
    } else {
        if (!flowerbed[0]) {
            count++;
        }
    }
    if (count >= n) {
        rc = true;
    }
    return rc;
}
