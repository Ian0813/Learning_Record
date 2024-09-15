/*
 * =====================================================================================
 *
 *       Filename:  2379_minimum_recolors_to_get_k_consecutive_black_blocks.c
 *
 *    Description:  minimum recolors to get k consecutive black blocks
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define WHITE 'W' 

int minimumRecolors(char* blocks, int k) {

    int min_change = INT_MAX;
    int w_counter = 0;

    for (int i = 0; i < strlen(blocks)-(k-1); i++) {

        for (int j = i; j < (i+k); j++) {
            if (blocks[j] == WHITE) {
                w_counter++;
            }    
        }

        if (w_counter < min_change) {
            min_change = w_counter;
        }
        w_counter = 0;
    }

    return min_change;
}

int main(void) {

    char blocks[] = "WBBWWBBWBW";
    int k = 7;

    printf("%d\n", minimumRecolors(blocks, 7));

    return EXIT_SUCCESS;
}
