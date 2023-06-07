#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define brand_length 32

struct Dimension {

    int length, breadth, height;
};

struct Charger {

    char brand[brand_length]; 
    int volts; 
    int amperes; 
    int frequency;

    struct Dimension phone_charger_dimension;
};

int main(void) {

    struct Charger phone_charger; 

    strncpy(phone_charger.brand, "Realme", strlen("Realme"));
    phone_charger.volts = 220; 
    phone_charger.amperes = 10; 
    phone_charger.frequency = 50;
    phone_charger.phone_charger_dimension.length = 7; 
    phone_charger.phone_charger_dimension.breadth = 8; 
    phone_charger.phone_charger_dimension.height = 5;

    printf("Brand:%s\nVolts:%d V\nAmpere: %d A\nFrequency: %d Hz\nLength: %d CM\nBreadth: %d\nHeight: %d\n", 
        phone_charger.brand, phone_charger.volts, phone_charger.amperes, phone_charger.frequency, 
        phone_charger.phone_charger_dimension.length, phone_charger.phone_charger_dimension.breadth, phone_charger.phone_charger_dimension.height);
}