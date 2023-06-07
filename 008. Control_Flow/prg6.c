#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    char* pc = 0; 
    short* ps = 0; 
    int* pi = 0;
    double* pd = 0; 

    printf("pc + 1 = %p\n", pc+1); 
    printf("pc + 2 = %p\n", pc+2); 
    printf("pc + 3 = %p\n", pc+3); 
    puts("---------------------"); 
    printf("ps + 1 = %p\n", ps+1); 
    printf("ps + 2 = %p\n", ps+2); 
    printf("ps + 3 = %p\n", ps+3); 
    puts("---------------------"); 
    printf("pi + 1 = %p\n", pi+1); 
    printf("pi + 2 = %p\n", pi+2); 
    printf("pi + 3 = %p\n", pi+3); 
    puts("---------------------"); 
    printf("pd + 1 = %p\n", pd+1); 
    printf("pd + 2 = %p\n", pd+2); 
    printf("pd + 3 = %p\n", pd+3); 
    puts("---------------------"); 
    
    return (0); 
}

/* 
    Interpretation of addition & subtraction of 
    of a pointer and integer 

    Let p be a pointer of type T. 

    T* p = 0; 

    p + k = p + k * sizeof(T)
    p - k = p - k * sizeof(T)

    Let x be an address in p. 

    p + k = x + k * sizeof(T)
    p - k = x - k * sizeof(T)
*/