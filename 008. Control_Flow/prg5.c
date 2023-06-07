#include <stdio.h> 
#include <stdlib.h> 

struct Date {

    int dd; 
    int mm;
};

struct Date* fun() {
    struct Date* d1 = (struct Date*)malloc(sizeof(struct Date)); 
    return d1;
}

int main(void) {

    
    struct Date* d1 = fun();
    printf("%p\n", &d1);

    return 0;
}