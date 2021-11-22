/*
 * =====================================================================================
 *
 *       Filename:  getfloat.c
 *
 *    Description:  get next integer from input into *pn to form a floating number.
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



/* getfloat :  get next integer from input into *pn to form a floating number. */

int getfloat(float *pn){
	
	/* 
	 * 1. The variable mark is a recorder to observe that notation either '+' or '-' whether occurs. 
	 *
	 * 2. The variable digits represent how many the digit number of a fraction.  
	 *
	*/
	int c = 0, sign = 0, mark = 0, digits = 1; 
	float val; /* The variable val is a part of a fraction that part is after a dot. */ 

	while(isspace(c = getch()))  /*  skip white space */
		;
	
	//printf("%d, %d, %d\n", c, __LINE__, isdigit(c));


	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}


	sign = (c == '-') ? -1: 1;
	if( c == '+' || c == '-'){
		mark = 1;
		c = getch();
	}

	for( *pn = 0; isdigit(c); c = getch()){
		*pn = 10 * *pn + (c - '0');
		//printf("c : %d, %d, %d\n", c, *pn, __LINE__);
	}

	if(c == '.'){

		c = getch();
		for(val = 0; isdigit(c); c = getch()){
			val = (float) val * 10 + (c - '0');
			digits *= 10;
		}

		*pn = *pn + (val/digits);

	}

	*pn *= sign;

	if(c != EOF && mark == 1 && *pn == 0){
		if(sign == 1){
			ungetch('+');
		}else if(sign == -1){
			ungetch('-');
		}	
	}else if(c != EOF){
		ungetch(c);
	}

	//printf("%d\n", c);

	//printf("c : %d, %d, %d\n", c, *pn, __LINE__);
	return c;

}


