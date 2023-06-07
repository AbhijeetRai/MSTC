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

struct Mirror {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension MirrorD;
};

int main(void) {

    struct Mirror my_Mirror; 

    strncpy(my_Mirror.color, "White", strlen("White"));
    my_Mirror.price = 501.51;
    strncpy(my_Mirror.brand, "Unknown", strlen("Unknown"));
    strncpy(my_Mirror.shape, "Rectangular ", strlen("Rectangular"));

    my_Mirror.MirrorD.length = 50; 
    my_Mirror.MirrorD.breadth = 36; 

    printf("Mirror:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_Mirror.color, my_Mirror.price, 
        PRICE_UNIT, my_Mirror.brand, my_Mirror.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_Mirror.MirrorD.length, 
        DIMENSION_UNIT, my_Mirror.MirrorD.breadth, DIMENSION_UNIT);

    return 0;
}