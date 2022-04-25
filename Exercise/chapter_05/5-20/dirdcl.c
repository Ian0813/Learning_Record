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

	if (tokentype == '(') {         /*  ( dcl ) */
		dcl();
		if (tokentype != ')'){
			errmsg("error : missing )\n");
		}
	} else if (tokentype == NAME){   /*  variable name */
		if (name[0] == '\0') {
			strcpy(name, token);
		}		
		memset(token, 0, strlen(token));
	} else {
		prevtoken = YES;
		//errmsg("error : expected name or (dcl)\n");
	}

	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
		if (type == PARENS){
			strcat(out, " function returning");
		} else if (type == '(') {
			strcat(out, " function expecting");
			printf("[%s] tokentype : %d\n", __func__, tokentype);
			parmdcl();
			strcat(out, " and returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
