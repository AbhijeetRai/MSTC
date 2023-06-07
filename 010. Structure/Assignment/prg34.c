#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define POWER_UNIT  "WATTAGE"
#define BRAND_NAME_LENGTH   32
#define TYPE_LENGTH  32
#define WEIGHT_UNIT  "Gram"
#define CURRENCY     "INR"
#define COLOR_LENGTH  16

struct Light {
    int power;  //int in watts
    char brand[BRAND_NAME_LENGTH];
    char type[TYPE_LENGTH];
    int weight; 
    double price;
    char color[COLOR_LENGTH];   //light emitted color
};  

int main(void) {

    struct Light myLight; 

    myLight.power = 18; 
    strncpy(myLight.brand, "WIPRO", strlen("WIPRO"));
    strncpy(myLight.type, "LED", 3);
    myLight.weight = 67; 
    myLight.price = 315.51;
    strncpy(myLight.color, "WHITE", 5);

    printf("Light Bulb:\nPower: %d %s\nType: %s\nWeight: %d %s\nPrice: %.2lf %s\nColor: %s", 
        myLight.power, POWER_UNIT, myLight.type, myLight.weight, WEIGHT_UNIT, myLight.price, CURRENCY, myLight.color);

    return 0;
}