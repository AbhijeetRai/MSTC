#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "mm"
#define price_currency      "INR"

struct CURTAIN_DIMENISION {

    int length;     
    short diameter;
};

struct CURTAIN_RAIL {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct CURTAIN_DIMENISION dimensions;
};

int main(void) {

    struct CURTAIN_RAIL rail; 

    strncpy(rail.color, "White", strlen("White"));
    strncpy(rail.metal, "Steel", strlen("Steel"));
    strncpy(rail.brand, "Geeta", strlen("Geeta"));

    rail.price = 350.52;

    rail.dimensions.length = 72; 
    rail.dimensions.diameter = 15;

    printf("Curtain rail:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %f %s\n", rail.color, rail.metal, rail.brand, rail.price, price_currency);
    printf("Length: %d %s\nDimater: %ld %s\n", rail.dimensions.length, length_dimension, rail.dimensions.diameter, diameter_dimension);

    return 0;
}