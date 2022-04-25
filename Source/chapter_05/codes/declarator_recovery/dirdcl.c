/*
 * =====================================================================================
 *
 *       Filename:  dirdcl.c
 *
 *    Description:  parse a direct declarator
 *
 *        Version:  1.0
 *        Created:  2022年04月02日 01時01分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "dcl_parser.h"

/*  dirdcl : parse a direct declarator */
void dirdcl(void) {

	int type;

	if (tokentype == '('){         /*  ( dcl ) */
		dcl();
		if (tokentype != ')'){
			printf("error : missing )\n");
		}
	} else if (tokentype == NAME){   /*  variable name */
		strcpy(name, token);
		memset(token, 0, strlen(token));
	} else {
		printf("error : expected name or (dcl)\n");
	}

	while ((type=gettoken()) == PARENS || type == BRACKETS){
		if (type == PARENS){
			strcat(out, " function returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
