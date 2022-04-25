/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  Small test
 *
 *        Version:  1.0
 *        Created:  2022年03月15日 00時33分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#if 0
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void *greeting(void *s){

	char *str = (char *) s;	
	printf("thread id : %ld\n", pthread_self());
	puts(str);
	pthread_exit(EXIT_SUCCESS);
}

void main(void){
	
	pthread_t pid; 
	fprintf(stdout, "Testing...\n");
	char *s = "Hello, how are you ? ";
	printf("greeting : %p\n", greeting);
	printf("greeting address : %p\n", &greeting);

	if(pthread_create(&pid, NULL, &greeting, (void *) s) != 0){
		perror("pthread create ");
		exit(EXIT_FAILURE);
	}

	pthread_join(pid, NULL);

	return;	
}
#endif
