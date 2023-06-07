/*
    @AUTHOR: ABHIJEET RAI 
    @DATE: 27-01-2023 
    @GOAL: Allocate array of strucutres dynamically
*/


#include <stdio.h> 
#include <stdlib.h> 


typedef struct Date {
    int day, month, year;
}Date;


void init_array(Date* pointer);
void show_array(Date* pointer);
void free_array(Date** pointer_to_pointer); 


#define array_length 5


/**
 * init_array - to initialise structure array passed to it
 * @pointer - address of array which is to be initialised
*/
void init_array(Date* pointer) {

    for(int i = 0; i < array_length; i++) {

        (*(pointer + i)).day = i + 1;
        pointer[i].month = 10 - i; 
        pointer[i].year = 2020 + i;
    }
}

/**
 * show_array - to show structure array passed to it
 * @pointer - address of array which is to be shown
*/
void show_array(Date* pointer) {
    for(int i = 0; i < array_length; i++) 
        printf("Index: %d Date: %d/%d/%d\n", i, pointer[i].day, pointer[i].month, pointer[i].year);
    printf("\n");
}

/**
 * free_array - to show structure array passed to it
 * @pointer - address of array which is to be freed
*/
void free_array(Date** pointer_to_pointer) {

    free(*pointer_to_pointer);
    *pointer_to_pointer = 0;
}

/**
 * main - entry pointer function 
 * returns: exit code for cleanup to parent process
*/
int main(void) {

    Date* pointer = 0;
    pointer = (Date*)malloc(sizeof(Date) * 5);

    if(pointer == 0) {
        puts("fatal:malloc failed: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    init_array(pointer);
    show_array(pointer);
    free_array(&pointer);

    exit(EXIT_SUCCESS);
}