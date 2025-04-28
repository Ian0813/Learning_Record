/*
 * =====================================================================================
 *
 *       Filename:  2525_categorize_box_according_to_criteria.c
 *
 *    Description:  categorize box according to criteria
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

#define GET_VOLUME(l, h, w) ((l)*(h)*(w)*1LL)

#define IS_GE(value, boundary) ((value)>=(boundary))
#define IS_BULKY(l, w, h, m, volume) (((IS_GE(l, 10000)) || (IS_GE(w, 10000)) || (IS_GE(h, 10000)) || (IS_GE(m, 10000))) || (volume>=1000000000LL))
#define IS_HEAVY(m) ((m)>=100)

struct shape_info {
    long long length, width, height, mass;
    long long volume; 
};

enum {
    TYPE_NEITHER = 0,
    TYPE_BULKY = 1,
    TYPE_HEAVY = 2,
    TYPE_BOTH = 3
};


static char *get_category(struct shape_info *cube, char *types[]) {

    char *ptr = NULL;

    if (IS_BULKY(cube->length, cube->width, cube->height, cube->mass, cube->volume) && IS_HEAVY(cube->mass)) {
        ptr = strdup(types[TYPE_BOTH]);
    } else if (IS_BULKY(cube->length, cube->width, cube->height, cube->mass, cube->volume)) {
        ptr = strdup(types[TYPE_BULKY]);
    } else if (IS_HEAVY(cube->mass)) {
        ptr = strdup(types[TYPE_HEAVY]);
    } else {
        ptr = strdup(types[TYPE_NEITHER]);
    }
    return ptr;
}

char* categorizeBox(int length, int width, int height, int mass) {

    char *result = NULL;

    static char *category_types[] = {
        [TYPE_NEITHER] = "Neither",
        [TYPE_BULKY] = "Bulky",
        [TYPE_HEAVY] = "Heavy",
        [TYPE_BOTH] = "Both"
    };

    struct shape_info cube = {.length = (long long) length, .height = (long long) height, .width = (long long) width, .mass = (long long) mass};

    cube.volume = GET_VOLUME(cube.length, cube.height, cube.width); 

    result = get_category(&cube, category_types);
    return result;
}

int main(void) {
    return EXIT_SUCCESS;
}
