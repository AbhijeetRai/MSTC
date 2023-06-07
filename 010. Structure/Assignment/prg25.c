#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define color_length 16 
#define metal_length 16 
#define brand_length 16 

#define length_dimension "inches"
#define diameter_dimension "inches"
#define price_currency      "INR"

struct SINK_DIMENSION {

    int height;     
    short diameter;
};

struct BASIN_SINK {

    char color[color_length];
    char metal[metal_length];
    char brand[brand_length];
    float price;

    struct SINK_DIMENSION dimensions;
};

int main(void) {

    struct BASIN_SINK sink; 

    strncpy(sink.color, "White", strlen("White"));
    strncpy(sink.metal, "Ceramic", strlen("Ceramic"));
    strncpy(sink.brand, "Sinclair", strlen("Sinclair"));

    sink.price = 3200;

    sink.dimensions.height = 8; 
    sink.dimensions.diameter = 10;

    printf("Basin Sink:\n");
    printf("Color: %s\nMetal: %s\nBrand: %s\nPrice: %f %s\n", sink.color, sink.metal, sink.brand, sink.price, price_currency);
    printf("Height: %d %s\nDimater: %ld %s\n", sink.dimensions.height, length_dimension, sink.dimensions.diameter, diameter_dimension);

    return 0;
}