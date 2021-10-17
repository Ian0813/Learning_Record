/*
 * =====================================================================================
 *
 *       Filename:  getop.c
 *
 *    Description:  get operator or operand.
 *
 *        Version:  1.0
 *        Created:  2021年10月06日 22時23分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include "polish.h"
#include <string.h>

#if defined(RECENTLY_VAL)
#undef RECENTLY_VAL
#endif


//#define EMPTY(c)
//
//#define getch getchar
//#define ungetch(c) EMPTY(c) 


int getch(void);
void ungetch(int);
void ungets(int);


/* getop : get next operator or numeric operand */
int getop(char s[]){

	int i, c, op;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';


	if(!isdigit(c) && c != '.' && c != '-'){
		return c; /* not a number */
	}
	
	i = 0;

	if(isdigit(c) || c == '-'){  /*  collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
	}

	if(c == '.'){   /*  collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';
	if(strlen(s) != 0){
		//printf("s : %s\n", s);
	}

	if(c != EOF){
		ungetch(c);
	}

	return NUMBER;
}
