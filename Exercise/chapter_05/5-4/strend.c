/*
 * =====================================================================================
 *
 *       Filename:  strend.c
 *
 *    Description:  Observe a string t whether occurs at the end of a string s.  
 *
 *        Version:  1.0
 *        Created:  2021年12月03日 00時50分05秒
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


/* strend  */
void strend(char *s, char *t){

	int s_len, t_len;

	s_len = strlen(s);
	t_len = strlen(t);

	if(!strcmp((s+(s_len-t_len)), t)){
		printf("We can find a string t at the end of a string s.\n");
	}else{
		printf("Not found !!!\n");
	}
}

