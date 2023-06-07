#include <stdio.h> 

extern int fun(void);

int main(void) {
    
    fun();
    return 0;
}

extern int fun(void) {

    //error LNK2019: unresolved external symbol n1 referenced in function fun
    extern int n1;
    printf("%d = n1", n1);  //NOT GETTING ANY N1 FROM ANY SOURCE FILE TO SHOW WHILE COMPILING
    return 0;
}