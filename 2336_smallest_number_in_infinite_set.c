/*
 * =====================================================================================
 *
 *       Filename:  2336_smallest_number_in_infinite_set.c
 *
 *    Description:  Smallest number in infinite set  
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

#define TABLE_SIZE 1001

struct node {
    int val;
    struct node *next;
    struct node *prev;
};

typedef struct {
    struct node *head;
    struct node *tail;
    int table[TABLE_SIZE];
} SmallestInfiniteSet;

static void freelist(struct node *node) {

    struct node *temp = NULL; 

    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    return;
}

static void insert_node(struct node *head, struct node *new) {

    struct node *second = head->next;     

    while (head->val < new->val) {

        if (second->val > new->val) {
            second->prev = new; 
            new->next = second;
            head->next = new;
            new->prev = head;
            break;
        }
        second = second->next;
        head = head->next;
    }
    return;
}

static struct node *create_node(int num) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));

    if (temp) {
        temp->next = temp->prev = NULL; 
        temp->val = num;
    }
    return temp;
}    

SmallestInfiniteSet* smallestInfiniteSetCreate(void) {

    SmallestInfiniteSet *obj = NULL;

    obj = (SmallestInfiniteSet *) malloc(sizeof(SmallestInfiniteSet));

    if (obj) {

        memset(obj->table, 0, sizeof(int) * TABLE_SIZE);

        obj->tail = obj->head = NULL;

        for (int i = 1; i <= 1000; i++) {
            if (!obj->head) {
                obj->head = obj->tail = create_node(i);
            } else {
                obj->tail->next = create_node(i); 
                obj->tail->next->prev = obj->tail;
                obj->tail = obj->tail->next;
            }
        }
    }
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {

    int rc = 0;
    struct node *temp = NULL;

    if (obj->head) {
        obj->table[obj->head->val] = 1;
        rc = obj->head->val;
        temp = obj->head;
        obj->head = obj->head->next;
        if (obj->head)
            obj->head->prev = NULL;
        free(temp);
    }
    return rc;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {

    struct node *temp = NULL; 

    if (obj && obj->table[num]) {

        temp = create_node(num);        
		obj->table[num] = 0;

        if (!obj->head) {
            obj->head = obj->tail = temp;
        } else {
            if (obj->head->val > temp->val) {
                temp->next = obj->head;
                obj->head = temp;
            } else if (obj->tail->val < temp->val) {
                temp->prev = obj->tail;
                obj->tail = temp;
            } else {
                insert_node(obj->head, temp);
            }
        }
    }
    return;
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {

    if (obj) {
        freelist(obj->head);
        free(obj);
    }
    return;
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);

 * smallestInfiniteSetAddBack(obj, num);

 * smallestInfiniteSetFree(obj);
*/

