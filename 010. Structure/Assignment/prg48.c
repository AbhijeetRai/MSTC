#include <stdio.h>
#include <stdlib.h> 

#define brand_name_length 16
#define color_length 16

struct DoorBell {

    char brand[brand_name_length];
    int no_of_speakers;     
    char color[color_length];
}my_pen;

int main(void) {

    strncpy(my_pen.brand, "Cello", 5);
    strncpy(my_pen.color, "White pattern", strlen("White pattern"));
    my_pen.no_of_speakers = 2;
    printf("%d\n%s\n%s\n", my_pen.no_of_speakers, my_pen.brand, my_pen.color);
    return 0;
}