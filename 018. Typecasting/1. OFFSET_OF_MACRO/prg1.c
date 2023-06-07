#include <stdio.h> 
#include <stdlib.h> 

typedef struct data {

    int a; 
    char b; 
    int c; 
    char d;
}data;

int main(void) {

    data* data_ptr = 0;

    /*no SEG_FAULT because we are only accessing or printing invalid address*/
    /*not doing any read write operation on invalid address*/    
    printf("%llu %llu %llu %llu\n", (unsigned long long)&data_ptr->a, (unsigned long long)&data_ptr->b, 
        (unsigned long long)&data_ptr->c, (unsigned long long)&data_ptr->d);

    /*as good as*/
    //putting 0 instad of data_ptr and casting 0 to data*
    printf("%llu\n", (unsigned long long)(&((data*)0)->d));

    printf("%llu %llu %llu %llu\n", ((unsigned long long)(&(((data*)0)->a))), ((unsigned long long)(&(((data*)0)->b))),
        ((unsigned long long)(&(((data*)0)->c))), ((unsigned long long)(&(((data*)0)->d))));

    return (0);
}