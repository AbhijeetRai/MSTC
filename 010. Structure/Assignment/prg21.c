#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#define DIMENSION_UNIT "INCHES"
#define brand_length    32
#define color_length    16
#define material_length 16
#define CURRENCY        "INR"
#define weight_unit     "KG"

struct Dimension {

    int height; 
    int length; 
    int breadth;
};

struct SHELF {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension SHELF_DIMENSION;
    double weight;
};  

int main(void) {

    struct SHELF my_SHELF; 

    my_SHELF.cost = 315.5; 
    strncpy(my_SHELF.brand, "Unknown", strlen("Unknown"));
    strncpy(my_SHELF.color, "Metallic", strlen("Metallic"));
    strncpy(my_SHELF.material, "Iron/Wood", strlen("Iron/Wood"));

    my_SHELF.SHELF_DIMENSION.height = 60;
    my_SHELF.SHELF_DIMENSION.length = 30;
    my_SHELF.SHELF_DIMENSION.breadth = 40;

    my_SHELF.weight = 21.1;

    printf("SHELF:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %.2f %s\n", 
        my_SHELF.brand, my_SHELF.color, my_SHELF.material, my_SHELF.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_SHELF.SHELF_DIMENSION.length, DIMENSION_UNIT, 
        my_SHELF.SHELF_DIMENSION.breadth, DIMENSION_UNIT, my_SHELF.SHELF_DIMENSION.height, DIMENSION_UNIT);
    printf("Weight: %.2lf %s\n", my_SHELF.weight, weight_unit);

    exit(EXIT_SUCCESS);
}