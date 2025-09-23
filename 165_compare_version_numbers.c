/*
 * =====================================================================================
 *
 *       Filename:  165 compare version numbers.c
 *
 *    Description:  compare version numbers
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

#define CH_TO_INT(ch) ((ch)-'0')

typedef enum {
    COMPARISON_LESS = -1,
    COMPARISON_EQUAL = 0,
    COMPARISON_GREATER = 1
} comparison_type;

typedef struct split_version {
    int ver_array[BUFSIZ];
    int ver_size;
} sp_version;

static int str_to_int(char *s) {

    int value = -1;
    int len = 0, count_zero = 0; 

    if (!s)
        return value;

    len = strlen(s);
    value = 0;

    if (s[0] == '0') {
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                count_zero++;
                continue;
            }
            break;
        }
    }

    for (int i = count_zero; i < len; i++) {
        value *= 10; 
        value += CH_TO_INT(s[i]);
    }    

    return value;
}    

static void sp_version_init(char *version, sp_version *v) {

    char str[BUFSIZ] = {0}, *ptr = NULL;

    memcpy(str, version, strlen(version));

    if (!v)
        return;

    if (!version) {
        v->ver_array[0] = 0;
        v->ver_size = 1;
    } else {

        ptr = strtok(str, ".");      

        while (ptr) {
            v->ver_array[v->ver_size++] = str_to_int(ptr);    
            ptr = strtok(NULL, ".");
        }
    }
    return;
}

static comparison_type sp_version_compare(sp_version *v1, sp_version *v2) {

    comparison_type rc = COMPARISON_EQUAL, expected = COMPARISON_EQUAL;
    int comp_len = 0, index = 0;
    sp_version *temp = NULL;

    if (!v1 || !v2)
        return rc;

    comp_len = v1->ver_size > v2->ver_size ? v2->ver_size : v1->ver_size; 

    for (index = 0; index < comp_len; index++) {
        if (v1->ver_array[index] > v2->ver_array[index]) {
            rc = COMPARISON_GREATER;
            break;
        } else if (v1->ver_array[index] < v2->ver_array[index]) {
            rc = COMPARISON_LESS; 
            break;
        }
    }

    if (rc == COMPARISON_EQUAL) {

        if (index < v1->ver_size) {
            temp = v1;
            expected = COMPARISON_GREATER;
        } else if (index < v2->ver_size) {
            temp = v2;
            expected = COMPARISON_LESS;
        }

        if (temp)
            for (index; index < temp->ver_size; index++) {
                if (temp->ver_array[index]) {
                    rc = expected;
                    break;
                }
            }
    }

    return rc;
}

int compareVersion(char* version1, char* version2) {

    sp_version v1 = {0}, v2 = {0};
    int rc = 0;

    sp_version_init(version1, &v1);
    sp_version_init(version2, &v2);

    fprintf(stdout, "version1:\n");
    for (int i = 0; i < v1.ver_size; i++) {
        printf("%d ", v1.ver_array[i]);
    }
    putchar('\n');

    fprintf(stdout, "version2:\n");
    for (int i = 0; i < v2.ver_size; i++) {
        printf("%d ", v2.ver_array[i]);
    }
    putchar('\n');

    rc = sp_version_compare(&v1, &v2);
    
    return rc;
}
