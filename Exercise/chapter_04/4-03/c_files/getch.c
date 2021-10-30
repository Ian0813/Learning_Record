/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description:  Get a character and push back the remain character.
 *
 *        Version:  1.0
 *        Created:  2021年10月07日 23時15分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];     /*  buffer for ungetch  */
int bufp = 0; /* next free position in buf */

int getch(void){   /*  get a (possibly pushed back) character */

	return (bufp > 0) ? buf[--bufp]: getchar(); 
}


void ungetch(int c){ /*  push character back on input */

	if(bufp >= BUFSIZE){
		printf("ungetch : too many characters.\n");
	}else{
		buf[bufp++] = c;
	}
}

void ungets(int c){
	int flag = 0;
	//printf("c : %d\n", c);

	if(c != EOF && c != '\0'){
		flag = 1;
		ungetch(c);
	}

	if(flag == 0){
		printf("No remains character.\n");
	}
}
