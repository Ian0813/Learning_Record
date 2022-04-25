/*
 * =====================================================================================
 *
 *       Filename:  substr.c
 *
 *    Description:  Fetch a substring from a particular string.
 *
 *        Version:  1.0
 *        Created:  2022年03月19日 17時32分16秒
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

void substr(char *s, char *str, int maxstr){

	int i, j, len;
	extern int pos1, pos2;

	len = strlen(s);
	
	if(pos2 > 0 && len > pos2){
		len = pos2;
	}else if(pos2 > 0 && len < pos2){
		fprintf(stderr, "substr : string too short\n");	
	}

	for(j = 0, i = pos1; i < pos2 && (i < maxstr); i++, j++){
		str[j] = s[i];
	}
	str[j] = '\0';
	
	return;
}


