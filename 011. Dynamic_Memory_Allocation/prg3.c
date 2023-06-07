#include <stdio.h> 
#include <stdlib.h> 


typedef struct Date {

    int day; 
    int month; 
    int year;
}Date, *Date_Pointer;


void get_array(Date_Pointer* pointer_to_pointer, int* pointer);
void init_array(Date_Pointer pointer, size_t size); 
void show_array(Date* pointer, int array_length);
void free_array(Date** pointer_to_pointer);

/**
 * get_array - to create array of structures of given size 
 * pointer_to_pointer - address of pointer that stores array base address 
 * pointer - address of size variable of array 
*/
void get_array(Date_Pointer* pointer_to_pointer, int* pointer) {

    Date_Pointer ptr = 0; 
    int size = 0;

    printf("Enter size of array\n");
    scanf("%d", &size);

    ptr = (Date*)calloc(size, sizeof(Date));
    /*
        * to see if pointer points to somewhere in heap (negative logic)
    */
    if(ptr == 0) {
        printf("fatal:calloc fails: out of memory\n");
        exit(EXIT_FAILURE);
    }

    *pointer_to_pointer = ptr; 
    *pointer = size;
}

/**
 * init_array - to initialise the data in array of structures 
 * @pointer - address of structure array 
 * @size - length of array
*/
void init_array(Date_Pointer pointer, size_t size) {

    for(int i = 0; i < size; i++) {

        (*(pointer + i)).day = i + 1;
        pointer[i].month = 10 - i; 
        pointer[i].year = 2020 + i;
    }
}

/**
 * show_array - to show the data in array of structures 
 * @pointer - address of structure array 
 * @array_length - length of array
*/
void show_array(Date* pointer, int array_length) {
    for(int i = 0; i < array_length; i++) 
        printf("Index: %d Date: %d/%d/%d\n", i, pointer[i].day, pointer[i].month, pointer[i].year);
    printf("\n");
}

/**
 * free_array - to free array of structure 
 * @pointer_to_pointer - pointer to the pointer of structure array
*/
void free_array(Date** pointer_to_pointer) {

    free(*pointer_to_pointer);
    *pointer_to_pointer = 0;
}

/**
 * main - entry point function 
 * returns - exit code for cleanup to parent process
*/
int main(void) {

    Date_Pointer pointer = 0;
    int size = 0;
    
    get_array(&pointer, &size);
    init_array(pointer, size);
    show_array(pointer, size);

    exit(EXIT_SUCCESS);
}