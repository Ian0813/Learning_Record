/*
 * =====================================================================================
 *
 *       Filename:  3477_fruits_into_baskets_ii.c
 *
 *    Description:  fruits into baskets ii
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

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {

    int count = 0; 

    for (int i = 0; i < fruitsSize; i++) {
        for (int j = 0; j < basketsSize; j++) {
            if (fruits[i] <= baskets[j]) {
                count++;
                baskets[j] = 0;
                break;
            }
        }
    }

    return fruitsSize - count;
}
