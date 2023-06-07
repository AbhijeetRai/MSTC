#include <stdio.h> 
#include <string.h>

#define BRAND_NAME_LENGTH   64 
#define DIMENSION_UNIT      "INCHES"
#define PRICE_UNIT          "INR"
#define SHAPE_LENGTH        32
#define COLOR_LENGTH        32

struct Dimension {

    int length, breadth;
};

struct Door {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension DoorD;
};

int main(void) {

    struct Door my_Door; 

    strncpy(my_Door.color, "Whitish Yellow", strlen("Whitish Yellow"));
    my_Door.price = 3007.5;
    strncpy(my_Door.brand, "Unknown", strlen("Unknown"));
    strncpy(my_Door.shape, "Rectangular ", strlen("Rectangular"));

    my_Door.DoorD.length = 84; 
    my_Door.DoorD.breadth = 28; 

    printf("Door:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_Door.color, my_Door.price, 
        PRICE_UNIT, my_Door.brand, my_Door.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_Door.DoorD.length, 
        DIMENSION_UNIT, my_Door.DoorD.breadth, DIMENSION_UNIT);

    return 0;
}