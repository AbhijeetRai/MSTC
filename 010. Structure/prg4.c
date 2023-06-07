#include <stdio.h> 
#include <stdlib.h>

struct random_structure {

    long long a; 
    char b; 
    int c; 
};

struct S {
    char a; 
    int i; 
    double b;
}instance_S;

int main(void) {

    struct random_structure instance;
    //example of internal padding, even if size is expected 16and it is 16
    //see how int address is aligned to 4 and internal padding is used for same
    printf("%llu %llu %llu\n", &instance.a, &instance.b, &instance.c);
    printf("size = %zu\n", sizeof(struct random_structure));

    printf("%zu\n", sizeof(instance_S));
    printf("%llu %llu %llu\n", &instance_S.a, &instance_S.i, &instance_S.b);

    return 0;
}
