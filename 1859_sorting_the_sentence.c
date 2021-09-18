/*
 * =====================================================================================
 *
 *       Filename:  1859_sorting_the_sentence.c
 *
 *    Description:  Sorting the sentence 
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX 10

int retrieve_number(char *s) {

    int number = 0; 
	int index = 0, mark = -1;

    for (index = 0; index < strlen(s); index++) {
        if (isdigit(s[index])) {
            mark = mark == -1 ? index : mark; 
            number = number * 10 + (s[index] - 48);
		}
    }
	s[mark] = '\0';
    return number;
}

char * sortSentence(char * s){

    char *arrays[MAX] = {NULL};
	char *part = NULL, *result = NULL; 
	int max = 0, index = 0; 

	//result = (char *) calloc(strlen(s) + 1, sizeof(char));
	result = (char *) malloc((strlen(s) + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (strlen(s) + 1));

	part = strtok(s, " ");

	while (part != NULL) {
        index = retrieve_number(part);
        arrays[index] = part; 
		part = strtok(NULL, " ");
        if (index > max) {
            max = index;
		}
	}

	for (int i = 1; i < max; i++) {
        strcat(result, arrays[i]); 
		strcat(result, " ");
	}
    strcat(result, arrays[max]); 
	return result;
}


int main(void) {

    char s[BUFSIZ] = "is2 sentence4 This1 a3";

	char *rc = NULL;

	rc = sortSentence(s);

	printf("%s\n", rc);
	free(rc);

	return 0;
}

