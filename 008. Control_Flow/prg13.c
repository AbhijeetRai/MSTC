#include <stdio.h> 
#include <stdlib.h> 

#define TRUE    1 
#define FALSE   0

int is_prime(int number) {
 
    int flag = TRUE;
    
    for(int divisor = 2; divisor < (number / 2) + 1; divisor++) {
        if(number % divisor == 0) {
            flag = FALSE;
            break;
        }
    }

    return flag;
}

int main(void) {

    printf("%d\n", is_prime(2));
    exit(EXIT_SUCCESS);
}