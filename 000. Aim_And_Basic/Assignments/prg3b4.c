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

    double a, b, c; 

    a = take_input("Enter a: ");
    b = take_input("Enter b: "); 
    c = take_input("Enter c: ");

    if( (a + b) < c) {
        puts("Inappropirate dimensions");
        exit(EXIT_FAILURE);
    }

    double perimeter = (a + b + c);
    double s = perimeter / 2;   //semiperimeter
    double ar = sqrt(s * (s - a) * (s - b) * (s - c)); //area

    double A, B, C;              //measure angle A, angle B and angle C
    double as, bs, cs;           //square of side a, side b, side c

    as = a * a; 
    bs = b * b; 
    cs = c * c;

    A = (bs + cs - as) / (2 * b * c);
    B = (cs + as - bs) / (2 * c * a);
    C = (as + bs - cs) / (2 * a * b);

    A = acos(A);    //measure of angle A in radiians
    B = acos(B);    //measure of angle B in radiians
    C = acos(C);    //measure of angle C in radiians

    double A_inDegree = A * 180/ M_PI;
    double B_inDegree = B * 180/ M_PI;
    double C_inDegree = C * 180/ M_PI;

    printf("Perimeter = %lf\n", perimeter);
    printf("Area = %lf\n", ar);
    printf("Angles in radiians: A = %lf B = %lf C = %lf\n", A, B, C);
    printf("Angles in degrees: A = %lf B = %lf C = %lf\n", A_inDegree, B_inDegree, C_inDegree);

    exit(EXIT_SUCCESS);
}