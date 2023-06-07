#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define NR_TRIES 3

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

    double a, b, c, d; 

    a = take_input("Enter a: ");
    b = take_input("Enter b: ");
    c = take_input("Enter c: ");
    d = take_input("Enter d: ");

    if((a + b + c) < d) {
        printf("Inappropirate dimensions\n"); 
        exit(EXIT_FAILURE);
    }

    double perimeter = (a + b + c + d);
    double s = perimeter / 2;  
    double ar = sqrt((s - a) * (s - b) * (s - c) * (s - d));

    printf("%lf %lf\n", perimeter, ar);

    exit(EXIT_SUCCESS); 
}