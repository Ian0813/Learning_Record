/*
 * =====================================================================================
 *
 *       Filename:  2024_09_09_901_online_stock_span.c
 *
 *    Description:  Online stock span  
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

#define MAX_BUFSIZE 10001
#define INIT_SPAN 1

typedef struct unit {
    int val;
    int span;
} *UNITPTR;

struct stack {
/* 
    bool (*push)(struct stack *s, UNITPTR unit); 
    bool (*pop)(struct stack *s); 
    UNITPTR (*gettop)(struct stack *s); 
*/
    UNITPTR *buffer;
    int top;
};
typedef struct stack Stack;

static Stack *create_stack(void) {

    Stack *s = NULL;

    s = (Stack *) malloc(sizeof(Stack));
    if (s) {
		s->top = 0;
        s->buffer = (UNITPTR *) calloc(MAX_BUFSIZE, sizeof(UNITPTR));
    }
    return s;
}    

static bool push(Stack *s, int price, int spans) {

    bool rc = true;
    UNITPTR unit = NULL;

    if (s) {
        if (s->top < MAX_BUFSIZE) {
            unit = (UNITPTR) malloc(sizeof(struct unit));
            unit->val = price;
            unit->span = spans;
            s->buffer[s->top++] = unit;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

static bool pop(Stack *s) {

    bool rc = true;

    if (s) {
        if (s->top > 0) {
            free(s->buffer[s->top-1]);
            s->top--;
        } else {
            rc = false; 
        }
    } else {
        rc = false;   
    }
    return rc;
}

static UNITPTR gettop(Stack *s) {

    if (s) {
        if (s->top > 0) {
            return s->buffer[s->top-1];
        }
    }
    return NULL;
}

static void delete_stack(Stack *s) {

    if (s) {
        for (int i = 0; i < s->top; i++) {
            free(s->buffer[i]);
        }
        free(s->buffer);
        free(s);
    }
    return;
}

typedef struct {
    Stack *data_stack;
} StockSpanner;

StockSpanner* stockSpannerCreate(void) {

    StockSpanner *obj = NULL;    

    obj = (StockSpanner *) malloc(sizeof(StockSpanner));

    if (obj) {
        obj->data_stack = create_stack();
    }
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {

    UNITPTR temp_ptr = NULL;
    int spans = INIT_SPAN;

    temp_ptr = gettop(obj->data_stack);

    if (!temp_ptr) {
        push(obj->data_stack, price, spans);
    } else {

        while (temp_ptr->val <= price) {

            spans += temp_ptr->span;
            pop(obj->data_stack);

            if ((temp_ptr = gettop(obj->data_stack)) == NULL) {
                break; 
            }    
        }
        push(obj->data_stack, price, spans);
    }
    return spans;
}

void stockSpannerFree(StockSpanner* obj) {

    if (obj) {
        delete_stack(obj->data_stack);
        free(obj);
    }
    return;
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);

 * stockSpannerFree(obj);
*/

