#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#define DIMENSION_UNIT "INCHES"
#define brand_length    32
#define color_length    16
#define material_length 16
#define CURRENCY        "INR"

struct Dimension {

    int height; 
    int length; 
    int breadth;
};

struct STOOL {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension STOOL_DIMENSION;
};  

int main(void) {

    struct STOOL my_STOOL; 

    my_STOOL.cost = 315.5; 
    strncpy(my_STOOL.brand, "Dmart", strlen("Dmart"));
    strncpy(my_STOOL.color, "Walnut", strlen("Walnut"));
    strncpy(my_STOOL.material, "Plastic", strlen("Plastic"));

    my_STOOL.STOOL_DIMENSION.height = 6;
    my_STOOL.STOOL_DIMENSION.length = 10;
    my_STOOL.STOOL_DIMENSION.breadth = 10;

    printf("STOOL:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %f %s\n", 
        my_STOOL.brand, my_STOOL.color, my_STOOL.material, my_STOOL.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_STOOL.STOOL_DIMENSION.length, DIMENSION_UNIT, 
        my_STOOL.STOOL_DIMENSION.breadth, DIMENSION_UNIT, my_STOOL.STOOL_DIMENSION.height, DIMENSION_UNIT);

    exit(EXIT_SUCCESS);
}