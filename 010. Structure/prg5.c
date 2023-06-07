#include <stdio.h> 
#include <stdlib.h> 

struct B {

    double x; 
    double y;
};

struct A {

    int num; 
    struct B* pB; 
    float fnum;
};  

int main(void) {

    struct B inB; 
    struct A inA; 

    inA.pB = &inB;
    struct A* pA = &inA;

    (*pA).num = 10; 
    (*pA).fnum = 10.0f;
    (*(*pA).pB).x = 10; 
    (*(*pA).pB).y = 10; 

    printf("%d %f %lf %lf\n", inA.num, pA -> fnum, inA.pB->x, inA.pB->y);

    return 0;
}