#include <stdio.h> 
int main(void) {

    double val1 = 0; 
    double val2 = 0;
    double val3 = 0;
    double* ptr1 = NULL;
    double* ptr2 = NULL;
    double* ptr3 = NULL;

    ptr1 = &val1; 
    ptr2 = &val2;
    ptr3 = &val3;

    //(ptr3 - ptr1) = (ptr3 - ptr1)/sizeof(double)
    printf("%llu %llu %llu %llu\n", (unsigned long long)ptr1, (unsigned long long)ptr2, (unsigned long long)ptr3, ptr3 - ptr1);

    return (0);
}