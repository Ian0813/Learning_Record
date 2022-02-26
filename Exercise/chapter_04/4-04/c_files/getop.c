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

	i = 1;
	//printf("c : %d\n", c);

	if(isalpha(c)){

		while((s[i++] = c = getch()) >= 'a' && c <= 'z')
				;
		//if(c == '\n'){
		//	//printf("push back ! \n");
		//	ungetch(c);
		//}
		s[strlen(s) - 1] = '\0';
		if(!strcmp(s, "top")){
			//printf("match\n");	
			bzero(s, strlen(s));
			return 't';
		}else if(!strcmp(s, "duplicate")){
			bzero(s, strlen(s));
			return 'd';
		}else if(!strcmp(s, "swap")){
			bzero(s, strlen(s));
			return 's';
		}else if(!strcmp(s, "clear")){
			bzero(s, strlen(s));
			return 'c';	
		}else if(!strcmp(s, "sin") && c == '\n'){
			printf("sin called\n");
			ungetch(c);
			bzero(s, strlen(s));
			return SIN;
		}else if(!strcmp(s, "exp") && c == '\n'){
			bzero(s, strlen(s));
			ungetch(c);
			return 'e';
		}else if(!strcmp(s, "pow") && c == '\n'){
			bzero(s, strlen(s));
			ungetch(c);
			return 'p';
		}else if(!strcmp(s, "recently")){
			bzero(s, strlen(s));
			return 'r';
		}
		//printf("strcmp : %d\n", strcmp(s, "top"));
		return c;
	}

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
		ungets(c);
		//ungetch(c);
	}
	

	return NUMBER;
}
