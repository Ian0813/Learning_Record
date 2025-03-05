/*
 * =====================================================================================
 *
 *       Filename:  2579_count_total_number_of_colored_cells.c
 *
 *    Description:  count total number of colored cells
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

static long long calculate(int n) {

    if (n == 1) {
        return 1;
    }
    return (calculate(n-1)+(4*(n-1)));
}

long long coloredCells(int n) {

    return calculate(n); 
}

int main(void) {

    int test = 10;

    for (int i = 1; i <= test; i++) {
        printf("[%d, %lld] ", i, calculate(i));
    }
    putchar('\n');
    return EXIT_SUCCESS;
}
