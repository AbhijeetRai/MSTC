#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

    //same code would crash on Linux 
    //modifying string literal, pointed by pointer, not existing in local stack 
    //is forbidden by c on Linux, do not ever do it
    //See if the code does it
    char* name = "Abhi"; 
    name[3] = 'I'; 
    printf("%s\n", name);

    return 0;
}