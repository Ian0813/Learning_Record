/*
 * =====================================================================================
 *
 *       Filename:  push_pop.c
 *
 *    Description:  the push and pop function.
 *
 *        Version:  1.0
 *        Created:  2021年10月06日 21時58分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <string.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;
double val[MAXVAL]; /* val stack */

/* push : push f onto value stack */
void push(double f){

	if(sp < MAXVAL){
		val[sp++] = f;
	}else{
		printf("error : stack full, can't push : %g\n", f);
	}
}


/* pop : pop and return top value from stack */
double pop(void){

	if(sp > 0){			
		return val[--sp];
	}else{
		printf("error : stack empty !\n");
		return 0.0;
	}
}

/* top : This function returns a reference of the element at the top of the stack container. */
double top(void){
	//printf("%s called\n", __func__);
	if(sp > 0){
		//printf("%f\n", val[sp - 1]);	
		printf("Stack index : %d, val : %f\n", sp-1, val[sp - 1]);	
		return val[sp - 1];
	}else{
		printf("The stack is empty.\n");
		return 0.0;
	}
}

void swap(){
	
	double temp;

	if(sp > 1){
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
	   	val[sp-2] = temp;	
	}else{
		printf("Not enough elements to swap !\n");
	}
}

void clear(){

	printf("Before clear : \n");
	for(int x = 0; x < sp; x++){
		printf("val[%d] = %f ", x, val[x]);
	}
	putchar(10);
	memset(val, 0, sizeof(val));
	sp = 0;
	printf("Finish clear.\n");
#if 0
	for(int x = 0; x < sp; x++){
		printf("val[%d] = %f ", x, val[x]);
	}
#endif
}
