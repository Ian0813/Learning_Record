/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  A declaration parser. 
 *
 *        Version:  1.0
 *        Created:  2022年04月02日 11時34分12秒
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
#include "dcl_parser.h"


int tokentype;           /* type of last token */
int prevtoken;           /* previous token holder */
char token[MAXTOKEN];    /* last token string  */
char name[MAXTOKEN];     /*  identifier name   */
char datatype[MAXTOKEN]; /*  data type = int, char */
char out[MAXTOKEN];      /* ouput string */

/* convert declaration to words */
void main(void){

	while (gettoken() != EOF) {     /* 1st token on line */
		strcpy(datatype, token);    /* is the data type */
		memset(token, 0, sizeof(token));
	   	out[0] = '\0';
		dcl();    /* parse rest of line */
		if (tokentype != '\n') {
			printf("syntax error, tokentype : %d\n", tokentype);
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
}
