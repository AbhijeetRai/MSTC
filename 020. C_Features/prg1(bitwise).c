/* SHIFT AND BITWISE OPERATORS */

#include <stdio.h> 
#include <stdlib.h> 

void bitwise_and_demo(void);
void bitwise_or_demo(void); 
void bitwise_xor_demo(void);
void bitwise_not_demo(void);
void left_shift_demo(void);
void right_shift_demo(void);

int main(void) {
    //bitwise_and_demo();
    //bitwise_or_demo();
    //bitwise_xor_demo();
    //bitwise_not_demo();
    left_shift_demo();
    right_shift_demo();

    return (0);
}

void bitwise_and_demo(void) {
    int n1 = 0xa0b0c0d0;
    int n2 = 0x4982a2d4;
    printf("%x\n", n1 & n2);
}

void bitwise_or_demo(void) {
    int n1 = 0xa0b0c0d0;
    int n2 = 0x4982a2d4;
    printf("%x\n", n1 | n2);
}

void bitwise_xor_demo(void) {
    int n1 = 0xa0b0c0d0;
    int n2 = 0x4982a2d4;
    printf("%x\n", n1 ^ n2);
}

void bitwise_not_demo(void) { 
    int n = 0xa0b0c0d0;
    printf("rs = %x\n", ~n); 
}

void left_shift_demo(void) {
    printf("%d\n", 8 << 2);
}

void right_shift_demo(void) {
    printf("%d\n", 8 >> 2);
}