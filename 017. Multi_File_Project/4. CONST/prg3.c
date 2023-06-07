#include <stdio.h> 
static const int value = 10; 

int main(void) {

    int* ptr = &value;
    *ptr = 20;
    printf("%d\n", value);
}