/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  Implement a stack functionality.
 *
 *        Version:  1.0
 *        Created:  2022年01月02日 15時40分25秒
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
#include <stdbool.h>
#include "stack.h"


/**
 * @brief Record how many elements existed in the stack.
 */
unsigned int count = 0;


static void mem_allocate(Stack **element){

	*element = (Stack *) malloc(sizeof(Stack));

	if(*element == NULL){
		perror("malloc ");
		exit(EXIT_FAILURE);
	}
}


void push(Stack **top, int data){

	if(count >= MAXIMUM){
		printf("Reach limitation of the stack.\n");
		return;
	}
	
	if(*top == NULL){
		//printf("First ...\n");
		mem_allocate(top);

		(*top)->data = data;
		(*top)->ptr = NULL;
	}else{
		Stack *element;
		mem_allocate(&element); 	
		
		element->data = data;
		element->ptr = *top;
		*top = element;
	}
	count++;

	return;
}


Stack *pop(Stack **top){

	if(*top == NULL){
		printf("[%s] Not have elements.\n", __func__);
		return NULL;
	}

	if(count == 0){
		printf("Nothin pop up.\n");
		return NULL;	
	}

	Stack *element = *top;
	//printf("element : %p\n", element);
	if(count > 1){
		*top = (*top)->ptr;
	}else{
		*top = NULL; 
	}

	count--;

	return element;	
}

bool check_empty(Stack **top){
	
	if(*top == NULL){
		return true;
	}else{
		return false;
	}
}

void show_topmost(Stack **top){
	if(*top == NULL){
		printf("Nothing can show up.\n");
		return;
	}

	printf("The topmost element as follows\ndata : %d, ptr : %p\n", (*top)->data, (*top)->ptr);

	return;
}

void mem_release(Stack **top){

	Stack *element;
	while(*top != NULL){
		element = *top;
		*top = (*top)->ptr;
		free(element);
	}	
}
