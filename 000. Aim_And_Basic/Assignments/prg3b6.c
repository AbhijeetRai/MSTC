#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define NR_TRIES 3
#define M_PI 3.14159265358979323846

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

    double r = take_input("Enter r: ");
    printf("%lf %lf\n", M_PI * r * r, M_PI * r  * 2);
}