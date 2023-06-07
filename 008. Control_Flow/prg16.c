#include <stdio.h> 
#include <stdlib.h>

void merge(int* arr, int p, int q, int r) {

    int N1 = q - p + 1; 
    int N2 = r - q; 

    int* array1 = (int*)calloc(N1, sizeof(int));
    assert(array1 != NULL);

    for(int i = 0; i < N1; i++) 
        array1[i] = arr[p + i];

    int* array2 = (int*)calloc(N2, sizeof(int)); 
    assert(array2 != NULL);

    for(int i = 0; i < N2; i++) 
        array2[i] = arr[q + 1 + i];
}

int main(void) {

    int arr[] = {11, 13,     15, 17, 19, 20, 22, 26,                 45, 37};
    merge(arr, 2, 4, 7);

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]); 
    printf("\n");
}