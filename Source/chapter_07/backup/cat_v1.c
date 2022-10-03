/*
 * =====================================================================================
 *
 *       Filename:  cat_v1.c 
 *
 *    Description:  concatenate files, version 1
 *
 *        Version:  1.0
 *        Created:  2022年09月19日 23時04分53秒
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

int main(int argc, char *argv[]) {

    FILE *fp = NULL;
	void filecopy(FILE *, FILE *);

	if (argc == 1) {    /* no args: copy standard input */
       filecopy(stdin, stdout); 
	} else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
				return 0;
			} else {
                filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
}
