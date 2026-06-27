/*
 * =====================================================================================
 *
 *       Filename:  2682_find_the_losers_of_the_circular_game.c
 *
 *    Description:  find the losers of the circular game
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXIMUM_VISIT_TIMES 2

typedef struct {
    int *players;
    int *non_visit;
    int jump_distance;
    int player_size;
    int non_visit_len;
} player_group;

static bool game_init(player_group *p, int player_amount, int step_unit) {

    if (!player_amount || !step_unit || !p)
        return false;

    memset(p, 0, sizeof(*p));

    p->players = calloc(player_amount, sizeof(int)); 
    p->player_size = player_amount; 
    p->non_visit = calloc(player_amount, sizeof(int)); 
    p->jump_distance = step_unit;

    return true;
}

static bool game_process(player_group *p) {

    int index = 0, unit = 0, last_index = 0;

    if (!p)
        return false;

    unit = p->jump_distance;

    while (p->players[last_index] != MAXIMUM_VISIT_TIMES) {
        p->players[index]++;
        last_index = index;
        index = (index + p->jump_distance) % p->player_size;
        p->jump_distance += unit;
    }

    for (int i = 0; i < p->player_size; i++) {
        if (!p->players[i]) {
            p->non_visit[p->non_visit_len++] = i+1;    
        }
    }
    return true;
}

int* circularGameLosers(int n, int k, int* returnSize) {

    player_group attendee = {0};
    *returnSize = 0;

    if (!game_init(&attendee, n, k)) {
        return NULL;
    }

    if (!game_process(&attendee)) {
        return NULL;
    }

    free(attendee.players);
    *returnSize = attendee.non_visit_len;

    return attendee.non_visit;
}
