#include <stdio.h> 
#include <stdlib.h> 

void insertion_sort(int* array_ptr, int last_index);

int main(void) {

    int arr[] = {10, -1, 17, -12, 5, 61, 1};
    insertion_sort(arr, 6);

    for(int i = 0; i <= 6; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return (0);
}

void insertion_sort(int* array_ptr, int last_index) {
    int i;

    for(i = 1; i <= last_index; i++) {

        int key = array_ptr[i];
        int j = i - 1;

        while(j >= 0 && array_ptr[j] > key) {
            array_ptr[j + 1] = array_ptr[j];
            j -= 1;
        }
        array_ptr[j+1] = key;
    }
}