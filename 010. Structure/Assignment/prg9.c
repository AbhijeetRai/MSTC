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

struct CURTAIN {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension curtainD;
};

int main(void) {

    struct CURTAIN my_curtain; 

    strncpy(my_curtain.color, "Blue", strlen("Blue"));
    my_curtain.price = 715.5;
    strncpy(my_curtain.brand, "Bombay Dying", strlen("Bombay Dying"));
    strncpy(my_curtain.shape, "Rectangular", strlen("Rectangular"));

    my_curtain.curtainD.length = 84; 
    my_curtain.curtainD.breadth = 36; 

    printf("Curtain:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_curtain.color, my_curtain.price, 
        PRICE_UNIT, my_curtain.brand, my_curtain.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_curtain.curtainD.length, 
        DIMENSION_UNIT, my_curtain.curtainD.breadth, DIMENSION_UNIT);

    return 0;
}