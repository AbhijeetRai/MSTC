struct Spoon {

    int weight;
    char brand[16];
    int price;
};

#include <stdio.h>
#include <stdlib.h> 

int main(void) {

    struct Spoon my_spoon; 
    my_spoon.weight = 50;
    strncpy(my_spoon.brand, "Dior", 4);
    my_spoon.price = 10; 
    printf("%d %s %d\n", my_spoon.weight, my_spoon.brand, my_spoon.price);

    return 0;
}