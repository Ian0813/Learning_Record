/*
 * =====================================================================================
 *
 *       Filename:  1523_count_odd_numbers_in_an_interval_range.c
 *
 *    Description:  count odd numbers in an interval range
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

#define IS_ODD(val) (((val)%2))

typedef enum {
    DIGIT_EVEN_EVEN = 0,
    DIGIT_ODD_EVEN = 1,
    DIGIT_EVEN_ODD = 2,
    DIGIT_ODD_ODD = 3
} digit_combo_t;

static digit_combo_t get_digit_combo(int low, int high) {

    digit_combo_t combo = DIGIT_EVEN_EVEN;

    if (IS_ODD(low) && IS_ODD(high)) {
        combo = DIGIT_ODD_ODD;
    } else if (IS_ODD(low)) {
        combo = DIGIT_ODD_EVEN;
    } else if (IS_ODD(high)) {
        combo = DIGIT_EVEN_ODD;
    }

    return combo;
}

int countOdds(int low, int high){

    int count = 0, range = 0;
    digit_combo_t opt = -1;

    opt = get_digit_combo(low, high);
    range = (low != high) ? ((high-low) - 1) : 0;

    if (!range) {

        if (high == (low+1)) {
            count = IS_ODD(high) ? count + 1 : count;
        }

        count = IS_ODD(low) ? count + 1 : count;
        goto EXIT_POINT;
    }

    printf("combo : %d\n", opt);

    switch (opt) {

        case DIGIT_EVEN_EVEN:
            count = (range/2) + 1;
        break;

        case DIGIT_ODD_EVEN:
        case DIGIT_EVEN_ODD:
            count += 1;
            count += (range/2);
        break;

        case DIGIT_ODD_ODD:
            count += 2;
            count += (range/2);
        break;
    }

EXIT_POINT:;
    return count;
}
