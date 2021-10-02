/*
 * =====================================================================================
 *
 *       Filename:  goto.c
 *
 *    Description:  Consider the problem of determining whether two arrays a and b have
 *    				an element in common.
 *
 *        Version:  1.0
 *        Created:  2021年09月19日 15時54分48秒
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


int main(int argc, char *argv[]){


	int common = 0;
	int a[10] = {0}, b[10] = {0};

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(a[i] == b[j]){
				common = 1;
				goto found;
			}
		}
	}	

found:
	if(common == 1){
		printf("Found a common value.\n");
	}else{
		printf("Not found\n");
	}

	return 0;

}





