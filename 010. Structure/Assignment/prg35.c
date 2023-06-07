#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define POWER_UNIT  "PASCAL"
#define BRAND_NAME_LENGTH   32
#define TYPE_LENGTH  32
#define WEIGHT_UNIT  "Gram"
#define CURRENCY     "INR"
#define COLOR_LENGTH  16

struct Tap {
    int power;  //int in pascal
    char brand[BRAND_NAME_LENGTH];
    char type[TYPE_LENGTH];
    int weight; 
    double price;
    char color[COLOR_LENGTH];   //Tap emitted color
};  

int main(void) {

    struct Tap myTap; 

    myTap.power = 200e3; 
    strncpy(myTap.brand, "Sinclair", strlen("Sinclair"));
    strncpy(myTap.type, "Hose", 4);
    myTap.weight = 3750; 
    myTap.price = 9011.1;
    strncpy(myTap.color, "Metallic Steel", strlen("Metallic Steel"));

    printf("House Tap:\nPower: %d %s\nType: %s\nWeight: %d %s\nPrice: %.2lf %s\nColor: %s", 
        myTap.power, POWER_UNIT, myTap.type, myTap.weight, WEIGHT_UNIT, myTap.price, CURRENCY, myTap.color);

    return 0;
}