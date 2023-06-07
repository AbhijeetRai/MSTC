#include <stdio.h> 

typedef struct Cloth_Hanger {

    char color[8]; 
    char brand[16]; 
    int price; 
    int length;
    int breadth;
}Hanger;

int main(void) {

    Hanger my_hanger; 
    
    strncpy(my_hanger.color, "Blue", strlen("Blue"));
    strncpy(my_hanger.brand, "NeelKamal", strlen("Neelkamal"));
    my_hanger.price = 10; 
    my_hanger.length = 30; 
    my_hanger.breadth = 20;

    printf("Color = %s\nBrand = %s\nPrice = %drs\nLength = %dcm\nBreadth = %dcm\n", 
        my_hanger.color, my_hanger.brand, my_hanger.price, my_hanger.length, my_hanger.breadth);

    return 0;
}