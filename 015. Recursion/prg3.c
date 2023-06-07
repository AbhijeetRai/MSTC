#include <stdio.h> 
#include <stdlib.h> 

int* get_array(int* array_length_pointer);
void show_array(char* message, int* array, int array_length);
void sort(int* array, int array_length); 
void insertion_sort(int* array, int index); 
int get_key();

int main(void) {

    int array_length = 0; 
    
    int* array = get_array(&array_length);
    sort(array, array_length);
    show_array("Array: ", array, array_length);

    int key = get_key();
    printf("index of key: %d", bin_search(array, 0, array_length - 1, key));
}

int* get_array(int* array_length_pointer) {

    int array_length = 0; 
    printf("Enter array length: ");
    scanf("%d", &array_length); 

    if(array_length <= 1) {
        printf("Array must contain 2 or more elements\n"); 
        exit(EXIT_FAILURE);
    }

    int* array = NULL; 
    array = (int*)malloc(sizeof(array) * array_length);

    if(array == NULL) {
        printf("fatal: malloc: memory allocation to array failed\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < array_length; i++)
        array[i] = rand() % 100;

    *array_length_pointer = array_length;
    return array;
}

void show_array(char* message, int* array, int array_length) {

    if(message) 
        puts(message);

    for(int i = 0; i < array_length; i++) 
        printf("%d ", array[i]);
    printf("\n");
}

void insertion_sort(int* array, int index) {

    int element_to_be_sorted = array[index];
    int j = index - 1;

    for(j; j >= 0; j--) 
        if(array[j] > element_to_be_sorted) 
            array[j + 1] = array[j];
        else 
            break;

    array[j + 1] = element_to_be_sorted;

}

void sort(int* array, int array_length) {

    for(int i = 2; i <= array_length - 1; i++) 
        insertion_sort(array, i);
}

int get_key() {

    int key = 0;

    printf("Enter key to be found in array: ");
    scanf("%d", &key);

    return key;
}

int bin_search(int* array, int i, int j, int key) {

    if(i < j) {
        int mid = (i + j) / 2; 

        if(array[mid] == key) 
            return mid; 

        else if(array[mid] > key) 
            bin_search(array, i, mid - 1, key);

        else 
            bin_search(array, mid + 1, j, key);
    }

    else {
        printf("%d %d", i, j);
        return -1;
    }
}