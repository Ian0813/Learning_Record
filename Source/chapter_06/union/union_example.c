/*
 * =====================================================================================
 *
 *       Filename:  union_example.c
 *
 *    Description:  union type example
 *
 *        Version:  1.0
 *        Created:  2022年08月03日 00時02分38秒
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

union hybrid {
	int val;
	float num;
	char str[100];
	long long big_num;
} tags;

void main(int argc, char *argv[]) {
		
	char ch = 0; 

	if (argc < 2) {
		fprintf(stdout, "Please enter a correct argument.\n");
		exit(EXIT_FAILURE);
	} else {
		
		if (!strcmp(argv[1], "int")) {

			scanf("%d", &tags.val);
			printf("tags : %d\n", tags.val);

		} else if (!strcmp(argv[1], "float")) {

			scanf("%f", &tags.num);
			printf("tags : %f\n", tags.num);

		} else if (!strcmp(argv[1], "string")) {

			scanf("%s", tags.str);
			printf("tags : %s\n", tags.str);

		} else if (!strcmp(argv[1], "long")) {

			scanf("%lld", &tags.big_num);
			printf("tags : %lld\n", tags.big_num);

		}

		printf("The union tags size is : %ld\n", sizeof(tags));
	}

	return;
}
