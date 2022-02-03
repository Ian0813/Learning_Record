/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  The testing feature of stack. 
 *
 *        Version:  1.0
 *        Created:  2022年01月02日 19時14分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "stack.h"

Stack *top = NULL;

int DEBUG(void *ptr){
	
	int error = 0;
	if(ptr == NULL){
		printf("Not have elements in the stack.\n");
		error = -1;
	}

	return error;
}

void DO_OPERATE(Stack *ptr, int *v1, int *v2){

	ptr = pop(&top);
	if(DEBUG((void *) ptr) == -1){
		exit(1);		
	}
	*v2 = ptr->data;
	free(ptr);

	ptr = pop(&top);
	if(DEBUG((void *) ptr) == -1){
		exit(EXIT_FAILURE);	
	}
	*v1 = ptr->data;
	free(ptr);
}


void main(int argc, char *argv[]){

	int keep_on = true;
	int action, val1 = 0, val2, val_number = 0;
	char op;
	// ptr : Take over the pointer from a pop(). 
	Stack *ptr = NULL;
	printf("Postfix calculator.\n");

	if(argc > 1){
		//printf("argc : %d\n", argc);		
		while((++val_number) < argc){

			val1 = atoi(argv[val_number]);
			if(val1 != 0 || !strcmp(argv[val_number], "0")){
				push(&top, val1);
				continue;
			}

			memcpy(&op, argv[val_number], 1);

			switch(op){
			
				case '+':
					DO_OPERATE(ptr, &val1, &val2);
					push(&top, (val1+val2));
					break;
				case '-':
					DO_OPERATE(ptr, &val1, &val2);
					push(&top, (val1-val2));
					break;
				case '%':
					DO_OPERATE(ptr, &val1, &val2);
					push(&top, (val1%val2));
					break;
				case '*':
					DO_OPERATE(ptr, &val1, &val2);
					push(&top, (val1*val2));
					break;
				case '/':
					DO_OPERATE(ptr, &val1, &val2);
					push(&top, (val1/val2));
					break;
				default:
					printf("op : %c\n", op);
					printf("No operator matches.\n");
					break;

			}	

		}

		ptr = pop(&top);
		if(DEBUG((void *) ptr) == -1){
			exit(1);		
		}
		printf("result : %d\n", ptr->data);
		free(ptr);

	}else{
		printf("Invalid arguments.\n");
	}

	printf("Ending...\n");
	mem_release(&top);

	return;
}



