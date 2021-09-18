/*
 * =====================================================================================
 *
 *       Filename:  290_word_pattern.c
 *
 *    Description:  Word Pattern    
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

#define SIZE 26

typedef unsigned int bool;
enum BOOL {false, true};

bool check_exist(char **table, char *token) {

    for (int i = 0; i < SIZE; i++) {
        if (table[i] != NULL && !strcmp(table[i], token)) {
            return true;
		}
	}
	return false;
}

bool wordPattern(char* pattern, char* s) {

	char *table[SIZE] = {NULL};
	char *token = NULL;
    char copy[BUFSIZ] = {0}, result[BUFSIZ] = {0};

    memcpy(copy, s, sizeof(char) * BUFSIZ);

	token = strtok(copy, " ");

	for (int i = 0; i < strlen(pattern); i++) {

        if (table[pattern[i]-97] == NULL && !check_exist(table, token)) {
            table[pattern[i]-97] = token;
		}

		token = strtok(NULL, " ");
		if (token == NULL)
            break;
    }

	for (int i = 0; i < strlen(pattern); i++) {
        if (table[pattern[i]-97] != NULL)
            strcat(result, table[pattern[i]-97]);
		if (i != strlen(pattern)-1) {
            strcat(result, " ");
		}
	}
	result[strlen(result)] = '\0';

    //fprintf(stdout, "%s\n", result);

	return strcmp(result, s) == 0 ? true : false; 
}

/*
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
*/

int main(void) {

    //char *pattern = "abba", s[BUFSIZ] = "dog cat cat dog";
    char *pattern = "abba", s[BUFSIZ] = "dog dog dog dog";
	bool rc = true;

	rc = wordPattern(pattern, s);

	fprintf(stdout, "%u\n", rc);

    return 0;
}
