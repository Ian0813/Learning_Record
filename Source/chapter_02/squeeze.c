/*
 * =====================================================================================
 *
 *       Filename:  squeeze.c
 *
 *    Description:  Remove all occurrences of the character c from the string s 
 *
 *        Version:  1.0
 *        Created:  2021年08月31日 23時05分42秒
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


/* squeeze : delete all c from s */
void squeeze(char *s, int c){
	int i, j;

	for(i = j = 0; s[i] != '\0'; i++){
		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}


int main(int argc, char *argv[]){
	
	char str[100] = "just a sentence.\n"; 

	printf("Before squeeze...\n");
	printf("%s", str);
	squeeze(str, 32);
	printf("After squeeze...\n");
	printf("%s", str);

	return 0;
}


