#include <stdio.h>
#include <stdlib.h> 

#define NR_TRIES 3
#define G 6.67e-11

void my_exit(int flag) {

    if(flag == 0) {
        printf("\nPositive value not entered\n");
        printf("Terminating...\n");
        _getch(); 
        exit(EXIT_FAILURE);
    }
}

double take_input(char* message) {

    int flag = 0;

    double value;
    for(int i = 0; i < NR_TRIES; i++) {
        printf(message);
        scanf("%lf", &value);

        if(value < 0) {
            printf("Value must be greater than 0\n");
        }
        else {
            flag = 1;
            break;
        }
    }
    my_exit(flag);
    return value;
}

int main(void) {

    double m1, m2, r; 

    m1 = take_input("Enter m1: ");
    m2 = take_input("Enter m2: "); 
    r  = take_input("Enter r:  ");

    printf("Gravitational force = %lf\n", (G * m1 * m2) / (r * r));

    exit(EXIT_SUCCESS);
}