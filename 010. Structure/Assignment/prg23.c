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

struct Laptop_Bag {

    float cost; 
    char brand[brand_length];
    char color[color_length];
    char material[material_length];
    struct Dimension Laptop_Bag_DIMENSION;
    double weight;
};  

int main(void) {

    struct Laptop_Bag my_Laptop_Bag; 

    my_Laptop_Bag.cost = 2015.5; 
    strncpy(my_Laptop_Bag.brand, "WildCraft", strlen("WildCraft"));
    strncpy(my_Laptop_Bag.color, "Light Green-Greyish", strlen("Light Green-Greyish"));
    strncpy(my_Laptop_Bag.material, "Fabric and Cushion", strlen("Fabric and Cushion"));

    my_Laptop_Bag.Laptop_Bag_DIMENSION.height = 12;
    my_Laptop_Bag.Laptop_Bag_DIMENSION.length = 10;
    my_Laptop_Bag.Laptop_Bag_DIMENSION.breadth = 4;

    my_Laptop_Bag.weight = 0.4;

    printf("Laptop_Bag:\n");
    printf("Brand: %s\nColor: %s\nMaterial: %s\nCost: %.2f %s\n", 
        my_Laptop_Bag.brand, my_Laptop_Bag.color, my_Laptop_Bag.material, my_Laptop_Bag.cost, CURRENCY);
    printf("Length: %d %s\nBreadth: %d %s\nHeight %d %s\n", my_Laptop_Bag.Laptop_Bag_DIMENSION.length, DIMENSION_UNIT, 
        my_Laptop_Bag.Laptop_Bag_DIMENSION.breadth, DIMENSION_UNIT, my_Laptop_Bag.Laptop_Bag_DIMENSION.height, DIMENSION_UNIT);
    printf("Weight: %.2lf %s\n", my_Laptop_Bag.weight, weight_unit);

    exit(EXIT_SUCCESS);
}