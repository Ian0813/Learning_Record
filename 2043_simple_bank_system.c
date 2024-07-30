/*
 * =====================================================================================
 *
 *       Filename:  2043_simple_bank_system.c
 *
 *    Description:  Simple bank system  
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

typedef enum {false, true} bool; 

typedef struct {
    long long *balance;    
    int balanceSize;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {

    Bank *obj = NULL;

    if (balanceSize) {
        obj = (Bank *) malloc(sizeof(Bank));
        obj->balance = balance;
        obj->balanceSize = balanceSize;
    }
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {

    bool rc = true; 

    if (obj) {
        if (account1 <= obj->balanceSize && account2 <= obj->balanceSize) {
            if (obj->balance[account1-1] >= money) {
                obj->balance[account1-1] -= money;
                obj->balance[account2-1] += money;
            } else {
                goto FALSE_POINT;
            }
        } else {
            goto FALSE_POINT;        
        }
    } else {
FALSE_POINT:;
        rc = false;
    }
    return rc;
}

bool bankDeposit(Bank* obj, int account, long long money) {

    bool rc = true;

    if (obj) {
        if (account <= obj->balanceSize) {
            obj->balance[account-1] += money;            
        } else {
            goto FALSE_POINT; 
        }
    } else {
FALSE_POINT:;
        rc = false;
    }
    return rc;  
}

bool bankWithdraw(Bank* obj, int account, long long money) {

    bool rc = true;

    if (obj) {
        if (account <= obj->balanceSize) {
            if (obj->balance[account-1] >= money) {
                obj->balance[account-1] -= money;
            } else {
                goto FALSE_POINT;  
            }
        } else {
            goto FALSE_POINT;
        }
    } else {
FALSE_POINT:;
        rc = false;
    }
    return rc;
}

void bankFree(Bank* obj) {

    if (obj) {
        free(obj); 
    }
    return;
}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);
 
 * bool param_2 = bankDeposit(obj, account, money);
 
 * bool param_3 = bankWithdraw(obj, account, money);
 
 * bankFree(obj);
*/

