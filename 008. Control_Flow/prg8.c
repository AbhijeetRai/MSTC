
#include <stdio.h> 
#include <stdlib.h> 

char* pointer = "BATTLE OF PANIPAT III";


//to find out whether string is mutable or immutable
int main(void) {

    printf("value = %s, address = %p\n", pointer, pointer);
    pointer = "TREATY OF PURANDAR"; 
    printf("value = %s, address  = %p\n", pointer, pointer);

    /*
    value = BATTLE OF PANIPAT III, address = 00007FF71E63D008
    value = TREATY OF PURANDAR, address  = 00007FF71E63D040
    */

    return 0;
}