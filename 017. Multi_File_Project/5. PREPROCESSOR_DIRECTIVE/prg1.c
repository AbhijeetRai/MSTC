#include <stdio.h>
#include <stdlib.h> 

#define ADD(a, b) ((a) + (b)) 

int main(void) {

    int rs; 
    int m = 10, n = 25; 

    rs = ADD(5, 7);
    printf("rs = %d\n", rs);
    rs = ADD(4 + 5, 7 - 9);
    printf("rs = %d\n", rs);
    rs = ADD(m + 1, n * 2); 
    printf("rs = %d\n", rs);

    return (0);
}