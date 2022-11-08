/*
 * =====================================================================================
 *
 *       Filename:  isupper.c
 *
 *    Description:  Implement the isupper() function in two aspects that save time and 
 *                  save space. 
 *
 *        Version:  1.0
 *        Created:  2022年11月08日 00時35分51秒
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

#define SAVE_SPACE

/* The implementation for saving time. */ 
#define isupper_v2(c) (((c) >= 'A' && (c) <= 'Z') ? 1 : 0 )

/* The implementation for saving space. */
/* isupper_v1: return 1 (true) if c is an upper case letter */
int isupper_v1(char c) {

    printf("enter to %s function.\n", __func__);

    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    char ch;
    
    while(printf("Input a character: \n"), (ch = getchar()) != EOF) {
#ifdef SAVE_TIME  
        if (isupper_v2(ch)) {
#elif defined(SAVE_SPACE)
        if (isupper_v1(ch)) {
#endif
            printf("[%ld] %c is uppercase.\n", time(NULL), ch);
        } else {
            printf("[%ld] %c is lowercase.\n", time(NULL), ch);
        }
        getchar();
    }

    return 0;
}

