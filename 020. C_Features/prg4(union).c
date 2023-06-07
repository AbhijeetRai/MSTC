#include <stdio.h> 

union my_union {
    int var1; 
    char var2; 
    double var3; 
    long long var4;
};

int main(void) {

    union my_union data;
    printf("%zu\n", sizeof(data));

    data.var1 = 1165;
    //1165 is aranged in 8 bytes like: 
    //00000000 00000000 00000100 10001101
    //var2 is accessed, since it is char, first byte is read: 10001101: which is 141: 
    //141 is ascii of 'ì'  ì: it is acute i,  not english's "i"

    printf("%c\n", data.var2);

    return (0);
}

