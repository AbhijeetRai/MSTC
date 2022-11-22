#include<stdio.h> 

int main() {

    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(signed char));
    printf("%zu\n", sizeof(unsigned char));

    printf("\n");

    printf("%zu\n", sizeof(short));
    printf("%zu\n", sizeof(short int));
    printf("%zu\n", sizeof(signed short));
    printf("%zu\n", sizeof(signed short int));
    printf("%zu\n", sizeof(unsigned short));
    printf("%zu\n", sizeof(unsigned short int));

    printf("\n");

    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(signed int));
    printf("%zu\n", sizeof(unsigned int));

    printf("\n");

    printf("%zu\n", sizeof(long));
    printf("%zu\n", sizeof(long int));
    printf("%zu\n", sizeof(signed long));
    printf("%zu\n", sizeof(signed long int));
    printf("%zu\n", sizeof(unsigned long));
    printf("%zu\n", sizeof(unsigned long int));

    printf("\n");

    printf("%zu\n", sizeof(long long));
    printf("%zu\n", sizeof(long long int));
    printf("%zu\n", sizeof(signed long long));
    printf("%zu\n", sizeof(signed long long int));
    printf("%zu\n", sizeof(unsigned long long));
    printf("%zu\n", sizeof(unsigned long long int));

    return 0;
}