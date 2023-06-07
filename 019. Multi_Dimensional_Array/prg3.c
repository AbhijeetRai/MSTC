/*LOOK AT THE WARNINGS & OUTPUT VERY CAREFULLY*/
#include <stdio.h> 
#include <stdlib.h> 

int arr[3][5][4];

int main(void) {

    printf("%llu\n", arr);    
    printf("%llu\n", (arr+1));          
    printf("%llu\n", *(arr+1));        
    printf("%llu\n", *(*(arr + 1)+2));  

    return (0);
}