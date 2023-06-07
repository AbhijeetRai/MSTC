#include <stdio.h>
#include <stdlib.h> 

#define length_unit "inches"
#define brand_name_length   16 
#define material_name_length 16
#define type_name_length    16

typedef struct Brush {

    int length; 
    char brand[brand_name_length];
    int price; 
    char material[material_name_length]; 
    char type[type_name_length];
}Brush;

int main(void) {

    Brush brush; 

    brush.length = 2; 
    strncpy(brush.brand, "ORAL-B", strlen("ORAL-B"));
    brush.price = 79;
    strncpy(brush.material, "Plastic", strlen("Plastic"));     
    strncpy(brush.type, "Tooth", strlen("Tooth"));

    printf("%s Brush:\n", brush.type);
    printf("Length: %d %s\n", brush.length, length_unit);
    printf("Brand: %s\n", brush.brand);
    printf("Price: %d\n", brush.price);
    printf("Material: %s\n", brush.material);

    return 0;
}