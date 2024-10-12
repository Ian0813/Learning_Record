/*
 * =====================================================================================
 *
 *       Filename:  1823_find_the_winner_of_the_circular_game.c
 *
 *    Description:  find the winner of the circular game
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
#include <limits.h>

typedef enum {false, true} bool;

struct queue {
    int *buffer;
    int windex;
    int rindex;
    int size;
};

typedef struct queue *Queue;

static Queue create_queue(int size) {

    Queue q = NULL;

    if (size) {
        q = (Queue) malloc(sizeof(struct queue));
        q->buffer = (int *) calloc(size, sizeof(int)); 
        q->windex = q->rindex = 0;
        q->size = size;
    }
    return q;
}

static bool enqueue(Queue q, int val) {

    bool rc = true; 

    if (q) {
        if ((q->windex+1)%q->size != q->rindex) {
            q->buffer[q->windex++] = val; 
            q->windex %= q->size;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

static bool dequeue(Queue q) {

    bool rc = true; 

    if (q) {
        if (q->rindex != q->windex) {
            q->rindex++;
            q->rindex %= q->size;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

static int peek(Queue q) {

    int val = INT_MIN; 

    if (q) {
        if (q->rindex != q->windex) {
            val = q->buffer[q->rindex]; 
        }
    }
    return val;
}

static void delete_queue(Queue q) {

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}

int findTheWinner(int n, int k) {

    Queue q = NULL;
    int counter = 1, remove_counter = 0;
    int *arr = NULL;
    int index = 0;
    int val = 0;

    if (n) {

        arr = (int *) calloc(n, sizeof(int));
        q = create_queue(BUFSIZ);

        for (int i = 1; i <= n; i++) {
            arr[index++] = i;
        }

        while (remove_counter < (n-1)) {

            for (int i = 0; i < index; i++) {
                if (counter == k) {
                    remove_counter++;
                    counter = 1;
                    //printf("remove: %d\n", i+1); 
                } else {
                    enqueue(q, arr[(i+1)%index]); 
                    counter++;
                }

                if (remove_counter == (n-1)) {
                    enqueue(q, arr[i+1]);  
                    break;
                }
            }

            index = 0;

            while ((val = peek(q)) != INT_MIN) {
                dequeue(q);
                arr[index++] = val;   
            }
        }
        //printf("val :%d\n", *arr);
        val = *arr;
        delete_queue(q);
        free(arr);
    }
    return val;
}

int main(void) {

    findTheWinner(6, 5);

    return EXIT_SUCCESS;
}

