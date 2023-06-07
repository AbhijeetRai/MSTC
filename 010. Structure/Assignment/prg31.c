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

struct Rack {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension RackD;
};

int main(void) {

    struct Rack my_Rack; 

    strncpy(my_Rack.color, "Black Marble", strlen("Black Marble"));
    my_Rack.price = 140.5;
    strncpy(my_Rack.brand, "Unknown", strlen("Unknown"));
    strncpy(my_Rack.shape, "Rectangular ", strlen("Rectangular"));

    my_Rack.RackD.length = 30; 
    my_Rack.RackD.breadth = 10; 

    printf("Rack:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_Rack.color, my_Rack.price, 
        PRICE_UNIT, my_Rack.brand, my_Rack.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_Rack.RackD.length, 
        DIMENSION_UNIT, my_Rack.RackD.breadth, DIMENSION_UNIT);

    return 0;
}