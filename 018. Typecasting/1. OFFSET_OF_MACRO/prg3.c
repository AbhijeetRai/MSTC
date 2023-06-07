#include <stdio.h> 
#include <stdlib.h> 

#define     OFFSET(type, member)        ((unsigned long long)(&(((type*)0)->member)))      

void print_struct_data(float* var3_address);

typedef struct stat {
        int var1;
        char var2; 
        float var3;
}stat;

int main(void) {

    stat ins1 = {10, 'A', 10.0f}; 
    stat ins2 = {20, 'B', 20.0f};
    print_struct_data(&ins1.var3);
    print_struct_data(&ins2.var3);

    return (0);
}

void print_struct_data(float* var3_address) {

    stat* stat_instance_address = 0;

    stat_instance_address = (stat*)((unsigned long long)var3_address - OFFSET(stat, var3));
    printf("%d %c %.2f\n", stat_instance_address->var1, stat_instance_address->var2, stat_instance_address->var3);
}