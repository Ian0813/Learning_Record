/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Reverse Polish calculator
 *
 *        Version:  1.0
 *        Created:  2022年09月17日 03時47分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h> /*  for atof() */
#include <stdio.h>
#include <string.h>

#define MAXOP   100    /* max size of operand or operator */
#define NUMBER  '0'    /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);


void main(void) {

    int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
        switch (type) {
        
			case NUMBER:
                push(atof(s));
				break;
			case '+': 
				push(pop() + pop());
				break;
			case '*':
				pop() + pop();
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
				    push(pop() / op2);
                } else {
                    printf("zero divisor.");
				}
				break;
			case '\n':
                printf("result: %.8g\n", pop());
			    break;
			default: 
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return ;
}
