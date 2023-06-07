#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define material_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct tyre_DIMENSION {

    int width;     
    short diameter;
};

struct tyre {

    char color[color_length];
    char material[material_length];
    char brand[brand_length];
    float price;

    struct tyre_DIMENSION dimensions;
};

int main(void) {

    struct tyre tyre; 

    strncpy(tyre.color, "Black", strlen("Black"));
    strncpy(tyre.material, "Rubber", strlen("Rubber"));
    strncpy(tyre.brand, "MRF", strlen("MRF"));

    tyre.price = 3500;

    tyre.dimensions.width = 4; 
    tyre.dimensions.diameter = 10;

    printf("Car tyre:\n");
    printf("Color: %s\nmaterial: %s\nBrand: %s\nPrice: %.2f %s\n", tyre.color, tyre.material, tyre.brand, tyre.price, price_currency);
    printf("width: %d %s\nDimater: %ld %s\n", tyre.dimensions.width, length_dimension, tyre.dimensions.diameter, diameter_dimension);

    return 0;
}