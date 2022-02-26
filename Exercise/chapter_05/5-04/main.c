/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The main function for testing the strend().
 *
 *        Version:  1.0
 *        Created:  2021年11月21日 15時38分56秒
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

void strend(char *, char *);

int main(int argc, char *argv[]){


	strend(argv[1], argv[2]);

	return 0;
	
}

