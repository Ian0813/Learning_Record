/*
 * =====================================================================================
 *
 *       Filename:  word_count.c
 *
 *    Description:  Count the words with a switch
 *
 *        Version:  1.0
 *        Created:  2021年09月11日 18時04分08秒
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


int main(){

	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	memset(ndigit, 0, sizeof(ndigit));


	while((c - getchar()) != EOF){
		switch(c){

			case '0': case '1': case '2': 
			case '3': case '4': case '5': 
		    case '6': case '7': case '8': 
			case '9': 
    			ndigit[c - '0']++;
			    break;	
			case ' ': 
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;	
		}
	}

	printf("digits : \n");
	for(i = 0; i < 10; i++){
		printf("[%d] = %d\n", i, ndigit[i]);
	}
	printf("white space : %d, other : %d\n", nwhite, nother);

	return 0;
}

