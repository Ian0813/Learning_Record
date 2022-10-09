/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  testing
 *
 *        Version:  1.0
 *        Created:  2022年10月08日 15時21分39秒
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

char *ex_fgets(char *, int, FILE *);

/* Note: The dollar sign in a text file means EOL (End of line), which is a combination of CR (carriage return) and LF (line feed). */ 

int main(void) {

    FILE *fp = fopen("t.txt", "r");
    char buffer[100];

	memset(buffer, 0, sizeof(buffer));

	if (ex_fgets(buffer, 13, fp) != NULL) {
        printf("buffer: %s", buffer);
	}

	fclose(fp);

    return 0;
}

