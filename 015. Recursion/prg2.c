#include <stdio.h>
#include <stdlib.h>

void show_arr_forward(int* arr, int index) {

    if(index < 0) 
        return; 

    show_arr_forward(arr, index - 1);
    printf("%d ", arr[index]); 
}

void show_arr_backward(int* arr, int index) {

    if(index < 0) 
        return; 

    printf("%d ", arr[index]); 
    show_arr_backward(arr, index - 1);
}

int main(void) {

    int arr[] = {10, 20, 30, 40, 50};
    show_arr_forward(arr, 4);
    printf("\n");
    show_arr_backward(arr, 4);
    return 0;
}