/*
 * =====================================================================================
 *
 *       Filename:  70_climbing_stairs.c
 *
 *    Description:  Climbing stairs (like hanno tower)   
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* result 1 if n = 1, 2 if n = 2, ....*/

#define SLOTS 45

#if 0
int calculate(int n) {
    if (n == 1) {
        return 1;
    }
    return calculate(n - 1) + calculate(n - 2);
}
#endif

static unsigned int tables[SLOTS];

int climbStairs(int n) {
    return tables[n-1] + tables[n-2];
}

void fill_tables(void) {

    tables[0] = 1;
	tables[1] = 2;

	for (int i = 2; i < SLOTS; i++) {
        tables[i] = tables[i -1] + tables[i -2]; 
	}
	return;
}

int main(void) {

	fill_tables();
	for (int i = 0; i < SLOTS; i++) {
        printf("tables[%d]: %d\n", i, tables[i]);
	}
    printf("climbStairs[%d]: %d\n", rand()%46, climbStairs(rand()%46));
    return 0;
}

