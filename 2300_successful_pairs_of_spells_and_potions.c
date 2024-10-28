/*
 * =====================================================================================
 *
 *       Filename:  2300_successful_pairs_of_spells_and_potions.c
 *
 *    Description:  successful pairs of spells and potions
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TABLE_SIZE 100001

static void merge_process(int *arr, int head, int middle, int end) {

    int farr_size = (middle-head)+1, tarr_size = (end-middle);
    int farr[farr_size], tarr[tarr_size];
    int farr_index = 0, tarr_index = 0, arr_index = head;

    for (farr_index; farr_index < farr_size; farr_index++) {
        farr[farr_index] = arr[head+farr_index];
    }

    for (tarr_index; tarr_index < tarr_size; tarr_index++) {
        tarr[tarr_index] = arr[middle+tarr_index+1];
    }

    farr_index = tarr_index = 0;

    while (farr_index < farr_size && tarr_index < tarr_size) {
        if (farr[farr_index] > tarr[tarr_index]) {
            arr[arr_index++] = tarr[tarr_index++];
        } else {
            arr[arr_index++] = farr[farr_index++];
        }
    }

    while (farr_index < farr_size)
        arr[arr_index++] = farr[farr_index++];

    while (tarr_index < tarr_size)
        arr[arr_index++] = tarr[tarr_index++];
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_process(arr, head, middle, end);
    }
    return;
}

static int find_least_index(int power_factor, int *potions, int head, int end) {

    int index = -1;
    int middle = (head+end)/2;

    if (head < end) {
        if (potions[middle] > power_factor) {
            index = find_least_index(power_factor, potions, head, middle);
        } else if (potions[middle] < power_factor) {
            index = find_least_index(power_factor, potions, middle+1, end);
        } else {
            for (middle; middle >= 0 && potions[middle] == power_factor; middle--)
                ;
            index = middle+1;
        }
    } else {
        index = middle;
    }
    return index;
}

int find_max_spells(int *spells, int spellsSize, int success) {

    int max = 0;
    int factor = 0;

    for (int i = 0; i < spellsSize; i++) {
        if (max < (factor = success/spells[i]))
            max = spells[i];
    }
    return max;
}


int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {

    int *result = 0;
    int least_index = 0, rindex = 0, rsize = 0;
    int power_factor_table[TABLE_SIZE] = {0};
    long long power_factor = 0;
    int max = 0;

    if (spellsSize && potionsSize) {

        rsize = potionsSize > spellsSize ? potionsSize : spellsSize;
        result = (int *) calloc(rsize, sizeof(int));

        merge_sort(potions, 0, potionsSize-1);

        for (int i = 0; i < spellsSize; i++) {

            power_factor = success/spells[i];;

            if (success%spells[i])
                power_factor++;

            if (power_factor_table[spells[i]] != 0) {
                result[rindex++] = power_factor_table[spells[i]];
            } else {
                if (!power_factor) {
                    result[rindex] = potionsSize;
                } else {
                    least_index = find_least_index(power_factor, potions, 0, potionsSize-1);

                    if (power_factor <= potions[least_index])
                        result[rindex] = (potionsSize-least_index);
                    else
                        result[rindex] = 0;
                }
                power_factor_table[spells[i]] = result[rindex];
                rindex++;
            }
        }
    }
    *returnSize = rindex;
    return result;
}

int main(void) {

    int spells[] = {38,14,1,11,33,38,21,11,25,14,27,29,40,11,10,40,14,16,25,35,33,11,30,31,7,36,11,1,39,5,11,8,22,20,29,31,27,8,38,32,28,32,22,19,26,24,20,25,5,34,24,18}, potions[] = {33,14,15,32,26,37,35,32,30,28,24,29,13,22,39,9,26}, success = 39;
    int size = 0;
    int *ptr = NULL;

    ptr = successfulPairs(spells, sizeof(spells)/sizeof(*spells), potions, sizeof(potions)/sizeof(*potions), (long long) success, &size);
    putchar('\n');

    for (int i = 0; i < sizeof(potions)/sizeof(*potions); i++)
        printf("%d ", potions[i]);
    putchar('\n');

    for (int i = 0; i < size; i++) {
        printf("%d(%d) ", ptr[i], spells[i]);
    }
    putchar('\n');
    free(ptr);
    return EXIT_SUCCESS;
}

