#include <stdio.h>
#include <stdlib.h> 

#define motor_company_name_length   64
#define weight_unit "KG"
#define length 16
#define brand_name_length 16
#define motor_capacity_unit     "Volts"

struct Motor {

    char motor_company[motor_company_name_length];
    int capacity; //volts in number
};

struct Fan {

    int no_of_blades; 
    int weight;
    struct Motor motor_details; 
    char color[length];
    int price; 
    char brand[brand_name_length];
};

int main(void) {
    
    struct Fan myFan; 

    myFan.no_of_blades = 3; 
    myFan.weight = 3; 

    strncpy(myFan.motor_details.motor_company, "USHA", strlen("USHA"));
    myFan.motor_details.capacity = 220;

    strncpy(myFan.color, "Dark Maroon", strlen("Dark Maroon"));
    myFan.price = 3200;
    strncpy(myFan.brand, "USHA", 4);

    printf("Fan\nNo of Blades: %d\nWeight: %d %s\nMotor Company: %s\nMotor capacity: %d %s\n", 
        myFan.no_of_blades, myFan.weight, weight_unit, myFan.motor_details.motor_company, myFan.motor_details.capacity, motor_capacity_unit);
    printf("Price: %d\nBrand: %s\n", myFan.price, myFan.brand);

    return 0;
}