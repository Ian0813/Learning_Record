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
#include <time.h>
#include "stack.h"


void main(void){

	int keep_on = true;
	int action, val;
	Stack *top = NULL, *ptr;
	srand(time(NULL));
	printf("Testing features of the stack.\n");

	while(keep_on){

		printf("Choose an action to do.\n");
		printf("0 : exit\n1 : push\n2 : pop\n3 : check_empty\n4 : show_topmost\n");

		scanf("%d", &action);

		switch(action){
			case 0:
				keep_on = false;
				break;
			case 1:
				val = rand() % 10000;
				printf("val : %d\n", val);
				push(&top, val);
				break;
			case 2:
				ptr = pop(&top);
				if(ptr != NULL){
					printf("current data : %d\n", ptr->data);
				}else{
					printf("Not have an element in the stack.\n");
				}
				break;
			case 3:
				check_empty(&top);
				break;
			case 4:
				show_topmost(&top);
				break;
			default:
				printf("No have this option.\n");
		}	
		printf("\n");
	}	

	mem_release(&top);

	return;
}



