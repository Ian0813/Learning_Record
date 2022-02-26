/*
 * =====================================================================================
 *
 *       Filename:  find1.c
 *
 *    Description:  print lines that match pattern from 1st argument.
 *
 *        Version:  1.0
 *        Created:  2021年12月31日 21時23分20秒
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

#define MAXLINE 1000


int GetString(char *line){

	char ch;
	int len = 0;
	
	while((ch = getchar()) != EOF && ch != '\n' && (len+2) < MAXLINE){
		*line++ = ch;
		len++;
	}

	if(len > 0){
		*line++ = '\n';
		*line = '\0';
	}
	
	return len;		
}

void main(int argc, char *argv[]){

	char line[MAXLINE] = {0};
	long lineno = 0;	
	int found = 0, number = 0, except = 0, c;

	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0]){
			switch(c){
			    case 'x':
				    except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find illegal option %c\n", c);
					found = -1;
					break;
			}
		}
	}

	if(argc != 1){
		printf("Usage : find -x -n \"pattern\"\n");
		exit(EXIT_FAILURE);
	}

	while(GetString(line) > 0){
		lineno++;
		if((strstr(line, *argv) != NULL) != except){
			if(number){
				printf("%ld ", lineno);
			}
			printf("Find pattern %s in the line.\n", *argv);
			found++;
		}		
	}
}
