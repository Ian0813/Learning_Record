/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  Configuration stack information for use.  
 *
 *        Version:  1.0
 *        Created:  2022年01月02日 16時07分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */


#define MAXIMUM 100

/**
 * @brief An element of stack structure. 
 */
typedef struct stack{
	int data;
	struct stack *ptr;
}Stack;

void push(Stack **, int);

Stack *pop(Stack **);

bool check_empty(Stack **);

void show_topmost(Stack **);

void mem_release(Stack **);
