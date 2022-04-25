/*
 * =====================================================================================
 *
 *       Filename:  data_generator.c
 *
 *    Description:  Generate a set of data for the quick sort numerically testing. 
 *
 *        Version:  1.0
 *        Created:  2022年01月29日 12時48分03秒
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
#include <time.h> 
#include <math.h>


void reverse(char *str, int len){
    
    int i, j;
    char ch;
    i = 0;
    j = len -1;
    
    for(; i < j; i++, j--){
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}


void double_to_string(double num, char *str){
    
    double temp = num;
    char fraction[10];
    double additional = 0;
    long positive = 1, partition = 0;
	partition = num/1;
	//printf("partition : %ld\n", partition);
    for(int i = 0; partition > 0; i++){
        str[i] = (partition%10) + '0'; 
        partition /= 10;
		positive *= 10;
    }
	partition = num/1;
    //printf("str : %s\n", str);
    reverse(str, strlen(str));
    //printf("str : %s\n", str);
	num -= partition;
	//printf("num : %.015f\n", num);

    //additional = atof(str)/positive;
    //printf("additional : %f\n", additional);
    //num = (num - additional) * positive;
	if(num > 0){
		str[strlen(str)] = '.';
	   	str[strlen(str)] = '\0';
		for(int i = 0, len = strlen(str); i < 6; i++){
			num *= 10;
			//printf("num : %f\n", num);
			partition = num/1;
			partition %= 10;
			str[len + i] = (partition % 10) + '0';
		}
		str[strlen(str)] = '\n';
		str[strlen(str)] = '\0';
		return;
	}else{
		return;
	}
	
    //printf("additional : %f\n", additional);
    //printf("num - t : %f\n", (num - additional)*positive);
	
}

void main(int argc, char *argv[]){
	
	int amount = 0;
	double num;
	char nvalue[30];

	srand48(time(NULL));
	srand(time(NULL));

	if(argc > 1){

		amount = atoi(argv[1]);
		FILE *fp = NULL;

		fp = fopen("data.txt", "w");
		if(fp == NULL){
  			perror("fopen ");
			exit(EXIT_FAILURE);
		}

		for(int i = 0; i < amount; i++){
			memset(nvalue, 0, sizeof(nvalue));
			num = fmod((rand() * drand48()), 100001);
			double_to_string(num, nvalue);
			printf("[%d] %s", i, nvalue);
			if(fwrite(&nvalue, 1, strlen(nvalue), fp) <= 0){
				perror("fwrite ");
				exit(EXIT_FAILURE);
			}
		}
		
		fclose(fp);

		printf("File writing successful !!!\n");

	}else{
		printf("Please enter the correct parameters. (The amout of a columns.)\n");
		exit(EXIT_FAILURE);
	}

	return;
}	
