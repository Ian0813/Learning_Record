/*
 * =====================================================================================
 *
 *       Filename:  getint.c
 *
 *    Description:  get next integer from input into *pn
 *
 *        Version:  1.0
 *        Created:  2021年11月21日 14時31分07秒
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
#include <ctype.h>


int getch(void);
void ungetch(int);



/* getint :  get next integer from input into *pn */

int getint(int *pn){

	int c = 0, sign = 0;

	while(isspace((c = getch())))  /*  skip white space */
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1: 1;
	if( c == '+' || c == '-'){
		c = getch();
	}

	for( *pn = 0; isdigit(c); c = getch()){
		*pn = 10 * *pn + (c - '0');
		//printf("c : %d, %d\n", c, *pn);
	}

	*pn *= sign;
	if(c != EOF){
		ungetch(c);
	}

	return c;

}


