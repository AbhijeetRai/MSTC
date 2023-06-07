//-> has greater precedence than &

#include <stdio.h> 
#include <stdlib.h> 

typedef struct random_struct {
    int int_data1; 
    char char_data; 
    int int_data2;
}random_struct;

int main(void) {

    random_struct* random_struct_ptr = NULL;
    random_struct instance;

    random_struct_ptr  = &instance;
    printf("%d %c %d\n", random_struct_ptr -> int_data1, random_struct_ptr -> char_data, random_struct_ptr -> int_data2);

    /*offset of variables from the struct*/
    printf("%llu %llu %llu %llu\n", (unsigned long long)random_struct_ptr, (unsigned long long)&random_struct_ptr -> int_data1, 
        (unsigned long long)&random_struct_ptr -> char_data, (unsigned long long)&random_struct_ptr -> int_data2);

    return (0);
}