#include <stdio.h> 
#include <stdlib.h> 

int cpa_add(int n1, int n2); 
double compute_gravity(double m1, double m2, double r);

int main(void) {
    int rate; 
    double rated;
    int (*pfn1)(int, int);
    double (*pfn2)(double, double, double);

    pfn1 = &cpa_add; 
    pfn2 = compute_gravity;

    rate = pfn1(10, 20);
    rated = pfn2(1.1, 2.2, 3.3);

    printf("rate = %d, rated = %.2lf cpa_add = %p compute_gravity = %p\n", rate, rated, cpa_add, &compute_gravity);

    return 0;
}

int cpa_add(int n1, int n2) {

    puts("I am in cpa_add"); 
    return (0);
}

double compute_gravity(double m1, double m2, double r) {

    puts("I am in compute_gravity");
    return (0.0);
}