/*
 * =====================================================================================
 *
 *       Filename:  860_lemonade_change.c
 *
 *    Description:  lemonade change   
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

typedef unsigned int bool;
enum BOOL {false, true};

enum PAYS {
    FIVE = 5,
	TEN = 10,
	TWENTY = 20
};

#define MAX 21

bool lemonadeChange(int* bills, int billsSize) {

    int table[MAX] = {0};
	int flag = true;

	for (int i = 0; i < billsSize; i++) {
        table[bills[i]]++;
        switch(bills[i]) {
			case FIVE:
                break;
            case TEN:
                flag = table[FIVE]-- > 0 ? true : false;
				break;
            case TWENTY:
                flag = table[FIVE]-- > 0 ? true : false;
                if (!table[TEN] && table[FIVE] > 1) {
                    table[TEN] = 1;
					table[FIVE] -= 2;
				}
                flag = flag && (table[TEN]-- > 0 ? true : false);
				break;
            default:
				break;
		}
		if (!flag)
            return flag;
	}
	return flag;
}


int main(void) {

    int bills1[5] = {5,5,5,10,20};
    int bills2[5] = {5,5,10,10,20};

	printf("%d\n", lemonadeChange(bills1, 5));
	printf("%d\n", lemonadeChange(bills2, 5));

	return 0;
}

