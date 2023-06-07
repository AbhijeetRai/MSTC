#include <stdio.h>

#define BRAND_LENGTH    32
#define SIZE_DIMENSION "GB"

struct Date {

    int day, month, year;
};

struct phone {

    char brand[BRAND_LENGTH];
    int ram_size; 
    int disk_size; 
    struct Date purchase_date;
};

int main(void) {

    struct phone my_lenovo; 
    
    my_lenovo.ram_size = 4;
    my_lenovo.disk_size = 64; 
    strncpy(my_lenovo.brand, "LENOVO", strlen("LENOVO"));
    
    my_lenovo.purchase_date.day = 2;
    my_lenovo.purchase_date.month = 1; 
    my_lenovo.purchase_date.year = 2021;

    printf("Brand = %s\nRam size = %d %s\nDisk Size = %d %s\n", 
        my_lenovo.brand, my_lenovo.ram_size, SIZE_DIMENSION, my_lenovo.disk_size, SIZE_DIMENSION);
    printf("Purchase date: %d-%d-%d\n", my_lenovo.purchase_date.day, my_lenovo.purchase_date.month, my_lenovo.purchase_date.year);

    return 0;
}