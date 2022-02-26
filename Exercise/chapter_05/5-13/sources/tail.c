/*
 * =====================================================================================
 *
 *       Filename:  tail.c
 *
 *    Description:  The program should print the last n lines of its input.
 *
 *        Version:  1.0
 *        Created:  2022年01月09日 20時08分20秒
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
#include <stdbool.h>
#include <time.h>

/*  
	Type 1: For file read.
	Type 2: For file write.
*/

#define READ 1
#define WRITE 2

struct textinfo{
	
	int size;
	int columns;
};

void open_file(FILE **fp, int op){

	if(op == 1){
		*fp = fopen("t.txt", "r");
		if(fp == NULL){
			perror("fopen ");
			exit(EXIT_FAILURE);
		}
	}else if(op == 2){
		*fp = fopen("t.txt", "w");
		if(fp == NULL){
			perror("fopen ");
			exit(EXIT_FAILURE);
		}
	}

	return;
}

long get_file_size(FILE *fp){

	long size = 0;

	if(fseek(fp, 0L, SEEK_END) == -1){
		perror("fseek ");
		exit(EXIT_FAILURE);
	}

	if((size = ftell(fp)) == -1){
		perror("ftell ");
		exit(EXIT_FAILURE);		
	}

	if(fseek(fp, 0L, SEEK_SET) == -1){
		perror("fseek ");
		exit(EXIT_FAILURE);
	}

	return size;
}

void file_read(char *data, int size, FILE *fp, struct textinfo *info){
	
	int s = 0;

	while((s = fgetc(fp)) != EOF){
		
		info->size++;

		if(s == '\n'){
			info->columns += 1;
		}
		
		*data = s;
		data++;
	}

	if(s == EOF && info->size == 0){
		perror("fread ");
		exit(EXIT_FAILURE);
	}

	return;
}

int random_int(void){

	return  rand() % 26 + 65;
}

void file_write(int column, FILE *fp, struct textinfo *info){
	
	int r, newline = 10;
	info->columns = column;	

	while(column > 0){
	
		for(int i = 0; i < 10; i++){
			r = random_int();
			info->size += fwrite(&r, sizeof(char), 1, fp);
		}
		info->size += fwrite(&newline, sizeof(char), 1, fp);
		column--;
	}
	
	return;
}


void main(int argc, char *argv[]){
	
	//The default number of printed to ten columns.
	int columns = 10, type = 0, amount = 0, index = 0;
	long size;
	FILE *fp = NULL;
	char data[2048];
	struct textinfo info;

	memset(&info, 0, sizeof(struct textinfo));

	if(argc > 1){
		amount = argc;

		for(int i = 1; amount>1; i++, amount--){
			if(!strncmp("--", *(argv + i), 2)){
				if(!strcmp("type", (*(argv + i))+2)){
					type = atoi(*(++argv + i));
					amount -= i;
				}						
			}else if(!strncmp("-n", *(argv + i), 2)){
				columns = atoi(*(++argv + i));
				amount -= i;
			}
		}

		printf("type : %d\n", type);
		//printf("columns : %d\n", columns);

	}else{
		printf("The amount of argument is not enough.\n");	
	}


#if 1 
	srand(time(NULL));
	memset(data, 0, sizeof(data));

	if(type == WRITE){

		open_file(&fp, type);
		file_write(100, fp, &info);
		size = get_file_size(fp);
		printf("Write, size : %d, columns : %d\n", info.size, info.columns);

	}else if(type == READ){

		open_file(&fp, type);
		size = get_file_size(fp);
		file_read(data, size, fp, &info);
		printf("Read, size : %d, columns : %d\n", info.size, info.columns);

		for(int col = info.columns - columns; col > 0; index++){
			
			if(data[index] == '\n'){
				col--;
			}
		}

		while(columns > 0){

			printf("%c", data[index]);
			if(data[index] == '\n'){
				columns--;
			}
			index++;
		}
	}

	//file_read(data, (int) size, fp);
	//for(i = 0; *(data + i) != EOF; i++){
	//	printf("%c", *(data + i));
	//}

	//if(*(data + i) == EOF){
	//	printf("-1\n");
	//}
	//printf("size %ld\n", size);
	fclose(fp);


	//if(argc > 2){

	//}
#endif	
	return;	
}

