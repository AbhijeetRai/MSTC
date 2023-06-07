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

struct MATTRESS {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension MATTRESSD;
};

int main(void) {

    struct MATTRESS my_MATTRESS; 

    strncpy(my_MATTRESS.color, "grey", strlen("Grey"));
    my_MATTRESS.price = 2500.51;
    strncpy(my_MATTRESS.brand, "Sleepwell", strlen("Sleepwell"));
    strncpy(my_MATTRESS.shape, "Rectangular ", strlen("Rectangular"));

    my_MATTRESS.MATTRESSD.length = 84; 
    my_MATTRESS.MATTRESSD.breadth = 36; 

    printf("MATTRESS:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_MATTRESS.color, my_MATTRESS.price, 
        PRICE_UNIT, my_MATTRESS.brand, my_MATTRESS.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_MATTRESS.MATTRESSD.length, 
        DIMENSION_UNIT, my_MATTRESS.MATTRESSD.breadth, DIMENSION_UNIT);

    return 0;
}