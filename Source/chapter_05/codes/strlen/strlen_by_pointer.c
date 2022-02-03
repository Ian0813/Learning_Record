/*
 * =====================================================================================
 *
 *       Filename:  strlen_by_pointer.c
 *
 *    Description:  To compute a string length by a pointer subtraction.
 *
 *        Version:  1.0
 *        Created:  2021年11月28日 21時00分20秒
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



int strlenByPointer(char *s){

	char *ptr = s;

	while(*s != '\0'){
		s++;
	}

	return s - ptr;
}



int main(int argc, char *argv[]){


	if(argc > 1){
		printf("The string : %s\n", argv[1]);
		printf("The string its length : %d\n", strlenByPointer(argv[1]));
	}else{
		puts("Please enter a string as your parameter.\n");
	}

	return 0;
}

