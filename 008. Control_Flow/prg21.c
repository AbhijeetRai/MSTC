#include <stdio.h> 
#include <stdlib.h>

#define TRUE    1

void* merge(int* array, int p, int q, int r) {

    int N1 = q - p + 1; 
    int N2 = r - q;

    int* array1 = (int*)malloc(sizeof(int) * N1); 
    int* array2 = (int*)malloc(sizeof(int) * N2);

    if(array1 == NULL) {
        printf("fatal: malloc: out of memory");
        exit(EXIT_FAILURE);
    }

    if(array2 == NULL) {
        printf("fatal: malloc: out of memory"); 
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < N1; i++) 
        array1[i] = array[p + i];

    for(int i = 0; i < N2; i++) 
        array2[i] = array[q + 1 + i];


    int i = p;  //main array 
    int j = 0; 
    int k = 0; 

    while(TRUE) {

        if(array1[j] <= array2[k]) {
            array[i] = array1[j];
            i++; 
            j++; 

            if(j == N1) {
                while(k < N2) {
                    array[i] = array2[k];
                    i++; 
                    k++;
                }
                break;
            } 
        }

        else {
            array[i] = array2[k];
            i++; 
            k++;

            if(k == N2) {
                while(j < N1) {
                    array[i] = array1[j];
                    i++;
                    j++;
                }
                break;
            }
        }
    }
}

int main() {

    int arr[] = {60, 70, 80, 15, 25, 75};
    merge(arr, 0, 2, 5);

    for(int i = 0; i <=5; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
}