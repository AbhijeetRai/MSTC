#include <stdio.h>
#include <stdlib.h> 

int main(void) {

    void* arr[3];

    arr[0] = malloc(sizeof(int));
    *((int*)arr[0]) = 10;
    printf("%d\n", *(int*)arr[0]);

    printf("%p\n", arr[1]);

    return (0);
}