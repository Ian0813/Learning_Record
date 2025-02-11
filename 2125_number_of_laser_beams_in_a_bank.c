/*
 * =====================================================================================
 *
 *       Filename:  2125_number_of_laser_beams_in_a_bank.c
 *
 *    Description:  number of laser beams in a bank
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

#define IS_DEVICE(dev) (dev) == '1' ? 1 : 0

static void count_device(int *counter, char **bank, int bankSize, int *index) {

    int amount = 0;

    for (int i = 0; i < bankSize; i++, amount = 0) {
        for (int j = 0; j < strlen(bank[i]); j++) {
            amount += IS_DEVICE(bank[i][j]);
        }
        if (amount)
            counter[(*index)++] = amount;
    }
    return;
}

int numberOfBeams(char** bank, int bankSize) {

    int *counter = NULL;
    int result = 0, index = 0;

    if (bank) {

        counter = (int *) calloc(bankSize, sizeof(int));
        count_device(counter, bank, bankSize, &index);

        for (int i = 0; i < index-1; i++) {
            result += (counter[i]*counter[i+1]);
        }
    }
    return result;
}
