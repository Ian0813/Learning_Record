/*
 * =====================================================================================
 *
 *       Filename:  1047_remove_all_adjacent_duplicates_in_string.c
 *
 *    Description:  Remove all adjacent duplicates in string 
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 *
 * =====================================================================================
 */

/* Example:
 * Input: s = "abbaca"
 * Output: "ca"
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char* removeDuplicates(char* s) {

    char *result = (char *) calloc(sizeof(char), strlen(s) + 1);
	int index = 0;


    for (int i = 0; i < strlen(s); i++) {
        if (index > 0 && s[i] == result[index-1]) {
            result[index-1] = '\0';  
			index -= 1;
		} else {
            result[index++] = s[i];
		}
	}
	return result;
}

int main(void) {

    char *input = "abbaca";
	char *rc = NULL;

	rc = removeDuplicates(input);

	fprintf(stdout, "%s\n", rc);

	free(rc);

	return 0;
}

