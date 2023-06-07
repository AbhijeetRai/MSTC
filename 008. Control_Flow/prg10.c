#include <stdio.h> 

struct random {

    long long value; 
    int integer; 
    char character;
    char character1;
}r1;

int main(void) {

    printf("%zd\n", sizeof(struct random)); //16 
    printf("%p %p %p %p\n", &r1.value, &r1.integer, &r1.character, &r1.character1);
    return 0;
}