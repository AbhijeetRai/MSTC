#include <stdio.h> 
#include <stdlib.h> 

typedef struct data {

    int a; 
    char b; 
    int c; 
    char d;
}data;

#define OFFSET_OF(type, member)     (unsigned long long)\
                                    (&((type*)0)->member)

int main(void) {

    printf("%llu\n", OFFSET_OF(data, a));
    printf("%llu\n", OFFSET_OF(data, b));
    printf("%llu\n", OFFSET_OF(data, c));
    printf("%llu\n", OFFSET_OF(data, d));

    return (0);
}