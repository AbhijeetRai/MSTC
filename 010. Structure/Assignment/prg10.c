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

struct MAT {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension matD;
};

int main(void) {

    struct MAT my_MAT; 

    strncpy(my_MAT.color, "Sky Blue", strlen("Sky Blue"));
    my_MAT.price = 315.5;
    strncpy(my_MAT.brand, "Bombay Dying", strlen("Bombay Dying"));
    strncpy(my_MAT.shape, "Rectangular Fur", strlen("Rectangular Fur"));

    my_MAT.matD.length = 48; 
    my_MAT.matD.breadth = 15; 

    printf("MAT:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_MAT.color, my_MAT.price, 
        PRICE_UNIT, my_MAT.brand, my_MAT.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_MAT.matD.length, 
        DIMENSION_UNIT, my_MAT.matD.breadth, DIMENSION_UNIT);

    return 0;
}