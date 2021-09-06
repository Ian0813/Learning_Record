/*
 * =====================================================================================
 *
 *       Filename:  2-5.c
 *
 *    Description:  Return the first location in the string s1 where any character from 
 *    				the string s2 occurs, or -1 if s1 contains no characters from s2.
 *
 *        Version:  1.0
 *        Created:  2021年09月01日 07時26分32秒
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



int any(char *s1, char *s2){

	char ch;

	for(int i = 0; i < strlen(s2); i++){
		
		for(int j = 0; j < strlen(s1); j++){
			if(s2[i] == s1[j]){
				return j;
			}	
		}
	}

	return -1; 
}


int main(int argc, char *argv[]){

	int position;	
	if(argc > 2){
		
		position = any(argv[1], argv[2]);
	}else{
		printf("Please enter the correct arguments.\n");
	}

	if(position > -1){
		printf("Find the same character from s2 at position %d of s1.\n", position);
	}else{
		printf("Not find !!!\n");				
	}


	return 0;

}




