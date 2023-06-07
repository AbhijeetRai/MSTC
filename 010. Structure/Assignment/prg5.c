#include <stdio.h> 
#include <string.h>

#define BRAND_NAME_LENGTH   64 
#define DIMENSION_UNIT      "CM"

struct Dimension {

    int length, breadth;
};

struct NOTEBOOK {
    int number_of_pages; 
    char brand[BRAND_NAME_LENGTH];
    struct Dimension note_dimension;
};

int main(void) {

    struct NOTEBOOK instance; 

    instance.number_of_pages = 250; 
    strncpy(instance.brand, "NAVNEET", strlen("NAVNEET"));
    instance.note_dimension.length = 45; 
    instance.note_dimension.breadth = 30;

    printf("Number of pages = %d\nBrand = %s\nLength = %d %s\nBreadth = %d %s\n", 
        instance.number_of_pages, instance.brand, instance.note_dimension.length, 
            DIMENSION_UNIT, instance.note_dimension.breadth, DIMENSION_UNIT);
    return 0;
}