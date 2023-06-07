#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define brand_name_length 32 
#define type_name_length  32 
#define currency          "INR"
#define weight_unit       "grams"
#define color_length      16

struct Date {
    int day,month, year;
};  

struct HeadPhone {

    char brand[brand_name_length];
    char type[type_name_length];        //wired or bluetooth
    unsigned int price; 
    double weight;
    char color[color_length];
    struct Date purchase_date;
};

int main(void) {

    struct HeadPhone myBoat; 

    strncpy(myBoat.brand, "BoAt", strlen("BoAt"));
    strncpy(myBoat.type, "Bluetooth/Wired", strlen("Bluetooth/Wired"));
    myBoat.price = 2000; 
    myBoat.weight = 415;
    strncpy(myBoat.color, "Red & Black", strlen("Red & Black"));
    myBoat.purchase_date.day = 10; 
    myBoat.purchase_date.month = 5; 
    myBoat.purchase_date.year = 2018;

    printf("Headphone\nBrand: %s\nType: %s\nPrice: %u\nWeight: %.2lf %s\nColor: %s", 
        myBoat.brand, myBoat.type, myBoat.price, myBoat.weight, weight_unit, myBoat.color);
    printf("\nPurchase date: %d-%d-%d\n", myBoat.purchase_date.day, myBoat.purchase_date.month, myBoat.purchase_date.year);

    return 0;
}