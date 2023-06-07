#include <stdio.h> 

#define BRAND_LENGTH        32
#define COLOR_LENGTH        32
#define DIMENSION_UNIT      "CM"
#define zipper_manufacturer_name_length 128

struct Dimension {

    int length, breadth;
};

struct laptop_case {

    char brand[BRAND_LENGTH];
    char color[COLOR_LENGTH];
    struct Dimension case_dimension; 
    char zipper_manufacturer[zipper_manufacturer_name_length];
};  

int main(void) {

    struct laptop_case my_case; 
    
    strncpy(my_case.brand, "GIZGA ESSENTIALS", strlen("GIZGA ESSENTIALS"));
    strncpy(my_case.color, "GREY", strlen("GREY"));
    my_case.case_dimension.length = 150; 
    my_case.case_dimension.breadth = 60;
    strncpy(my_case.zipper_manufacturer, "GIZGA ESSENTIALS", strlen("GIZGA ESSENTIALS"));

    printf("Brand = %s\nColor= %s\nLength = %d %s\nBreadth = %d %s\nZipper Manufacuter = %s", 
        my_case.brand, my_case.color, my_case.case_dimension.length, DIMENSION_UNIT, 
        my_case.case_dimension.breadth, DIMENSION_UNIT, my_case.zipper_manufacturer);

    return 0;
}