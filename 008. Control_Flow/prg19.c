#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

int* get_array(int* size_ptr) {

    int* array = NULL; 

    int size = 0; 
    printf("Enter size of array: "); 
    scanf("%d", &size);
    assert(size > 5);

    array = (int*)calloc(size, sizeof(int));
    assert(array != NULL);

    for(int i = 0; i < size; i++) 
        array[i] = rand() % 100 + 1; 

    *size_ptr = size;
    return array; 
}

void show_array(const char* message, int* array, int size) { 

    if(message) 
        puts(message);

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");
}

void partition(int* array, int p, int r) {

    int pivot = array[r];
    int j = 0; 
    int i = -1;
    int temp = 0;

    for(j = 0; j < r; j++) {
        if(array[j] <= pivot) {
            i += 1;
            temp = array[i]; 
            array[i] = array[j];
            array[j] = temp;
        }
    }

    i += 1; 
    temp = array[i]; 
    array[i] = array[j]; 
    array[j] = temp;
}

int main(void) {

    int size = 0;
    
    int* array = get_array(&size); 
    show_array("Before partition: ", array, size);
    partition(array, 0, size - 1);
    show_array("After partition: ", array, size);

    return 0;
}