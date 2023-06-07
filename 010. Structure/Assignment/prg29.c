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

struct Towel {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension TowelD;
};

int main(void) {

    struct Towel my_Towel; 

    strncpy(my_Towel.color, "Reddish White Chequed", strlen("Reddish White Chequed"));
    my_Towel.price = 40.5;
    strncpy(my_Towel.brand, "Unknown", strlen("Unknown"));
    strncpy(my_Towel.shape, "Rectangular ", strlen("Rectangular"));

    my_Towel.TowelD.length = 42; 
    my_Towel.TowelD.breadth = 14; 

    printf("Towel:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_Towel.color, my_Towel.price, 
        PRICE_UNIT, my_Towel.brand, my_Towel.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_Towel.TowelD.length, 
        DIMENSION_UNIT, my_Towel.TowelD.breadth, DIMENSION_UNIT);

    return 0;
}