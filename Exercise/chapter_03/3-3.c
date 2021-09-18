/*
 * =====================================================================================
 *
 *       Filename:  3-3.c
 *
 *    Description:  expand(s1, s2)
 *    				the function expand() expands shorthand notation like a-z in the 
 *    				string s1 into the equivalent complete list abc...xyz in s2. 
 *
 *        Version:  1.0
 *        Created:  2021年09月14日 22時53分14秒
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
#define MAX(x, y) x > y ? x : y;
#define MIN(x, y) x < y ? x : y;

void expand(char *s1, char *s2){

	char c1, c2, index;

	for(int i =0, j = 1, index = 0; j < strlen(s1); i += 2, j+=2){
		
		c1 = MAX(s1[i], s1[j]);
		c2 = MIN(s1[i], s1[j]);

		for(int k = c2; k <= c1; k++, index++){
			s2[index] = k; 
		}
	}
}

int main(int argc, char *argv[]){


 	int len, index = 0, size = 0;	
	char *strlist, *newlist;
	char c1, c2; 

	if(argc > 1){
		len = strlen(argv[1]);
		strlist = (char *) malloc(strlen(argv[1]) * sizeof(char));
		memset(strlist, 0, len * sizeof(char));
		for(int i = 0; i < len; i++){
			if(argv[1][i] != '-'){
				strlist[index] = argv[1][i];
				index++;
			}
		}
		printf("Expanding this string %s to the complete list.\n", argv[1]);
		printf("strlist = %s\n", strlist);
		for(int i = 0, j = 1; j < strlen(strlist); i+=2, j+=2){
			c1 = MAX(strlist[i], strlist[j]);
			c2 = MIN(strlist[i], strlist[j]);
			size += c1 - c2 + 1;
		}
		printf("size : %d\n", size);
		newlist = (char *) malloc((size + 1) + sizeof(char)); 
		memset(newlist, 0, sizeof(char) * (size + 1));
		expand(strlist, newlist);
		printf("Show newlist\n");
		printf("%s\n", newlist);
	}else{
		printf("Please enter the argument.\n");
	}

	if(strlist){
		free(strlist);
	}

	if(newlist){
		free(newlist);
	}

	return 0;
}
