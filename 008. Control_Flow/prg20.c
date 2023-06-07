#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int* get_array(int* size_ptr); 
void show_array(const char* message, int* array, int size); 
void quick_sort(int* array, int p, int q);
int partition(int* array, int p, int q);

int* get_array(int* size_ptr) {

    int* array = NULL; 

    int size = 0; 
    printf("Enter size of array: "); 
    scanf("%d", &size);
    assert(size > 5);

    array = (int*)calloc(size, sizeof(int));
    assert(array != NULL);

    int val = 1;
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % 100 + 1) * val; 
        val *= -1;
    }

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

int partition(int* array, int p, int q) {

    int j = p;
    int i = p - 1;
    int pivot = 0;

    for(; j <= q; j++) {
        if(array[j] <= pivot) {
            i++; 
            int tmp = array[i]; 
            array[i] = array[j]; 
            array[j] = tmp;
        }
    }
}

int main(void) {

    int size = 0;
    
    int* array = get_array(&size); 
    show_array("Before sort: ", array, size);
    partition(array, 0, size - 1); 
    show_array("After sort: ", array, size);

    return 0;
}