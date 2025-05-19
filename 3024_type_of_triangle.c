/*
 * =====================================================================================
 *
 *       Filename:  3024_type_of_triangle.c
 *
 *    Description:  type of triangle
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

#define EQUILATERAL "equilateral"      
#define ISOSCELES "isosceles"      
#define SCALENE "scalene"
#define NONE "none"

#define SIDES 3
#define IS_ALL_EQUAL(nums) (((nums[0]) == (nums[1])) && ((nums[1]) == (nums[2])))
#define IS_ALL_DIFF(nums) (((nums[0]) != (nums[1])) && ((nums[1]) != (nums[2])) && ((nums[0] != nums[2])))
#define IS_VALID(nums) ((((nums[0]) + (nums[1])) > nums[2]) || (((nums[1]) + (nums[2])) > nums[0]) || ((nums[0]+nums[2]) > nums[1]))

char* triangleType(int* nums, int numsSize) {

    char *type = NULL;

    if (numsSize == SIDES) {
        if (IS_ALL_EQUAL(nums)) {
            type = EQUILATERAL;
        } else if (IS_ALL_DIFF(nums)) {
            type = SCALENE;
        } else {
            type = ISOSCELES;  
        }
    }

    if (!IS_VALID(nums)) {
        type = NONE;
    }
    return type;
}
