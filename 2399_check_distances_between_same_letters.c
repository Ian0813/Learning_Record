/*
 * =====================================================================================
 *
 *       Filename:  2399_check_distances_between_same_letters.c
 *
 *    Description:  Check distances between same letters  
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
#define ALPHABET_SIZE 26

bool checkDistances(char* s, int* distance, int distanceSize) {

    int alphabet[ALPHABET_SIZE] = {0}; 
    bool mark[ALPHABET_SIZE] = {0};
    bool rc = true;

    for (int i = 0; i < strlen(s); i++) {
        if (alphabet[s[i]-97] == 0 && !mark[s[i]-97]) {
            mark[s[i]-97] = 1;
            alphabet[s[i]-97] = i;
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        if (i != alphabet[s[i]-97]) {
            if ((i-alphabet[s[i]-97]-1) != distance[s[i]-97]) {
                rc = false; 
                break;
            }
        }
    }
    return rc;
}
