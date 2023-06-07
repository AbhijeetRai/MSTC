#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct CYLINDER_DIMENSION {

    int height;     
    short diameter;
};

struct CYLINDER {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct CYLINDER_DIMENSION dimensions;
};

int main(void) {

    struct CYLINDER CYLINDER; 

    strncpy(CYLINDER.color, "Red", strlen("Red"));
    strncpy(CYLINDER.metal, "Iron", strlen("Iron"));
    strncpy(CYLINDER.brand, "Bharat gas", strlen("Bharat gas"));

    CYLINDER.price = 1200;

    CYLINDER.dimensions.height = 24; 
    CYLINDER.dimensions.diameter = 5;

    printf("Kitchen CYLINDER:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %.2f %s\n", CYLINDER.color, CYLINDER.metal, CYLINDER.brand, CYLINDER.price, price_currency);
    printf("Height: %d %s\nDimater: %ld %s\n", CYLINDER.dimensions.height, length_dimension, CYLINDER.dimensions.diameter, diameter_dimension);

    return 0;
}