/*
 * =====================================================================================
 *
 *       Filename:  2-4.c
 *
 *    Description:  Advance the squeeze function 
 *
 *        Version:  1.0
 *        Created:  2021年08月31日 23時19分10秒
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


void squeeze(char *s1, char *s2){
	
	int i, j, k, len = strlen(s1), count = 0;

	for( i = 0; i < strlen(s2); i++){
		for( k = j = 0; j < len; j++){
			if(s1[j] != s2[i]){
				s1[k++] = s1[j];	
			}else{
				count++;
			}
		}
		len -= count;
		count = 0;
	}

	if(strlen(s1) > len){
		int temp = strlen(s1);
		for(int index = len; index < temp; index++){
			s1[index] = '\0';
		}
	}
}


int main(int argc, char *argv){

    char str1[100] = "just a sentence.\n", str2[100] = "jte";

    printf("Before squeeze...\n");
    printf("%s", str1);
    squeeze(str1, str2);
    printf("After squeeze...\n");
    printf("%s", str1);

    return 0;
}

