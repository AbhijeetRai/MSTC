#include <stdio.h> 

int main(void) {

    //Ideally everytime hardcoded double quoted string is used 
    //Point it by const char*, pointer to const 
    //We cannot afford to modify data in rodata section 
    //That data is immovable, hence point it by pointer to const 
    //Treat pointee as constant
    const char* message = "Hi"; 
    *message = "Hello";
    printf("%s\n", message);
}