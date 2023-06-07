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

struct BLANKET {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension BLANKETD;
};

int main(void) {

    struct BLANKET my_BLANKET; 

    strncpy(my_BLANKET.color, "Dark Blue", strlen("Dark Blue"));
    my_BLANKET.price = 4015.5;
    strncpy(my_BLANKET.brand, "Bombay Dying", strlen("Bombay Dying"));
    strncpy(my_BLANKET.shape, "Rectangular Fur", strlen("Rectangular Fur"));

    my_BLANKET.BLANKETD.length = 84; 
    my_BLANKET.BLANKETD.breadth = 36; 

    printf("BLANKET:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_BLANKET.color, my_BLANKET.price, 
        PRICE_UNIT, my_BLANKET.brand, my_BLANKET.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_BLANKET.BLANKETD.length, 
        DIMENSION_UNIT, my_BLANKET.BLANKETD.breadth, DIMENSION_UNIT);

    return 0;
}