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

struct TABLE {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension TABLE_DIMENSION;
};  

int main(void) {

    struct TABLE my_TABLE; 

    my_TABLE.cost = 3000; 
    strncpy(my_TABLE.brand, "Azzaro", strlen("Azzaro"));
    strncpy(my_TABLE.color, "Walnut", strlen("Walnut"));
    strncpy(my_TABLE.material, "Wood/Iron", strlen("Wood/Iron"));

    my_TABLE.TABLE_DIMENSION.height = 30;
    my_TABLE.TABLE_DIMENSION.length = 30;
    my_TABLE.TABLE_DIMENSION.breadth = 24;

    printf("Table:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %f %s\n", 
        my_TABLE.brand, my_TABLE.color, my_TABLE.material, my_TABLE.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_TABLE.TABLE_DIMENSION.length, DIMENSION_UNIT, 
        my_TABLE.TABLE_DIMENSION.breadth, DIMENSION_UNIT, my_TABLE.TABLE_DIMENSION.height, DIMENSION_UNIT);

    exit(EXIT_SUCCESS);
}