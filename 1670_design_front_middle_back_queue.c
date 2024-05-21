/*
 * =====================================================================================
 *
 *       Filename:  1670_design_front_middle_back_queue.c
 *
 *    Description:  Design front middle back queue   
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

typedef enum {false, true} bool;

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

struct dequeue {
    struct node *head;
    struct node *tail;
    int size;
};

static struct node *newNode(int value) {

    struct node *new = NULL;
    new = (struct node *) malloc(sizeof(struct node)); 

    if (new) {
        new->value = value; 
        new->next = new->prev = NULL;
    }
    return new;
}

struct dequeue *createDequeue(void) {

    struct dequeue *q = (struct dequeue *) malloc(sizeof(struct dequeue));

    if (q) {
        q->tail = q->head = NULL;
        q->size = 0;
    }
    return q;
}

bool addFront(struct dequeue *obj, int value) {

    bool rc = true;
    struct node *new = NULL; 

    new = newNode(value);

    if (obj && new) {
        if (!obj->head) {
            obj->head = obj->tail = new;
        } else {
            obj->head->prev = new;
            new->next= obj->head;
            obj->head = new;
        }
        obj->size++; 
    } else {
        rc = false;
    }
    return rc; 
}

bool addBack(struct dequeue *obj, int value) {

    bool rc = true;
    struct node *new = NULL;

    new = newNode(value);

    if (obj && new) {
        if (!obj->head) {
            obj->head = obj->tail = new;
        } else {
            new->prev = obj->tail;
            obj->tail->next = new;
            obj->tail = obj->tail->next;
        }
        obj->size++; 
    } else {
        rc = false;
    }
    return rc;
}

void removeFront(struct dequeue *obj) {

    struct node *del = NULL;

    if (obj && obj->head) {

        if (obj->head == obj->tail) {
            obj->tail = NULL;
        }

        del = obj->head;
        obj->head = obj->head->next;

        if (obj->head) {
            obj->head->prev = NULL;
        }

        free(del);
        obj->size--; 
    }
    return;
}

void removeBack(struct dequeue *obj) {

    struct node *del = NULL;

    if (obj && obj->tail) {

        if (obj->head == obj->tail) {
            obj->head = NULL; 
        }

        del = obj->tail;
        obj->tail = obj->tail->prev;

        if (obj->tail) {
            obj->tail->next = NULL;
        }
        free(del);
        obj->size--; 
    }
    return;

}

int getFront(struct dequeue *obj) {

    int result = -1;

    if (obj->size) {
        result = obj->head->value;
    }
    return result;
}

int getBack(struct dequeue *obj) {

    int result = -1;

    if (obj->size) {
        result = obj->tail->value;
    }
    return result;
}

bool isEmpty(struct dequeue *obj) {

    bool rc = false;
    if (!obj->size) {
        rc = true;
    }
    return rc;
}

int size(struct dequeue *obj) {

    int result = 0;

    if (obj) {
        result = obj->size;
    }
    return result;
}

void deleteDequeue(struct dequeue *obj) {

    struct node *del = NULL;

    if (obj) {
        while ((del = obj->head)) {
            obj->head = obj->head->next;
            free(del);
        }
        free(obj);
    }
    return;
}

typedef struct {
    struct dequeue *front;
    struct dequeue *back;
} FrontMiddleBackQueue;

void _balance(FrontMiddleBackQueue *obj) {

    int value = 0;

    while (size(obj->front)-1 >= size(obj->back)) {
        value = getBack(obj->front);
        removeBack(obj->front);
        addFront(obj->back, value);
    }

    while (size(obj->back) > size(obj->front)) {
        value = getFront(obj->back);
        removeFront(obj->back);
        addBack(obj->front, value);
    }
    return;
}

FrontMiddleBackQueue* frontMiddleBackQueueCreate(void) {

    FrontMiddleBackQueue *obj = (FrontMiddleBackQueue *) malloc(sizeof(FrontMiddleBackQueue));

    if (obj) {
        obj->front = createDequeue(); 
        obj->back  = createDequeue(); 
    }

    if (obj && (!obj->front || !obj->back)) {
        free(obj->front);
        free(obj->back);
        free(obj);
        obj = NULL;
    }
    return obj;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {

    if (obj && obj->front) {
        addFront(obj->front, val);  
        _balance(obj);
    }
    return;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {

    int _val = 0;

    if (size(obj->front)-1 >= size(obj->back)) {
        _val = getBack(obj->front);
        removeBack(obj->front);
        addFront(obj->back, _val);
    }
    addBack(obj->front, val);

    return;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {

    if (obj && obj->back) {
        addBack(obj->back, val);  
        _balance(obj);
    }
    return;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {

    int result = -1;

    if (obj) {
        if (size(obj->front) > 0) {
           result = getFront(obj->front);
           removeFront(obj->front);
        } else if (size(obj->back) > 0) {
           result = getFront(obj->back); 
           removeFront(obj->back);
        }
        _balance(obj);
    }

    return result;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {

    int result = -1;

    if (obj) {

        if (size(obj->front) >= size(obj->back)) {
            result = getBack(obj->front);
            removeBack(obj->front);
        } else if (size(obj->back)) {
            result = getFront(obj->back);
            removeFront(obj->back);
        }
    }
    return result;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {

    int result = -1;

    if (obj) {
        if (size(obj->back) > 0) {
            result = getBack(obj->back);
            removeBack(obj->back);
        } else if (size(obj->front) > 0) {
            result = getBack(obj->front);
            removeBack(obj->front);
        }
        _balance(obj);
    }
    return result;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {

    if (obj) {
        if (obj->front) {
            deleteDequeue(obj->front);
        }
        if (obj->back) {
            deleteDequeue(obj->back);
        }
    }
    return;
}

int main(void) {

    int value = 0;

    FrontMiddleBackQueue *obj = frontMiddleBackQueueCreate();

#if 0
    ["FrontMiddleBackQueue","pushMiddle","pushMiddle","popMiddle","popFront","popMiddle","popMiddle","pushMiddle","popMiddle","pushMiddle","pushMiddle","popMiddle","pushMiddle","pushFront","pushMiddle","popMiddle","pushMiddle","pushMiddle","popMiddle","pushFront","pushMiddle","pushMiddle","popMiddle","popBack","popBack","popBack","popMiddle","popMiddle","pushMiddle","popBack","popMiddle","popMiddle","pushMiddle","pushMiddle","pushMiddle","popMiddle"]
[[],[595242],[962643],[],[],[],[],[816362],[],[636844],[469298],[],[902622],[86119],[714413],[],[508692],[936365],[],[233476],[640498],[462491],[],[],[],[],[],[],[903385],[],[],[],[762740],[676159],[639276],[]]

    frontMiddleBackQueuePushFront(obj, 1);
    frontMiddleBackQueuePushBack(obj, 2);
#endif

    frontMiddleBackQueuePushMiddle(obj, 595242);
    frontMiddleBackQueuePushMiddle(obj, 962643);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopFront(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    frontMiddleBackQueuePushMiddle(obj, 816362);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    frontMiddleBackQueuePushMiddle(obj, 636844);
    frontMiddleBackQueuePushMiddle(obj, 469298);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    frontMiddleBackQueuePushMiddle(obj, 902622);
    frontMiddleBackQueuePushFront(obj, 86119);
    frontMiddleBackQueuePushMiddle(obj, 714413);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    frontMiddleBackQueuePushMiddle(obj, 508692);
    frontMiddleBackQueuePushMiddle(obj, 936365);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    frontMiddleBackQueuePushFront(obj, 233476);
    frontMiddleBackQueuePushMiddle(obj, 640498);
    frontMiddleBackQueuePushMiddle(obj, 462491);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopBack(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopBack(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopBack(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

#if 0
    value = frontMiddleBackQueuePopMiddle(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopBack(obj);
    fprintf(stdout, "value: %d\n", value);

    value = frontMiddleBackQueuePopFront(obj);
    fprintf(stdout, "value: %d\n", value);
#endif

    frontMiddleBackQueueFree(obj);

    return EXIT_SUCCESS;
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);

 * frontMiddleBackQueuePushMiddle(obj, val);

 * frontMiddleBackQueuePushBack(obj, val);

 * int param_4 = frontMiddleBackQueuePopFront(obj);

 * int param_5 = frontMiddleBackQueuePopMiddle(obj);

 * int param_6 = frontMiddleBackQueuePopBack(obj);

 * frontMiddleBackQueueFree(obj);
*/

