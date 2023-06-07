#include <stdio.h>
#include <stdlib.h> 


void get_array(int*** ppptr, int* pointer);
void init_array(pointer_to_int_pointer, length);
void show_array(int** pointer_to_int_pointer_array, int length); 


void get_array(int*** ppptr, int* pointer) {

    int size = 0;

    printf("Enter size: ");
    scanf("%d", &size);

    int** pointer_to_int_pointer = 0;
    pointer_to_int_pointer = (int**)malloc(sizeof(int*) * size);

    if(pointer_to_int_pointer == 0) {
        puts("fatal: malloc failed: out of memory");
        exit(EXIT_FAILURE);
    }

    *ppptr = pointer_to_int_pointer;
    *pointer = size;
}

void init_array(int** pointer_to_int_pointer_array, int length) {

    for(int i = 0; i < length; i++) {
        
        *(pointer_to_int_pointer_array + i) = 0;
        *(pointer_to_int_pointer_array + i) = (int*)malloc(sizeof(int));
        
        if(pointer_to_int_pointer_array[i] == 0) {
            puts("fatal: malloc failed: out of memory");
            exit(EXIT_FAILURE);
        }

        **(pointer_to_int_pointer_array + i) = (i + 1) * 10;
    }
}

void show_array(int** pointer_to_int_pointer_array, int length) {

    for(int i = 0; i < length; i++)
        printf("%d ", *pointer_to_int_pointer_array[i]);
    printf("\n");
}

void free_memory(int*** ppptr, int size) {

    for(int i = 0; i < size; i++) {
        free(*(*ppptr + i));
    }
    free(*ppptr); 
    *ppptr = 0;
}

int main(void) {

    int** pointer_to_int_pointer = 0;
    int length = 0;

    get_array(&pointer_to_int_pointer, &length);
    init_array(pointer_to_int_pointer, length);
    show_array(pointer_to_int_pointer, length);
    free_memory(&pointer_to_int_pointer, length);

    exit(EXIT_SUCCESS);
}