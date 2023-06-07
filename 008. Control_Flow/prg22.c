#include <stdio.h> 
#include <stdlib.h> 

void sort(int* array, int index);
void show_array(int* array, int size); 
void insertion_sort(int* array, int last_index);

int main(void) {

    int array[] = {10, -15, 35, 14, 13, 36};
    insertion_sort(array, 5);
    show_array(array, 6);

    int key = 0; 
    printf("Enter key, you want to search: ");
    scanf("%d", &key);

    //int index = bin_search(array, 0, 5, key);
    //printf("%d\n", index);
}

void insertion_sort(int* array, int last_index) {

    for(int i = 1; i <= last_index; i++) 
        sort(array, i);
}

void sort(int* array, int index) {

    int ele_to_be_sorted = array[index];
    int j = index - 1;

    for(j; j >= 0 && array[j] > ele_to_be_sorted; j--)
        array[j+1] = array[j];

    array[j + 1] = ele_to_be_sorted;
}

void show_array(int* array, int size) {

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n\n\n");
}

int bin_search(int* array, int i, int j, int key) {

    if (j < i)
        return -1;

    int mid = (i + j)/2;

    if (key == array[mid])
        return mid;

    else if(key > array[mid]) 
        return bin_search(array, mid + 1, j, key);

    else 
        return bin_search(array, i, mid - 1, key);
}