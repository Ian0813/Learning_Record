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

	int i, op, flag, temp;
	static int c = -1;
	
	if(c == ' ' || c == '\t' || c == EOF || c == '\n'){
		while((s[0] = c = getch()) == ' ' || c == '\t')
			;
	}else{
		//getchar();
		printf("c : %d\n", c);
	}

	//else if(c != ' ' && c != '\t'){
	//	printf("c : %c\n", c);
	//	s[0] = c;
	//	c = -1;
	//}

	s[1] = '\0';


	if(!isdigit(c) && c != '.' && c != '-'){
		temp = c;
	    c = EOF;
		return temp;	
	}
	
	i = 0;

	if(c == '-'){
		flag = 1;
	}

	if(isdigit(c) || c == '-'){  /*  collect integer part */
		while(isdigit(s[++i] = c = getch())){
			flag = 0; 
		}	
	}

	if(flag == 1){
		ungetch(c);
		return '-';
	}


	if(c == '.'){   /*  collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';
	if(strlen(s) != 0){
		//printf("s : %s\n", s);
	}


	//if(c != EOF){
	//	ungetch(c);
	//}

	return NUMBER;
}
