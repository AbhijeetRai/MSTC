#include <stdio.h> 
#include <stdlib.h> 

void fun(int a, int b);
void gun(int c, int d); 
int sun(int e, int f); 

int main(void) {

    void (*fptr) (int, int) = gun;
    fptr(10, 20);   

    fptr = fun; 
    fptr(20, 30);

    int (*fpn) (int, int) = NULL;
    fpn = &sun; 
    int val = fpn(11,11);
    printf("%d\n", val);

    return (0);
}

void fun(int a, int b) {
    printf("a+b=%d\n", a+b);
    printf("In fun\n");
}

void gun(int c, int d) {
    printf("c+d=%d\n", c+d);
    printf("In gun\n");
}

int sun(int e, int f) {
    printf("e+f=%d\n", e+f);
    printf("In sun\n");

    return e+f;
}