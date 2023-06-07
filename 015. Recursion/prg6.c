#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>


int* get_array(int* size_ptr);
show_array(const char* message, int* array, int size);
void sort(int* array, int index);
void insertion_sort(int* array, int size); 


int main(void) {

    int size = 0;
    int* array = get_array(&size);
    show_array("Before sort: ", array, size);

    insertion_sort(array, size); 
    show_array("After sort: ", array, size);

    return 0;
}

int* get_array(int* size_ptr) {

    int size = 0; 
    printf("Enter size: ");
    scanf("%d", &size); 
    assert(size > 0);

    int* array = NULL;
    array = (int*)malloc(sizeof(int) * size);
    if(array == NULL) {
        printf("fatal: malloc: out of memory\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; i++) 
        array[i] = rand() % 100 + 1;

    *size_ptr = size; 
    return array;
}

show_array(const char* message, int* array, int size) {

    if(message) 
        puts(message);

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");
}

void sort(int* array, int index) {

    int ele = array[index];
    int j = index - 1;

    for(; j >= 0 && array[j] > ele; j--)
        array[j + 1] = array[j];
    
    array[j + 1] = ele;
}

void insertion_sort(int* array, int size) {

    for(int i = 1; i < size; i++) 
        sort(array, i);
}