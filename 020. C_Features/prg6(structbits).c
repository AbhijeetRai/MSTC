#include <stdio.h> 

struct Date {

    int day:5;      //5 bits are sufficient for storing date: 1 to 31 
    int month:4; 
    int year;
};

int main(void) {

    printf("%zu\n", sizeof(struct Date));
    return (0);
}