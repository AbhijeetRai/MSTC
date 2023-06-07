#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

    int a = 10; 
    int b = 20; 
    int c = 300; 
    int d = 200; 
    int e = 200; 
    int f = 200; 
    int rs; 

    rs =((a>b) || (c<d)) && ((c<d) || (e==f)) && ((e==f) || (a>b)); 
    printf("%d\n", rs);

    exit(EXIT_SUCCESS);
}