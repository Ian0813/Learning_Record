/*
 * =====================================================================================
 *
 *       Filename:  1534_count_good_triplets.c
 *
 *    Description:  count good triplets
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

#define CHECK_CONDITION(v1, v2, boundary) (abs((v1)-(v2)) <= boundary)

enum {
    NO_FOUND = 0, 
    FOUNDED = 1
};

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){

    int count = 0, flag = 0;

    for (int i = 0; i < arrSize-2; i++) {
        for (int j = i+1; j < arrSize-1; j++) {

            flag = CHECK_CONDITION(arr[i], arr[j], a) ? FOUNDED : NO_FOUND;

            for (int k = j+1; k < arrSize; k++) {
                if (flag == FOUNDED) {
                    if (CHECK_CONDITION(arr[j], arr[k], b) && CHECK_CONDITION(arr[i], arr[k], c)) {
                        count++;
                    }    
                }    
            }
        }
    }
    return count;
}
