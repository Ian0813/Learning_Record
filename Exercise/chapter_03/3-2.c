/*
 * =====================================================================================
 *
 *       Filename:  3-2.c
 *
 *    Description:  Convert character like newline and tab into visible escape sequences  
 *  				like \n and \t as it copies the string t to s.
 *
 *        Version:  1.0
 *        Created:  2021年09月11日 19時49分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 


void escape(char *s, char *t){

	int sindex = 0, tindex = 0;

	for(sindex; sindex < strlen(s); sindex++){

		switch(s[sindex]){

			case '\a':
				t[tindex++] = '\\';
				t[tindex++] = 'a';
				break;
			case '\b':
				t[tindex++] = '\\';
				t[tindex++] = 'b';
				break;
			case '\f':
				t[tindex++] = '\\';
				t[tindex++] = 'f';
				break;
			case '\n':
				t[tindex++] = '\\';
				t[tindex++] = 'n';
				break;
			case '\r':
				t[tindex++] = '\\';
				t[tindex++] = 'r';
				break;
			case '\t':
				t[tindex++] = '\\';
				t[tindex++] = 't';
				break;			
			case '\v':
				t[tindex++] = '\\';
				t[tindex++] = 'v';
				break;	
			case '\\':
				t[tindex++] = '\\';
				t[tindex++] = '\\';
				break;
			case '\?':
				t[tindex++] = '\\';
				t[tindex++] = '\?';
				break;
			case '\'':
				t[tindex++] = '\\';
				t[tindex++] = '\'';
				break;
			case '\"':
				t[tindex++] = '\\';
				t[tindex++] = '"';
				break;
			default:
				printf("Not a escape character.\n");
				break;
		}

	}
}

int main(int argc, char *argv[]){
	
	char *s, *t;
	int slen, tlen, i;

	if(argc > 1){
		slen = atoi(argv[1]);
		tlen = (slen * 2) - 1;

		s = (char *) malloc(sizeof(char) * 10);
		memset(s, 0, slen);
		for(i = 0; i < slen - 1; i++){
			*(s + i) = getchar();
		}
		t = (char *) malloc(sizeof(char) *  tlen);
		memset(t, 0, tlen);
		
		printf("Converting...\n");
		escape(s, t);
		printf("Result %s\n", t);
		free(s);
		free(t);
	}else{
		printf("Please enter the correct arguments.\n");
	}

	return 0; 
}

