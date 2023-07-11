#include <stdio.h> 
#include <stdlib.h> 

int arr[8] = {4, 7, 1, 5, 8, 10, 15, 11 }; 
int i; 

int main(void){
    for(i = 0; i < 8; ++i){
        if(arr[i] % 5 == 0)
            break; 
        printf("arr[%d]:%d\n", i, arr[i]); 
    }

    puts("End of loop containing break"); 
    for(i = 0; i < 8; ++i){
        if(arr[i] % 5 == 0)
            continue; 
        printf("arr[%d]:%d\n", i, arr[i]); 
    }

    puts("End of program"); 
    exit(0); 
}