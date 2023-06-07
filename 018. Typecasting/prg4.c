#include <stdio.h>
#include <stdlib.h> 

int main(void) {

    unsigned long long hex_val = 0x0f0c0a0b0a0b0c0d;
    printf("%llu %llu\n", (unsigned long long)&hex_val, (unsigned long long)(&hex_val +1) );

    printf("%X\n", *(char*)(&hex_val));
    unsigned long long read_two_bytes = *((short*)((char*)(&hex_val) + 2)) ;
    printf("read_two_bytes = %llX\n", read_two_bytes);

    short last_two_bytes = *((((char*)(&hex_val)) + 7)) ;
    printf("%x\n", last_two_bytes);

    return (0);
}