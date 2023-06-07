#include <stdio.h> 
#include <stdlib.h> 

#define k 8.988e+9

int main(void) {

    double q1, q2, r, F; 
    char* force_type = NULL;

    printf("Enter q1 q2 r: ");
    scanf("%lf %lf %lf", &q1, &q2, &r);

    F = (k * q1 * q2) / (r * r);

    if(F > 0) 
        force_type = "repulsion"; 
    else 
        force_type = "attraction";

    printf("F = %.2lf %s\n", F, force_type);

    return 0;
}