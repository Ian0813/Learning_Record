/*
 * =====================================================================================
 *
 *       Filename:  1117_building_h2o.c
 *
 *    Description:  building h2o
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
#include <pthread.h>

typedef enum {
    SEM_THREAD = 0,
    SEM_PROCESS = 1
} sem_scope_t;

typedef enum {
    H2O_INIT = 0,
    H2O_FORM = 2
} h2o_action_t;

typedef enum {
    MUTEX_NONLOCK = 0,
    MUTEX_LOCKED = 1
} mutex_state_t;

struct tracked_mutex {
    pthread_mutex_t lock;
    mutex_state_t state;
};

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mutex;
    sem_t hsem, osem;
    h2o_action_t oxygen_flag;
} H2O;

void releaseHydrogen();

void releaseOxygen();

H2O* h2oCreate() {

    H2O* obj = (H2O*) malloc(sizeof(H2O));

    // Initialize user defined data here.

    sem_init(&obj->hsem, SEM_THREAD, 0);
    sem_init(&obj->osem, SEM_THREAD, 0);
    pthread_mutex_init(&obj->mutex, NULL);
    obj->oxygen_flag = H2O_INIT;

    return obj;
}

void hydrogen(H2O* obj) {

    // releaseHydrogen() outputs "H". Do not change or remove this line.

    if (!pthread_mutex_lock(&obj->mutex)) {
        obj->oxygen_flag++;
        if (obj->oxygen_flag == H2O_FORM) {
            sem_post(&obj->hsem);
            sem_wait(&obj->osem);
        }
        pthread_mutex_unlock(&obj->mutex);
    }
    releaseHydrogen();

    return;
}

void oxygen(H2O* obj) {

    // releaseOxygen() outputs "O". Do not change or remove this line.
    sem_wait(&obj->hsem);

    releaseOxygen();
    obj->oxygen_flag = H2O_INIT;

    sem_post(&obj->osem);

    return;
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->mutex);
    sem_destroy(&obj->hsem);
    sem_destroy(&obj->osem);
    return;
}
