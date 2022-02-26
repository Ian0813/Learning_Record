/*
 * =====================================================================================
 *
 *       Filename:  echo1.c
 *
 *    Description:  Display the argument list and separate each string by a blank.
 *
 *        Version:  1.0
 *        Created:  2021年12月29日 22時58分17秒
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

void main(int argc, char *argv[]){

	int i;

	for(i = 1; i < argc; i++){
		printf("%s%s", argv[1], (i < argc-1) ? " ":"");
	}
	printf("\n");
}

