/*
 * =====================================================================================
 *
 *       Filename:  1689_partitioning_into_minimum_number_of_deci_binary_numbers.c
 *
 *    Description:  partitioning into minimum number of deci binary numbers.c
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

#define ENTER_LOOP (1U)
#define OUT_LOOP (0U)
#define CH_ZERO '0'

int minPartitions(char* n) {

    int length = strlen(n);
    int flag = ENTER_LOOP;
    int counter = 0;
    char max_ch = CH_ZERO;

    for (int i = 0; i < length; i++) {
        max_ch = n[i] > max_ch ? n[i] : max_ch;
    }

    counter = max_ch - CH_ZERO;
    return counter;
}

int main(void) {

    char test[] = "27346209830709182346";

    printf("count times: %d\n", minPartitions(test));

    return EXIT_SUCCESS;
}
