#include <stdio.h> 
#include <stdlib.h> 

show_array(int* ptr);
show_pointer_array(int** pptr);

int main() {

    int array[3] = {10, 20, 30};
    show_array(array);   //array = &array[0] = &int = int*

    for(int i = 0; i <=2; i++)
        printf("%d ", *(&array[0] + i) );
    printf("\n");

    int* ptr[5];
    for(int i = 0; i < 5; i++) {
        ptr[i] = (int*)malloc(sizeof(int));
        **(&ptr[0] + i) = (i + 1) * 100;
    }

    for(int i = 0; i < 5; i++) 
        printf("%d %d %d %d %d ", **(ptr + i), *ptr[i], 
        **(&ptr[i]), **(&(*(&ptr[0] + i))), **(&ptr[0] + i));
    printf("\n");

    show_pointer_array(ptr); //ptr = &ptr[0] = &int* = int**

    return 0;
}

show_array(int* ptr) {
    for(int i = 0; i <= 2; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

show_pointer_array(int** pptr) {
    for(int i = 0; i < 5; i++) 
        printf("%d %d ", **(pptr + i), *(pptr[i]) );
    printf("\n");
}