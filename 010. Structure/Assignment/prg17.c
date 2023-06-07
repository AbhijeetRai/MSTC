#include <stdio.h> 

#define BRAND_LENGTH        32
#define COLOR_LENGTH        32
#define DIMENSION_UNIT      "CM"
#define zipper_manufacturer_name_length 128

struct Dimension {

    int length, breadth;
};

struct phone_case {

    char brand[BRAND_LENGTH];
    char color[COLOR_LENGTH];
    struct Dimension case_dimension; 
    int price;
};  

int main(void) {

    struct phone_case my_case; 
    
    strncpy(my_case.brand, "realme", strlen("realme"));
    strncpy(my_case.color, "White", strlen("White"));
    my_case.case_dimension.length = 13; 
    my_case.case_dimension.breadth = 5;

    printf("Brand = %s\nColor= %s\nLength = %d %s\nBreadth = %d %s\nprice = %s", 
        my_case.brand, my_case.color, my_case.case_dimension.length, DIMENSION_UNIT, 
        my_case.case_dimension.breadth, DIMENSION_UNIT, "Free with phone");

    return 0;
}