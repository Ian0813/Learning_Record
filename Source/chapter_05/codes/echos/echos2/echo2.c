/*
 * =====================================================================================
 *
 *       Filename:  echo2.c (pointer version)
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


/* echo : command-line arguments. 2nd version */
void main(int argc, char *argv[]){

	while(--argc > 0){
		printf("%s%s", *++argv, (argc > 1) ? " ": "");
	}
	printf("\n");
}

