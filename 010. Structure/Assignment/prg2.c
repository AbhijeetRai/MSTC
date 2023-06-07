#include <stdio.h> 
#include <string.h>

#define BRAND_NAME_LENGTH   64 
#define DIMENSION_UNIT      "CM"

struct Dimension {

    int length, breadth;
};

struct STICKY_NOTES {
    int number_of_notes; 
    char brand[BRAND_NAME_LENGTH];
    struct Dimension note_dimension;
};

int main(void) {

    struct STICKY_NOTES instance; 

    instance.number_of_notes = 250; 
    strncpy(instance.brand, "NAVNEET", strlen("NAVNEET"));
    instance.note_dimension.length = 8; 
    instance.note_dimension.breadth = 6;

    printf("Number of notes = %d\nBrand = %s\nLength = %d\nBreadth = %d\n", 
        instance.number_of_notes, instance.brand, instance.note_dimension.length, instance.note_dimension.breadth);
}