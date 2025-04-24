/*
 * =====================================================================================
 *
 *       Filename:  1195_fizz_buzz_multithreaded.c
 *
 *    Description:  fizz buzz multithreaded
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
#include <semaphore.h>

/* 
    You have the four functions:
    
    printFizz that prints the word "fizz" to the console,
    printBuzz that prints the word "buzz" to the console,
    printFizzBuzz that prints the word "fizzbuzz" to the console, and
    printNumber that prints a given integer to the console.
    You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:
    
    Thread A: calls fizz() that should output the word "fizz".
    Thread B: calls buzz() that should output the word "buzz".
    Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
    Thread D: calls number() that should only output the integers.
    Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:
    
    "fizzbuzz" if i is divisible by 3 and 5,
    "fizz" if i is divisible by 3 and not 5,
    "buzz" if i is divisible by 5 and not 3, or
    i if i is not divisible by 3 or 5.
    Implement the FizzBuzz class:
    
    FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
    void fizz(printFizz) Calls printFizz to output "fizz".
    void buzz(printBuzz) Calls printBuzz to output "buzz".
    void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
    void number(printNumber) Calls printnumber to output the numbers.
*/

#define SEMAPHORE_SIZE 4
#define SHARE_THREADS 0
#define SHARE_PROCESSES 1

#define DEVISIBLE_BY_3(value) (!(value%3))
#define DEVISIBLE_BY_5(value) (!(value%5))

typedef enum {
    SEM_NUMBER = 0,
    SEM_BUZZ = 1,
    SEM_FIZZ = 2,
    SEM_FIZZBUZZ = 3,
} sem_type_t;

typedef struct {
    int limitation;
    int sequence_val;
    int is_reached;
    sem_t sem_objs[SEMAPHORE_SIZE];
    void (*dispatcher)(void *, const char *);
} FizzBuzz;

static void dispatcher(void *ptr, const char *func) {

    FizzBuzz *obj = (FizzBuzz *) ptr;

    if (obj && obj->sequence_val < obj->limitation) {
        obj->sequence_val++;
        if (DEVISIBLE_BY_3(obj->sequence_val) && DEVISIBLE_BY_5(obj->sequence_val)) {
            sem_post(&obj->sem_objs[SEM_FIZZBUZZ]);
        } else if (DEVISIBLE_BY_3(obj->sequence_val)) {
            sem_post(&obj->sem_objs[SEM_FIZZ]);
        } else if (DEVISIBLE_BY_5(obj->sequence_val)) {
            sem_post(&obj->sem_objs[SEM_BUZZ]);
        } else {
            sem_post(&obj->sem_objs[SEM_NUMBER]);
        }
    } else {
        obj->is_reached = 1;
        for (int i = SEM_NUMBER; i <= SEM_FIZZBUZZ; i++) {
            sem_post(&obj->sem_objs[i]);    
        }
    }
    return;
}

FizzBuzz* fizzBuzzCreate(int n) {

    int value = 0;

    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));

    memset(obj, 0, sizeof(FizzBuzz));

    obj->limitation = n;
    obj->sequence_val = 1;
    obj->dispatcher = dispatcher;
    obj->is_reached = 0;

    for (int i = SEM_NUMBER; i <= SEM_FIZZBUZZ; i++) {

        value = i == SEM_NUMBER ? 1 : 0;
        if (sem_init(&obj->sem_objs[i], SHARE_THREADS, value))
            perror("sem_init ");
    }
    return obj;
}

// Don't change the following declarations
void printNumber(int a);
void printFizz();
void printBuzz();
void printFizzBuzz();


// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {

    while (obj->sequence_val <= obj->limitation) {
        sem_wait(&obj->sem_objs[SEM_FIZZ]);
        if (obj->is_reached)
            break;
        printFizz();
        obj->dispatcher(obj, __func__);
    }
    return;
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {

    while (obj->sequence_val <= obj->limitation) {
        sem_wait(&obj->sem_objs[SEM_BUZZ]);
        if (obj->is_reached)
            break;
        printBuzz();
        obj->dispatcher(obj, __func__);
    }
    return;
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {

    while (obj->sequence_val <= obj->limitation) {
        sem_wait(&obj->sem_objs[SEM_FIZZBUZZ]);
        if (obj->is_reached)
            break;
        printFizzBuzz();
        obj->dispatcher(obj, __func__);
    }
    return;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {

    while (obj->sequence_val <= obj->limitation) {
        sem_wait(&obj->sem_objs[SEM_NUMBER]);
        if (obj->is_reached)
            break;
        printNumber(obj->sequence_val);
        obj->dispatcher(obj, __func__);
    }
    return;
}

void fizzBuzzFree(FizzBuzz* obj) {

    if (obj) {
        for (int i = SEM_NUMBER; i <= SEM_FIZZBUZZ; i++) {
            sem_post(&obj->sem_objs[i]);
            sem_destroy(&obj->sem_objs[i]);
        }
        free(obj);
    }
    return;
}
