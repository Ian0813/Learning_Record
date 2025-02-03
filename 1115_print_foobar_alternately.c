/*
 * =====================================================================================
 *
 *       Filename:  1115_print_foobar_alternately.c
 *
 *    Description:  print foobar alternately
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
#include <pthread.h>
#include <semaphore.h>

enum {
    THREAD_SHARED = 0,    
    PROCESS_SHARED = 1
};

typedef struct {
    int n;
    sem_t foo_sem, bar_sem; 
} FooBar;

// Function declarations. Do not change or remove this line
void printFoo();
void printBar();

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->foo_sem, THREAD_SHARED, 1);
    sem_init(&obj->bar_sem, THREAD_SHARED, 0);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        // printFoo() outputs "foo". Do not change or remove this line.
        sem_wait(&obj->foo_sem);
        printFoo();
        sem_post(&obj->bar_sem);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        // printBar() outputs "bar". Do not change or remove this line.
        sem_wait(&obj->bar_sem);    
        printBar();
        sem_post(&obj->foo_sem);    
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&obj->foo_sem);
    sem_destroy(&obj->bar_sem);
    return;
}
