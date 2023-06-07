#include <stdio.h> 
#include <stdlib.h> 


int** get_array(int* size_pointer);
void init_array(int** pointer_to_int_pointer, int size); 
void show_array(int** pointer_to_int_pointer, int size);
void free_array(int*** pointer_to_pointer_to_int_pointer_array, int size);


/*
 * get_array - create an array of int pointer dynamically of custom size given by user
 *             allocate memory dynamically to each int pointer in int pointer array 
 * 
 * @size_pointer: address of size variable sent by caller, out parameter
 * 
 * Return: pointer_to_int_pointer (base address of int pointer array)
*/
int** get_array(int* size_pointer) {

    int size = 0; 
    printf("Enter size: ");
    scanf("%d", &size);

    int** pointer_to_int_pointer = (int**)malloc(sizeof(int*) * size);

    for(int i = 0; i < size; i++) 
        *(pointer_to_int_pointer + i) = (int*)malloc(sizeof(int));

    *size_pointer = size;
    return pointer_to_int_pointer;
}

/*
 * init_array - initialise memory block pointed by each int pointer, in int pointer array
 * 
 * @pointer_to_int_pointer: holds base address of int pointer array 
 * @size: size of array
*/
void init_array(int** pointer_to_int_pointer, int size) {

    for(int i = 0; i < size; i++)
        **(pointer_to_int_pointer + i) = (i + 1) * 10;
}

/*
 * show_array - show value in memory block pointed by each int pointer, in int pointer array
 * 
 * @pointer_to_int_pointer: holds base address of int pointer array 
 * @size: size of array
*/
void show_array(int** pointer_to_int_pointer, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", *pointer_to_int_pointer[i]); 
    printf("\n");
}

/*
 * free_array - free each memory block pointed by int pointer, in int pointer array
 *              free int pointer array 
 * 
 * @pointer_to_pointer_to_int_pointer_array: holds base address of pointer to int pointer array 
 * @size: size of int pointer array
*/
void free_array(int*** pointer_to_pointer_to_int_pointer_array, int size) {

    for(int i = 0; i < size; i++) 
        free( *(*pointer_to_pointer_to_int_pointer_array + i) );

    free(*pointer_to_pointer_to_int_pointer_array);
    *pointer_to_pointer_to_int_pointer_array = 0; 
}

/*
 * main - entry pointe function 
 *        responsible to call functions to: 
 *          i) create array of int pointers 
 *          ii) intiailise array of int pointers 
 *          iii) show array of int pointers 
 *          iv) free array of int pointers
*/
int main(int argc, char* argv[]) {

    int size = 0;
    
    int** pointer_to_int_pointer = get_array(&size);
    init_array(pointer_to_int_pointer, size);
    show_array(pointer_to_int_pointer, size);
    free_array(&pointer_to_int_pointer, size);

    exit(EXIT_SUCCESS);
}