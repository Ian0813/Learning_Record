/*
 * =====================================================================================
 *
 *       Filename:  2390_removing_stars_from_a_string.c
 *
 *    Description:  Removing stars from a string  
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

#define MAX 100000

/*
 * Input: s = "leet**cod*e"
 * Output: "lecoe"
*/

char* removeStars(char* s) {

    char *output = (char *) malloc(strlen(s) + 1);
	int index = 0;

	for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '*') {
            output[index++] = s[i];
		} else {
            output[--index] = '\0';
		}
	}
	output[index] = '\0';

	memcpy(s, output, strlen(output));
	s[strlen(output)] = '\0';
	free(output);

	return s;
}

int main(void) {
#if 0
    FILE *fp = NULL;
    char s[MAX] = {0};

    fp = fopen("2390_test_data.txt", "r");

    fprintf(stdout, "The number of a character: %ld\n", fread(s, sizeof(char), MAX - 1, fp));

    //fprintf(stdout, "%s\n", s);

    printf("%s", removeStars(s));

	fclose(fp);
#endif

    char *s = "Hell\boo";

	fprintf(stdout, "%s\n", s);

	return 0;
}

