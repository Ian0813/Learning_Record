/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  A declarator recovery.
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
char token[MAXTOKEN];    /* last token string  */
char name[MAXTOKEN];     /*  identifier name   */
char datatype[MAXTOKEN]; /*  data type = int, char */
char out[MAXTOKEN];      /* ouput string */

/* convert word description to declaration */
void main(void){

	int type;
	char temp[MAXTOKEN];
	
	while (gettoken() != EOF) {     /* 1st token on line */
		strcpy(out, token);    /* is the data type */
		//memset(token, 0, sizeof(token));
		while((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS) {
				strcat(out, token);
			} else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
				memset(temp, 0, sizeof(temp));
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
				memset(temp, 0, sizeof(temp));
			} else if (type != ':') {
				printf("invalid input at %s, %d\n", token, type);
			}
		}
		printf("%s\n", out);
	}
	return;
}
