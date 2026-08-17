/*
 * =====================================================================================
 *
 *       Filename:  677_map_sum_pairs.c
 *
 *    Description:  map sum pairs
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
#include <stdbool.h>

#define LIST_MAX 255
#define MAX_UNIT_COUNT 1024
#define IS_EXTEND(ptr) ((!ptr.llen) ? 0 : (ptr.matched_list[ptr.llen-1]+1))

typedef struct {
    char *key;
    int value;
} key_pair_t;

typedef struct {
    char *str;
    int matched_list[LIST_MAX];
    int llen;
} str_match_t;

typedef struct {
    key_pair_t pairs[MAX_UNIT_COUNT];
    str_match_t matchs[MAX_UNIT_COUNT];
    int pair_size;
    int match_size;
} MapSum;

MapSum* mapSumCreate(void) {

    MapSum *obj = NULL;

    obj = calloc(1, sizeof(*obj));
    return obj;
}

void mapSumInsert(MapSum* obj, char* key, int val) {

    if (!obj)
        return;

    bool flag = false;

    for (int i = 0; i < obj->pair_size; i++) {
        if (!strcmp(obj->pairs[i].key, key)) {
            obj->pairs[i].value = val; 
            flag = true;
            break;
        }
    }

    if (!flag) {
        obj->pairs[obj->pair_size].value = val; 
        obj->pairs[obj->pair_size].key = key; 
        obj->pair_size++;
    }
    return;
}

int mapSumSum(MapSum* obj, char* prefix) {

    if (!obj)
        return -1;

    bool flag = false;
    int len = strlen(prefix), index = 0, sum = 0;

    for (int i = 0; i < obj->match_size; i++) {
        if (!strcmp(obj->matchs[i].str, prefix)) {
            index = i;
            flag = true;
            break;
        }
    }

    if (!flag) {
        obj->matchs[obj->match_size].str = prefix; 
        index = obj->match_size;
        obj->match_size++;
    }

    for (int i = IS_EXTEND((obj->matchs[index])); i < obj->pair_size; i++) {
        if (!strncmp(obj->pairs[i].key, prefix, len)) {
            obj->matchs[index].matched_list[obj->matchs[index].llen++] = i;
        }
    }

    for (int i = 0; i < obj->matchs[index].llen; i++) {
        sum += obj->pairs[obj->matchs[index].matched_list[i]].value;
    }
    return sum;
}

void mapSumFree(MapSum* obj) {

    if (!obj)
        return;

    free(obj);
    return;
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);

 * int param_2 = mapSumSum(obj, prefix);

 * mapSumFree(obj);
*/
