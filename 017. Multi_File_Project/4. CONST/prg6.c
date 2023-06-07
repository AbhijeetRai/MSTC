#include <stdio.h> 

extern void fun(char* message);

int main(void) {

    int dhoni_jersey = 7;               //dhoni_jersey is modifiable 
    
    const int* pointer = &dhoni_jersey;       //but I do not want it to be modifiable via pointer
    //hence made declaration of pointer to const
    //*pointer = 8; 
    //printf("%d\n", dhoni_jersey);

    fun("Trial and Error");
}

void fun(char* message) {
    
    /**
     * In Linux, Double quoted strings go on rodata
     * We do not know whether message receives double quoted string 
     * (double quoted string of global and local scope go to rodta)
     * 
     * If we try to modify value on rodata, program leads to seg fault
     * 
     * Array of characters go on data section(global scope) 
     * or stack(local scope) depending on scope 
     * Values on stack and data section are modfiable 
     * 
     * But we cannot always assume message stores address of 
     * data or stack section and not rodata section.
     * 
     * Although modification of rodata's data works in Windows 
     * It straightaway leads to seg fault in Linux 
     * 
     * We have to write robust code, ensuring code does not fail on any OS 
     * 
     * Hence we must make sure, string pointed by char* is not modifiable (in this function) 
     * Even if the passed string is modifiable (array) or not modifiable (double quoted string)
     * We must make sure, under no circumstance, we modify string pointed by char* message 
     * 
     * For same purpose we could make message a pointer to const: 
     * void fun(const char* message) and we could never modify data on address pointed by the message
    */
    *message = "Trial and Mistake";
    printf("%s\n", message);
}

