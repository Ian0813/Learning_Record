/*
 * =====================================================================================
 *
 *       Filename:  852_peak_index_in_a_mountain_array.c
 *
 *    Description:  peak index in a mountain array
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
#include <limits.h>
#include <stdint.h>

#define CHECK_BOUNDARY(peak, size) (peak > 0 && peak < size)
#define CHECK_PEAK(arr, peak) (arr[peak] > arr[peak-1] && arr[peak] > arr[peak+1])

static int find_peak(int *arr, int head, int end, int size) {

    int middle = (end+head)/2;    
    int peak = 0;

    if (CHECK_BOUNDARY(middle, size) && CHECK_PEAK(arr, middle)) {
        return middle;
    } else if (!middle || arr[middle] < arr[middle+1]) {
        peak = find_peak(arr, middle+1, end, size); 
    } else if (arr[middle] < arr[middle-1]) {
        peak = find_peak(arr, head, middle, size); 
    }
    return peak;
}    

int peakIndexInMountainArray(int* arr, int arrSize) {

    int peak = 0;

    peak = find_peak(arr, 0, arrSize-1, arrSize-1);

    return peak;
}
