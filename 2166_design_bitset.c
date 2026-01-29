/*
 * =====================================================================================
 *
 *       Filename:  2166_design_bitset.c
 *
 *    Description:  design bitset
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define IDX_TO_INDEX(idx) ((idx/8))

typedef enum {
    COUNT_ZERO = 0,
    COUNT_ONE = 1,
    COUNT_LEN = 2
} count_t;

typedef struct {
    char *bitmap;
    int mapsize;
    int bitslen;
    char *bitstr;
    count_t counter[COUNT_LEN];
} Bitset;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void bitsdisplay(Bitset *obj) {

    int temp = 0;

    if (!obj)
        return;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        for (int j = 0; j < CHAR_BIT; j++) {
            printf("%d ", (obj->bitmap[i] & (1 << j)) ? 1 : 0);
        }
    }

    temp = !(obj->bitslen % 8) ? CHAR_BIT : (obj->bitslen % 8);

    for (int i = 0; i < temp; i++) {
        printf("%d ", (obj->bitmap[obj->mapsize-1] & (1 << i)) ? 1 : 0);
    }

    putchar('\n');

    return;
}

Bitset* bitsetCreate(int size) {

    Bitset *obj = NULL;

    obj = (Bitset *) malloc(sizeof(*obj));

    if (!obj)
        return obj;

    obj->bitslen = size;
    obj->mapsize = (size/8) + 1;
    obj->bitmap = (char *) calloc(obj->mapsize, sizeof(char));

    if (!obj->bitmap) {
        free(obj);
        return NULL;
    }

    obj->bitstr = (char *) calloc(size+1, sizeof(char));
    obj->counter[COUNT_ZERO] = size;
    obj->counter[COUNT_ONE] = 0;

    if (!obj->bitstr) {
        free(obj->bitmap);
        free(obj);
        obj = NULL;
    }

    return obj;
}

void bitsetFix(Bitset* obj, int idx) {

    int pos = 0;

    if (!obj)
        return;

    pos = (idx % CHAR_BIT);

    if (obj->bitmap[IDX_TO_INDEX(idx)] & (1 << pos))
        return;

    obj->bitmap[IDX_TO_INDEX(idx)] |= (1 << pos);
    obj->counter[COUNT_ONE]++;
    obj->counter[COUNT_ZERO]--;

    return;
}

void bitsetUnfix(Bitset* obj, int idx) {

    int pos = 0;
    bool rc = true;

    if (!obj)
        return;

    pos = (idx % 8);

    if (obj->bitmap[IDX_TO_INDEX(idx)] & (1 << pos)) {
        obj->counter[COUNT_ONE]--;
        obj->counter[COUNT_ZERO]++;
    }

    obj->bitmap[IDX_TO_INDEX(idx)] &= (~(1 << pos));

    return;
}

void bitsetFlip(Bitset* obj) {

    int temp = 0;

    if (!obj)
        return;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        obj->bitmap[i] = ~obj->bitmap[i];
    }

    if (!(obj->bitslen % CHAR_BIT)) {
        obj->bitmap[obj->mapsize-1] = ~obj->bitmap[obj->mapsize-1];
    } else {
        temp = obj->bitslen % CHAR_BIT;

        for (int i = temp; i >= 0; i--) {
            obj->bitmap[obj->mapsize-1] ^= (1 << i);
        }
    }

    swap((int *) &obj->counter[COUNT_ZERO], (int *) &obj->counter[COUNT_ONE]);
    return;
}

bool bitsetAll(Bitset* obj) {

    return obj ? (obj->counter[COUNT_ONE] == obj->bitslen ? 1 : 0) : 0;

    int temp = 0;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        for (int j = 0; j < CHAR_BIT; j++) {
            if (!(obj->bitmap[i] & (1 << j))) {
                 return false;
            }
        }
    }

    temp = (obj->bitslen % 8);
    for (int j = 0; j < temp; j++) {
        if (!(obj->bitmap[obj->mapsize-1] & (1 << j))) {
             return false;
        }
    }

    return true;
}

bool bitsetOne(Bitset* obj) {

    return obj ? (obj->counter[COUNT_ONE] > 0 ? 1 : 0) : 0;
    int temp = 0;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        for (int j = 0; j < CHAR_BIT; j++) {
            if ((obj->bitmap[i] & (1 << j))) {
                 return true;
            }
        }
    }

    temp = (obj->bitslen % 8);
    for (int j = 0; j < temp; j++) {
        if ((obj->bitmap[obj->mapsize-1] & (1 << j))) {
             return true;
        }
    }

    return false;
}

int bitsetCount(Bitset* obj) {

    return obj->counter[COUNT_ONE];

    int temp = 0, count = 0;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        for (int j = 0; j < CHAR_BIT; j++) {
            if ((obj->bitmap[i] & (1 << j))) {
                 count++;
            }
        }
    }

    temp = (obj->bitslen % 8);

    for (int j = 0; j < temp; j++) {
        if ((obj->bitmap[obj->mapsize-1] & (1 << j))) {
            count++;
        }
    }

    return count;
}

char* bitsetToString(Bitset* obj) {

    int temp = 0, index = 0;

    for (int i = 0; i < obj->mapsize - 1; i++) {
        for (int j = 0; j < CHAR_BIT; j++) {
            if ((obj->bitmap[i] & (1 << j))) {
                obj->bitstr[index++] = '1';
            } else {
                obj->bitstr[index++] = '0';
            }
        }
    }

    temp = (obj->bitslen % 8);

    for (int j = 0; j < temp; j++) {
        if ((obj->bitmap[obj->mapsize-1] & (1 << j))) {
            obj->bitstr[index++] = '1';
        }  else {
            obj->bitstr[index++] = '0';
        }
    }

    return obj->bitstr;
}

void bitsetFree(Bitset* obj) {

    if (obj) {
        free(obj->bitmap);
        free(obj->bitstr);
    }
    return;
}

/**
 * Your Bitset struct will be instantiated and called as such:
 * Bitset* obj = bitsetCreate(size);
 * bitsetFix(obj, idx);

 * bitsetUnfix(obj, idx);

 * bitsetFlip(obj);

 * bool param_4 = bitsetAll(obj);

 * bool param_5 = bitsetOne(obj);

 * int param_6 = bitsetCount(obj);

 * char* param_7 = bitsetToString(obj);

 * bitsetFree(obj);
*/
