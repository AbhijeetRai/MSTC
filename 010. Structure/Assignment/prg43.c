#include <stdio.h> 
#include <stdlib.h>

#define supplier_name_length    32
#define dealer_name_length      32 
#define color_name_length       32 
#define type_name_length        32

#define currency        "INR"
#define weight_unit     "gm"
#define dimension_unit  "Inches"

typedef struct date {
    int day, month,year;
}date;

struct dimension {
    int height; 
    int length; 
    int breadth;
};

typedef struct chair {

    char supplier[supplier_name_length]; 
    char dealer[dealer_name_length];
    char color[color_name_length];
    char type[type_name_length]; //office chair or plastic chair
    int price; 
    int weight; 
    date purchase_date;
    struct dimension stats;

}chair;

void show_details(chair my_chair) {

    printf("Chair\n");
    printf("Supplier: %s\nDealer: %s\nColor: %s\nType: %s\nPrice: %d %s\nWeight: %d %s\n",
        my_chair.supplier, my_chair.dealer, my_chair.color, my_chair.type, my_chair.price, currency, my_chair.weight, weight_unit);
    printf("Purchase_date: %d-%d-%d\n", my_chair.purchase_date.day, my_chair.purchase_date.month, my_chair.purchase_date.year);
    printf("\nDimensions:\nLength: %d %s\nBreadth: %d %s\nHeight: %d %s\n", my_chair.stats.length, dimension_unit,
        my_chair.stats.breadth, dimension_unit, my_chair.stats.height, dimension_unit);
}

int main(void) {

    chair my_chair; 

    //strncpy(my_chair., "", strlen(""));
    strncpy(my_chair.supplier, "amazon", strlen("amazon"));
    strncpy(my_chair.dealer, "nazaro", strlen("nazaro"));
    strncpy(my_chair.color, "All black", strlen("All Black"));
    strncpy(my_chair.type, "Office Chair", strlen("Office Chair"));
    my_chair.price = 6000; 
    my_chair.weight = 7000;

    my_chair.purchase_date.day = 1;
    my_chair.purchase_date.month = 1;
    my_chair.purchase_date.year = 2023;

    my_chair.stats.length = 12;
    my_chair.stats.breadth = 12;
    my_chair.stats.height = 60;

    show_details(my_chair);

    exit(EXIT_SUCCESS);
}