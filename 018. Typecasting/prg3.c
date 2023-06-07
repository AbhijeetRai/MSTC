/*
Big Endian:     Most significant byte at smallest address
Little Endian:  Most significant byte at largest address 
*/

#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

    unsigned int value = 0x0a0b0c0d;

    if ( *((char*)(&value)) == 0xd)
        printf("Little endian");
    else 
        printf("Big endian");

    return (0);
}

/* 
    Assume n is at M[1000:1003]
    As per the little endian organization, 
    the value 0x0a0b0c0d is stored in n as follows: 

    M[1000]     M[1001]     M[1002]     M[1003]
    0d          0c          0b          0a 

    As per the big endian organization, 
    the value 0x0a0b0c0d is stroed in n as follows: 
    M[1000]     M[1001]     M[1002]     M[1003]
    0a          0b          0c          0d

    To write a program to determine an endianness of machine, 
    you should compare the contents of memory location M[1000]
    with 0xd and 0xa. 

    If comparison with 0xd is true then its a little endian machine 
    else if comparison 0xa is true then its a big endian machine 
*/