#include <stdio.h> 
#include <stdlib.h>

//fibonacci non recursive code

int fib(int n) {

    if(n <= 1)
        return n;

    int a = 0;
    int b = 1;
    int sum = 0;
    
    for(int i = 2; i <= n; i++) {

        sum = a + b;
        a = b; 
        b = sum;
    }
    
    return sum;
}

int main(void) {

    int ans = fib(3);
    printf("%d ", ans);
    return 0;
}