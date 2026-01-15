/*
 * =====================================================================================
 *
 *       Filename:  2558_take_gifts_from_the_richest_pile.c
 *
 *    Description:  take gifts from the richest pile
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
#include <math.h>

#define GET_PARENT(pos) (((pos)-1)/2)
#define GET_LEFTCHILD(pos) ((pos*2)+1)
#define GET_RIGHTCHILD(pos) ((pos*2)+2)
#define CHECK_BOUNDARY(left, right, len) ((left) < len || (right) < len)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
    NO_APPEND = 0,
    DO_APPEND = 1
} append_op;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void heap_move_down(int *ptr, int len, int pos) {

    int target = 0, left = 0, right = 0;

    left = GET_LEFTCHILD(pos);
    right = GET_RIGHTCHILD(pos);

    while (CHECK_BOUNDARY(left, right, len)) {

        if (right >= len) {
            target = left;
        } else {
            target = ptr[left] > ptr[right] ? left : right;
        }

        if (ptr[pos] < ptr[target]) {
            swap(&ptr[pos], &ptr[target]);
            pos = target;
            left = GET_LEFTCHILD(pos);
            right = GET_RIGHTCHILD(pos);
            continue;
        }
        break;
    }
    return;
}

static void heap_move_up(int *ptr, int *len, int value, append_op op) {

    int parent = 0, target = 0;

    if (ptr) {

        if (*len) {
            target = *len;
            parent = GET_PARENT(target);

            if (ptr[parent] < value) {
                swap(&ptr[parent], &value);
                heap_move_up(ptr, &parent, MAX(ptr[parent], value), NO_APPEND);
            }
        }

        ptr[target] = value;

        if (op == DO_APPEND)
            *len += 1;
    }
    return;
}

long long pickGifts(int* gifts, int giftsSize, int k) {

    int *ptr = NULL, len = 0;
    long long result = 0LL;

    ptr = (int *) calloc(giftsSize, sizeof(int));

    for (int i = 0; i < giftsSize; i++) {
        heap_move_up(ptr, &len, gifts[i], DO_APPEND);
    }

    while (k) { 
        ptr[0] = (int) floor(sqrt(ptr[0]));
        heap_move_down(ptr, giftsSize, 0);
        k--;
    }

    for (int i = 0; i < giftsSize; i++) {
        result += ptr[i];
    }

    free(ptr);
    return result;
}
