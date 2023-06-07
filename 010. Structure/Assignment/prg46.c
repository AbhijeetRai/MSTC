#include <stdio.h> 

int main(void) {

    struct plate {

        int diameter; 
        char brand[16]; 
        char color[16];
    }my_plate;

    my_plate.diameter = 6;
    strncpy(my_plate.brand, "Dior", 4);
    strncpy(my_plate.color, "White pattern", strlen("White pattern"));
    printf("%d\n%s\n%s\n", my_plate.diameter, my_plate.brand, my_plate.color);

    return 0;
}