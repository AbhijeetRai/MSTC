#include <stdio.h>
#include <stdlib.h> 

typedef struct random_struct {

    char char_data1; 
    int int_data1; 
    char char_data2;
}random_struct;

/*Print offset of all members from base address of struct*/
int main(void) {

    random_struct struct_instance;

    int offset1 = (unsigned long long)&struct_instance.char_data1 - (unsigned long long)&struct_instance;
    printf("%d\n", offset1);

    int offset2 = (unsigned long long)&struct_instance.int_data1 - (unsigned long long)&struct_instance;
    printf("%d\n", offset2);

    int offset3 = (unsigned long long)&struct_instance.char_data2 - (unsigned long long)&struct_instance;
    printf("%d\n", offset3);

    

    return (0);
}