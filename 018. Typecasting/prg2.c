#include <stdio.h> 
#include <stdlib.h> 

struct A {
    int a; 
    char b; 
    int c; 
    char d;
};

struct B {
    char a, b; 
    int c, d;
};

int main(void) {
    struct A inA; 
    unsigned long long offset; 

    offset = (unsigned long long)&inA.c - (unsigned long long)&inA; 
    printf("%llu\n", offset);

    struct A* ptrA = &inA;
    &ptrA -> c;

    /*
        struct A* ptrA = &inA;
        ptrA -> c;               
        
        //Go to base address if inA, get offset of c 
        //&inA + offset(c) is address of c in inA
        //now read x bytes from c depending on type of c
    */
    return (0);
}

/*
int main(void) {
    int b;              Let x be base address of b, let compiler read variables in register eax
    
    What happes when a <var><semi-colon> is written, for example b;
    b;                          eax <- M[x : x + 3]         compiler reads 4 bytes from base adress in register eax
    (short)b;                   eax <- M[x : x + 1]         compiler reads 2 bytes from base adress in register eax
    (char)b;                    eax <- M[x]                 compiler reads 1 bytes from base adress in register eax
    (unsigned long long)b

    return (0);
}
*/