#include <stdio.h> 
#include <stdlib.h> 

/*
 * init_array - intialise int pointer array with some values, in the memory where each element of int pointer array points
 * @pointer_to_int_pointer - holds base address of integer pointer array
*/
void init_array(int** pointer_to_int_pointer) {

    for(int i = 0; i < 5; i++) 
        **(pointer_to_int_pointer + i) = (i + 1) * 10;
}

/*
 * show_array - show respective values in respective memory pointed by each element in int pointer array
 * @pointer_to_int_pointer - holds base address of integer pointer array
*/
void show_array(int** pointer_to_int_pointer) {

    for(int i = 0; i < 5; i++) 
        printf("%d ", *pointer_to_int_pointer[i]); 
    printf("\n");
}

/*
 * main - entry point function, creates array of 5 integer pointers and allocated memory to each int pointer dynamically and frees the memory
*/
int main() {

    int* pointer[5];

    for(int i = 0; i < 5; i++)
        pointer[i] = (int*)malloc(sizeof(int));

    init_array(pointer); 
    show_array(pointer);

    for(int i = 0; i < 5; i++)
        free(pointer[i]);

    return 0;
}