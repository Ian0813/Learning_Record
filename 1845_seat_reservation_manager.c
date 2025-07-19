/*
 * =====================================================================================
 *
 *       Filename:  1845_seat_reservation_manager.c
 *
 *    Description:  seat reservation manager
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

typedef struct node {
    int value;
    struct node *next;
} *NodePtr;

typedef struct {
    NodePtr *reserved;
    NodePtr available;
    int totalSeat;
    int availableSeat;
} SeatManager;

static NodePtr insert_node(NodePtr head, int value) {

    if (!head) {
        head = (NodePtr) malloc(sizeof(*head));
        head->value = value;
        head->next = NULL;
    } else {
        head->next = insert_node(head->next, value);
    }
    return head;
}

static void free_node(NodePtr node) {

    if (node) {
        free_node(node->next);  
        free(node);
    }
    return;
}


SeatManager* seatManagerCreate(int n) {

    SeatManager *obj = NULL;
    NodePtr new = NULL;

    if (n) {

        obj = (SeatManager *) malloc(sizeof(*obj));

        if (!obj) 
            return obj;

        obj->available = NULL;
        obj->reserved = (NodePtr *) calloc(n+1, sizeof(NodePtr));
        obj->totalSeat = n;
        obj->availableSeat = n;

        for (int i = n; i >= 1; i--) {
            new = (NodePtr) malloc(sizeof(*new));
            new->value = i;
            new->next = obj->available;
            obj->available = new; 
        }
    }

    return obj;
}

int seatManagerReserve(SeatManager* obj) {

    int seatNumber = 0;

    if (obj && obj->available) {

        seatNumber = obj->available->value;
        obj->reserved[seatNumber] = obj->available;
        obj->available = obj->available->next;
        obj->availableSeat--;
    }
    return seatNumber;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {

    NodePtr temp = NULL, node = NULL, prev = NULL; 

    if (obj) {

        temp = obj->reserved[seatNumber];  

        if (!temp)
            return; 

        if (obj->available) {

            node = obj->available;

            while (node->value < temp->value) {
                prev = node;         
                node = node->next;
            }

            if (prev) {
                prev->next = temp;
                temp->next = node;
            } else {
                temp->next = node; 
            }
        }

        if (!prev)
            obj->available = temp;

        obj->reserved[seatNumber] = NULL;
        obj->availableSeat++;
    }

    return; 
}

void seatManagerFree(SeatManager* obj) {

    if (obj) {

        if (obj->availableSeat) 
            free_node(obj->available);

        for (int i = 1; i <= obj->totalSeat; i++) {
            if (obj->reserved[i]) 
                free(obj->reserved[i]);
        }    
        free(obj->reserved);
        free(obj);
    }
    return;
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);
 
 * seatManagerUnreserve(obj, seatNumber);
 
 * seatManagerFree(obj);
*/

