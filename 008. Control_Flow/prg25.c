/**
 * BIG BUG IN THE QUICK SORT PROGRAM
 * IN QUICK SORT FUNCTION, WHILE (P < R) IS USED INSTEAD OF IF(P < R)
 * THIS CAUSES THE FUNCTION TO BREAK AT SOME POINT P < R BUT VALUE OF P AND R IS NOT CHANGED IN QUICK SORT FUNCTION ITSELF 
 * CODE REPEATEDLY TRIES TO SORT / PARTITION SAME SUBARRAY AGAIN AND AGAIN. NEVER MOVING TO OTHER SUBARRAY 
 * IT IS LIKE CASETTE STUCK OVER SAME SECTION OF REEL. QUICK SORT WAS WRITTEN BY TONY HOARE
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int* get_array(int* size_ptr);
void show_array(char* message, int* array, int size);
int partition(int* array, int p, int r); 
void quick_sort(int* array, int p, int r); 

int main(void) {
    
    int size = 5;
    int array[] = {-1, 3, 65, 61, 7};
    show_array("Before sort: ", array, size);

    quick_sort(array, 0, size - 1);
    show_array("After sort: ", array, size);

    return 0;
}

int* get_array(int* size_ptr) {

    int size = 0; 
    printf("Enter size: ");
    scanf("%d", &size);

    assert(size > 0); 
    *size_ptr = size; 

    int* array = (int*)malloc(sizeof(int)* size);
    assert(array != NULL);
    memset(array, 0, sizeof(int) * size);

    for(int i = 0; i < size; i++)
        array[i] = rand() % 50 + 1; 

    return array;
}

void show_array(char* message, int* array, int size) {

    if(message)
        printf("%s: ", message);

    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("\n");
}

int partition(int* array, int p, int r) {

    int i = p - 1; 
    int pivot = array[r];
    int j = p;

    for(j; j < r; j++)
        if(array[j] <= pivot) {
            i += 1;
            int temp = array[i]; 
            array[i] = array[j]; 
            array[j] = temp;
        }

    i += 1;
    int temp = array[i];
    array[i] = array[j]; 
    array[j] = temp;

    return i;
}

void quick_sort(int* array, int p, int r) {

    while(p<r) {
        int q = partition(array, p, r);
        quick_sort(array, p, q - 1); 
        quick_sort(array, q+1, r);
    }
}