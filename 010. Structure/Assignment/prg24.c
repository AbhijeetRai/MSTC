#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct BASKET_DIMENSION {

    int height;     
    short diameter;
};

struct LAUNDRY_BASKET {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct BASKET_DIMENSION dimensions;
};

int main(void) {

    struct LAUNDRY_BASKET basket; 

    strncpy(basket.color, "White/Blue", strlen("White/Blue"));
    strncpy(basket.metal, "Fabric", strlen("Fabric"));
    strncpy(basket.brand, "Dmart", strlen("Dmart"));

    basket.price = 350.52;

    basket.dimensions.height = 20; 
    basket.dimensions.diameter = 5;

    printf("Laundry basket:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %f %s\n", basket.color, basket.metal, basket.brand, basket.price, price_currency);
    printf("Height: %d %s\nDimater: %ld %s\n", basket.dimensions.height, length_dimension, basket.dimensions.diameter, diameter_dimension);

    return 0;
}