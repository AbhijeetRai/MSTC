#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 


typedef struct Date {
    int day; 
    int month;
    int year;
}Date;


void allocate_array(Date*** pointer_to_pointer_to_struct_pointer_array, int* sizepointer); 
void show_array(Date** pointer_to_struct_pointer_array, int size_of_struct_pointer_array); 
void init_array(Date** pointer_to_struct_pointer_array, int size_of_struct_pointer_array);
void free_array(Date*** pointer_to_pointer_to_struct_pointer_array, int size_of_struct_pointer_array); 


int main(int argc, char* argv) {

    int size_of_struct_pointer_array = 0;
    Date** pointer_to_struct_pointer_array = 0; 

    allocate_array(&pointer_to_struct_pointer_array, &size_of_struct_pointer_array);
    show_array(pointer_to_struct_pointer_array, size_of_struct_pointer_array);
    init_array(pointer_to_struct_pointer_array, size_of_struct_pointer_array);
    show_array(pointer_to_struct_pointer_array, size_of_struct_pointer_array);
    free_array(&pointer_to_struct_pointer_array, size_of_struct_pointer_array);

    assert(pointer_to_struct_pointer_array == 0);

    exit(EXIT_SUCCESS);
}

void allocate_array(Date*** pointer_to_pointer_to_struct_pointer_array, int* sizepointer) {

    int size = 0;
    Date** pointer_to_struct_pointer_array = 0;

    printf("Enter size of structure pointer array: "); 
    scanf("%d", &size);

    assert(size > 0);

    pointer_to_struct_pointer_array = (Date**)malloc(sizeof(Date*) * size);
    assert(pointer_to_struct_pointer_array != 0);
    memset(pointer_to_struct_pointer_array, 0, sizeof(Date*) * size);

    for(int i = 0; i < size; i++) {
        pointer_to_struct_pointer_array[i] = (Date*)malloc(sizeof(Date));
        assert(pointer_to_struct_pointer_array[i] != 0);
        pointer_to_struct_pointer_array[i] -> day = 0;
        pointer_to_struct_pointer_array[i] -> month = 0;
        pointer_to_struct_pointer_array[i] -> year = 0;
    }

    *sizepointer = size; 
    *pointer_to_pointer_to_struct_pointer_array = pointer_to_struct_pointer_array;
}

void show_array(Date** pointer_to_struct_pointer_array, int size_of_struct_pointer_array) {

    for(int i = 0; i < size_of_struct_pointer_array; i++) {
        
        int day = (*(pointer_to_struct_pointer_array + i)) -> day; 
        int month = (*(*(pointer_to_struct_pointer_array + i))).month;
        int year = pointer_to_struct_pointer_array[i] -> year;

        printf("%d %d %d\n", day, month, year);
    }
    printf("\n\n");
}

void init_array(Date** pointer_to_struct_pointer_array, int size_of_struct_pointer_array) {

    for(int i = 0; i < size_of_struct_pointer_array; i++) { 
        pointer_to_struct_pointer_array[i] -> day = 10 + i; 
        pointer_to_struct_pointer_array[i] -> month = 12 - i; 
        pointer_to_struct_pointer_array[i] -> year = 2021 + i;
    }
}

void free_array(Date*** pointer_to_pointer_to_struct_pointer_array, int size_of_struct_pointer_array) {

    Date** pointer_to_struct_pointer_array = *pointer_to_pointer_to_struct_pointer_array;

    for(int i = 0; i < size_of_struct_pointer_array; i++) {
        free(pointer_to_struct_pointer_array[i]);
        pointer_to_struct_pointer_array[i] = 0;
    }

    free(pointer_to_struct_pointer_array); 
    pointer_to_struct_pointer_array = 0; 
    
    *pointer_to_pointer_to_struct_pointer_array = 0;
}