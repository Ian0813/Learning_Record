/*
 * =====================================================================================
 *
 *       Filename:  1603_design_parking_system.c
 *
 *    Description:  design parking system
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

typedef enum {false, true} bool;

#define GET_SLOT_TYPE(type) \
    !strcmp("big", #type) ? SLOT_BIG : !strcmp("medium", #type) ? SLOT_MEDIUM : SLOT_SMALL

#define IS_AVAILABLE(spaces) !(spaces) ? false : true
#define TYPE_TO_SLOT(carType) ((carType)-1)

typedef enum {
    SLOT_BIG = 0,
    SLOT_MEDIUM = 1,
    SLOT_SMALL = 2, 
    SLOT_SIZE
} slot_size_t;

typedef struct {
    int slot_spaces[SLOT_SIZE];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {

    ParkingSystem *parking_tracker = NULL;

    parking_tracker = (ParkingSystem *) malloc(sizeof(*parking_tracker));

    if (parking_tracker) {
        parking_tracker->slot_spaces[GET_SLOT_TYPE(big)] = big;
        parking_tracker->slot_spaces[GET_SLOT_TYPE(medium)] = medium;
        parking_tracker->slot_spaces[GET_SLOT_TYPE(small)] = small;
    }    

    return parking_tracker;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {

    bool rc = false;

    if (!obj)
        return rc;

    switch (carType) {
        case 1:
            rc = IS_AVAILABLE(obj->slot_spaces[SLOT_BIG]);
        break;

        case 2:
            rc = IS_AVAILABLE(obj->slot_spaces[SLOT_MEDIUM]);
        break;

        case 3:
            rc = IS_AVAILABLE(obj->slot_spaces[SLOT_SMALL]);
        break;

        default:
    }

    if (rc) {
        obj->slot_spaces[TYPE_TO_SLOT(carType)]--;
    }

    return rc;
}

void parkingSystemFree(ParkingSystem* obj) {

    if (obj)
        free(obj); 

    return;
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);

 * parkingSystemFree(obj);
*/

