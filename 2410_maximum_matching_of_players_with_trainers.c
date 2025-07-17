/*
 * =====================================================================================
 *
 *       Filename:  2410_maximum_matching_of_players_with_trainers.c
 *
 *    Description:  maximum matching of players with trainers
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
#include <stdint.h>

enum {
    IS_EMPTY = 0,
    IS_USED = 1
};

enum {
    COND_KEEP = 0,
    COND_BREAK = 1
};

static void merge_operation(int *arr, int head, int middle, int end) {

    int a1Size = (middle-head)+1, a2Size = (end-middle);
    int arr1[a1Size], arr2[a2Size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        arr1[i] = arr[i+head];
    }

    for (int i = a2_index; i < a2Size; i++) {
        arr2[i] = arr[i+middle+1];
    }

    while (a1_index < a1Size && a2_index < a2Size) {

        if (arr1[a1_index] < arr2[a2_index]) {
            arr[index++] = arr1[a1_index++];
        } else {
            arr[index++] = arr2[a2_index++];
        }    
    }

    while (a1_index < a1Size) {
        arr[index++] = arr1[a1_index++];
    }

    while (a2_index < a2Size) {
        arr[index++] = arr2[a2_index++];
    }
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);    
        merge_sort(arr, middle+1, end);    
        merge_operation(arr, head, middle, end);
    }
    return;
}

static int get_maxmatched(int *players, int playersSize, int *trainers, int trainersSize) {

    int count = 0, break_cond = COND_KEEP, track = 0;
    int check_uses[trainersSize];

    memset(check_uses, IS_EMPTY, sizeof(int) * trainersSize);

    for (int i = 0; i < playersSize; i++) {

        for (int j = track; j < trainersSize; j++) {
            if (players[i] > trainers[trainersSize-1]) {
                break_cond = COND_BREAK;
                break;
            }

            if (players[i] <= trainers[j] && check_uses[j] == IS_EMPTY) {
                count++;
                check_uses[j] = IS_USED;
                track = j + 1;
                break;
            }
        }

        if (break_cond == COND_BREAK)
            break; 
    }

    return count;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {

    int maximum_matched = 0;

    merge_sort(players, 0, playersSize-1);
    merge_sort(trainers, 0, trainersSize-1);

    maximum_matched = get_maxmatched(players, playersSize, trainers, trainersSize);

    return maximum_matched;

}
