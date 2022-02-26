/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Implement a simple calculator by the reverse polish notatiom.
 *
 *        Version:  1.0
 *        Created:  2021年10月06日 20時50分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h> // for atof()
#include <stdio.h>
#include <string.h>
#include "polish.h" 
#include <math.h>

int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);

/* reverse polish notation */
int main(int argc, char *argv[]){

	int type;
	double op2, val, duplicate;
	char s[MAXOP];
	memset(s, 0, sizeof(s));
	//memcpy(s, argv[1], strlen(argv[1]));
	double answer;

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0){
					push(pop() / op2);
				}else{
					printf("error : zero divisor.\n");
				}
				break;
			case '%':
				op2 = pop();
				//printf("%d %d\n", o1, o2);
				if(op2 != 0){
					push((int)pop()%(int)op2);
				}else{
					printf("a mod 0 is undefined.\n");
				}
				break;
			case '\n':
				answer = pop();
				printf("anwser : \t%.8g\n", answer);
				// push(answer);
				break;
			default:
				printf("error : unknown command %s\n", s);
				break;		
		}
	}
	
	return 0;	
}
