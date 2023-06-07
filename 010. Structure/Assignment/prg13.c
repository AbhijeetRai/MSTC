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

struct BEDSHEET {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension BEDSHEETD;
};

int main(void) {

    struct BEDSHEET my_BEDSHEET; 

    strncpy(my_BEDSHEET.color, "Sky Blue", strlen("Sky Blue"));
    my_BEDSHEET.price = 400.5;
    strncpy(my_BEDSHEET.brand, "Bombay Dying", strlen("Bombay Dying"));
    strncpy(my_BEDSHEET.shape, "Rectangular ", strlen("Rectangular"));

    my_BEDSHEET.BEDSHEETD.length = 84; 
    my_BEDSHEET.BEDSHEETD.breadth = 36; 

    printf("BEDSHEET:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_BEDSHEET.color, my_BEDSHEET.price, 
        PRICE_UNIT, my_BEDSHEET.brand, my_BEDSHEET.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_BEDSHEET.BEDSHEETD.length, 
        DIMENSION_UNIT, my_BEDSHEET.BEDSHEETD.breadth, DIMENSION_UNIT);

    return 0;
}