#include <stdio.h> 

int main(void) {

    int a[5]; 
    int (*ptr)[5] = &a;     
    printf("ptr     = %llu\nptr + 1 = %llu\n", ptr, ptr + 1);   
}