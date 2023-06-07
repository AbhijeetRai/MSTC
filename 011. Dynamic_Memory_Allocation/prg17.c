//realloc application 

#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

    int num; 
    int choice; 

    int* arr = NULL; 
    int N = 0;

    while(1) {
        printf("Do you want to enter an integer? [1]: Yes, [0]: No:");
        scanf("%d", &choice);
        if(choice != 1) 
            break;
        printf("Enter the value:");
        scanf("%d", &num);
        printf("Entered num = %d\n", num);
        
        N = N + 1;
        arr = (int*)realloc(arr, N * sizeof(int));
        if(arr == NULL) {
            puts("Error in allocating memory\n");
            exit(EXIT_FAILURE);
        }

        arr[N-1] = num;
    }

    for(int i = 0; i < N; i++)
        printf("arr[%d]:%d\n", i, arr[i]);

    return (0);
}