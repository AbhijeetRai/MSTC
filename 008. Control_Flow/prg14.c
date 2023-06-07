#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

int* get_array(int* size_ptr);
void show_array(int* array, int size);
void iterate_array(int* array, int size);
void search_array(int* array, int element, int size); 

int main(void) {

    int size = 0; 
    
    int* array = get_array(&size);
    show_array(array, size);
    iterate_array(array, size);

    exit(EXIT_SUCCESS);
}

int* get_array(int* size_ptr) {

    int size = 0; 
    int* array = NULL;

    printf("Enter size: "); 
    scanf("%d", &size);
    assert(size > 2);

    array = (int*)calloc(size, sizeof(int));
    assert(array != NULL);

    for(int i = 0; i < size; i++) 
        array[i] = rand() % 10 + 1;

    *size_ptr = size;
    return array; 
}

void show_array(int* array, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", array[i]); 
    printf("\n");
}

void search_array(int* array, int element, int size, int index) {

    int counter = 0; 
    for(int i = 0; i < size; i++) 
        if(array[i] == element) {
            if(i < index) 
                return; 
            else
            counter++;
        }

    printf("%d -> %d\n", element, counter);
}

void iterate_array(int* array, int size) {

    for(int i = 0; i < size; i++)
        search_array(array, array[i], size, i);
}