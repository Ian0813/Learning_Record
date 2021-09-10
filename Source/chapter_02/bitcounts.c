/*
 * =====================================================================================
 *
 *       Filename:  bitcounts.c
 *
 *    Description:  Counts the number of 1-bits in its integer argument
 *
 *        Version:  1.0
 *        Created:  2021年09月04日 17時40分17秒
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




int bitcounts(unsigned int x){

	int b;

	for(b = 0; x != 0; x >>= 1){
		if(x & 01){
			b++;
		}
	}

	return b;
}





int main(int argc, char *argv[]){

}	
