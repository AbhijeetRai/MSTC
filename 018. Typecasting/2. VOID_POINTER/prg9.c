#include <stdio.h> 
#include <stdlib.h> 

int fun(int d, int);
void gun(int(*fptr)(int a, int b));     

int main(void) {

    gun(fun);
    return (0);
}

void gun(int(*fptr)(int a, int b)) {
    printf("In gun");
    fptr(1, 2);
}

int fun(int x, int z) {
    printf("in fun");
    return 10;
}