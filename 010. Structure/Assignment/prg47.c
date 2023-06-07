#include <stdio.h> 

int main(void) {

    struct pen {

        int diameter; 
        char brand[16]; 
        char color[16];
    }my_pen;

    my_pen.diameter = 8;
    strncpy(my_pen.brand, "Cello", 5);
    strncpy(my_pen.color, "White pattern", strlen("White pattern"));
    printf("%d\n%s\n%s\n", my_pen.diameter, my_pen.brand, my_pen.color);

    return 0;
}