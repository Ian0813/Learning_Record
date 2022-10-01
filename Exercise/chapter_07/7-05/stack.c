/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  Create a couple of functions for implementing a stack!
 *
 *        Version:  1.0
 *        Created:  2022年09月17日 14時37分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXVAL 100    /* maximum free stack position */

int sp = 0;    /* next free stack position */
double val[MAXVAL];         /* value stack */ 

/* push: push f onto value stack */
void push(double f) {

    if (sp < MAXVAL) {
        val[sp++] = f;
	} else {
        printf("error: stack full, can't push %g\n", f);
	}
	return;
}

/* pop: pop and return top value from stack */
double pop(void) {

    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty, can't pop.\n");
		return 0.0;
    } 
}
