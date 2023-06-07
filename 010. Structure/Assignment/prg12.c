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

struct PILLOW {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension PILLOWD;
};

int main(void) {

    struct PILLOW my_PILLOW; 

    strncpy(my_PILLOW.color, "Blue", strlen(" Blue"));
    my_PILLOW.price = 400.5;
    strncpy(my_PILLOW.brand, "Bombay Dying", strlen("Bombay Dying"));
    strncpy(my_PILLOW.shape, "Rectangular ", strlen("Rectangular"));

    my_PILLOW.PILLOWD.length = 24; 
    my_PILLOW.PILLOWD.breadth = 12; 

    printf("PILLOW:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_PILLOW.color, my_PILLOW.price, 
        PRICE_UNIT, my_PILLOW.brand, my_PILLOW.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_PILLOW.PILLOWD.length, 
        DIMENSION_UNIT, my_PILLOW.PILLOWD.breadth, DIMENSION_UNIT);

    return 0;
}