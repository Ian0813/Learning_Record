/*
 * =====================================================================================
 *
 *       Filename:  1116_print_zero_even_odd.c
 *
 *    Description:  print zero even odd
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
#include <time.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

#define S_THREAD 0
#define S_PROCESS 1

void printNumber(int x);

typedef struct {
    int n;
    int cur_value;
    int exit;
    sem_t s_zero;
    sem_t s_odd;
    sem_t s_even;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    obj->cur_value = 0;
    obj->exit = 0; 
    sem_init(&obj->s_zero, S_THREAD, 1);
    sem_init(&obj->s_odd, S_THREAD, 0);
    sem_init(&obj->s_even, S_THREAD, 0);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    do {
        if (!sem_wait(&obj->s_zero)) {
            printNumber(0);
            obj->cur_value++;

            if (obj->cur_value%2) {
                sem_post(&obj->s_odd);
            } else {
                sem_post(&obj->s_even);
            }
        }
    } while (obj->cur_value < obj->n);

    sem_wait(&obj->s_zero);
    obj->exit = 1;

    if (obj->cur_value%2) {
        sem_post(&obj->s_even);
    } else {
        sem_post(&obj->s_odd);
    }
    return;
}

void even(ZeroEvenOdd* obj) {

    do {
        if (!sem_wait(&obj->s_even) && !obj->exit) {
            printNumber(obj->cur_value); 
            sem_post(&obj->s_zero);
        }
    } while (obj->cur_value < obj->n);
    return;
}

void odd(ZeroEvenOdd* obj) {

    do {
        if (!sem_wait(&obj->s_odd) && !obj->exit) {
            printNumber(obj->cur_value); 
            sem_post(&obj->s_zero);
        }
    } while (obj->cur_value < obj->n);
    return;
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {

    if (obj) {
        sem_close(&obj->s_zero);
        sem_close(&obj->s_odd);
        sem_close(&obj->s_even);
        free(obj);
    }
    return;
}
