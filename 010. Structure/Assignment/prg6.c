#include <stdio.h> 
#include <stdlib.h> 

#define BRAND_NAME_LENGTH   64 
#define DIMENSION_UNIT      "CM"
#define COLOR_LENGTH        16

struct Dimension {

    int length, breadth, width;
};

struct MOSQUITO_KILLING_MACHINE {

    char brand[BRAND_NAME_LENGTH];
    char color[COLOR_LENGTH];
    int price; 
    struct Dimension machine_dimension;

};

int main(void) {

    struct MOSQUITO_KILLING_MACHINE allout; 
    
    strncpy(allout.brand, "ALL OUT", strlen("ALL OUT")); 
    strncpy(allout.color, "Red/White", strlen("Red/White"));
    
    allout.price = 120; 
    
    allout.machine_dimension.length = 10;
    allout.machine_dimension.breadth = 5;
    allout.machine_dimension.width = 2;

    printf("Brand = %s\nColor = %s\nPrice = %d\n", allout.brand, allout.color, allout.price);
    printf("Length = %d %s \nBreadth = %d %s \nWidth = %d %s", allout.machine_dimension.length, DIMENSION_UNIT, 
        allout.machine_dimension.breadth, DIMENSION_UNIT, allout.machine_dimension.width, DIMENSION_UNIT);

    return 0;
}