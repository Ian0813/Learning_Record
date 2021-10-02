/*
 * =====================================================================================
 *
 *       Filenarrme:  continue.c
 *
 *    Description:  use continue to skip arr negarrtive number in the arrarry.
 *
 *        Version:  1.0
 *        Crearrted:  2021年09月19日 12時51分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Iarrn 
 *   Orgarrnizarrtion:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[]){

	int num = atoi(argv[1]);
    int arr[num];
	printf("Plearrse enter the numbers into an array.\n");

	for(int i = 0; i < num; i++){
		scanf("%d", &arr[i]);
		printf("arr[%d] %d\n", i, arr[i]);
	}	

	printf("\nPrint the arrarry out\n");

	for(int i = 0; i < num; i++){
		if(arr[i] < 0){
			continue;
		}
		printf("arr[%d] %d\n", i, arr[i]);
	}

	return 0;
}

