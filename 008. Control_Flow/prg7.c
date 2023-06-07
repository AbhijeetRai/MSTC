#include <stdio.h> 

/*
    @AUTHOR: ABHIJEET RAI 
    @GOAL: TO PRINT ELEMENTS IN ARRAY IN VARIOUS WAYS 
    @DATE: 23/12/2022
*/
int main(void) {

    int array[] = {100, 200, 300, 400, 500};
    int* pointer_to_base_address = array; //array = &array[0]
    int  (*pointer_to_array)[5] = &array;

    for(int i = 0; i < 5; i++)
        printf("%d %d %d %d %d %d\n", array[i], *(array + i), pointer_to_base_address[i], *(pointer_to_base_address + i), (*pointer_to_array)[i], *(*(pointer_to_array) + i) );

    return 0;
}