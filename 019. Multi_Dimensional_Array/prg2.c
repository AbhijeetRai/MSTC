/* LOOK AT THE WARNING MESSAGES METICULOUSLY */

#include <stdio.h> 
#include <stdlib.h> 

int arr[4][2];

int main(void) {

    printf("%llu\n", arr); //arr = &arr[0] = type(&arr[0]) = int(*ptr)[2], will be seen in warning

    /*
    * arr+1 = &arr[0] + 1
    * We know that ptr + 1, ptr + size(type(pointer)) * 1 
    * RATHER ptr + size(type(address)) * 1
    * type(&arr[0]) = int(*ptr)[2] = 8 bytes
    * hence arr + 1 = arr + (1 * 8)
    * 
    * Also, arr + 1, is arr + 8, but it still points to 2D array at index 1 
    * In simple words, if arr is array {{0, 0}, {0, 0}, {0, 0}, {0, 0}}
    * arr + 1 points to second sub array, hence its type is int(*ptr)[2]
    */
    printf("%llu\n", arr+1);    
    
    /*
    * *(arr+1) leads to base address of first int in second sub array
    */
    printf("%llu\n", *(arr+1));

    return (0);
}