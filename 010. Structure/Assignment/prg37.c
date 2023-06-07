#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct bottle_DIMENSION {

    int height;     
    short diameter;
};

struct bottle {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct bottle_DIMENSION dimensions;
};

int main(void) {

    struct bottle bottle; 

    strncpy(bottle.color, "Transparent", strlen("Transparent"));
    strncpy(bottle.metal, "Glass", strlen("Glass"));
    strncpy(bottle.brand, "VERITAS", strlen("VERITAS"));

    bottle.price = 1200;

    bottle.dimensions.height = 8; 
    bottle.dimensions.diameter = 1;

    printf("Water bottle:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %.2f %s\n", bottle.color, bottle.metal, bottle.brand, bottle.price, price_currency);
    printf("Height: %d %s\nDimater: %ld %s\n", bottle.dimensions.height, length_dimension, bottle.dimensions.diameter, diameter_dimension);

    return 0;
}