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

struct Trolley {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension Trolley_DIMENSION;
    double weight;
};  

int main(void) {

    struct Trolley my_Trolley; 

    my_Trolley.cost = 315.5; 
    strncpy(my_Trolley.brand, "American Tourister", strlen("American Tourister"));
    strncpy(my_Trolley.color, "Sky Blue-Pinkish", strlen("Sky Blue-Pinkish"));
    strncpy(my_Trolley.material, "Polymer", strlen("Polymer"));

    my_Trolley.Trolley_DIMENSION.height = 30;
    my_Trolley.Trolley_DIMENSION.length = 24;
    my_Trolley.Trolley_DIMENSION.breadth = 24;

    my_Trolley.weight = 3.31;

    printf("Trolley:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %.2f %s\n", 
        my_Trolley.brand, my_Trolley.color, my_Trolley.material, my_Trolley.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_Trolley.Trolley_DIMENSION.length, DIMENSION_UNIT, 
        my_Trolley.Trolley_DIMENSION.breadth, DIMENSION_UNIT, my_Trolley.Trolley_DIMENSION.height, DIMENSION_UNIT);
    printf("Weight: %.2lf %s\n", my_Trolley.weight, weight_unit);

    exit(EXIT_SUCCESS);
}