/*
 * =====================================================================================
 *
 *       Filename:  2024_08_19_1137_n_th_tribonacci_number.c
 *
 *    Description:  N th tribonacci number  
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

#define TABLE_SIZE 38

int tribonacci_table[TABLE_SIZE] = {0, 1, 1};

static int get_tribonacci(int n) {
    return tribonacci_table[n]; 
}

static void fill_table(void) {
    for (int i = 3; i < TABLE_SIZE; i++) {
        tribonacci_table[i] = tribonacci_table[i-3] + tribonacci_table[i-2] + tribonacci_table[i-1];
    }
    return;
}    

int tribonacci(int n){
    fill_table();
    return tribonacci_table[n];
}
