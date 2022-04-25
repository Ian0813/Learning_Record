/*
 * =====================================================================================
 *
 *       Filename:  dcl.c
 *
 *    Description:  parse a declarator
 *
 *        Version:  1.0
 *        Created:  2022年04月01日 22時08分22秒
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
#include <string.h>
#include "dcl_parser.h"

/* dcl : parse a declarator */
void dcl(void){

	int ns;
	for(ns = 0; gettoken() == '*'; ){
		ns++;
	}
	dirdcl();
	while(ns-- > 0){
		strcat(out, " pointer to");
	}
}	
