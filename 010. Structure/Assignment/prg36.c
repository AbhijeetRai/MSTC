#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct helmet_DIMENSION {

    int height;     
    short diameter;
};

struct helmet {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct helmet_DIMENSION dimensions;
};

int main(void) {

    struct helmet helmet; 

    strncpy(helmet.color, "Red", 3);
    strncpy(helmet.metal, "Polymer", strlen("Polymer"));
    strncpy(helmet.brand, "STUDDS", strlen("STUDDS"));

    helmet.price = 1200;

    helmet.dimensions.height = 12; 
    helmet.dimensions.diameter = 5;

    printf("Bike Helmet:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %.2f %s\n", helmet.color, helmet.metal, helmet.brand, helmet.price, price_currency);
    printf("Height: %d %s\nDimater: %ld %s\n", helmet.dimensions.height, length_dimension, helmet.dimensions.diameter, diameter_dimension);

    return 0;
}