#include <stdio.h> 
#include <stdlib.h> 

typedef struct data {

    int a; 
    char b; 
    int c; 
    char d;
}data;

#define OFFSET_OF(type, member)     (&((type*)0)->member)

int main(void) {

    printf("%p\n", OFFSET_OF(data, a));
    printf("%p\n", OFFSET_OF(data, b));
    printf("%p\n", OFFSET_OF(data, c));
    printf("%p\n", OFFSET_OF(data, d));

    return (0);
}