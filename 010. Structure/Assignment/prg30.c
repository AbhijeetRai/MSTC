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

struct Tiles {

    char color[COLOR_LENGTH];
    double price; 
    char brand[BRAND_NAME_LENGTH];
    char shape[SHAPE_LENGTH];

    struct Dimension TilesD;
};

int main(void) {

    struct Tiles my_Tiles; 

    strncpy(my_Tiles.color, "Brick Red", strlen("Brick Red"));
    my_Tiles.price = 140.5;
    strncpy(my_Tiles.brand, "Unknown", strlen("Unknown"));
    strncpy(my_Tiles.shape, "Rectangular ", strlen("Rectangular"));

    my_Tiles.TilesD.length = 24; 
    my_Tiles.TilesD.breadth = 18; 

    printf("Tiles:\n");
    printf("Color: %s\nPrice: %.2lf %s\nBrand:%s\nShape:%s\n", my_Tiles.color, my_Tiles.price, 
        PRICE_UNIT, my_Tiles.brand, my_Tiles.shape);
    printf("\nDimension:\nLength: %d %s\nBreadth: %d %s\n", my_Tiles.TilesD.length, 
        DIMENSION_UNIT, my_Tiles.TilesD.breadth, DIMENSION_UNIT);

    return 0;
}