#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

int** allocate_array_of_pointers_to_integers(int* size_pointer);
void show_array(int** pointer_to_int_pointer, int size);
void init_array(int** pointer_to_int_pointer, int size);
void free_array(int** pointer_to_int_pointer, int size);

int main() {

    int size = 0;
    
    int** pointer_to_int_pointer = allocate_array_of_pointers_to_integers(&size);
    show_array(pointer_to_int_pointer, size);
    init_array(pointer_to_int_pointer, size);
    show_array(pointer_to_int_pointer, size);
    free_array(pointer_to_int_pointer, size);

    pointer_to_int_pointer = 0; 
}

int** allocate_array_of_pointers_to_integers(int* size_pointer) {

    int size = 0;
    printf("Enter size: "); 
    scanf("%d", &size);

    assert(size > 0);

    int** pointer_to_int_pointer = 0;
    pointer_to_int_pointer = (int**)malloc(sizeof(int*) * size);
    assert(pointer_to_int_pointer != 0);
    memset(pointer_to_int_pointer, 0, sizeof(int*) * size);

    for(int i = 0; i < size; i++) {
        pointer_to_int_pointer[i] = (int*)malloc(sizeof(int));
        assert(pointer_to_int_pointer[i] != 0);
        memset(pointer_to_int_pointer[i], 0, sizeof(int));
    }

    *size_pointer = size; 
    return pointer_to_int_pointer;
}

void show_array(int** pointer_to_int_pointer, int size) {

    for(int i = 0; i < size; i++) 
        printf("%d ", *pointer_to_int_pointer[i]); 
    printf("\n");
}

void init_array(int** pointer_to_int_pointer, int size) {

    for(int i = 0; i < size; i++) 
        *pointer_to_int_pointer[i] = (i + 1) * 100;
}

void free_array(int** pointer_to_int_pointer, int size) {

    for(int i = 0; i < size; i++) {
        free(pointer_to_int_pointer[i]);
        pointer_to_int_pointer[i] = 0; 
    }

    free(pointer_to_int_pointer);
    pointer_to_int_pointer = 0;
}