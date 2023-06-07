#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define brand_length 16

struct Dimension {

    int length, breadth, height;
};

struct Charger {

    char brand[brand_length]; 
    int volts; 
    int amperes; 
    int frequency;

    struct Dimension laptop_charger_dimension;
};

int main(void) {

    struct Charger laptop_charger; 

    strncpy(laptop_charger.brand, "Lenovo", strlen("Lenovo"));
    laptop_charger.volts = 220; 
    laptop_charger.amperes = 10; 
    laptop_charger.frequency = 50;
    laptop_charger.laptop_charger_dimension.length = 17; 
    laptop_charger.laptop_charger_dimension.breadth = 8; 
    laptop_charger.laptop_charger_dimension.height = 5;

    printf("Brand:%s\nVolts:%d V\nAmpere: %d A\nFrequency: %d Hz\nLength: %d CM\nBreadth: %d\nHeight: %d\n", 
        laptop_charger.brand, laptop_charger.volts, laptop_charger.amperes, laptop_charger.frequency, 
        laptop_charger.laptop_charger_dimension.length, laptop_charger.laptop_charger_dimension.breadth, laptop_charger.laptop_charger_dimension.height);
}