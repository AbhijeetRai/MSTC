#include <stdio.h> 

int fun(void)  {

    printf("In function\n");
    return 1;
}

int main() {

    int a = 10;
    fun(a);
    return 0;
}