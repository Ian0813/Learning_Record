/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  Handle a pointer by the increment operator.
 *
 *        Version:  1.0
 *        Created:  2022年01月15日 12時47分21秒
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


int main(int argc, char *argv[]){

//	printf("%s\n", *(argv+1));

	//printf("%s\n", *(++argv+1));

	char (*str)[];
	printf("%ld\n", sizeof(str));

	//str = (char *) malloc(4); 
	//printf("%ld\n", sizeof(str));
	*str = "Hello";
	//printf("%s\n", *str);
	//*++str = "world";
	//
	//printf("%s\n", *str);
	//str--;
	//for(int i = 0; i < 10; i++){
	//	free(*str);
	//	str++;
	//}
	//str--;	
	//free(str);
	//++str;
	//free(str);
	//str++;
	//free(*str);


	return 0;
}
