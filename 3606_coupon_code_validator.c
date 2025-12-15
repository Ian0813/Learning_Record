/*
 * =====================================================================================
 *
 *       Filename:  3606_coupon_code_validator.c
 *
 *    Description:  coupon code validator
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/** 3606. Coupon Code Validator
 * You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.


Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

First coupon is valid.
Second coupon has empty code (invalid).
Third coupon is valid.
Fourth coupon has special character @ (invalid).
Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]

Explanation:

First coupon is inactive (invalid).
Second coupon is valid.
Third coupon has invalid business line (invalid).


Constraints:

n == code.length == businessLine.length == isActive.length
1 <= n <= 100
0 <= code[i].length, businessLine[i].length <= 100
code[i] and businessLine[i] consist of printable ASCII characters.
isActive[i] is either true or false.

Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

#define MAXIMUM_SIZE 100

typedef enum {
    BU_NONE = -1,
    BU_ELECTRONICS = 0,
    BU_GROCERY = 1,
    BU_PHARMACY = 2,
    BU_RESTAURANT = 3,
    BU_NODELEN
} BU_NODETYPE;

typedef struct {
    char *business;
    char *codes[MAXIMUM_SIZE];
    int codes_len;
} businessNode;

static void swap(char **s1, char **s2) {

    char *temp = *s1; 

    *s1 = *s2;
    *s2 = temp;
    return;
}

static void quick_sort(char **strs, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (strcmp(strs[head], strs[tail]) > 0) {
                last++; 
                swap(&strs[last], &strs[tail]);
                continue;
            }
            tail--;
        }

        swap(&strs[head], &strs[last]);
        quick_sort(strs, head, last-1);
        quick_sort(strs, last+1, end);
    }    
    return;
}

static bool code_valid(char *code, bool active) {

    bool rc = false;
    int len = 0; 

    if (!active || !code) {
        return rc;     
    }

    len = strlen(code);

    if (!len) return rc;

    for (int i = 0; i < len; i++) {
        if (!(isalnum(code[i]) || code[i] == '_')) {
            return rc; 
        }
    }

    rc = true;
    return rc;
}

static BU_NODETYPE get_nodetype(char *bu) {

    BU_NODETYPE type = BU_NONE;

    if (!strcmp("electronics", bu)) {
        type = BU_ELECTRONICS;
    } else if (!strcmp("grocery", bu)) {
        type = BU_GROCERY;
    } else if (!strcmp("pharmacy", bu)) {
        type = BU_PHARMACY;
    } else if (!strcmp("restaurant", bu)) {
        type = BU_RESTAURANT;
    }
    return type;
}

static void bulist_getcodes(businessNode *bulist, char **code, char **businessLine, bool *isActive, int infoSize) {

    BU_NODETYPE type = BU_NONE;

    for (int i = 0; i < infoSize; i++) {

        type = get_nodetype(businessLine[i]); 

        if (type != BU_NONE && code_valid(code[i], isActive[i])) {
             bulist[type].codes[bulist[type].codes_len++] = code[i]; 
        }
    }
    return;
}

char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {

    char **result = NULL;

    businessNode businessList[BU_NODELEN] = {
        [BU_ELECTRONICS] = {.business = "electronics", NULL, 0},
        [BU_GROCERY] = {.business = "grocery", NULL, 0},
        [BU_PHARMACY] = {.business = "pharmacy", NULL, 0},
        [BU_RESTAURANT] = {.business = "restaurant", NULL, 0},
    };

    *returnSize = 0;
    result = (char **) calloc(MAXIMUM_SIZE, sizeof(char *));

    bulist_getcodes(businessList, code, businessLine, isActive, businessLineSize);

    for (int i = 0; i < BU_NODELEN; i++) {

        quick_sort(businessList[i].codes, 0, businessList[i].codes_len-1);

        for (int j = 0; j < businessList[i].codes_len; j++) {
            result[*returnSize] = strdup(businessList[i].codes[j]); 
            *returnSize += 1;
        }
    }

    return result;
}
