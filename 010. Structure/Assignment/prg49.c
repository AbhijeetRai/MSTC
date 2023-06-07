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

struct CAR {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension CAR_DIMENSION;
};  

int main(void) {

    struct CAR my_CAR; 

    my_CAR.cost = 1200076.57; 
    strncpy(my_CAR.brand, "Mahindra XUV 700", strlen("Mahindra XUV 700"));
    strncpy(my_CAR.color, "Walnut", strlen("Walnut"));
    strncpy(my_CAR.material, "Alloy", strlen("Alloy"));

    my_CAR.CAR_DIMENSION.height = 60;
    my_CAR.CAR_DIMENSION.length = 80;
    my_CAR.CAR_DIMENSION.breadth = 48;

    printf("CAR:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %f %s\n", 
        my_CAR.brand, my_CAR.color, my_CAR.material, my_CAR.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_CAR.CAR_DIMENSION.length, DIMENSION_UNIT, 
        my_CAR.CAR_DIMENSION.breadth, DIMENSION_UNIT, my_CAR.CAR_DIMENSION.height, DIMENSION_UNIT);

    exit(EXIT_SUCCESS);
}