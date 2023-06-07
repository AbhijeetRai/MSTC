#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int* get_array(int* size_ptr, int* even_ptr, int* odd_ptr);
void split(int* array, int size, int even, int odd);

int main(void) {

    int size = 0; 
    int even = 0; 
    int odd = 0;

    int* array = get_array(&size, &even, &odd);
    split(array, size, even, odd);

    exit(EXIT_SUCCESS);
}

int* get_array(int* size_ptr, int* even_ptr, int* odd_ptr) {

    int even = 0, odd = 0; //track to keep number stored in array
    int* array = NULL; 

    int size = 0; 
    printf("Enter size of array: "); 
    scanf("%d", &size);
    assert(size > 5);

    array = (int*)calloc(size, sizeof(int));
    assert(array != NULL);

    for(int i = 0; i < size; i++) {
        int number = rand() % 100 + 1; 
        array[i] = number;

        if(number % 2 == 0) 
            even += 1; 
        else 
            odd += 1;
    }

    *size_ptr = size;
    *even_ptr = even; 
    *odd_ptr = odd;

    return array; 
}

void split(int* array, int size, int even, int odd) {

    int* array1 = (int*)malloc(sizeof(int) * even);
    int* array2 = (int*)malloc(sizeof(int) * odd);

    assert(array1 != NULL);
    assert(array2 != NULL);

    int j = -1; 
    int k = -1; 

    for(int i = 0; i < size; i++) {
        if(array[i] % 2 == 0) {
            j++; 
            array1[j] = array[i]; 
        }
        else {
            k++; 
            array2[k] = array[i];
        }
    }

    for(j = 0; j < even; j++) 
        printf("%d ", array1[j]);
    printf("\n");

    for(k = 0; k < odd; k++) 
        printf("%d ", array2[k]);
    printf("\n");

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");

    free(array1); 
    array1 = NULL; 

    free(array2); 
    array2 = NULL;
}