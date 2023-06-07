#include <stdio.h> 


int main(void) {
    const static int a = 10;
    a += 1;
    printf("%d\n", a);
}