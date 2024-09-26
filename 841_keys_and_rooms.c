/*
 * =====================================================================================
 *
 *       Filename:  841_keys_and_rooms.c
 *
 *    Description:  Keys and rooms  
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

typedef enum {false, true} bool;

#define ZERO_ROOM 0
#define KEY_SIZE 3001

#define CHECK_AVAIL_KEY(key) (key <= (KEY_SIZE-1))

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {

    uint16_t key_list[KEY_SIZE] = {0}, key_index = 0, index = 0, room_num = 0;
    bool *room_unlock = (bool *) calloc(roomsSize, sizeof(bool));
    bool result = true;

    for (int i = 0; i < roomsColSize[ZERO_ROOM]; i++) {
        key_list[key_index++] = rooms[ZERO_ROOM][i];
    }

    while (CHECK_AVAIL_KEY(index)) {

        if (!room_unlock[key_list[index]]) {
             room_unlock[key_list[index]] = true;
             room_num = key_list[index]; 

            for (int j = 0; j < roomsColSize[room_num]; j++) {
                key_list[key_index++] = rooms[room_num][j]; 
            }
        }
        index++;
    }

    for (int i = 1; i < roomsSize; i++) {
        if (!room_unlock[i]) {
            result = false;
            break;
        }
    }
    return result;
}
