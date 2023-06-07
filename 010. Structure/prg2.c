//Read about internal padding (to keep struct members aligned) and tail padding (last variable padded)
#include <stdio.h> 

struct A {
    int a; 
    char b; 
    float c; 
    char d;
};

struct B {
    int a; 
    char d;
    char c; 
    float b; 
};

struct C {
    long long a; 
    int b; 
    char c;
    short d;
};

struct D {
    int a; 
    char b; 
    short c; 
};

struct E {
    unsigned long long val; 
    int num1, num2; 
};

int main(void) {

    struct C instance;
    printf("%llu, %llu, %llu, %llu %llu\n", &instance, &instance.a, &instance.b, &instance.c, &instance.d);

    struct D instance_of_D; 
    printf("%llu, %llu, %llu, %llu\n", &instance_of_D, &instance_of_D.a, &instance_of_D.b, &instance_of_D.c);

    
    printf("%zu\n", sizeof(struct A)); //16 
    printf("%zu\n", sizeof(struct B)); //12 
    printf("%zu\n", sizeof(struct C)); //16 
    printf("%zu\n", sizeof(struct D)); //8
    printf("%zu\n", sizeof(struct E)); //16
    
}