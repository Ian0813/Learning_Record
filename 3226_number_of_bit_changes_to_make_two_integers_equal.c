/*
 * =====================================================================================
 *
 *       Filename:  3226_number_of_bit_changes_to_make_two_integers_equal.c
 *
 *    Description:  number of bit changes to make two integers equal
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
#include <unistd.h>

typedef enum {false, true} bool;

#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))

static int get_nonzero_msbpos(int val) {

    int pos = -1;
    
    for (int i = 30; i >= 0; i--) {
        if ((val >> i) & 1) {
            pos = i;
            break;
        }
    }

    return pos;
}

int minChanges(int n, int k) {

    int msbpos = 0, changes = 0;
    bool is_zero = false, is_one = false;

    msbpos = get_nonzero_msbpos(MAX(n, k));

    for (int i = msbpos; i >= 0; i--) {

        is_zero = !((k >> i) & 1) ? true : false; 
        is_one = ((n >> i) & 1) ? true : false;

        if (is_zero && is_one) {
            n = ((n) ^ (1 << i));   
            changes++; 
        }
    }

    return (n == k) ? changes : -1;
}

int main(int argc, char *argv[]) {

    int n = -1, k = -1, opt = '?';

    while ((opt = getopt(argc, argv, "n:k:")) != -1) {

        switch (opt) {

            case 'n':
                n = atoi(optarg);
            break;   
            case 'k':
                k = atoi(optarg);
            break;   
        }
    }

    if (k == -1 || n == -1) {
        fprintf(stderr, "Please enusure the passed arguments are correct.\n");
        return EXIT_FAILURE; 
    }

    printf("min change: %d\n", minChanges(n, k));

    return EXIT_SUCCESS;
}
